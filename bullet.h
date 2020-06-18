#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QRect>
#include <QPainter>
#include <QSound>
//#include <QDebug>
#include <QString>

class Bullet
{
public:
    explicit Bullet();
    void setActive(bool);
    bool getActive();
    void move();
    void setDir();


public:
    //子弹图片
    QPixmap bullet_upimg;
    QPixmap bullet_downimg;
    QPixmap bullet_leftimg;
    QPixmap bullet_rightimg;

    //图片宽高
    int bullet_w;
    int bullet_h;

    //移动速度，是否开始移动
    int bullet_speed;
    bool bullet_active;

    //矩形框
    QRect bullet_rect;

    //是否碰撞，碰撞位置
    bool bullet_bump;
    int bullet_bumpx;
    int bullet_bumpy;


    //爆炸图片
    QVector<QPixmap> bullet_pixAir;

};

#endif // BULLET_H
