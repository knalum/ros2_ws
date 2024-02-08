#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"

class PoseSubscriber:public rclcpp::Node{
    public:
        PoseSubscriber():Node("pose_subscriber"){
            RCLCPP_INFO(this->get_logger(),"Starting pose subscriber cpp");

            subscription = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&PoseSubscriber::topic_callback,this,std::placeholders::_1));
        }

    private:
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription;
    void topic_callback(const turtlesim::msg::Pose &pose) const {
        RCLCPP_INFO(this->get_logger(),"Pose %f , %f",pose.x,pose.y);
    }
};

int main(int argc,char *argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<PoseSubscriber>());
    rclcpp::shutdown();
}