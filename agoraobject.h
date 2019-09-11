#ifndef CAGORAOBJECT_H
#define CAGORAOBJECT_H

#include <Memory>
#include <mutex>

//Specify your APP ID here
#define APPID "aab8b8f5a8cd4469a63042fcfafe7063"

#include <QString>
#include <QVariant>
#include <IAgoraRtcEngine.h>
#include <IAgoraMediaEngine.h>
using namespace agora::rtc;

typedef QMap<QString,QString> qSSMap;

class CAgoraObject
{
public:

    int joinChannel(const QString& key, const QString& channel, uint uid);
    int leaveChannel();
    int muteLocalAudioStream(bool muted);
    BOOL LocalVideoPreview(HWND hVideoWnd, BOOL bPreviewOn, RENDER_MODE_TYPE renderType = RENDER_MODE_TYPE::RENDER_MODE_FIT);
    BOOL RemoteVideoRender(uid_t uid, HWND hVideoWnd, RENDER_MODE_TYPE renderType = RENDER_MODE_TYPE::RENDER_MODE_HIDDEN);

    int enableVideo(bool enabled);
    int enableAudio(bool enabled);

    BOOL setLogPath(const QString &strDir);
    BOOL SetChannelProfile(CHANNEL_PROFILE_TYPE channelType);
    BOOL SetClientRole(CLIENT_ROLE_TYPE roleType);
    BOOL EnableWebSdkInteroperability(BOOL bEnable);

    qSSMap getRecordingDeviceList();
    qSSMap getPlayoutDeviceList();
    qSSMap getVideoDeviceList();

    int setRecordingDevice(const QString& guid);
    int setPlayoutDevice(const QString& guid);
    int setVideoDevice(const QString& guid);

    BOOL setVideoProfile(int nWidth,int nHeight);
    BOOL setRecordingIndex(int nIndex);
    BOOL setPlayoutIndex(int nIndex);
    BOOL setVideoIndex(int nIndex);

public:
    static CAgoraObject* getInstance();
    static CAgoraObject* m_pInstance;
    static std::mutex    m_mutex;

private:
    explicit CAgoraObject();
    ~CAgoraObject();

    agora::rtc::IRtcEngine* m_rtcEngine;
    std::unique_ptr<agora::rtc::IRtcEngineEventHandler> m_eventHandler;
};

#endif // CAGORAOBJECT_H
