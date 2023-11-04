#include "pronto_ros2/pronto_ros2_node.hpp"


using namespace std::chrono_literals;





namespace pronto {











ProntoNode::ProntoNode() : Node("pronto_ros2_node")
{

	bool publish_pose;
	tf2_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*this);

	if(this->get_parameter("publish_pose", publish_pose)){
		if(publish_pose){
			std::string pose_frame_id = "odom";
			if(!this->get_parameter("pose_frame_id", pose_frame_id)){
				RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \"pose_frame_id\". Setting default to: \"" + pose_frame_id +"\"");
			}
			std::string pose_topic = "POSE_BODY";
			if(this->get_parameter("pose_topic", pose_topic)){
				pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(pose_topic, 200);
				pose_msg_.header.frame_id = pose_frame_id;
			}
			std::string twist_topic = "TWIST_BODY";
			std::string twist_frame_id = "base";
			if(!this->get_parameter("twist_frame_id", twist_frame_id)){
				RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \"twist_frame_id\". Setting default to: \"" + twist_frame_id +"\"");
			}
			if(this->get_parameter("twist_topic", twist_topic)){
				twist_pub_ = this->create_publisher<geometry_msgs::msg::TwistWithCovarianceStamped>(twist_topic, 200);
				twist_msg_.header.frame_id = twist_frame_id;
			}
			// try to
			if(!this->get_parameter("publish_tf", publish_tf_)){
				RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \"publish_tf\". Not publishing TF.");
			}
			if(publish_tf_){
				std::string tf_child_frame_id = "base";
				if(!this->get_parameter("tf_child_frame_id", tf_child_frame_id)){
					RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \"tf_frame_id\". Setting default to \"base\".");
				}
				transform_msg_.header.frame_id = pose_frame_id;
				// NOTE implicitly assuming the twist frame id is the base frame
				transform_msg_.child_frame_id = tf_child_frame_id;
				RCLCPP_INFO_STREAM(this->get_logger(), "Publishing TF with frame_id: \"" + transform_msg_.header.frame_id + "\" and child_frame_id: \"" + transform_msg_.child_frame_id + "\"");
			}
		}

	}


	double history_span = 1e6; // keep 1 second as default
	if(!this->get_parameter("utime_history_span", history_span)){
	RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param \"utime_history_span\". Setting default to \"" + std::to_string(history_span) + "\"");
	}
	history_span_ = history_span;
	initializeState();
	initializeCovariance();
	if(verbose_){
		RCLCPP_INFO_STREAM(this->get_logger(), "Frontend constructed.");
	}

	aicp_path_publisher = this->create_publisher<nav_msgs::msg::Path>("/aicp/relative_path",100);

}



ProntoNode::~ProntoNode()
{


}










// template<typename MsgT>
// void ProntoNode::addSensingModule(MsgT& module, const SensorId_t& sensor_id, bool roll_forward,
// 											bool publish_head, const std::string& topic, bool subscribe) 
// {

// 	if(active_modules_.count(sensor_id) > 0){
// 			RCLCPP_WARN_STREAM(this->get_logger(), "Sensing Module \"" << sensor_id << "\" already added. Skipping.");
// 			return;
// 	}

	// RCLCPP_INFO_STREAM(this->get_logger(), "Sensor id: " << sensor_id);
	// RCLCPP_INFO_STREAM(this->get_logger(), "Roll forward: "<< (roll_forward? "yes" : "no"));
	// RCLCPP_INFO_STREAM(this->get_logger(), "Publish head: "<< (publish_head? "yes" : "no"));
	// RCLCPP_INFO_STREAM(this->get_logger(), "Topic: " << topic);


	// // store the will to roll forward when the message is received
	// std::pair<SensorId_t, bool> roll_pair(sensor_id, roll_forward);
	// roll_forward_.insert(roll_pair);

	// // store the will to publish the estimator state when the message is received
	// std::pair<SensorId_t, bool> publish_pair(sensor_id, publish_head);
	// publish_head_.insert(publish_pair);

	// // store the module as void*, to allow for different types of module to stay
	// // in the same container. The type will be known when the message arrives
	// // so we can properly cast back to the right type.
	// std::pair<SensorId_t, void*> pair(sensor_id, (SensingModule<MsgT>*) &module);
	// active_modules_.insert(pair);

	// // subscribe the generic templated callback for all modules
	// if(subscribe){
	// 		std::cerr << sensor_id << " subscribing to " << topic;
	// 		std::cerr << " with MsgT = " << type_name<MsgT>() << std::endl;

	// 		rclcpp::QoS qos(rclcpp::KeepLast(10000));  // Keep the last 10000 messages
	// 		qos.transient_local();  // Use transient local QoS for fast intra-process communication
	// 		sensor_subscribers_[sensor_id] = this->create_subscription<MsgT>(topic, qos, 
	// 															std::bind(&ProntoNode::callback<MsgT>, this, std::placeholders::_1, sensor_id));
	// }



