#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // 游戏初始化
    void initGame();
    //

public:
    QPixmap bullet_map\bullete_X

};

#endif // MAINWINDOW_H
