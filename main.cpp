#include "mainwindow.h"
#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //注册外部二进制资源文件
//    QResource::registerResource(GAME_RES_PATH);

    MainWindow w;
    w.show();

    return a.exec();
}
