from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        # Start the Turtlesim Node (with turtle1 spawned by default)
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim'
        ),

        # Spawn turtle2
        ExecuteProcess(
            cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', '{x: 5.0, y: 5.0, theta: 0.0, name: "turtle2"}'],
            output='screen'
        ),

        # Node to control Turtle1 (circle movement) with initial speed
        Node(
            package='task4',  
            executable='turtlesim_dynamic', 
            name='turtle1_controller',
            output='screen',
            parameters=[{'turtle_name': 'turtle1', 'movement_type': 'circle', 'radius': 1.0, 'linear_speed': 0.5, 'angular_speed': 0.5}]
        ),

        # Node to control Turtle2 (spiral movement) with initial speed
        Node(
            package='task4',  
            executable='turtlesim_dynamic', 
            name='turtle2_controller',
            output='screen',
            parameters=[{'turtle_name': 'turtle2', 'movement_type': 'spiral', 'linear_speed': 0.5, 'angular_speed': 0.5}]
        )
    ])
