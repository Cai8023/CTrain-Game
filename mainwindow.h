#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // 游戏初始化
    void initGame();
    // 渲染
    void paintEvent(QPaintEvent *) override;
public:
    void keyPressEvent(QKeyEvent *event);

    void move();

};

#endif // MAINWINDOW_H
