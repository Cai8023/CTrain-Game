#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // 初始化游戏
    initGame();
}

MainWindow::~MainWindow()
{
    // 删除定时器
    delete timer_play;
    delete timer_enemyShot;
    delete timer_eneymyMove;
    delete timer_bulletMove;
    delete timer_refresh;

}

void MainWindow::initGame()
{
    // 加载图标
    setWindowIcon(QIcon(GAME_ICON));
    // 初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    // 设置窗口标题
    setWindowTitle(GAME_TITLE);
    // 设置窗口属性，在退出窗口是自动 delete 自己
    setAttribute(Qt::WA_DeleteOnClose);
    // 设置窗口背景
    setStyleSheet("background-color:black;");
    // 设置矩形边框
    map_campRect.setRect(12*GAME_BASESIZE, 24*GAME_BASESIZE, GAME_SIZE, GAME_SIZE);

    // ---------------加载图像-----------------
    // 加载 背景 —— 灰色
    map_bg_gray.load(MAP_BACKGROUND_GRAY);
    map_bg_gray = resizePic(map_bg_gray,GAME_SIZE,GAME_SIZE);
    // 加载 地图 —— 草
    map_grass.load(MAP_GRASS);
    map_grass = resizePic(map_grass,GAME_BASESIZE,GAME_BASESIZE);
    // 加载 地图 —— 铁墙
    map_iron.load(MAP_IRON);
    map_iron = resizePic(map_iron,GAME_BASESIZE,GAME_BASESIZE);
    // 加载 地图 —— 砖
    map_brick.load(MAP_BRICK);
    map_brick = resizePic(map_brick,GAME_BASESIZE,GAME_BASESIZE);
    // 加载 地图 —— 水
    map_water.load(MAP_WATER);
    map_water = resizePic(map_water,GAME_BASESIZE,GAME_BASESIZE);
    // 加载 地图 —— 冰
    map_ice.load(MAP_ICE);
    map_ice = resizePic(map_ice,GAME_BASESIZE,GAME_BASESIZE);

//    // 设置定时器
    timer_play = new QTimer(this);
    timer_enemyShot = new QTimer(this);
    timer_eneymyMove = new QTimer(this);
    timer_bulletMove = new QTimer(this);
    timer_refresh = new QTimer(this);
    // 定时器绑定函数
    connect(timer_play,&QTimer::timeout,this,&MainWindow::play);
    connect(timer_enemyShot,&QTimer::timeout,this,&MainWindow::enemyMove);
    connect(timer_enemyShot,&QTimer::timeout,this,&MainWindow::enemyShot);
    connect(timer_bulletMove,&QTimer::timeout,this,&MainWindow::bulletMove);
    connect(timer_refresh,&QTimer::timeout,this,&MainWindow::refresh);

    // 初始化关卡
    gate = 1;

//    bomb_recorder = BOMB_INTERVAL;
//    bomb_flag = false;

    // 调用初始化初始化设置
    initReady();

}

void MainWindow::initReady()
{
    // 加载地图
    loadMap();

    // 加载大本营图标
    map_camp.load(MAP_CAMP);
    map_camp = resizePic(map_camp,GAME_SIZE,GAME_SIZE);

    // 播放音乐 —— 开始
    QSound::play(SOUND_START);

    // 创建、调用 敌人 部分代码
    cursor=0;
    enemy_num = 20;
    for(int i=0;i<4;i++)
    {
        createEnemy();
    }

    // 创建、调用 玩家 部分代码
    createPlayer();
    player_life = 3;

    // 开始游戏，设置开始界面为30次渐变
    start = 30;

    // 启动定时器
    timer_play->start(TIMER_PLAY);
    timer_enemyShot->start(TIMER_ENEMYSHOT);
    timer_eneymyMove->start(TIMER_ENEMYMOVE);
    timer_bulletMove->start(TIMER_BULLETMOVE);
    timer_refresh->start(TIMER_REFRESH);
}

void MainWindow::loadMap()
{
    // 开始读取 dat 文件中的地图数据
    std::ifstream file;
    try
    {
        file.open((QCoreApplication::applicationDirPath()+"\\map.dat").toStdString().c_str(),std::ios::in|std::ios::binary);
        if(!file)
        {
            throw "无法加载地图!" ;
        }
    }
    catch(const char *err)
    {
        QMessageBox msg(QMessageBox::Icon(QMessageBox::Icon::Critical),"ERROR",err);
        msg.exec();
        exit(-1);

    }
    // 读取第 gate 关的数据
    file.seekg(sizeof(MAP)*(gate-1));
    // 将读到的数据 存放在 map中
    file.read(*MAP,sizeof(MAP));
    // 关闭文件
    file.close();
}

