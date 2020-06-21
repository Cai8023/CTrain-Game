#ifndef TANKBASE_H
#define TANKBASE_H
#include <QPixmap>
#include <QPainter>
#include "config.h"
#include "bullet.h"

class TankBase
{
public:
    //坦克相关配置函数
    TankBase();
    TankBase& operator=(const TankBase&);
    TankBase(const TankBase&);
    ~TankBase();
    //发射子弹
    void shot();
    //玩家坦克的移动变换
    //坦克移动函数
    virtual void move();
    //确定坦克方向函数
    virtual void setDir(direct dir);
    //打印履带函数
    virtual void display(QPainter&,bool state);
    //玩家坦克移动碰撞和到达范围
    bool canReachable(int x,int y,direct);

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
    //坦克速度
    int tank_speed;
    //坦克的矩形边框
    QRect tank_rect;
    //坦克的方向
    direct tank_dir;

    //子弹对象
    Bullet bullet;
};

#endif // TANKBASE_H
