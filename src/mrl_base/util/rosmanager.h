#ifndef ROSMANAGER_H
#define ROSMANAGER_H
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <QThread>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <boost/signals2.hpp>

class SpinThread : public QThread
{
    Q_OBJECT

protected:
    void run(){ ros::spin();}
};

class rosmanager
{


public:
    rosmanager();

    void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

    void imageCallback1(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback2(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback3(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback4(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback5(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback6(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback7(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback8(const sensor_msgs::ImageConstPtr& msg);
    void imageCallback9(const sensor_msgs::ImageConstPtr& msg);
    boost::signals2::signal<void (const QImage&)> VideoCallback[9];

    void init(int argc, char *argv[]);
    ros::Publisher velpub[20];
    ros::Subscriber joysub;
    geometry_msgs::Twist vel;
    int linear_, angular_;
    double l_scale_, a_scale_;

    image_transport::Subscriber sub1;
    image_transport::Subscriber sub2;
    image_transport::Subscriber sub3;
    image_transport::Subscriber sub4;
    image_transport::Subscriber sub5;
    image_transport::Subscriber sub6;
    image_transport::Subscriber sub7;
    image_transport::Subscriber sub8;
    image_transport::Subscriber sub9;

    static rosmanager *_inst;
    static rosmanager* Instance();
    static rosmanager* _instance;
    SpinThread spinthread;

    void rosprint(QString message) ;

    int selectedRobot = 1 ;
    void SetSelectedRobot(int robotnumber) ;

private:

};


#endif // ROSMANAGER_H
