#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
<<<<<<< HEAD
#include <QKeyEvent>
=======
#include <QPainter>
>>>>>>> 2cc748bf9f3b19b34e7289fdffd6dda7dfa32f53

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
<<<<<<< HEAD
public:
    void keyPressEvent(QKeyEvent *event);

    void move();
=======

public:

>>>>>>> 2cc748bf9f3b19b34e7289fdffd6dda7dfa32f53

};

#endif // MAINWINDOW_H
