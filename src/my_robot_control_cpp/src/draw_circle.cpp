#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class DrawCircle: public rclcpp::Node{
    public:
    DrawCircle(): Node("draw_circle"){
        RCLCPP_INFO(this->get_logger(),"Started draw circle node");
        publisher = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
        timer= this->create_wall_timer(500ms,std::bind(&DrawCircle::draw_callback,this));

    }

    private:
    rclcpp::TimerBase::SharedPtr timer;
    void draw_callback(){
        RCLCPP_INFO(this->get_logger(),"Draw callback...");
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = 2.0;
        msg.angular.z = 2.0;
        publisher->publish(msg);

    }
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
  
};


int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<DrawCircle>());
    rclcpp::shutdown();
}