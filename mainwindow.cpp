#include "mainwindow.h"
#include <config.h>
#include <QIcon>
#include <QKeyEvent>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // 初始化游戏
    initGame();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initGame()
{
    // 加载图标
    setWindowIcon(QIcon(GAME_ICON));
    // 初始化窗口大小
    resize(GAME_WIDTH,GAME_HEIGHT);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //渲染
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        move();
    }
}

void MainWindow::move()
{
    qDebug() << "xiang";
}