// }









// template<class MsgT>
// void ProntoNode::addInitModule(pronto::SensingModule<MsgT>& module, const SensorId_t& sensor_id,
// 				const std::string& topic, bool subscribe)

// {

// 	if(init_modules_.count(sensor_id) > 0){
// 			RCLCPP_WARN_STREAM(this->get_logger(), "Init Module \"" << sensor_id << "\" already added. Skipping.");
// 			return;
// 	}
// 	RCLCPP_INFO_STREAM(this->get_logger(), "Sensor init id: " << sensor_id);
// 	RCLCPP_INFO_STREAM(this->get_logger(), "Topic: " << topic);

// 	// add the sensor to the list of sensor that require initialization
// 	std::pair<SensorId_t, bool> init_id_pair(sensor_id, false);
// 	initialized_list_.insert(init_id_pair);
// 	// store the module as void*, to allow for different types of module to stay
// 	// in the same container. The type will be known when the message arrives
// 	// so we can properly cast back to the right type.
// 	std::pair<SensorId_t, void*> pair(sensor_id, (void*) &module);
// 	init_modules_.insert(pair);
// 	if(subscribe){
// 		std::cerr << sensor_id << " subscribing to " << topic;
// 		std::cerr << " with MsgT = " << type_name<MsgT>() << std::endl;
// 		rclcpp::QoS qos(rclcpp::KeepLast(10000));  // Keep the last 10000 messages
// 		qos.transient_local();  // Use transient local QoS for fast intra-process communication
// 		init_subscribers_[sensor_id] = this->create_subscription<MsgT>(topic, qos, 
// 									std::bind(&ProntoNode::initCallback<MsgT>, this, std::placeholders::_1, sensor_id));
// 	}

// }








bool ProntoNode::areModulesInitialized()
{

	std::map<SensorId_t ,bool>::iterator it = initialized_list_.begin();
	for(; it != initialized_list_.end(); ++it){
			if(!it->second){
					return false;
			}
	}
	return true;

}




bool ProntoNode::isFilterInitialized()
{
	return filter_initialized_;
}





inline void ProntoNode::getState(pronto::RBIS& state, pronto::RBIM& cov) const
{
	state_est_->getHeadState(state, cov);
}





inline bool ProntoNode::reset(const pronto::RBIS& state, const pronto::RBIM& cov) 
{
	state_est_->addUpdate(new pronto::RBISResetUpdate(state,
																											cov,
																											RBISUpdateInterface::reset,
																											state.utime), true);
	return true;
}




// template<class MsgT>
// void ProntoNode::initCallback(std::shared_ptr<MsgT const> msg, const SensorId_t& sensor_id)
// {

// 	if(verbose_){
// 		RCLCPP_INFO_STREAM(this->get_logger(), "Init callback for sensor " << sensor_id);
// 	}
// 	if(initialized_list_.count(sensor_id) > 0 && !initialized_list_[sensor_id])
// 	{
// 			initialized_list_[sensor_id] = static_cast<SensingModule<MsgT>*>(init_modules_[sensor_id])->processMessageInit(msg.get(),
// 				initialized_list_,
// 				default_state,
// 				default_cov,
// 				init_state,
// 				init_cov);

// 			// if the sensor has been successfully initialized, we unsubscribe.
// 			// This happens only for the sensors which are only for initialization.
// 			// The sensor which are for initialization and active will continue to listen
// 			if(initialized_list_[sensor_id]){
// 					init_subscribers_[sensor_id].reset();
// 					// attempt to initialize the filter, because the value has changed
// 					// in the list
// 					initializeFilter();
// 			}
// 	} else {
// 			// if we are here it means that the module is not in the list of
// 			// initialized modules or that the module is already initialized
// 			// in both cases we don't want to subscribe to this topic anymore,
// 			// unless there is no subscriber because we are processing a rosbag.
// 			if(init_subscribers_.count(sensor_id) > 0){
// 					init_subscribers_[sensor_id].reset();
// 			}
// 	}




