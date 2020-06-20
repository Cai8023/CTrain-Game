#ifndef PLAYER_H
#define PLAYER_H
#include "tankbase.h"

class Player: public TankBase
{
public:
    Player();

    // 判断玩家是否移动
    bool ismove;

    // 初始化玩家
    void initPlayer();

    // 调整玩家方向
    void setDir(direct) override;
};

#endif // PLAYER_H
