#ifndef ENTERROOM_H
#define ENTERROOM_H

#include <QWidget>

namespace Ui {
class wgEnterRoom;
}

class EnterRoom : public QWidget
{
    Q_OBJECT

public:
    explicit EnterRoom(QWidget *parent = 0);
    ~EnterRoom();

private:
    Ui::wgEnterRoom *ui;
};

#endif // ENTERROOM_H
