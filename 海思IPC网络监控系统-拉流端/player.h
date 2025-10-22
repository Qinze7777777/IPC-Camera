#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "rtsp.h"
namespace Ui {
class player;
}

class player : public QMainWindow
{
    Q_OBJECT

public:
    explicit player(QWidget *parent = nullptr);
    ~player();

private:
    Ui::player *ui;
    //播放属性
    int player_angle = 0;
    int player_play = 1;
    RTSP *rtsp;
    bool rtsp_init = false;
    QThread     *playThread = nullptr;

signals:
    void sigStartRead(void);

private slots:
    void onGetOneFrame(QImage img);
    void on_button_play_clicked();
    void on_button_spin_clicked();
};

#endif // PLAYER_H
