#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include<QKeyEvent>

class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);

public:
    void keyPressEvent(QKeyEvent *event);

    void move();

public:
    //飞机资源 对象
    QPixmap Player_tank;

    //飞机坐标
    int Player_X;
    int Player_Y;

    //飞机的矩形边框
    QRect Player_Rect;

signals:

public slots:
};

#endif // PLAYER_H
