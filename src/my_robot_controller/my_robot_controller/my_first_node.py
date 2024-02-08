#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        super().__init__("first_node")
        self.counter = 0
        self.create_timer(1.0,self.timer_callback)

    def timer_callback(self):
        self.counter += 1
        self.get_logger().info("Hello "+str(self.counter))

def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()
    pass

if __name__=='__main__':
    #print("Running from terminal")
    main()