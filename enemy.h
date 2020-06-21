#ifndef ENEMY_H
#define ENEMY_H
#include "tankbase.h"
#include "config.h"

class Enemy : public TankBase
{
public:
    Enemy();

    // 初始化敌军
    void initEnemy();

    bool operator == (const Enemy& other);

    virtual ~Enemy();
};

#endif // ENEMY_H
