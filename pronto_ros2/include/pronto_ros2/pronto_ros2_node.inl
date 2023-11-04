
inline void BlockToVector3d(const Eigen::Block<Eigen::VectorXd, 3, 1> in, geometry_msgs::msg::Vector3 & out)
{
    
    out.x = in(0);
    out.y = in(1);
    out.z = in(2);
}

inline void BlockToPoint(const Eigen::Block<Eigen::VectorXd, 3, 1> in, geometry_msgs::msg::Point & out)
{
    out.set__x(in(0));
    out.set__y(in(1));
    out.set__z(in(2));
}

inline void QuaternionToMsg(const Eigen::Quaterniond & in , geometry_msgs::msg::Quaternion & out)
{
    out.set__w(in.w());
    out.set__x(in.x());
    out.set__y(in.y());
    out.set__z(in.z());
}

















template<typename MsgT>
void ProntoNode::addSensingModule(pronto::SensingModule<MsgT>& module, const SensorId_t& sensor_id, bool roll_forward,
											bool publish_head, const std::string& topic, bool subscribe) 
{

	if(active_modules_.count(sensor_id) > 0){
			RCLCPP_WARN_STREAM(this->get_logger(), "Sensing Module \"" << sensor_id << "\" already added. Skipping.");
			return;
	}

	RCLCPP_INFO_STREAM(this->get_logger(), "Sensor id: " << sensor_id);
	RCLCPP_INFO_STREAM(this->get_logger(), "Roll forward: "<< (roll_forward? "yes" : "no"));
	RCLCPP_INFO_STREAM(this->get_logger(), "Publish head: "<< (publish_head? "yes" : "no"));
	RCLCPP_INFO_STREAM(this->get_logger(), "Topic: " << topic);


	// store the will to roll forward when the message is received
	std::pair<SensorId_t, bool> roll_pair(sensor_id, roll_forward);
	roll_forward_.insert(roll_pair);

	// store the will to publish the estimator state when the message is received
	std::pair<SensorId_t, bool> publish_pair(sensor_id, publish_head);
	publish_head_.insert(publish_pair);

	// store the module as void*, to allow for different types of module to stay
	// in the same container. The type will be known when the message arrives
	// so we can properly cast back to the right type.
	std::pair<SensorId_t, void*> pair(sensor_id, (SensingModule<MsgT>*) &module);
	active_modules_.insert(pair);

	// subscribe the generic templated callback for all modules
	if(subscribe){


			std::cerr << sensor_id << " subscribing to " << topic;
			std::cerr << " with MsgT = " << type_name<MsgT>() << std::endl;

			rclcpp::QoS qos(rclcpp::KeepLast(10000));  // Keep the last 10000 messages
			qos.transient_local();  // Use transient local QoS for fast intra-process communication
			// auto fcn = std::bind(&ProntoNode::callback<MsgT>, std::placeholders::_1, sensor_id);

			auto lambdaCallback = [this, sensor_id](const MsgT & msg) {
       			 this->callback<MsgT>(msg, sensor_id);
    		};

			// auto fcn = std::bind(ProntoNode::callback<MsgT>, std::placeholders::_1, sensor_id);
			sensor_subscribers_[sensor_id] = this->create_subscription<MsgT>(topic, qos, lambdaCallback);
								
	}


};











