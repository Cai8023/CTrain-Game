#include "player.h"

Player::Player()
{
    initPlayer();
}

void Player::initPlayer()
{
    ismove = false;
    tank_dir = up;
    tank_speed = 20;

    upimg1.load(PLAYER_UP1);
    upimg1 = resizePic(upimg1,GAME_SIZE,GAME_SIZE);
    upimg2.load(PLAYER_UP2);
    upimg2 = resizePic(upimg2,GAME_SIZE,GAME_SIZE);

    leftimg1.load(PLAYER_LEFT1);
    leftimg1 = resizePic(leftimg1,GAME_SIZE,GAME_SIZE);
    leftimg2.load(PLAYER_LEFT2);
    leftimg2 = resizePic(leftimg2,GAME_SIZE,GAME_SIZE);

    rightimg1.load(PLAYER_RIGHT1);
    rightimg1 = resizePic(rightimg1,GAME_SIZE,GAME_SIZE);
    rightimg2.load(PLAYER_RIGHT2);
    rightimg2 = resizePic(rightimg2,GAME_SIZE,GAME_SIZE);

    downimg1.load(PLAYER_DOWN1);
    downimg1 = resizePic(downimg1,GAME_SIZE,GAME_SIZE);
    downimg2.load(PLAYER_DOWN2);
    downimg2 = resizePic(downimg2,GAME_SIZE,GAME_SIZE);
}

void Player::setDir(direct tank_dir)
{
    this->tank_dir = tank_dir;
    ismove = true;
}
