#ifndef PLAYER_H
#define PLAYER_H
#include "tankbase.h"

class Player: public TankBase
{
public:
    Player();

    bool ismove;

    void initPlayer();

    void setDir(direct) override;
};

#endif // PLAYER_H
