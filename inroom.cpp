#include "stdafx.h"
#include "agoraobject.h"
#include "inroom.h"
#include "ui_inroom.h"

#ifdef Q_OS_WIN32
#include <Windows.h>
#endif

InRoom::InRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InRoom)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint
                         | Qt::WindowMinMaxButtonsHint );

    CAgoraObject* pObject = CAgoraObject::getInstance();
    connect(pObject,SIGNAL(sender_videoStopped()),
            this,SLOT(receive_videoStopped()));
    connect(pObject,SIGNAL(sender_joinedChannelSuccess(const QString&,unsigned int ,int)),
            this,SLOT(receive_joinedChannelSuccess(const QString&,unsigned int,int)));
    connect(pObject,SIGNAL(sender_userJoined(unsigned int,int)),
            this,SLOT(receive_userJoined(unsigned int,int)));
    connect(pObject,SIGNAL(sender_userOffline(unsigned int,USER_OFFLINE_REASON_TYPE)),
            this,SLOT(receive_userOffline(unsigned int,USER_OFFLINE_REASON_TYPE)));
    connect(pObject,SIGNAL(sender_firstLocalVideoFrame(int,int,int)),
            this,SLOT(receive_firstLocalVideoFrame(int,int,int)));
    connect(pObject,SIGNAL(sender_firstRemoteVideoDecoded(unsigned int,int,int,int)),
            this,SLOT(receive_firstRemoteVideoDecoded(unsigned int,int,int,int)));
    connect(pObject,SIGNAL(sender_firstRemoteVideoFrameDrawn(unsigned int,int,int,int)),
            this,SLOT(receive_firstRemoteVideoFrameDrawn(unsigned int,int,int,int)));
    connect(pObject,SIGNAL(sender_localVideoStats(LocalVideoStats)),
            this,SLOT(receive_localVideoStats(LocalVideoStats)));
    connect(pObject,SIGNAL(sender_remoteVideoStats(RemoteVideoStats)),
            this,SLOT(receive_remoteVideoStats(RemoteVideoStats)));
    connect(pObject,SIGNAL(sender_rtcStats(RtcStats)),
            this,SLOT(receive_rtcStats(RtcStats)));

    connect(this,SIGNAL(clicked()),this,SLOT(mouseClicked()));

    ui->widget_l->lower();
    ui->widget_r1->setWindowOpacity(1);
    ui->widget_r2->setWindowOpacity(1);
    ui->widget_r3->setWindowOpacity(1);

    m_timer_fps = new QTimer(this);
    connect(m_timer_fps,SIGNAL(timeout()),this,SLOT(receive_timer_pfs()));
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

void InRoom::focusInEvent(QFocusEvent *event)
{
    qDebug(__FUNCTION__);
    QApplication::sendEvent(m_uper.get(),event);
}

void InRoom::focusOutEvent(QFocusEvent *event)
{
    qDebug(__FUNCTION__);
    QApplication::sendEvent(m_uper.get(),event);
}

void InRoom::joinchannel(QMainWindow* pMainWnd,const QString& qsChannel,uint uid)
{
    qDebug(__FUNCTION__);
    this->show();

    CAgoraObject::getInstance()->joinChannel("",qsChannel,uid);

    m_uper.reset(new EnterRoom);
    m_uper->joinchannel(pMainWnd,qsChannel,uid);
}

void InRoom::leavechannel()
{
    qDebug(__FUNCTION__);

    m_timer_fps->stop();
    {
        std::lock_guard<std::mutex> autoLock(m_vsMutex);
        m_qivs.clear();
        delete m_timer_fps;
        m_bigUid = 0;
        m_uid = 0;
    }

    CAgoraObject::getInstance()->leaveChannel();
    this->hide();
}

void InRoom::receive_videoStopped()
{
    qDebug(__FUNCTION__);
}

void InRoom::receive_joinedChannelSuccess(const QString &qsChannel, unsigned int uid, int elapsed)
{
    qDebug("%s %s %u",__FUNCTION__,qsChannel.toStdString().c_str(),uid);

    {
        std::lock_guard<std::mutex> autoLock(m_vsMutex);
        m_uid = uid;
        if(!m_qivs.contains(uid)) {
            m_qivs[uid] = Video_Stats(uid);
        }
    }

    adjustPos();

    QString qsChannelInfo;
    qsChannelInfo.sprintf("%s %u",qsChannel.toStdString().c_str(),uid);
    m_uper->setChannelName(qsChannelInfo);
    m_bigUid = uid;
    m_timer_fps->start(2000);
}

