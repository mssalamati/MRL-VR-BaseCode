#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "singlerobotwidget.h"
#include <QGridLayout>
#include <QFrame>
#include <QLabel>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionSetup_New_Run_triggered();

    void on_actionRun_triggered();

private:
    Ui::MainWindow *ui;
    void OpenSetupDialog();
    void AssignRobotViews(int robotCnt);

    QWidget * central;
//    QGridLayout *gridLayout;
    QFrame * frames[20];
    singleRobotWidget *singlerobotview[20];
    QLayout *layouts[20];
    QLabel* monitor;

    void ImSelected(int robotNumber);

    void imageCallback1(const QImage& msg);
    void imageCallback2(const QImage& msg);
    void imageCallback3(const QImage& msg);
    void imageCallback4(const QImage& msg);
    void imageCallback5(const QImage& msg);
    void imageCallback6(const QImage& msg);
    void imageCallback7(const QImage& msg);
    void imageCallback8(const QImage& msg);
    void imageCallback9(const QImage& msg);
};

#endif // MAINWINDOW_H
