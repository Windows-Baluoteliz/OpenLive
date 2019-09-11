#ifndef CAGORAOBJECT_H
#define CAGORAOBJECT_H

#include <Memory>
#include <mutex>
#define APPID ""

#include <QString>
#include <QVariant>
#include <IAgoraRtcEngine.h>
#include <IAgoraMediaEngine.h>
using namespace agora::rtc;

typedef QMap<QString,QString> qSSMap;

class CAgoraObject
{
public:

    int joinChannel(const QString& key, const QString& channel, const QString& uid);
    int leaveChannel();
    int muteLocalAudioStream(bool muted);

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
