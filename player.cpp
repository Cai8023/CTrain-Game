#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    //初始化加载飞机图片资源
    Player_tank.load(":/res/pic/icon.png");

    //初始化飞机坐标
    Player_X = Player_tank.width();
    Player_Y = Player_tank.height();

    //初始化矩形边框
    Player_Rect.setWidth(Player_tank.width());
    Player_Rect.setHeight(Player_tank.height());
    Player_Rect.moveTo(Player_X,Player_Y);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_Return)
    {
        move();
    }
}

void Player::move()
{

}