// }
	





// template<class MsgT>
// void ProntoNode::callback(std::shared_ptr<MsgT const> msg, const SensorId_t& sensor_id)
// {

// 	RCLCPP_DEBUG_STREAM(this->get_logger(), "Callback for sensor " << sensor_id);

// 	// this is a generic templated callback that does the same for every module:
// 	// if the module is initialized and the filter is ready
// 	// 1) take the measurement update and pass it to the filter if valid
// 	// 2) publish the filter state if the module wants to
// 	if(isFilterInitialized()) {
// 	// appropriate casting to the right type and call to the process message
// 	// function to get the update
// 	// Record start time
// 	auto start = std::chrono::high_resolution_clock::now();
// 	RBISUpdateInterface* update = static_cast<pronto::SensingModule<MsgT>*>(active_modules_[sensor_id])->processMessage(msg.get(), state_est_.get());
// 	auto end = std::chrono::high_resolution_clock::now();
// 	RCLCPP_DEBUG_STREAM(this->get_logger(), "Time elapsed process message: " << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count());
// 	start = end;

// 	if(update == nullptr) {

// 		RCLCPP_DEBUG_STREAM(this->get_logger(), "Invalid " << sensor_id << " update" << std::endl);
// 		// special case for pose meas, it returns null when it does not want
// 		// to process data anymore
// 		if(sensor_id.compare("pose_meas") == 0){
// 				sensor_subscribers_["pose_meas"].reset();
// 		}
// 		return;

// 	}


// 	if(sensor_id.compare("fovis") == 0){
// 		RCLCPP_DEBUG_STREAM(this->get_logger(), "fovis update posterior: " << update->posterior_state.position().transpose());
// 	}

// 	#if DEBUG_AICP
// 	if(sensor_id.compare("scan_matcher") == 0){
// 		aicp_path.header.frame_id = "odom";
// 		Eigen::Vector3d p = dynamic_cast<RBISIndexedPlusOrientationMeasurement*>(update)->measurement.head<3>();
// 		Eigen::Quaterniond q = dynamic_cast<RBISIndexedPlusOrientationMeasurement*>(update)->orientation;

// 		std::cerr << "MEASR    : " << p.transpose() << "   " << rotation::getEulerAnglesDeg(q).transpose() << std::endl;

// 		// Eigen::Vector3d p = dynamic_cast<RBISIndexedMeasurement*>(update)->measurement.head<3>();

// 		// std::cerr << "ABOUT TO SEND TO FILTER THE FOLLOWING: " << p.transpose() << std::endl;

// 	}
// 	#endif

// 	pronto::RBIS prior;
// 	pronto::RBIS posterior;
// 	pronto::RBIM prior_cov;
// 	pronto::RBIM posterior_cov;
// 	state_est_->getHeadState(prior,prior_cov);
// 	// tell also the filter if we need to roll forward
// 	state_est_->addUpdate(update, roll_forward_[sensor_id]);
// 	state_est_->getHeadState(posterior,posterior_cov);

// 	if(sensor_id.compare("scan_matcher") == 0){
// 	std::cerr << "PRIOR    : " << prior.position().transpose() << " " << rotation::getEulerAnglesDeg(prior.orientation()).transpose() << std::endl;
// 	std::cerr << "POSTERIOR: " << posterior.position().transpose() << " " << rotation::getEulerAnglesDeg(posterior.orientation()).transpose() << std::endl;
// 	std::cerr << ":::::::" << std::endl;
// 	}

// 	end = std::chrono::high_resolution_clock::now();
// 	RCLCPP_DEBUG_STREAM(this->get_logger(), "Time elapsed process addUpdate: " << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count());
// 	start = end;


// 	if (publish_head_[sensor_id]) {

// 		state_est_->getHeadState(head_state, head_cov);

// 		// fill in linear velocitytemp_v3
// 		// tf::vectorEigenToTF(head_state.velocity(),);
// 		// tf::vector3TFToMsg(temp_v3,twist_msg_.twist.twist.linear);
// 		BlockToVector3d(head_state.velocity(),  twist_msg_.twist.twist.linear);
// 		// fill in angular velocity
// 		// tf::vectorEigenToTF(head_state.angularVelocity(),temp_v3);
// 		// tf::vector3TFToMsg(temp_v3,twist_msg_.twist.twist.angular);
// 		BlockToVector3d(head_state.angularVelocity(), twist_msg_.twist.twist.angular);

