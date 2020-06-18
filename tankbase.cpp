#include "tankbase.h"
//#include<QDebug>

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
//    int deviation = (GAME_SIZE-bullet.w)/2;

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

//坦克移动
void TankBase::move()
{
    int x = tank_rect.x();
    int y = tank_rect.y();
    if(tank_dir == direct::up)
    {
        y -= tank_speed;
    }
    else if(tank_dir == direct::down)
    {
        y += tank_speed;
    }
    else if(tank_dir == direct::left)
    {
        x -= tank_speed;
    }
    else if(tank_dir == direct::right)
    {
        x += tank_speed;
    }
    if(canReachable(x,y,this->tank_dir))
    {
        tank_rect.moveTo(x,y);
        //qDebug()<<"move"<<rect.x()<<" "<<rect.y();
    }
}

void TankBase::setDir(direct dir)
{
    this->tank_dir=dir;
}

//估计要用子弹的部分
void TankBase::display(QPainter &, bool state)
{
//    //state两个状态切换实现履带转动效果
//    if(state)
//    {
//        if(tank_dir==direct::up)
//        {
//             paint.drawPixmap(tank_rect.x(),tank_rect.y(),upimg1);
//        }
//        else if(tank_dir==direct::down)
//        {

//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),downimg1);
//        }
//        else if(tank_dir==direct::left)
//        {
//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),leftimg1);
//        }
//        else if(tank_dir==direct::right)
//        {
//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),rightimg1);
//        }
//    }
//    else
//    {
//        if(tank_dir==direct::up)
//        {
//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),upimg2);
//        }
//        else if(tank_dir==direct::down)
//        {
//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),downimg2);
//        }
//        else if(tank_dir==direct::left)
//        {
//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),leftimg2);
//        }
//        else if(tank_dir==direct::right)
//        {
//            paint.drawPixmap(tank_rect.x(),tank_rect.y(),rightimg2);
//        }
//    }
}

bool TankBase::canReachable(int x, int y, direct)
{
    //转换map坐标
    x /= GAME_BASESIZE;
    y /= GAME_BASESIZE;
    int x1(0);
    int y1(0);
    //判断坦克方向
    if(tank_dir==direct::up)
    {
        x1 = x + 1;
        y1 = y;
    }
    else if (tank_dir==direct::down)
    {
        y += 1;
        y1 = y;
        x1 = x + 1;
    }
    else if(tank_dir==direct::left)
    {
        x1 = x;
        y1 = y+1;
    }
    else if(tank_dir==direct::right)
    {
        x += 1;
        x1 = x;
        y1 = y + 1;
    }
    //判断坦克是否越界
    if(x<0 || x1<0 || x>25 || x1>25 || y<0 || y1<0 || y>25 || y1>25)
    {
        //qDebug()<<"越界"<<x<<" "<<y;
        return false;
    }
    //判断是否有障碍物
    else if(MAP[y][x]<='2'&&MAP[y1][x1]<='2')//注意行和列与x,y的关系
    {
        return true;
    }
    else
    {
        //qDebug()<<"障碍";
        return false;
    }
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
