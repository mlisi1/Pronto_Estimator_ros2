from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    config = os.path.join(
        get_package_share_directory('pronto_ros2'),
        'config',
        'state_estimator.yaml'
    )


    return LaunchDescription([
        Node(
            package='pronto_ros2',
            namespace='pronto_ros2',
            executable='pronto_ros2_node',
            name='pronto_ros2_node',
            parameters=[config]
        ),
        # Node(
        #     package='pronto_ros',
        #     namespace='pronto_ros',
        #     executable='joint_state_with_acceleration_republisher',
        #     name='joint_states_republisher'
        # ),

    ])