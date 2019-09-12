#ifndef ENTERROOM_H
#define ENTERROOM_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class wgEnterRoom;
}

class EnterRoom : public QWidget
{
    Q_OBJECT

public:
    explicit EnterRoom(QWidget *parent = 0);
    ~EnterRoom();

    void joinchannel(QMainWindow* pLastWnd,const QString& qsChannel,uint uid);
    void leavechannel();

    void setChannelName(const QString& qsChannel,uint uid);
    void setParam(const QString& qsParam);

protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

signals:
    void sender_exitChannel();
    void sender_updateVideo();

private slots:
    void on_btnExit_clicked();
    void on_rbCamera_stateChanged(int arg1);

    void on_rbMic_stateChanged(int arg1);

private:
    const int lnTitleWidth = 1366;
    const int lnTitleHeight = 30;
    QPoint m_mousePosition;
    bool   m_bMousePressed;

private:
    Ui::wgEnterRoom *ui;
    QMainWindow* m_pLastWnd;
};

#endif // ENTERROOM_H
