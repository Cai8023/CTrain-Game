#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QCoreApplication>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <QKeyEvent>
#include <QTimer>
#include <QSound>
#include <QList>
#include "player.h"
#include "enemy.h"
#include <config.h>
#include <QIcon>
#include <QKeyEvent>
//#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow() override;

    // √√√√√√ 游戏资源初始化
    void initGame();
    // √√√√√√ 游戏准备
    void initReady();
    // 渲染 -----------------------框架已经分好，大家来自行填充即可
    void paintEvent(QPaintEvent *) override;
    // √√√√√√ 加载地图
    void loadMap();
    // √√√√√√ 渲染地图
    void drawMap();
    // √√√√√√ 渲染边框
    void drawFrame();
    // √√√√√√ 渲染信息面板
    void drawPanel();
    // √√√√√√ 渲染游戏过渡的开始界面
    void drawStart();

    // 按键部分代码 ----------------------- 负责 控制player移动 的同学来补充此部分代码
//    void keyPressEvent(QKeyEvent *) override;
//    void keyReleaseEvent(QKeyEvent *event) override;

    // 碰撞检测 -------------------------负责 player 部分的同学进去完成 player的rect和bullet属性的修改
    // 碰撞检测 -------------------------负责 bullet 部分的同学进去完成 rect 属性的修改
    void collisionCheck();

    // √√√√√√ 下一关
    void nextGate();

    // √√√√√√ 游戏结束
    void gameOver();

    // 定时器连接到的函数
    // 开始游戏 ------------ 负责 player 的同学来这里补充 ismove
    void play();
    // 敌人移动 ---------------------未填写代码， 负责 Enemy 的同学进去完成填写
    void enemyMove();
    // 敌人射击 ---------------------未填写代码，负责 Enemy 的同学进去完成填写
    void enemyShot();
    // 子弹移动 ---------------------未填写代码，负责 Bullet 的同学进去完成填写
    void bulletMove();
    // 重新渲染（刷新）
    void refresh();


    // 制造敌人---------------------未填写代码， 负责 Enemy 的同学进去完成填写
    void createEnemy();
    // 制造玩家----------------------- 未填写代码，负责 player 的同学来补充此部分代码
    void createPlayer();

public:
    // 地图资源属性
    QPixmap map_grass;
    QPixmap map_brick;
    QPixmap map_water;
    QPixmap map_ice;
    QPixmap map_iron;
    // 背景 —— 灰色
    QPixmap map_bg_gray;
    // 地图 —— 大本营图标
    QPixmap map_camp;

    // 设置矩形边框
    QRect map_campRect;
    // 设置渲染
    QPainter paint;

    // 关卡
    int gate;
    // 敌人数目
    int enemy_num;
    // 敌人数组
    QList<Enemy> enemies;

    // 玩家角色
    Player player;
    // 玩家生命值
    int player_life;
    // 开始界面的渲染次数 —— 渐变
    int start;
    // cursor？？？？？？？？？？？？？？？？？？？cursor 是啥？？ Enemy的同学看一下
    int cursor;

    // ------------设置定时器--------------
    QTimer* timer_play;
    QTimer* timer_eneymyMove;
    QTimer* timer_enemyShot;
    QTimer* timer_bulletMove;
    QTimer* timer_refresh;


};

#endif // MAINWINDOW_H
