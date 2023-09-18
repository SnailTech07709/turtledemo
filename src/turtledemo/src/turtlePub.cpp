#include"ros/ros.h"
#include"geometry_msgs/Twist.h"

/*
    需求： 
                利用现有话题名称实现小乌龟控制命令
    实现步骤：
                1。包含头文件
                2。初始化ros节点
                3。创建句柄
                4。实例化发布者对象
                5。创建发布的数据
                6。组织发布数据
*/


int main(int argc, char *argv[])
{
    //防止出现中文乱码
    setlocale(LC_ALL, "");

    //初始化ros节点
    ros::init(argc, argv, "turtlePub"); //结点的名字随便取，自己看得懂就行

    //创建句柄
    ros::NodeHandle nh;

    //创建发布者对象（创建一个发布器）----->创建一个手枪
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    //创建发布的数据--->创建子弹
    geometry_msgs::Twist msg;  //int a 

    //linear
    msg.linear.x = 1.0; //线速度

    //angular
    msg.angular.z = 0.5; //角速度

    //设置发布频率使得循环发布
    ros::Rate rate(10);


    //循环发布数据
    while (ros::ok())
    {
        pub.publish(msg);//发布数据

        rate.sleep(); //设置休眠
    }
    
    return 0;
}
