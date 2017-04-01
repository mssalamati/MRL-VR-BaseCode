#ifndef SINGLEROBOTWIDGET_H
#define SINGLEROBOTWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <boost/signals2.hpp>
#include <QGraphicsView>

namespace Ui {
class singleRobotWidget;
}

class singleRobotWidget : public QWidget
{
    Q_OBJECT

public:
    boost::signals2::signal<void (int)> ImSelected;

    int _robotnumber = -1;
    explicit singleRobotWidget(QWidget *parent = 0);
    ~singleRobotWidget();

    void setAsSelected(bool isSelect);
    void setRobotNumber(int robotNumber);

    void SetVideo(QPixmap image);
private:
    Ui::singleRobotWidget *ui;

protected:
    void mouseReleaseEvent(QMouseEvent * event);
};

#endif // SINGLEROBOTWIDGET_H
