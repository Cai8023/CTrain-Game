#include "enemy.h"

Enemy::Enemy()
{
    initEnemy();
}

void Enemy::initEnemy()
{
    tank_dir = down;
    tank_speed = ENEMY_SPEED;
    tank_rect.setRect(0*GAME_BASESIZE,0*GAME_BASESIZE,GAME_SIZE,GAME_SIZE);

    upimg1.load(ENEMY_UP1);
    upimg1 = resizePic(upimg1,GAME_SIZE,GAME_SIZE);
    upimg2.load(ENEMY_UP2);
    upimg2 = resizePic(upimg2,GAME_SIZE,GAME_SIZE);

    leftimg1.load(ENEMY_LEFT1);
    leftimg1 = resizePic(leftimg1,GAME_SIZE,GAME_SIZE);
    leftimg2.load(ENEMY_LEFT2);
    leftimg2 = resizePic(leftimg2,GAME_SIZE,GAME_SIZE);

    rightimg1.load(ENEMY_RIGHT1);
    rightimg1 = resizePic(rightimg1,GAME_SIZE,GAME_SIZE);
    rightimg2.load(ENEMY_RIGHT2);
    rightimg2 = resizePic(rightimg2,GAME_SIZE,GAME_SIZE);

    downimg1.load(ENEMY_DOWN1);
    downimg1 = resizePic(downimg1,GAME_SIZE,GAME_SIZE);
    downimg2.load(ENEMY_DOWN2);
    downimg2 = resizePic(downimg2,GAME_SIZE,GAME_SIZE);
}

bool Enemy::operator ==(const Enemy &other)
{
    if(this->tank_rect==other.tank_rect)//矩形框相等视为同一个对象
        return true;
    return false;
}

Enemy::~Enemy()
{

}
