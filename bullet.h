#ifndef BULLET_H
#define BULLET_H
#include <QAction>
#include "config.h"
#include <QPixmap>
#include <QRect>
#include <QPainter>
#include <QSound>
//#include <QDebug>
#include <QString>
#include <QVector>
#include <QTimer>


class Bullet
{
public:
    explicit Bullet();
    void setActive(bool);//设置子弹的状态
    bool getActive();//获取子弹此时是否发射
    void move();//移动
    void setDir(direct);//设置方向
    void display(QPainter&);//绘制子弹
    bool canReachable(int, int, direct);//可到达
    Bullet(const Bullet&); //????????????????????????????????????
    Bullet& operator=(const Bullet&);//?????????????????
    void showExplosion(QPainter& paint);//显示爆炸
//    void explosionMove(QPainter &paint);
//    void showExplosion2(QPainter& paint);
//    void showExplosion3(QPainter& paint);

    ~Bullet();

public:
    //子弹图片
    QPixmap upimg;
    QPixmap downimg;
    QPixmap leftimg;
    QPixmap rightimg;

    //图片宽高
    int w;
    int h;

    //移动速度，是否开始移动
    int speed;
    bool active;

    //子弹的方向
    direct dir;

    //矩形框
    QRect rect;

    //是否碰撞，碰撞位置
    bool bump;
    int bumpx;
    int bumpy;


    //爆炸图片，爆炸图片下标
//    QVector<QPixmap> bulletPixAir;
//    int index;
    QPixmap bump3;
    QPixmap bump2;
    QPixmap bump1;

//    QTimer timer_move;
//    bool bomb_flag;
//    QTimer *timer_bump2;
//    QTimer *timer_bump1;

//    QPixmap bomb_fade;

//    Bomb bombs[BOMB_MAX];


};

#endif // BULLET_H
