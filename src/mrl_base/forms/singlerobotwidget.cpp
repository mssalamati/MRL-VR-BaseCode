#include "singlerobotwidget.h"
#include "ui_singlerobotwidget.h"
#include "util/rosmanager.h"
#include <QMouseEvent>
#include <QGraphicsView>

singleRobotWidget::singleRobotWidget(QLabel* MainMonitor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::singleRobotWidget),
    mainMonitor(MainMonitor),
    isSelected(false)
{
    ui->setupUi(this);


    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::yellow);
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(Pal);
}

singleRobotWidget::~singleRobotWidget()
{
    delete ui;
}

void singleRobotWidget::SetVideo(QPixmap image)
{
    ui->label_2->setPixmap(image.scaled(ui->label_2->size(), Qt::KeepAspectRatio));
    if (isSelected)
        mainMonitor->setPixmap(image.scaled(mainMonitor->size(), Qt::KeepAspectRatio));
}

void singleRobotWidget::setRobotNumber(int robotNumber)
{
    _robotnumber = robotNumber;
    QString printable = QString("Robot %1").arg(_robotnumber);
    ui->label->setText(printable);
}

void singleRobotWidget::setAsSelected(bool isSelect)
{
    isSelected = isSelect;
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

