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

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

public slots:
    void joinchannel(const QString& qsChannel,uint uid);
    void leavechannel();

private:
    const int lnTitleWidth = 1366;
    const int lnTitleHeight = 30;
    QPoint m_mousePosition;
    bool   m_bMousePressed;

private:
    Ui::wgEnterRoom *ui;
};

#endif // ENTERROOM_H
