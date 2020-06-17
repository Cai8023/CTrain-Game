#ifndef CONFIG_H
#define CONFIG_H

/**********  游戏配置数据 **********/
#define GAME_RES_PATH "../game/tank.rcc" // 编译目录下的rcc文件
#define GAME_ICON ":/res/pic/tank.ico"   // 图标文件
#define GAME_WIDTH 600          // 游戏窗口宽度
#define GAME_HEIGHT 600         // 游戏窗口高度

/**********  子弹配置数据 **********/
#define BULLET_UP_PATH "://res/pic/bullet-1.gif"
#define BULLET_DOWN_PATH "://res/pic/bullet-3.gif"
#define BULLET_LEFT_PATH "://res/pic/bullet-0.gif"
#define BULLET_RIGHT_PATH "://res/pic/bullet-2.gif"
#define BULLET_BOMB_PATH "://res/pic/bump%1.gif"
#define BULLET_BOMB_NUM 3
enum direct{up,right,down,left};


#endif // CONFIG_H