void MainWindow::drawMap()
{
    for (int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            // 编号3---砖
            if(MAP[i][j]=='3')
            {
                paint.drawPixmap(j*GAME_BASESIZE,i*GAME_BASESIZE,map_brick);
            }
            // 编号5---铁墙
            else if(MAP[i][j]=='5')
            {
                paint.drawPixmap(j*GAME_BASESIZE,i*GAME_BASESIZE,map_iron);
            }
            // 编写1---草地
            else if(MAP[i][j]=='1')
            {
                paint.drawPixmap(j*GAME_BASESIZE,i*GAME_BASESIZE,map_grass);
            }
            // 编号4---水
            else if(MAP[i][j]=='4')
            {
                paint.drawPixmap(j*GAME_BASESIZE,i*GAME_BASESIZE,map_water);
            }
            // 编号2---冰
            else if(MAP[i][j]=='2')
            {
                paint.drawPixmap(j*GAME_BASESIZE,i*GAME_BASESIZE,map_ice);
            }
        }
    }
    paint.drawPixmap(map_campRect.x(),map_campRect.y(),map_camp);
}

void MainWindow::drawFrame()
{
    // 绘制边框
    for(int i=0;i<15;i++)
    {
        paint.drawPixmap(0,i*GAME_SIZE,map_bg_gray);
        paint.drawPixmap(14*GAME_SIZE,i*GAME_SIZE,map_bg_gray);
        paint.drawPixmap(i*GAME_SIZE,0,map_bg_gray);
        paint.drawPixmap(i*GAME_SIZE,14*GAME_SIZE,map_bg_gray);
    }
}

void MainWindow::drawPanel()
{
    // 绘制游戏分数板
    paint.drawText(6*GAME_SIZE,GAME_BASESIZE,"第"+QString::number(gate)+"关，敌人数量："+QString::number(enemy_num));
    paint.drawText(7*GAME_SIZE,29*GAME_BASESIZE,"生命"+QString::number(player_life));
}

void MainWindow::drawStart()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            paint.drawPixmap(i*GAME_SIZE,j*GAME_SIZE,map_bg_gray);
        }
    }
    paint.setFont(QFont("宋体",24));
    paint.drawText(12*GAME_BASESIZE+10,13*GAME_BASESIZE+10,"第"+QString::number(gate)+"关");
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(start>0)
    {
        return;
    }
    if(event->key()==Qt::Key::Key_W)
    {
        player.setDir(direct::up);
    }
    else if(event->key()==Qt::Key::Key_S)
    {
        player.setDir(direct::down);
    }
    else if(event->key()==Qt::Key::Key_A)
    {
        player.setDir(direct::left);
    }
    else if(event->key()==Qt::Key::Key_D)
    {
        player.setDir(direct::right);
    }
    else if(event->key()==Qt::Key::Key_J)
    {
        if(!player.bullet.getActive())
        {
            player.shot();
            QSound::play(SOUND_SHOOT);
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key::Key_J)
    {
        return;
    }
    else
    {
        player.ismove=false;
    }
}

void MainWindow::collisionCheck()
{
    //玩家子弹和敌方子弹碰撞检测
        for(auto& enemy:enemies)
        {
            if(true==player.bullet.rect.intersects(enemy.bullet.rect))
            {
                player.bullet.setActive(false);
                enemy.bullet.setActive(false);
                break;
            }
            else if(true==map_campRect.intersects(enemy.bullet.rect)||true==map_campRect.intersects(player.bullet.rect))
            {
                QSound::play((SOUND_BOOM));
                map_camp.load(MAP_CAMPDESTROYED);
                map_camp = resizePic(map_camp,GAME_SIZE,GAME_SIZE);
                update();
                gameOver();
            }
        }
        //玩家子弹和敌方坦克碰撞检测
        for(auto enemy=enemies.begin();enemy!=enemies.end();enemy++)
        {
            if(true==player.bullet.rect.intersects(enemy->tank_rect))
            {
                QSound::play(SOUND_ENEMYBOOM);
                enemies.erase(enemy); //需要重载 == 操作符
                enemy_num--;
                if(enemy_num<=0)
                {
                    return;
                }
                createEnemy();
                player.bullet.setActive(false);
                break;
            }
        }
        //玩家和敌方子弹碰撞检测
        for(auto& enemy:enemies)
        {
            if(true==player.tank_rect.intersects(enemy.bullet.rect))
            {
                enemy.bullet.setActive(false);
                createPlayer();
                QSound::play(SOUND_BOOM);
                player_life--;
                if(player_life<=0)
                {
                    gameOver();
                }
                break;
            }
        }

}

