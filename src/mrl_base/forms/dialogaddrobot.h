#ifndef DIALOGADDROBOT_H
#define DIALOGADDROBOT_H

#include <QDialog>

namespace Ui {
class DialogAddRobot;
}

class DialogAddRobot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddRobot(QWidget *parent = 0);
    ~DialogAddRobot();
    
private:
    Ui::DialogAddRobot *ui;
};

#endif // DIALOGADDROBOT_H
