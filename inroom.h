#ifndef INROOM_H
#define INROOM_H

#include <Memory>
#include <QMainWindow>
#include "enterroom.h"

#include <IAgoraRtcEngine.h>
using namespace agora::rtc;

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

    void receive_videoStopped();
    void receive_joinedChannelSuccess(const char* channel, uid_t uid, int elapsed);
    void receive_userJoined(uid_t uid, int elapsed);
    void receive_userOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason);
    void receive_firstLocalVideoFrame(int width, int height, int elapsed);
    void receive_firstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed);
    void receive_firstRemoteVideoFrameDrawn(uid_t uid, int width, int height, int elapsed);
    void receive_localVideoStats(const LocalVideoStats &stats);
    void receive_remoteVideoStats(const RemoteVideoStats &stats);

private slots:


private:
    const int lnTitleWidth = 1366;
    const int lnTitleHeight = 30;
    QPoint m_mousePosition;
    bool   m_bMousePressed;
    std::unique_ptr<EnterRoom> m_uper;
};

#endif // INROOM_H