void MainWindow::nextGate()
{
    // 如果通观35关，则结束游戏
    if(gate==35)
    {
        QMessageBox msg(QMessageBox::Icon(QMessageBox::Icon::Information),"Victory","恭喜你通过全部关卡");
        msg.exec();
        exit(1);
    }
    gate++;
    initReady();
}

void MainWindow::gameOver()
{
    // 停止定时器
    timer_play->stop();
    timer_enemyShot->stop();
    timer_bulletMove->stop();
    timer_eneymyMove->stop();
    timer_refresh->stop();

    // 询问是否重新开始游戏
    QMessageBox msg(QMessageBox::Icon::Question,"GameOver","游戏结束是否重新开始？",(QMessageBox::StandardButton::Ok|QMessageBox::StandardButton::Cancel));
    if(QMessageBox::Ok == msg.exec())
    {
        for(auto it= enemies.begin();it!=enemies.end();it++)
            enemies.erase(it);
        gate=1;
        initReady();
    }
    else
    {
        this->close();
        exit(0);
    }
}

void MainWindow::play()
{
    //玩家移动
    if(player.ismove)
    {
        player.move();
//        QSound::play(SOUND_MOVE);
        }
}

void MainWindow::enemyMove()
{
        //敌方坦克移动
        static int d;
        srand((unsigned)time(NULL));
        for (auto& enemy:enemies)//使用引用类型 ，不然不是同一个对象
        {
            //随机方向移动
            d = rand()%4;
            if(d==0)
            {
                enemy.setDir(direct::left);
            }
            else if(d == 1)
            {
                enemy.setDir(direct::up);
            }
            else if(d == 2)
            {
                enemy.setDir(direct::right);
            }
            else if(d == 3)
            {
                enemy.setDir(direct::down);
            }
            enemy.move();
        }
}

void MainWindow::enemyShot()
{
    for(auto& enemy: enemies)
    {
        if(!enemy.bullet.getActive())
        {
            enemy.shot();
        }
    }
}

void MainWindow::bulletMove()
{
    //玩家子弹移动
    if(player.bullet.getActive())
    {
        player.bullet.move();
    }

    //敌人子弹移动
    for(auto& enemy:enemies)
    {
        if(enemy.bullet.getActive())
        {
            enemy.bullet.move();
        }
    }
}

void MainWindow::refresh()
{
    collisionCheck();
    if(enemy_num<=0)
    {
        nextGate();
    }
    update();
}

void MainWindow::createEnemy()
{
    if(enemy_num<4)
        return;
    Enemy enemy;
    enemy.tank_rect.setRect(cursor*GAME_SIZE,0,GAME_SIZE,GAME_SIZE);
    enemies.push_back(enemy);
    cursor+=6;
    cursor%=18;

}

void MainWindow::createPlayer()
{
    player.bullet.setActive(false);
    player.setDir(direct::up);
    player.ismove=false;
    player.tank_rect.setRect(9*GAME_BASESIZE,24*GAME_BASESIZE,GAME_SIZE,GAME_SIZE);
}


void MainWindow::paintEvent(QPaintEvent *)
{
    // 开始渲染
    paint.begin(this);


    // 渲染关下过渡动画
    if( 0 < start-- ){
        // 不断重复渲染
        drawStart();
        paint.end();
        return;
    }

    // 转换坐标系统
    paint.save();
    paint.translate(GAME_SIZE,GAME_SIZE);

    // 画地图
    drawMap();

//    bomb_recorder ++ ;

//    // 画玩家坦克
    static bool state=true;
    player.display(paint,state);
    state = !state;
    // 画玩家子弹
    player.bullet.display(paint);
    if(player.bullet.bump)
    {
        player.bullet.showExplosion(paint);
//        if(bomb_recorder >= BOMB_INTERVAL){
//            player.bullet.showExplosionFade(paint);
//            bomb_flag = true;
//        }
    }


//    // 画敌人
    for(auto& enemy:enemies)
    {
        //画子弹
        enemy.bullet.display(paint);
        if(enemy.bullet.bump)
        {
            enemy.bullet.showExplosion(paint);
//            if(bomb_recorder >= BOMB_INTERVAL){
//                player.bullet.showExplosionFade(paint);
//                bomb_flag = true;
//            }
        }
        //画坦克
        enemy.display(paint,state);
    }

//    if(bomb_flag){
//        bomb_recorder = 0;
//    }



    // 重置坐标系统
    paint.restore();
    // 画边框
    drawFrame();
    // 画信息面板
    drawPanel();

    paint.end();
}
