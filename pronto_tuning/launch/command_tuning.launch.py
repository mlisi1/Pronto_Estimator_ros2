import os
from launch.substitutions import LaunchConfiguration,PathJoinSubstitution
from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_path

def generate_launch_description():

    global config_file_path
    package_path = get_package_share_path("pronto_tuning")
    config_path = os.path.join(package_path, 'config/tuning_node_param.yaml')
    
    print()
    return LaunchDescription([

        # Launch the Pronto Solo node with parameters set in "state_estimator.yaml"
        Node(
            package='pronto_tuning',
            executable='command_node',
            parameters=[config_path]
        )

        # # Converts TSIF Pose messages into TF
        # Node(
        #     package='pronto_anymal_b',
        #     executable='pose_to_tf.py',
        #     name='tsif_tf_publisher',
        #     output='log',
        #     arguments=['--config_file', FindPackageShare('pronto_anymal_b') + '/config/pose_to_tf.yaml'],
        # ),
    ])