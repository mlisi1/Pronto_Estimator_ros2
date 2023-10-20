from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    return LaunchDescription([

        # Launch the Pronto Solo node with parameters set in "state_estimator.yaml"
        Node(
            package='pronto_solo12',
            namespace='pronto_solo12',
            executable='pronto_solo12_node',
            name='pronto_estimator',
            parameters=[FindPackageShare('pronto_solo12') + '/config/state_estimator.yaml']
        ),

        # # Converts TSIF Pose messages into TF
        # Node(
        #     package='pronto_anymal_b',
        #     executable='pose_to_tf.py',
        #     name='tsif_tf_publisher',
        #     output='log',
        #     arguments=['--config_file', FindPackageShare('pronto_anymal_b') + '/config/pose_to_tf.yaml'],
        # ),
    ])
