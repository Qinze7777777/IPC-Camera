#include "player.h"
#include "ui_player.h"

player::player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::player)
{
    ui->setupUi(this);
    playThread = new QThread(this);
    rtsp = new RTSP;
    rtsp->myffmpeg_setRTSPurl("rtsp://192.168.11.142:8554/live/stream");
//    rtsp->myffmpeg_setRTSPurl("rtsp://192.168.5.9:656/video0");
    if (rtsp->myffmpeg_init() < 0)
    {
        rtsp_init = false;
    }
    else
    {
        rtsp_init = true;
        connect(rtsp, &RTSP::MyFFmpegSigGetOneFrame, this, &player::onGetOneFrame);
        rtsp->myffmpeg_info();
        rtsp->moveToThread(playThread);
        playThread->start();
        connect(this, &player::sigStartRead, rtsp, &RTSP::startRead);
        emit sigStartRead();
    }
}

player::~player()
{
    delete ui;
}

void player::onGetOneFrame(QImage img)
{
    if (player_angle != 0)
    {
        QTransform transform;
        transform.rotate(player_angle);  // 旋转 90 度
        img = img.transformed(transform);
    }
    QImage m_Image = img.scaled(QSize(800, 480),Qt::KeepAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(m_Image));
}




void player::on_button_play_clicked()
{
    if (player_play == 1)
    {
//        rtsp->m_timer->stop();
        player_play = 0;
    }
    else
    {
//        timer->start(20);
        player_play = 1;
    }
}

void player::on_button_spin_clicked()
{
    player_angle += 90;
    if (player_angle == 360)
    {
        player_angle = 0;
    }
}
