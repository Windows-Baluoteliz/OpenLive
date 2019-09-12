#ifndef INROOM_H
#define INROOM_H

#include <QMainWindow>

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

signals:
    void send_mousePressEvent(QMouseEvent *e);
    void send_mouseMoveEvent(QMouseEvent *e);
    void send_mouseReleaseEvent(QMouseEvent *e);

public slots:
    void joinchannel(const QString& qsChannel,uint uid);
    void leavechannel();

private:
    const int lnTitleWidth = 1366;
    const int lnTitleHeight = 30;
    QPoint m_mousePosition;
    bool   m_bMousePressed;

};

#endif // INROOM_H
