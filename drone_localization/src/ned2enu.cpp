#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/ros.h"
#include "ros/subscriber.h"
#include "sensor_msgs/Imu.h"


class NED2ENU{
    public:
        NED2ENU(){
            sub = n.subscribe("imu", 1000, &NED2ENU::cb_subsciber, this);
            pub = n.advertise<sensor_msgs::Imu>("imu_enu", 1000);
        }

        void cb_subsciber(const sensor_msgs::ImuConstPtr& msg){
            sensor_msgs::Imu enu = *msg;

            enu.orientation.x = msg->orientation.y;
            enu.orientation.y = msg->orientation.x;
            enu.orientation.z = - msg->orientation.z;
            enu.orientation.w = - msg->orientation.w;

            enu.linear_acceleration.x = msg->linear_acceleration.y;
            enu.linear_acceleration.y = msg->linear_acceleration.x;
            enu.linear_acceleration.z = - msg->linear_acceleration.z;

            enu.angular_velocity.x = msg->angular_velocity.y;
            enu.angular_velocity.y = msg->angular_velocity.x;
            enu.angular_velocity.z = - msg->angular_velocity.z;

            pub.publish(enu);
        }
    private:
        ros::NodeHandle n;
        ros::Publisher pub;
        ros::Subscriber sub;
};


int main(int argc, char** argv){
    ros::init(argc, argv, "ned2enu");
    NED2ENU node;
    ros::spin();
    return 0;
}
