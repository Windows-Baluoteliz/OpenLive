#include "agoraobject.h"
#include <qmessagebox.h>
#include <cassert>

class AgoraRtcEngineEvent : public agora::rtc::IRtcEngineEventHandler
{
    CAgoraObject& m_engine;
public:
    AgoraRtcEngineEvent(CAgoraObject& engine)
        :m_engine(engine)
    {}
    virtual void onVideoStopped() override
    {
        //emit m_engine.videoStopped();
    }
    virtual void onJoinChannelSuccess(const char* channel, uid_t uid, int elapsed) override
    {
       // emit m_engine.joinedChannelSuccess(channel, uid, elapsed);
    }
    virtual void onUserJoined(uid_t uid, int elapsed) override
    {
        //emit m_engine.userJoined(uid, elapsed);
    }
    virtual void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason) override
    {
       // emit m_engine.userOffline(uid, reason);
    }
    virtual void onFirstLocalVideoFrame(int width, int height, int elapsed) override
    {
        //emit m_engine.firstLocalVideoFrame(width, height, elapsed);
    }
    virtual void onFirstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed) override
    {
        //emit m_engine.firstRemoteVideoDecoded(uid, width, height, elapsed);
    }
    virtual void onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed) override
    {
       // emit m_engine.firstRemoteVideoFrameDrawn(uid, width, height, elapsed);
    }
};

CAgoraObject* CAgoraObject::getInstance()
{
    std::lock_guard<std::mutex> autoLock(m_mutex);
    if(nullptr == m_pInstance)
        m_pInstance = new CAgoraObject;

    return m_pInstance;
}

CAgoraObject* CAgoraObject::m_pInstance = nullptr;
std::mutex  CAgoraObject::m_mutex;

CAgoraObject::CAgoraObject():
    m_rtcEngine(createAgoraRtcEngine()),
    m_eventHandler(new AgoraRtcEngineEvent(*this))
{
    agora::rtc::RtcEngineContext context;
    context.eventHandler = m_eventHandler.get();
    context.appId = "aab8b8f5a8cd4469a63042fcfafe7063";//Specify your APP ID here
    if (*context.appId == '\0')
    {
        QMessageBox::critical(nullptr, ("AgoraOpenLive"),
                                       ("You must specify APP ID before using the demo"));
    }
    m_rtcEngine->initialize(context);
}

CAgoraObject::~CAgoraObject()
{

}

int CAgoraObject::joinChannel(const QString& key, const QString& channel, const QString& uid)
{
    if (channel.isEmpty()) {
        QMessageBox::warning(nullptr,("AgoraHighSound"),("channelname is empty"));
        return -1;
    }

    if(uid.isEmpty()) {
        QMessageBox::warning(nullptr,("AgoraHighSound"),("mobile uid is empty ,it must at least 3 characters."));
        return -1;
    }
	
    m_rtcEngine->startPreview();
    int r = m_rtcEngine->joinChannel(key.toUtf8().data(), channel.toUtf8().data(), nullptr, uid.toInt());

    return r;
}

int CAgoraObject::leaveChannel()
{
    int r = m_rtcEngine->leaveChannel();
    return r;
}

int CAgoraObject::muteLocalAudioStream(bool muted)
{
    RtcEngineParameters rep(*m_rtcEngine);
    return rep.muteLocalAudioStream(muted);
}

int CAgoraObject::enableVideo(bool enabled)
{
    return enabled ? m_rtcEngine->enableVideo() : m_rtcEngine->disableVideo();
}

int CAgoraObject::enableAudio(bool enabled)
{
    return enabled ? m_rtcEngine->enableAudio() : m_rtcEngine->disableAudio();
}

BOOL CAgoraObject::setLogPath(const QString &strDir)
{
    int ret = 0;

    RtcEngineParameters rep(*m_rtcEngine);
    ret = rep.setLogFile(strDir.toUtf8().data());

    return ret == 0 ? TRUE : FALSE;
}

BOOL CAgoraObject::SetChannelProfile(CHANNEL_PROFILE_TYPE channelType)
{
    int ret = 0;
    ret = m_rtcEngine->setChannelProfile(channelType);

    return ret == 0 ? TRUE : FALSE;
}

BOOL CAgoraObject::SetClientRole(CLIENT_ROLE_TYPE roleType)
{
    int ret = 0;

    ret = m_rtcEngine->setClientRole(roleType);

    return ret == 0 ? TRUE : FALSE;
}

