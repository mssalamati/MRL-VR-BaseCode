#include "rosmanager.h"
#include <unistd.h>
#include <termios.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <boost/signals2.hpp>
#include <QPainter>

rosmanager::rosmanager()
{


}



void rosmanager::imageCallback1(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[0](image);
}

void rosmanager::imageCallback2(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[1](image);
}

void rosmanager::imageCallback3(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[2](image);
}

void rosmanager::imageCallback4(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[3](image);
}

void rosmanager::imageCallback5(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[4](image);
}

void rosmanager::imageCallback6(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[5](image);
}

void rosmanager::imageCallback7(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[6](image);
}

void rosmanager::imageCallback8(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[7](image);
}

void rosmanager::imageCallback9(const sensor_msgs::ImageConstPtr& msg)
{
    QImage temp(&(msg->data[0]), msg->width, msg->height, QImage::Format_RGB888);
    QImage image;
    image = temp;
    VideoCallback[8](image);
}

void rosmanager::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
//    ROS_INFO("joyCallback");
    vel.angular.z =joy->axes[0];
    vel.linear.x = joy->axes[1];

    velpub[selectedRobot].publish(vel);
}

void rosmanager::SetSelectedRobot(int robotnumber)
{
    selectedRobot = robotnumber;
}

void rosmanager::rosprint(QString message) {ROS_INFO("%s",qPrintable(message));}

void cb(const sensor_msgs::LaserScanConstPtr &_msg)
{

}

rosmanager* rosmanager::_instance = 0;

rosmanager* rosmanager::Instance()
{
    if(_instance == 0)
    {
        _instance = new rosmanager();
    }
    return _instance;
}

void rosmanager::init(int argc, char *argv[])
{
    return;
    ros::init(argc, argv, "mcore");

    ROS_INFO("MRL-VR Core ROS initiated");

    ros::NodeHandle nh;

    joysub = nh.subscribe<sensor_msgs::Joy>("joy", 10, &rosmanager::joyCallback, this);

    int i =0;
    for(i=0 ; i<20 ; i++)
    {
        QString s = "/robot"+QString::number(i)+"/cmd_vel";
        velpub[i] = nh.advertise<geometry_msgs::Twist>(s.toLocal8Bit().constData(), 1000);
    }

    geometry_msgs::Twist msg;

    image_transport::ImageTransport it(nh);

    sub1 = it.subscribe("/robot1/camera/camera", 1, &rosmanager::imageCallback1,this);
    sub2 = it.subscribe("/robot2/camera/camera", 1, &rosmanager::imageCallback2,this);
    sub3 = it.subscribe("/robot3/camera/camera", 1, &rosmanager::imageCallback3,this);
    sub4 = it.subscribe("/robot4/camera/camera", 1, &rosmanager::imageCallback4,this);
    sub5 = it.subscribe("/robot5/camera/camera", 1, &rosmanager::imageCallback5,this);
    sub6 = it.subscribe("/robot6/camera/camera", 1, &rosmanager::imageCallback6,this);
    sub7 = it.subscribe("/robot7/camera/camera", 1, &rosmanager::imageCallback7,this);
    sub8 = it.subscribe("/robot8/camera/camera", 1, &rosmanager::imageCallback8,this);
    sub9 = it.subscribe("/robot9/camera/camera", 1, &rosmanager::imageCallback9,this);

//    ros::Subscriber sub  = nh.subscribe("/robot1/hokuyo", 1000, cb);
//    ros::Subscriber sub2 = nh.subscribe("/robot2/hokuyo", 1000, cb);

    ros::Rate rate(20);

    ROS_INFO("finish init :)");

    spinthread.start();
}


