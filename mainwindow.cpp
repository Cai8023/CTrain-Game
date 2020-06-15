#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <config.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame()
{
    // 加载图标
    setWindowIcon(QIcon(GAME_ICON));
}
