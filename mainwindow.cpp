#include "mainwindow.h"
#include <config.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
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
