# Pronto_Estimator
ROS2 Pronto Floating Base System estimator implementation is a library 

## ROS1 Pronto Code Desription
### Code UML
Ros1 original code scheme 
![Prova](/doc/pronto_node_ros1.png)
Revisited Pronto Estimator has been adapted to a Ros2-Controller, it uses directly from the HW State interface the Imu Measure and the Joints State, including position, velocity and torque measure.
#### TODO
add other exteroceptive sensors 
![Controller](/doc/Controller_est.png)
### TODO
Add Pronto Parameters Description 

## Usage Simulation
### Dependecies
Eigen3

## Set up Instruction 
Create a ROS2 workspace and be sure to have installed GazeboClassic.

Add the simulation and motion control packages provided by [text](https://github.com/ddebenedittis/control_quadrupeds_soft_contacts) and follow the clone instruction.

Clone this repo into the src folder into the workspace.

Define your reference adding a config file into the folder pronto_tuning/config describing a base velocity setpoint used to define a repetable experiments.

Example:
The straight_motion.yaml file define a staight motion composed by 5 set point producing a trapezoidal velocity reference in forward direction.
'''

    set_point_list: 
      - start
      - move_for
      - straight
      - slow_down
      - stop 
    start: 
      vx: 0.0
      vy: 0.0
      omega: 0.0
      time: 0.0
    move_for: 
      vx: 0.15
      vy: 0.0
      omega: 0.0
      time: 1.0
    straight: 
      vx: 0.15
      vy: 0.0
      omega: 0.0
      time: 51.0
    slow_down: 
      vx: 0.0
      vy: 0.0
      omega: 0.0
      time: 52.0
    stop: 
      vx: 0.0
      vy: 0.0
      omega: 0.0
      time: 55.0

To launch the code are needed 2 terminals, into the first one should be started the simulation using:


    
    ros2 launch pronto_tuning experiments_pronto.launch.py

despite the second should be started the record and command node


    ros2 launch pronto_tuning cmd_rec.launch.py
    
The experiments can be changed by adding the new one into the config folder into the pronto_tuning package and changing the configuration file name into the filter_tuning.launch.py launch 

<!-- ### Class and methods
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
</ol> -->
