#include "stdafx.h"
#include "agoraobject.h"
#include "inroom.h"
#include "ui_inroom.h"

InRoom::InRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InRoom)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    CAgoraObject* pObject = CAgoraObject::getInstance();
    connect(pObject,SIGNAL(sender_videoStopped()),this,SLOT(receive_videoStopped()));
    connect(pObject,SIGNAL(sender_joinedChannelSuccess(const char*,uid_t,int)),
            this,SLOT(receive_joinedChannelSuccess(const char*,uid_t,int)));
    connect(pObject,SIGNAL(sender_userJoined(uid_t,int)),
            this,SLOT(receive_userJoined(uid_t,int)));
    connect(pObject,SIGNAL(sender_userOffline(uid_t,USER_OFFLINE_REASON_TYPE)),
            this,SLOT(receive_userOffline(uid_t,USER_OFFLINE_REASON_TYPE)));
    connect(pObject,SIGNAL(sender_firstLocalVideoFrame(int,int,int)),
            this,SLOT(receive_firstLocalVideoFrame(int,int,int)));
    connect(pObject,SIGNAL(sender_firstRemoteVideoDecoded(uid_t,int,int,int)),
            this,SLOT(receive_firstRemoteVideoDecoded(uid_t,int,int,int)));
    connect(pObject,SIGNAL(sender_firstRemoteVideoFrameDrawn(uid_t,int,int,int)),
            this,SLOT(receive_firstRemoteVideoFrameDrawn(uid_t,int,int,int)));
    connect(pObject,SIGNAL(sender_localVideoStats(LocalVideoStats)),
            this,SLOT(receive_localVideoStats(LocalVideoStats)));
    connect(pObject,SIGNAL(sender_remoteVideoStats(RemoteVideoStats)),
            this,SLOT(receive_remoteVideoStats(RemoteVideoStats)));
}

InRoom::~InRoom()
{
    delete ui;
}

void InRoom::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) {
        m_mousePosition = e->pos();
        if(m_mousePosition.x() < lnTitleWidth &&
           m_mousePosition.y() < lnTitleHeight)
            m_bMousePressed = true;
    }

    QApplication::sendEvent(m_uper.get(),e);
}

void InRoom::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bMousePressed == true) {
        QPoint movePos = e->globalPos() - m_mousePosition;
        move(movePos);
        e->accept();
    }


    QApplication::sendEvent(m_uper.get(),e);
}

void InRoom::mouseReleaseEvent(QMouseEvent *e)
{
   m_bMousePressed = false;

   QApplication::sendEvent(m_uper.get(),e);
}

void InRoom::joinchannel(QMainWindow* pMainWnd,const QString& qsChannel,uint uid)
{
    qDebug(__FUNCTION__);
    this->show();

    CAgoraObject::getInstance()->LocalVideoPreview((HWND)winId(),TRUE);
    CAgoraObject::getInstance()->joinChannel("",qsChannel,uid);

    m_uper.reset(new EnterRoom);
    connect(m_uper.get(),SIGNAL(sender_updateVideo()),this,SLOT(receive_updateVideo));
    m_uper->joinchannel(pMainWnd,qsChannel,uid);
}

void InRoom::leavechannel()
{
    qDebug(__FUNCTION__);
    CAgoraObject::getInstance()->leaveChannel();
}

void InRoom::receive_updateVideo()
{

}

void InRoom::receive_videoStopped()
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_joinedChannelSuccess(const char* channel, uid_t uid, int elapsed)
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_userJoined(uid_t uid, int elapsed)
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_userOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason)
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_firstLocalVideoFrame(int width, int height, int elapsed)
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_firstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed)
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_firstRemoteVideoFrameDrawn(uid_t uid, int width, int height, int elapsed)
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_localVideoStats(const LocalVideoStats &stats)
{
   qDebug(__FUNCTION__);
}

void InRoom::receive_remoteVideoStats(const RemoteVideoStats &stats)
{
   qDebug(__FUNCTION__);
}