// 		// fill in time
// 		twist_msg_.header.stamp = rclcpp::Time(head_state.utime * 1000);

// 		// TODO insert appropriate covariance into the message

// 		// set twist covariance to zero
// 		twist_msg_.twist.covariance.fill(0);

// 		Eigen::Block<RBIM, 3, 3> vel_cov = head_cov.block<3,3>(RBIS::velocity_ind,RBIS::velocity_ind);
// 		Eigen::Block<RBIM, 3, 3> omega_cov = head_cov.block<3,3>(RBIS::angular_velocity_ind,RBIS::angular_velocity_ind);


// 		for(int i=0; i<3; i++){
// 			for(int j=0; j<3; j++){
// 				twist_msg_.twist.covariance[6*i+j] = vel_cov(i,j);
// 				twist_msg_.twist.covariance[6*(i+3)+j+3] = omega_cov(i,j);
// 			}
// 		}

// 		twist_pub_->publish(twist_msg_);

// 		// make sure stuff is non-NAN before publishing
// 		assert(head_state.position().allFinite());

// 		// fill in message position
// 		// tf::vectorEigenToTF(head_state.position(), temp_v3);
// 		// tf::pointTFToMsg(temp_v3, pose_msg_.pose.pose.position);
// 		BlockToPoint(head_state.position(), pose_msg_.pose.pose.position);

// 		// fill in message orientation
// 		// tf::quaternionEigenToTF(head_state.orientation(), temp_q);
// 		// tf::quaternionTFToMsg(temp_q,pose_msg_.pose.pose.orientation);
// 		QuaternionToMsg(head_state.orientation(), pose_msg_.pose.pose.orientation);

// 		pose_msg_.header.stamp = rclcpp::Time(head_state.utime * 1000);


// 		if(publish_tf_){
// 				// Only publish the pose if the timestamp is different:
// 				// This prevents issues in Noetic where repeated warnings of type:
// 				// "TF_REPEATED_DATA ignoring data with redundant timestamp for frame base at time"
// 				// are otherwise printed to the terminal.
// 				// Cf. https://github.com/ros/geometry2/issues/467#issuecomment-751572836
// 				rclcpp::Time new_stamp = pose_msg_.header.stamp;
// 				if (new_stamp > transform_msg_.header.stamp) {
// 						transform_msg_.transform.translation.x = pose_msg_.pose.pose.position.x;
// 						transform_msg_.transform.translation.y = pose_msg_.pose.pose.position.y;
// 						transform_msg_.transform.translation.z = pose_msg_.pose.pose.position.z;
// 						transform_msg_.transform.rotation = pose_msg_.pose.pose.orientation;
// 						transform_msg_.header.stamp = new_stamp;
// 						tf2_broadcaster_->sendTransform(transform_msg_);
// 				}
// 		}

// 		pose_pub_->publish(pose_msg_);

// 	} else {

// 		RCLCPP_DEBUG_STREAM(this->get_logger(), "NOT Publish head sensor ID");

// 	}
// 	end = std::chrono::high_resolution_clock::now();
// 	RCLCPP_DEBUG_STREAM(this->get_logger(), "Time elapsed till the end: " << std::chrono::duration_cast<std::chrono::microseconds>(end -start).count());
// 	std::cout << std::endl;

// 	}

// }









bool ProntoNode::initializeFilter()
{

	// if the modules are not ready we return false
	if(!this->areModulesInitialized())
	{
		return false;
	}
	// if the filter is already initialized we quietly return
	if(this->isFilterInitialized()){
		return true;
	}
	state_est_.reset(new StateEstimator(new RBISResetUpdate(init_state, init_cov, RBISUpdateInterface::reset,
																	init_state.utime), history_span_));

	filter_initialized_ = true;
	if(verbose_){
		RCLCPP_INFO_STREAM(this->get_logger(), "Filter initialized.");
	}
	return true;

}








