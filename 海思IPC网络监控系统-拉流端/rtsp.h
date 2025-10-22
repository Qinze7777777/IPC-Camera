#ifndef RTSP_H
#define RTSP_H

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <libavutil/frame.h>
}

#include <QObject>
#include <QImage>
#include <QDebug>
#include <QTimer>

class RTSP: public QObject
{
    Q_OBJECT

public:
    RTSP(QObject *parent = nullptr);
    ~RTSP();
    void myffmpeg_info(void);
    int myffmpeg_init(void);
    int myffmpeg_readframe(void);
    void myffmpeg_destory(void);
    void myffmpeg_setRTSPurl(QString url);

signals:
    void MyFFmpegSigGetOneFrame(QImage img);


public slots:
    void startRead(); // 启动定时器
    void timeoutslot();
private:
    int              m_videoIndex;
    QString          m_rtspUrl;
    AVCodec         *m_AVCodec;
    AVFormatContext *m_AVFormatContext;
    AVCodecContext  *m_AVCodecContext;
    AVFrame         *m_AVFrame;
    AVFrame         *m_AVFrameRGB;
    AVPacket        *m_AVPacket;
    SwsContext      *m_SwsContext;
    uint8_t         *m_OutBuffer;
    QTimer *m_timer;
};

#endif // RTSP_H
