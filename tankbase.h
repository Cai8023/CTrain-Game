#ifndef TANKBASE_H
#define TANKBASE_H
#include <QPixmap>
#include <QPainter>
#include"config.h"

class TankBase
{
public:
    TankBase();
//    TankBase& operator=(const TankBase&);
//    TankBase(const TankBase&);
//    ~TankBase();
    //发射子弹
    void shot();
    //玩家坦克的移动变换
    //virtual void move();
    //virtual void setDir(direct);
    //virtual void display(QPainter&,bool);
    //玩家坦克移动碰撞和到达范围
    bool canReachable(int,int,direct);

public:
    //坦克资源属性
    QPixmap upimg1;
    QPixmap upimg2;
    QPixmap downimg1;
    QPixmap downimg2;
    QPixmap leftimg1;
    QPixmap leftimg2;
    QPixmap rightimg1;
    QPixmap rightimg2;
    int speed;
    QRect rect;
    direct dir;

    //子弹对象
    //Bullet bullet;
};

#endif // TANKBASE_H
