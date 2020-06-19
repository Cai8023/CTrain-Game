#include "bomb.h"

Bomb::Bomb()
{
    // 存入爆炸图片
    for (int i = 0; i <= BOMB_MAX; i++) {
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    m_X = 0;
    m_Y = 0;
    m_Free = true;

    m_index = 0;

    m_recorder = 0;
}

void Bomb::updateInfo()
{
    // 空闲则 return
    if(m_Free){
        return;
    }

    m_recorder ++ ;
    // 爆炸时间未到爆炸间隔不切图
    if( m_recorder < BOMB_INTERVAL){
        return;
    }

    m_recorder = 0;
    m_index ++ ;

    if(m_index > BOMB_MAX ){
        m_index = 0;
        m_Free = true;
    }
}
