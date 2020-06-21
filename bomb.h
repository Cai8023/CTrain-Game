#ifndef BOMB_H
#define BOMB_H

#include "config.h"
#include <QPixmap>
#include <QVector>

class Bomb
{
public:
    Bomb();

    // 更新信息（播放爆炸图片下标、爆炸间隔
    void updateInfo();

public:

    // 资源组
    QVector<QPixmap> m_pixArr;

    // 爆炸位置
    int m_X;
    int m_Y;

    // 状态
    bool m_Free;

    // 爆炸间隔
    int m_recorder;

    // 下标
    int m_index;

};

#endif // BOMB_H
