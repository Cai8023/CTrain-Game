#include "tankbase.h"

TankBase::TankBase()
{

}
//等子弹写好完善
void TankBase::shot()
{
//    //子弹射出
//    if(bullet.getActive() == true)
//    {
//        return;
//    }
//    //将子弹变为非空闲
//    bullet.bump=false;
//    //设置子弹的行为
//    bullet.setActive(true);
//    //设置子弹的方向
//    bullet.setDir(dir);

//    //弹道与坦克边界的偏移量
//    int deviation = (SIZE-bullet.w)/2;

//    //根据坦克的面向调整偏移量
//    if(dir == direct::up)
//    {
//        bullet.rect.setRect(rect.x()+deviation,rect.y(),bullet.w,bullet.h);
//    }
//    else if(dir == direct::down)
//    {
//        bullet.rect.setRect(rect.x()+deviation,rect.bottom()-bullet.h,bullet.w,bullet.h);
//    }
//    else if(dir == direct::left)
//    {
//        bullet.rect.setRect(rect.left(),rect.y()+deviation,bullet.h,bullet.w);
//    }
//    else if(dir == direct::right)
//    {
//        bullet.rect.setRect(rect.right()-bullet.h,rect.y()+deviation,bullet.h,bullet.w);
//    }
//    //判断子弹是否到达边界
//    if(bullet.rect.x()==0||bullet.rect.y()==0||bullet.rect.x()>=13*SIZE||bullet.rect.y()>=13*SIZE)
//    {
//        bullet.busy=false;
    //    }
}

bool TankBase::canReachable(int, int, direct)
{

}

//TankBase &TankBase::operator=(const TankBase &other)
//{
//    if(this==&other)return *this;
//    upimg1=other.upimg1;
//    upimg2=other.upimg2;
//    downimg1=other.downimg1;
//    downimg2=other.downimg2;
//    leftimg1=other.leftimg1;
//    leftimg2=other.leftimg2;
//    rightimg1=other.rightimg1;
//    rightimg2=other.rightimg2;
//    speed=other.speed;
//    rect=other.rect;
//    dir=other.dir;
//    //bullet = other.bullet;
//    return *this;
//}

//TankBase::TankBase(const TankBase &other)
//{
//    *this=other;
//}

//TankBase::~TankBase()
//{

//}
