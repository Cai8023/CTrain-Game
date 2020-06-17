#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include <QRect>

class Bullet
{
public:
    explicit Bullet();


public:
    //子弹图片加载
    QPixmap bullet_upimg;
    QPixmap bullet_downimg;
    QPixmap bullet_leftimg;
    QPixmap bullet_rightimg;
    //坐标

    //移动速度，是否开始移动
    int bullet_speed;
    bool bullet_active;

    //矩形框
    QRect bullet_rect;

    //是否碰撞，碰撞位置
    bool bullet_bump;
    int bullet_bumpx;
    int bullet_bumpy;


    //爆炸图片加载
    QPixmap bullet_bump1;
    QPixmap bullet_bump2;
    QPixmap bullet_bump3;

};

#endif // BULLET_H