void ProntoNode::initializeState() 
{

	// setting the initial values from the state
	std::vector<double> init_velocity = std::vector<double>(3,0.0);
	if(!this->get_parameter("x0.position", init_velocity)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get default velocity. Setting to zero.");
	}
	default_state.velocity() = Eigen::Map<Eigen::Vector3d>(init_velocity.data());

	// setting the initial values from the state
	std::vector<double> init_position  = std::vector<double>(3,0.0);
	if(!this->get_parameter("x0.position", init_position)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get default position. Setting to zero.");
	}
	default_state.position() = Eigen::Map<Eigen::Vector3d>(init_position.data());

	std::vector<double> init_omega = std::vector<double>(3,0.0);
	if(!this->get_parameter("x0.angular_velocity", init_omega)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get default ang velocity. Setting to zero.");
	}
	default_state.angularVelocity() = Eigen::Map<Eigen::Vector3d>(init_omega.data());

	std::vector<double> init_orient = std::vector<double>(3,0.0);
	if(!this->get_parameter("x0.rpy", init_orient)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get default ang velocity. Setting to zero.");
		default_state.orientation() = Eigen::Quaterniond::Identity();
	}
	default_state.orientation() = rotation::setQuatEulerAngles(Eigen::Map<Eigen::Vector3d>(init_orient.data()));
	init_state = default_state;
	head_state = default_state;
	if(verbose_){
		RCLCPP_INFO_STREAM(this->get_logger(), "Filter Initial State initialized.");
	}


}






void ProntoNode::initializeCovariance()
{
	default_cov = pronto::RBIM::Zero();

	double sigma_Delta_xy_init = 0;
	if(!this->get_parameter("sigma0.Delta_xy", sigma_Delta_xy_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/Delta_xy. Setting to zero.");
	}


	double sigma_Delta_z_init = 0;
	if(!this->get_parameter("sigma0.Delta_z", sigma_Delta_z_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/Delta_z. Setting to zero.");
	}

	double sigma_chi_xy_init = 0;
	if(!this->get_parameter("sigma0.chi_xy", sigma_chi_xy_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/chi_xy. Setting to zero.");
	}
	sigma_chi_xy_init *= M_PI / 180.0; // convert to radians

	double sigma_chi_z_init = 0;
	if(!this->get_parameter("sigma0/chi_z", sigma_chi_z_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/chi_z. Setting to zero.");
	}
	sigma_chi_z_init *= M_PI / 180.0; // convert to radians

	double sigma_vb_init = 0;
	if(!this->get_parameter("sigma0/vb", sigma_vb_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/vb. Setting to zero.");
	}

	double sigma_gyro_bias_init = 0;
	if(!this->get_parameter("sigma0/gyro_bias", sigma_gyro_bias_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/gyro_bias. Setting to zero.");
	}
	sigma_gyro_bias_init *= M_PI / 180.0; // convert to radians

	double sigma_accelerometer_bias_init = 0;
	if(!this->get_parameter("sigma0/accel_bias", sigma_accelerometer_bias_init)){
		RCLCPP_WARN_STREAM(this->get_logger(), "Couldn't get param sigma0/accel_bias. Setting to zero.");
	}

	Eigen::Vector3d xyz_cov_diag =
		Eigen::Array3d(sigma_Delta_xy_init, sigma_Delta_xy_init, sigma_Delta_z_init).square();

	Eigen::Vector3d init_chi_cov_diag = Eigen::Array3d(sigma_chi_xy_init, sigma_chi_xy_init, sigma_chi_z_init).square();

	//set all the sub-blocks of the covariance matrix
	default_cov.block<3, 3>(RBIS::velocity_ind, RBIS::velocity_ind) = std::pow(sigma_vb_init,2) * Eigen::Matrix3d::Identity();
	default_cov.block<3, 3>(RBIS::chi_ind, RBIS::chi_ind) = init_chi_cov_diag.asDiagonal();
	default_cov.block<3, 3>(RBIS::position_ind, RBIS::position_ind) = xyz_cov_diag.asDiagonal();
	default_cov.block<3, 3>(RBIS::gyro_bias_ind, RBIS::gyro_bias_ind) = Eigen::Matrix3d::Identity() * std::pow(sigma_gyro_bias_init,2);
	default_cov.block<3, 3>(RBIS::accel_bias_ind, RBIS::accel_bias_ind) = Eigen::Matrix3d::Identity() * std::pow(sigma_accelerometer_bias_init,2);

	init_cov = default_cov;
	head_cov = default_cov;
	if(verbose_){
		RCLCPP_INFO_STREAM(this->get_logger(), "Filter Covariance initialized.");
	}



}


}

