#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaddrobot.h"
#include "singlerobotwidget.h"
#include <QMessageBox>
#include "util/rosmanager.h"
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    central = new QWidget(this);
    setCentralWidget(central);
//    gridLayout = new QGridLayout(central);
    AssignRobotViews(6);

    rosmanager::Instance()->VideoCallback[0].connect(boost::bind(&MainWindow::imageCallback1, this, _1));
    rosmanager::Instance()->VideoCallback[1].connect(boost::bind(&MainWindow::imageCallback2, this, _1));
    rosmanager::Instance()->VideoCallback[2].connect(boost::bind(&MainWindow::imageCallback3, this, _1));
    rosmanager::Instance()->VideoCallback[3].connect(boost::bind(&MainWindow::imageCallback4, this, _1));
    rosmanager::Instance()->VideoCallback[4].connect(boost::bind(&MainWindow::imageCallback5, this, _1));
    rosmanager::Instance()->VideoCallback[5].connect(boost::bind(&MainWindow::imageCallback6, this, _1));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imageCallback1(const QImage& msg)
{
    singlerobotview[0]->SetVideo(QPixmap::fromImage(msg).scaled(200,200,Qt::KeepAspectRatio));
}
void MainWindow::imageCallback2(const QImage& msg)
{
    singlerobotview[1]->SetVideo(QPixmap::fromImage(msg).scaled(200,200,Qt::KeepAspectRatio));
}
void MainWindow::imageCallback3(const QImage& msg)
{
    singlerobotview[2]->SetVideo(QPixmap::fromImage(msg).scaled(200,200,Qt::KeepAspectRatio));
}
void MainWindow::imageCallback4(const QImage& msg)
{
    singlerobotview[3]->SetVideo(QPixmap::fromImage(msg).scaled(200,200,Qt::KeepAspectRatio));
}
void MainWindow::imageCallback5(const QImage& msg)
{
    singlerobotview[4]->SetVideo(QPixmap::fromImage(msg).scaled(200,200,Qt::KeepAspectRatio));
}
void MainWindow::imageCallback6(const QImage& msg)
{
    singlerobotview[5]->SetVideo(QPixmap::fromImage(msg).scaled(200,200,Qt::KeepAspectRatio));
}

void MainWindow::ImSelected(int robotNumber)
{
    int N = 6;
    rosmanager::Instance()->SetSelectedRobot(robotNumber);
    for (int i = 0; i < N; ++ i)
    {
        singlerobotview[i]->setAsSelected(false);
    }
    singlerobotview[robotNumber-1]->setAsSelected(true);
}

void MainWindow::AssignRobotViews(int)
{
    int N = 6;

    std::vector<QRect> layouts;
    layouts.push_back(QRect(0,   35, 280, 280));
    layouts.push_back(QRect(280, 35, 280, 280));
    layouts.push_back(QRect(560, 35, 280, 280));
    layouts.push_back(QRect(0,   315, 280, 280));
    layouts.push_back(QRect(280, 315, 280, 280));
    layouts.push_back(QRect(560, 315, 280, 280));

    monitor = new QLabel(this);
    monitor->setVisible(true);
    monitor->setGeometry(840, 35, 560, 560);
    monitor->setFrameShape(QFrame::Box);

    for (int i = 0; i < N; ++ i)
    {
        singlerobotview[i] = new singleRobotWidget(monitor, this);
        singleRobotWidget* srw = singlerobotview[i];
        srw->setVisible(true);
        srw->setGeometry(layouts.at(i));


        srw->setRobotNumber(i+1);
        srw->ImSelected.connect(boost::bind(&MainWindow::ImSelected, this, _1));
    }


//    int N = robotCnt;
//    int n = ceil(sqrt(N));
//    for (int i = 0; i < N; ++ i) {
//        frames[i] = new QFrame(central);
//        frames[i]->setFrameShape(QFrame::StyledPanel);
//        gridLayout->addWidget(frames[i], i/n, i%n, 1, 1);
//    }
//    for (int i = 0; i < N; ++ i) {
//        layouts[i] = new QVBoxLayout;
//        singlerobotview[i] = new singleRobotWidget(frames[i]);
//        singlerobotview[i]->setRobotNumber(i+1);
//        singlerobotview[i]->ImSelected.connect(boost::bind(&MainWindow::ImSelected, this, _1));
//        if(i==0)singlerobotview[i] ->setAsSelected(true);
//        layouts[i]->addWidget(singlerobotview[i]);
//        frames[i]->setLayout(layouts[i]);
//    }
}

void MainWindow::OpenSetupDialog()
{
    DialogAddRobot * dar = new DialogAddRobot(this);
    dar->show();

}

void MainWindow::on_actionSetup_New_Run_triggered()
{
    OpenSetupDialog();
}

void MainWindow::on_actionRun_triggered()
{
    AssignRobotViews(6);
}
