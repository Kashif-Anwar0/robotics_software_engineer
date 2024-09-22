#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <string>

class TurtleSimPattern : public rclcpp::Node
{
public:
    TurtleSimPattern(const std::string & turtle_name, const std::string & movement_type, double radius = 1.0) 
        : Node(turtle_name + "_controller"), turtle_name_(turtle_name), movement_type_(movement_type), radius_(radius)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/" + turtle_name_ + "/cmd_vel", 10);

        // Timer to control the update rate (10Hz)
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100),
            std::bind(&TurtleSimPattern::move_turtle, this));
    }

    void move_turtle()
    {
        geometry_msgs::msg::Twist cmd_msg;
        if (movement_type_ == "circle")
        {
            cmd_msg.linear.x = radius_;  // Constant linear velocity for circle
            cmd_msg.angular.z = 1.0;     // Constant angular velocity for circle
        }
        else if (movement_type_ == "spiral")
        {
            cmd_msg.linear.x = spiral_factor_;     // Increasing linear velocity for spiral
            cmd_msg.angular.z = 4.0 / spiral_factor_;  // Decreasing angular velocity for spiral
            spiral_factor_ += 0.05; // Slowly increase the factor to simulate spiral
        }
        publisher_->publish(cmd_msg);
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::string turtle_name_;
    std::string movement_type_;
    double radius_;
    double spiral_factor_ = 0.1;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto turtle1_node = std::make_shared<TurtleSimPattern>("turtle1", "circle", 2.0);  // Turtle1 for circle
    auto turtle2_node = std::make_shared<TurtleSimPattern>("turtle2", "spiral");       // Turtle2 for spiral

    // Use a multi-threaded executor to spin both nodes concurrently
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(turtle1_node);
    executor.add_node(turtle2_node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
