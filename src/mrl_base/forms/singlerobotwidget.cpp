#include "singlerobotwidget.h"
#include "ui_singlerobotwidget.h"
#include "util/rosmanager.h"
#include <QMouseEvent>
#include <QGraphicsView>

singleRobotWidget::singleRobotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::singleRobotWidget)
{
    ui->setupUi(this);


    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::yellow);
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(Pal);
    ui->progressBar->setValue(0);
}

singleRobotWidget::~singleRobotWidget()
{
    delete ui;
}

void singleRobotWidget::SetVideo(QPixmap image)
{
    ui->label_2->setPixmap(image);
}

void singleRobotWidget::setRobotNumber(int robotNumber)
{
    _robotnumber = robotNumber;
    QString printable = QString("Robot %1").arg(_robotnumber);
    ui->label->setText(printable);
}

void singleRobotWidget::setAsSelected(bool isSelect)
{
    QPalette Pal(palette());
    switch (isSelect)
    {
    case true:
        Pal.setColor(QPalette::Background, Qt::green);
        break;
    case false:
        Pal.setColor(QPalette::Background, Qt::yellow);
        break;
    }
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(Pal);
}

void singleRobotWidget::mouseReleaseEvent(QMouseEvent * event)
{
    ImSelected(_robotnumber);
}
