# Pronto_Estimator
ROS2 Pronto Floating Base System estimator implementation is a library 

## ROS1 Pronto Code Desription
### Code UML
![Prova](/doc/pronto_node_ros1.png)
![Controller](/doc/Controller_est.png)

### Class and methods
<ol>
    <li>
    ROS_FrontEnd (Pronto Ros)
    <ul>
        <li>
        Constructor: get the topic name of the estimate position, velocity and tf from ROS parameter; at the end initialize filter state and covariance using its own method
        </li>
        <li>
        initializeState: get the initial state, pose and velocity,  from ROS parameter and set the init state variable.
        </li>
        <li>
        initializeCovariance: get the initial covariance matrix from ROS parameter and set the init covariance variable.
        </li>
        <li>
            initializeFilter: check if the sensors module are initialize and if the filter is not then initialize it.
        </li>
        <li>
            areModouleInitialize: evaluate the initialization of all the sensors that need it.
        </li>
        <li>
            addSensingModule: create the data structure for the sensor: maps and topic.
        </li>
        <li>
            InitCallback: callback to initialize the sensing module, when initialized the sensor destroy the topic.
        </li>
        <li>
            callback: data topic subscribe callback, compute the update due to the data update.
        </li>
        </li>
    </ul>
    </li>
    <li>
        InsHandlerRos(Pronto_ROS): class used by the frontend to manage the InsModule.
        <ul>
        <li>
                Constructor: build the InsModule and create its topic
            </li>
            <li>
                ProcessMessage: get the IMU message and the estimator to return the state and covariance update.
            </li>
            <li>
                processMessageInit: get the IMU message and return a boolean reporting the initialization result.
            </li>
        </ul>
    </li>
    <li>
        SensinModule (Pronto_Core): virtual class to describe generic sensor.
        <ul>
            <li>
                ProcessMessage(virtual): get the sensor data and the estimator to return the state and covariance update.
            </li>
            <li>
                processMessageInit(virtual): get the init message and return a boolean reporting the initialization result.
            </li>
        </ul>
    </li>
    <li>
        DualSensinModule (Pronto_Core): virtual class to describe a sensing module with two sensor input.
        <ul>
            <li>
                ProcessMessage(virtual): get the sensor data and the estimator to return the state and covariance update.
            </li>
            <li>
                processMessageInit(virtual): get the init message and return a boolean reporting the initialization result.
            </li>
        </ul>
    </li>
    <li>
        InsModule(Pronto_Core):
        <ul>
            <li>
                Constructor: build the inertial sensing modue from the imu configuration and the imu-body frame tranformation
            </li>
            <li>
                ProcessMessage: get the IMU data and the estimator to return the state and covariance update.
            </li>
            <li>
                processMessageInit: get the IMU init message and return a boolean reporting the initialization result.
            </li>
        </ul>
    </li>
</ol>