template<typename MsgT>
void ProntoNode::callback(const MsgT & msg, const SensorId_t& sensor_id) 
{

	RCLCPP_DEBUG_STREAM(this->get_logger(), "Callback for sensor " << sensor_id);

	// this is a generic templated callback that does the same for every module:
	// if the module is initialized and the filter is ready
	// 1) take the measurement update and pass it to the filter if valid
	// 2) publish the filter state if the module wants to
	if(isFilterInitialized()) {
	// appropriate casting to the right type and call to the process message
	// function to get the update
	// Record start time
	auto start = std::chrono::high_resolution_clock::now();
	RBISUpdateInterface* update = static_cast<pronto::SensingModule<MsgT>*>(active_modules_[sensor_id])->processMessage(&msg, state_est_.get());
	auto end = std::chrono::high_resolution_clock::now();
	RCLCPP_DEBUG_STREAM(this->get_logger(), "Time elapsed process message: " << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count());
	start = end;

	if(update == nullptr) {

		RCLCPP_DEBUG_STREAM(this->get_logger(), "Invalid " << sensor_id << " update" << std::endl);
		// special case for pose meas, it returns null when it does not want
		// to process data anymore
		if(sensor_id.compare("pose_meas") == 0){
				sensor_subscribers_["pose_meas"].reset();
		}
		return;

	}


	if(sensor_id.compare("fovis") == 0){
		RCLCPP_DEBUG_STREAM(this->get_logger(), "fovis update posterior: " << update->posterior_state.position().transpose());
	}

	#if DEBUG_AICP
	if(sensor_id.compare("scan_matcher") == 0){
		aicp_path.header.frame_id = "odom";
		Eigen::Vector3d p = dynamic_cast<RBISIndexedPlusOrientationMeasurement*>(update)->measurement.head<3>();
		Eigen::Quaterniond q = dynamic_cast<RBISIndexedPlusOrientationMeasurement*>(update)->orientation;

		std::cerr << "MEASR    : " << p.transpose() << "   " << rotation::getEulerAnglesDeg(q).transpose() << std::endl;

		// Eigen::Vector3d p = dynamic_cast<RBISIndexedMeasurement*>(update)->measurement.head<3>();

		// std::cerr << "ABOUT TO SEND TO FILTER THE FOLLOWING: " << p.transpose() << std::endl;

	}
	#endif

	pronto::RBIS prior;
	pronto::RBIS posterior;
	pronto::RBIM prior_cov;
	pronto::RBIM posterior_cov;
	state_est_->getHeadState(prior,prior_cov);
	// tell also the filter if we need to roll forward
	state_est_->addUpdate(update, roll_forward_[sensor_id]);
	state_est_->getHeadState(posterior,posterior_cov);

	if(sensor_id.compare("scan_matcher") == 0){
	std::cerr << "PRIOR    : " << prior.position().transpose() << " " << rotation::getEulerAnglesDeg(prior.orientation()).transpose() << std::endl;
	std::cerr << "POSTERIOR: " << posterior.position().transpose() << " " << rotation::getEulerAnglesDeg(posterior.orientation()).transpose() << std::endl;
	std::cerr << ":::::::" << std::endl;
	}

	end = std::chrono::high_resolution_clock::now();
	RCLCPP_DEBUG_STREAM(this->get_logger(), "Time elapsed process addUpdate: " << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count());
	start = end;


	if (publish_head_[sensor_id]) {

		state_est_->getHeadState(head_state, head_cov);

		// fill in linear velocitytemp_v3
		// tf::vectorEigenToTF(head_state.velocity(),);
		// tf::vector3TFToMsg(temp_v3,twist_msg_.twist.twist.linear);
		BlockToVector3d(head_state.velocity(),  twist_msg_.twist.twist.linear);
		// fill in angular velocity
		// tf::vectorEigenToTF(head_state.angularVelocity(),temp_v3);
		// tf::vector3TFToMsg(temp_v3,twist_msg_.twist.twist.angular);
		BlockToVector3d(head_state.angularVelocity(), twist_msg_.twist.twist.angular);

		// fill in time
		twist_msg_.header.stamp = rclcpp::Time(head_state.utime * 1000);

		// TODO insert appropriate covariance into the message

		// set twist covariance to zero
		twist_msg_.twist.covariance.fill(0);

		Eigen::Block<RBIM, 3, 3> vel_cov = head_cov.block<3,3>(RBIS::velocity_ind,RBIS::velocity_ind);
		Eigen::Block<RBIM, 3, 3> omega_cov = head_cov.block<3,3>(RBIS::angular_velocity_ind,RBIS::angular_velocity_ind);


		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				twist_msg_.twist.covariance[6*i+j] = vel_cov(i,j);
				twist_msg_.twist.covariance[6*(i+3)+j+3] = omega_cov(i,j);
			}
		}

		twist_pub_->publish(twist_msg_);

		// make sure stuff is non-NAN before publishing
		assert(head_state.position().allFinite());

		// fill in message position
		// tf::vectorEigenToTF(head_state.position(), temp_v3);
		// tf::pointTFToMsg(temp_v3, pose_msg_.pose.pose.position);
		BlockToPoint(head_state.position(), pose_msg_.pose.pose.position);

		// fill in message orientation
		// tf::quaternionEigenToTF(head_state.orientation(), temp_q);
		// tf::quaternionTFToMsg(temp_q,pose_msg_.pose.pose.orientation);
		QuaternionToMsg(head_state.orientation(), pose_msg_.pose.pose.orientation);

		pose_msg_.header.stamp = rclcpp::Time(head_state.utime * 1000);


		if(publish_tf_){
				// Only publish the pose if the timestamp is different:
				// This prevents issues in Noetic where repeated warnings of type:
				// "TF_REPEATED_DATA ignoring data with redundant timestamp for frame base at time"
				// are otherwise printed to the terminal.
				// Cf. https://github.com/ros/geometry2/issues/467#issuecomment-751572836
				rclcpp::Time new_stamp = pose_msg_.header.stamp;
				if (new_stamp > transform_msg_.header.stamp) {
						transform_msg_.transform.translation.x = pose_msg_.pose.pose.position.x;
						transform_msg_.transform.translation.y = pose_msg_.pose.pose.position.y;
						transform_msg_.transform.translation.z = pose_msg_.pose.pose.position.z;
						transform_msg_.transform.rotation = pose_msg_.pose.pose.orientation;
						transform_msg_.header.stamp = new_stamp;
						tf2_broadcaster_->sendTransform(transform_msg_);
				}
		}

		pose_pub_->publish(pose_msg_);

	} else {

		RCLCPP_DEBUG_STREAM(this->get_logger(), "NOT Publish head sensor ID");

	}
	end = std::chrono::high_resolution_clock::now();
	RCLCPP_DEBUG_STREAM(this->get_logger(), "Time elapsed till the end: " << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count());
	std::cout << std::endl;

	}
};


