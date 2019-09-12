#ifndef INROOM_H
#define INROOM_H

#include <Memory>
#include <QMainWindow>
#include "enterroom.h"

namespace Ui {
class InRoom;
}

class InRoom : public QMainWindow
{
    Q_OBJECT

public:
    explicit InRoom(QWidget *parent = 0);
    ~InRoom();

private:
    Ui::InRoom *ui;

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

public slots:
    void joinchannel(QMainWindow* pMainWnd,const QString& qsChannel,uint uid);
    void leavechannel();
    void receive_updateVideo();

private:
    const int lnTitleWidth = 1366;
    const int lnTitleHeight = 30;
    QPoint m_mousePosition;
    bool   m_bMousePressed;
    std::unique_ptr<EnterRoom> m_uper;
};

#endif // INROOM_H
