#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_All_clicked()
{
    ui->checkBox_0->setChecked(true);
    ui->checkBox_1->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(true);
    ui->checkBox_5->setChecked(true);
    ui->checkBox_6->setChecked(true);
    ui->checkBox_7->setChecked(true);
    ui->checkBox_8->setChecked(true);
    ui->checkBox_9->setChecked(true);
}

void MainWindow::on_pushButton_None_clicked()
{
    ui->checkBox_0->setChecked(false);
    ui->checkBox_1->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
}

void MainWindow::on_pushButton_Run_clicked()
{
    std::ofstream ofs ("../../src/bring_up/launch/client.launch", std::ofstream::out);

    ofs << "<?xml version=\"1.0\"?>\n" <<
           "<launch>\n\n" <<

           "\t<param name=\"use_sim_time\" value=\"true\"/>\n"<<
           "\t<arg name=\"paused\" default=\"false\"/>\n"<<
           "\t<arg name=\"gui\" default=\"true\"/>\n"<<
           "\t<arg name=\"verbose\" default=\"true\"/>\n\n";

    if(ui->checkBox_0->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_0->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_0_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_0_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_0_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_1->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_1->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_1_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_1_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_1_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_2->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_2->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_2_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_2_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_2_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_3->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_3->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_3_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_3_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_3_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_4->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_4->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_4_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_4_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_4_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_5->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_5->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_5_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_5_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_5_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_6->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_6->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_6_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_6_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_6_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_7->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_7->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_7_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_7_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_7_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    if(ui->checkBox_8->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_8->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_8_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_8_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_8_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";


    if(ui->checkBox_9->isChecked())
        ofs << "\t<include file=\"$(find bring_up)/launch/robot_spawn.launch\">\n"<<
               "\t\t<arg name=\"robot_name\" value=\""<< ui->lineEdit_9->text().toStdString() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_x\" value=\""<< ui->spn_9_x->value() <<"\"/> \n"<<
               "\t\t<arg name=\"pose_y\" value=\""<< ui->spn_9_y->value() <<"\"/>\n"<<
               "\t\t<arg name=\"pose_yaw\" default=\""<< ui->spn_9_yaw->value() <<"\"/>\n"<<
               "\t</include>\n\n";

    ofs << "</launch>" << std::endl;

    ofs.close();

    on_pushButton_RunPrevious_clicked();
}

void MainWindow::on_pushButton_RunPrevious_clicked()
{

    system("bash ../mrl_robotSpawner/runClient.bash");

}
