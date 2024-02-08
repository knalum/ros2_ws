#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <chrono>
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MyPublisher: public rclcpp::Node{
    public:
    MyPublisher():Node("my_publisher"),count(0) {
        RCLCPP_INFO(this->get_logger(),"Starting publisher...");
        publisher = this->create_publisher<std_msgs::msg::String>("topic",10);
        timer = this->create_wall_timer(500ms,std::bind(&MyPublisher::timer_callback,this));
    }

    private:
    void timer_callback(){
        auto message = std_msgs::msg::String();
        message.data = "Publisher callback "+std::to_string(count++);
        RCLCPP_INFO(this->get_logger(),"Publishing %s",message.data.c_str());

        publisher->publish(message);
    }
    size_t count;
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;

};

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<MyPublisher>());
    rclcpp::shutdown();
}