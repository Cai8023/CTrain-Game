#ifndef CONFIG_H
#define CONFIG_H

/**********  方法定义数据 **********/
// 定义方法使图片大小限定
#define resizePic(p,w,h) p.scaled(w,h,Qt::AspectRatioMode::IgnoreAspectRatio,Qt::TransformationMode::SmoothTransformation)
enum direct{up,right,down,left};            // 游戏操作四个方向
extern char MAP[26][27];                    // 游戏界面分为26行26列由二维字符数组map保存地图内容


/**********  游戏配置数据  **********/
#define GAME_RES_PATH "../game/tank.rcc" // 编译目录下的rcc文件
#define GAME_ICON ":/res/pic/tank.ico"   // 图标文件
#define GAME_TITLE "坦克大战"             // 窗口标题
#define GAME_WIDTH 600          // 游戏窗口宽度
#define GAME_HEIGHT 600         // 游戏窗口高度
#define GAME_BASESIZE 20        // 矩形起点，12*，24*
#define GAME_SIZE 40            // 图形的标准尺寸

/**********  游戏_定时器_配置数据  **********/
#define TIMER_REFRESH 33         // 游戏帧率，30帧
#define TIMER_PLAY 120           // play 函数计时器
#define TIMER_ENEMYMOVE 150      // 敌机移动时间间隔
#define TIMER_ENEMYSHOT 1000     // 敌军发射子弹时间间隔
#define TIMER_BULLETMOVE 60      // 子弹移动

/**********  地图数据  **********/
#define MAP_BACKGROUND_GRAY ":/res/pic/bg_gray.gif" // 地图灰色背景
#define MAP_GRASS ":/res/pic/forest.gif"        // 草地
#define MAP_BRICK ":/res/pic/wall.gif"          // 砖
#define MAP_IRON ":/res/pic/stone.gif"          // 铁墙
#define MAP_WATER ":/res/pic/river-0.gif"       // 水
#define MAP_ICE ":/res/pic/ice.gif"             // 冰
#define MAP_CAMP ":/res/pic/camp0.gif"          // 大本营图标
#define MAP_CAMPDESTROYED ":/res/pic/camp1.gif" // 大本营被摧毁

/**********  音乐数据  **********/
#define SOUND_START ":/res/sound/start.wav"     // 音乐 —— 开始
#define SOUND_MOVE ":/res/sound/move.wav"       // 音乐 —— 玩家移动
#define SOUND_BOOM ":/res/sound/player_bomb.wav"// 音乐 —— 玩家死亡或者大本营被摧毁
#define SOUND_ENEMYBOOM ":/res/sound/enemy-bomb.wav"    // 音乐 —— 敌军被摧毁

#endif // CONFIG_H