template<class MsgT>
void ProntoNode::addInitModule(pronto::SensingModule<MsgT>& module, const SensorId_t& sensor_id,
				const std::string& topic, bool subscribe)

{

	if(init_modules_.count(sensor_id) > 0){
			RCLCPP_WARN_STREAM(this->get_logger(), "Init Module \"" << sensor_id << "\" already added. Skipping.");
			return;
	}
	RCLCPP_INFO_STREAM(this->get_logger(), "Sensor init id: " << sensor_id);
	RCLCPP_INFO_STREAM(this->get_logger(), "Topic: " << topic);

	// add the sensor to the list of sensor that require initialization
	std::pair<SensorId_t, bool> init_id_pair(sensor_id, false);
	initialized_list_.insert(init_id_pair);
	// store the module as void*, to allow for different types of module to stay
	// in the same container. The type will be known when the message arrives
	// so we can properly cast back to the right type.
	std::pair<SensorId_t, void*> pair(sensor_id, (void*) &module);
	init_modules_.insert(pair);
	if(subscribe){
		std::cerr << sensor_id << " subscribing to " << topic;
		std::cerr << " with MsgT = " << type_name<MsgT>() << std::endl;
		rclcpp::QoS qos(rclcpp::KeepLast(10000));  // Keep the last 10000 messages
		qos.transient_local();  // Use transient local QoS for fast intra-process communication

		auto lambdaCallback = [this, sensor_id](const MsgT & msg) {
       			 this->initCallback<MsgT>(msg, sensor_id);
		};

		init_subscribers_[sensor_id] = this->create_subscription<MsgT>(topic, qos, lambdaCallback);
	}

};



template<class MsgT>
void ProntoNode::initCallback(const MsgT & msg, const SensorId_t& sensor_id)
{

	if(verbose_){
		RCLCPP_INFO_STREAM(this->get_logger(), "Init callback for sensor " << sensor_id);
	}
	if(initialized_list_.count(sensor_id) > 0 && !initialized_list_[sensor_id])
	{
			initialized_list_[sensor_id] = static_cast<SensingModule<MsgT>*>(init_modules_[sensor_id])->processMessageInit(&msg,
				initialized_list_,
				default_state,
				default_cov,
				init_state,
				init_cov);

			// if the sensor has been successfully initialized, we unsubscribe.
			// This happens only for the sensors which are only for initialization.
			// The sensor which are for initialization and active will continue to listen
			if(initialized_list_[sensor_id]){
					init_subscribers_[sensor_id].reset();
					// attempt to initialize the filter, because the value has changed
					// in the list
					initializeFilter();
			}
	} else {
			// if we are here it means that the module is not in the list of
			// initialized modules or that the module is already initialized
			// in both cases we don't want to subscribe to this topic anymore,
			// unless there is no subscriber because we are processing a rosbag.
			if(init_subscribers_.count(sensor_id) > 0){
					init_subscribers_[sensor_id].reset();
			}
	}




}






