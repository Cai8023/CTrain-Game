#include "bullet.h"
#include "config.h"

Bullet::Bullet()
{
    bullet_h = 12;  //待改!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    bullet_w = 8;   //待改!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    bullet_speed = 60; //需改为蔡珂写的宏!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    bullet_active = false;
    bullet_bump = false;

    //加载图片，设置图片大小
    bullet_downimg.load(BULLET_DOWN_PATH);
    bullet_downimg =
    bullet_leftimg.load(BULLET_LEFT_PATH);
    bullet_rightimg.load(BULLET_RIGHT_PATH);
    bullet_upimg.load(BULLET_UP_PATH);




}