void InRoom::receive_userJoined(uid_t uid, int elapsed)
{
    qDebug("%s %u",__FUNCTION__,uid);
    {
        std::lock_guard<std::mutex> autoLock(m_vsMutex);
        if(!m_qivs.contains(uid)) {
            m_qivs[uid] = Video_Stats(uid);
        }
    }

    adjustPos();
}

void InRoom::receive_userOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason)
{
    qDebug("%s %u",__FUNCTION__,uid);
    {
        std::lock_guard<std::mutex> autoLock(m_vsMutex);
        if(m_qivs.contains(uid)) {
            auto it = m_qivs.find(uid);
            m_qivs.erase(it);
        }
    }

    adjustPos();
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
   // qDebug(__FUNCTION__);
    {
        std::lock_guard<std::mutex> autoLock(m_vsMutex);
        if(m_qivs.contains(m_uid)) {
            m_qivs[m_uid].nWidth = stats.encodedFrameWidth;
            m_qivs[m_uid].nHeight = stats.encodedFrameHeight;
            m_qivs[m_uid].nFps = stats.sentFrameRate;
            m_qivs[m_uid].nBitrate = stats.sentBitrate;
        }
    }
}

void InRoom::receive_remoteVideoStats(const RemoteVideoStats &stats)
{
  // qDebug(__FUNCTION__);
   {
       std::lock_guard<std::mutex> autoLock(m_vsMutex);
       if(m_qivs.contains(stats.uid)) {
           m_qivs[stats.uid].nLastmileDelay = stats.delay;
           m_qivs[stats.uid].nWidth = stats.width;
           m_qivs[stats.uid].nHeight = stats.height;
           m_qivs[stats.uid].nFps = stats.rendererOutputFrameRate;
           m_qivs[stats.uid].nBitrate = stats.receivedBitrate;
       }
   }
}

void InRoom::receive_rtcStats(const RtcStats &stats)
{
    m_nlastmileDelay = stats.lastmileDelay;

    std::lock_guard<std::mutex> autoLock(m_vsMutex);
    if(m_qivs.contains(m_uid))
        m_qivs[m_uid].nLastmileDelay = stats.lastmileDelay;
}

void InRoom::receive_timer_pfs()
{
    std::lock_guard<std::mutex> autoLock(m_vsMutex);
    if(m_qivs.contains(m_bigUid)) {
        QString qsFps;
        auto it = m_qivs.value(m_bigUid);
        qsFps.sprintf("SD-RTN: %dms.  Video: %dfps %dx%d",it.nLastmileDelay,it.nFps,it.nWidth,it.nHeight);
        m_uper->setParam(qsFps);
    }
}

void InRoom::adjustPos()
{
    ui->widget_l->setVisible(false);
    ui->widget_r1->setVisible(false);
    ui->widget_r2->setVisible(false);
    ui->widget_r3->setVisible(false);

    std::lock_guard<std::mutex> autoLock(m_vsMutex);
    auto it = m_qivs.begin();
    int nIndex = 0;
    while(m_qivs.end() != it) {
        if(it->uid == m_uid) {
            it->wid = ui->widget_l->winId();
            CAgoraObject::getInstance()->LocalVideoPreview((HWND)(it->wid),
                                                           TRUE,
                                                           (it->uid == m_bigUid) ? RENDER_MODE_FIT : RENDER_MODE_HIDDEN);
            ui->widget_l->setVisible(true);
        }
        else {
            nIndex++;
            if(nIndex == 1) {
                it->wid = ui->widget_r1->winId();
                CAgoraObject::getInstance()->RemoteVideoRender(it->uid,
                                                               (HWND)(it->wid),
                                                                (it->uid == m_bigUid) ? RENDER_MODE_FIT:RENDER_MODE_HIDDEN);
                m_uper->setR1(it->uid);
                ui->widget_r1->setVisible(true);
            }

            if(nIndex == 2) {
                it->wid = ui->widget_r2->winId();
                CAgoraObject::getInstance()->RemoteVideoRender(it->uid,
                                                               (HWND)(it->wid),
                                                                (it->uid == m_bigUid) ? RENDER_MODE_FIT:RENDER_MODE_HIDDEN);
                m_uper->setR2(it->uid);
                ui->widget_r2->setVisible(true);
            }

            if(nIndex == 3) {
                it->wid = ui->widget_r3->winId();
                CAgoraObject::getInstance()->RemoteVideoRender(it->uid,
                                                               (HWND)(it->wid),
                                                                (it->uid == m_bigUid) ? RENDER_MODE_FIT:RENDER_MODE_HIDDEN);
                m_uper->setR3(it->uid);
                ui->widget_r3->setVisible(true);
            }
        }
        it++;
    }

    m_uper->setAllRAtt(nIndex);
}

void InRoom::mouseClicked()
{
    qDebug(__FUNCTION__);
}