BOOL CAgoraObject::EnableWebSdkInteroperability(BOOL bEnable)
{
    RtcEngineParameters rep(*m_rtcEngine);

    int	nRet = rep.enableWebSdkInteroperability(static_cast<bool>(bEnable));

    return nRet == 0 ? TRUE : FALSE;
}

qSSMap CAgoraObject::getRecordingDeviceList()
{
    qSSMap devices;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return devices;

    agora::util::AutoPtr<IAudioDeviceCollection> spCollection(audioDeviceManager->enumerateRecordingDevices());
    if (!spCollection)
        return devices;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (!spCollection->getDevice(i, name, guid))
            {
                devices[name] = guid;
            }
        }
    }
    return devices;
}

qSSMap CAgoraObject::getPlayoutDeviceList()
{
    qSSMap devices;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return devices;

    agora::util::AutoPtr<IAudioDeviceCollection> spCollection(audioDeviceManager->enumeratePlaybackDevices());
    if (!spCollection)
        return devices;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (!spCollection->getDevice(i, name, guid))
            {
                devices[name] = guid;
            }
        }
    }
    return devices;
}

qSSMap CAgoraObject::getVideoDeviceList()
{
	m_rtcEngine->enableVideo();
    qSSMap devices;
    AVideoDeviceManager videoDeviceManager(m_rtcEngine);
    if (!videoDeviceManager)
        return devices;

    agora::util::AutoPtr<IVideoDeviceCollection> spCollection(videoDeviceManager->enumerateVideoDevices());
    if (!spCollection)
        return devices;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (!spCollection->getDevice(i, name, guid))
            {
                devices[name] = guid;
            }
        }
    }
    return devices;
}

int CAgoraObject::setRecordingDevice(const QString& guid)
{
    if (guid.isEmpty())
        return -1;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setRecordingDevice(guid.toUtf8().data());
}

int CAgoraObject::setPlayoutDevice(const QString& guid)
{
    if (guid.isEmpty())
        return -1;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return -1;
    return audioDeviceManager->setPlaybackDevice(guid.toUtf8().data());
}

int CAgoraObject::setVideoDevice(const QString& guid)
{
    if (guid.isEmpty())
        return -1;
    AVideoDeviceManager videoDeviceManager(m_rtcEngine);
    if (!videoDeviceManager)
        return -1;
    return videoDeviceManager->setDevice(guid.toUtf8().data());
}

BOOL CAgoraObject::setVideoProfile(int nWidth,int nHeight)
{
    int res = 0;
    VideoEncoderConfiguration vec;
    vec = VideoEncoderConfiguration(nWidth,nHeight,FRAME_RATE_FPS_15,500,ORIENTATION_MODE_FIXED_LANDSCAPE);
    res = m_rtcEngine->setVideoEncoderConfiguration(vec);

    return res ==0 ? TRUE : FALSE;
}

BOOL CAgoraObject::setRecordingIndex(int nIndex)
{
    int res = 0;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return FALSE;

    agora::util::AutoPtr<IAudioDeviceCollection> spCollection(audioDeviceManager->enumerateRecordingDevices());
    if (!spCollection)
        return FALSE;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    assert(res < count);
    spCollection->getDevice(nIndex,name,guid);
    res = spCollection->setDevice(guid);

    return res ==0 ? TRUE:FALSE;
}

BOOL CAgoraObject::setPlayoutIndex(int nIndex)
{
    int res = 0;
    AAudioDeviceManager audioDeviceManager(m_rtcEngine);
    if (!audioDeviceManager)
        return FALSE;

    agora::util::AutoPtr<IAudioDeviceCollection> spCollection(audioDeviceManager->enumeratePlaybackDevices());
    if (!spCollection)
        return FALSE;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    assert(res < count);
    spCollection->getDevice(nIndex,name,guid);
    res = spCollection->setDevice(guid);

    return res ==0 ? TRUE:FALSE;
}

BOOL CAgoraObject::setVideoIndex(int nIndex)
{
    int res = 0;
    AVideoDeviceManager videoDeviceManager(m_rtcEngine);
    if (!videoDeviceManager)
        return FALSE;

    agora::util::AutoPtr<IVideoDeviceCollection> spCollection(videoDeviceManager->enumerateVideoDevices());
    if (!spCollection)
        return FALSE;
    char name[MAX_DEVICE_ID_LENGTH], guid[MAX_DEVICE_ID_LENGTH];
    int count = spCollection->getCount();
    assert(nIndex < count);
    spCollection->getDevice(nIndex,name,guid);
    res = spCollection->setDevice(guid);

    return res == 0 ? TRUE : FALSE;
}