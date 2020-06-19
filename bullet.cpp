#include "bullet.h"

Bullet::Bullet()
{
    //子弹高，宽
    h = 12;
    w = 8;
    //子弹速度，是否发射，是否碰撞
    speed = BULLET_SPEED;
    active = false;
    bump = false;

    //加载图片，设置图片大小
    downimg.load(BULLET_DOWN_PATH);
    downimg = resizePic(downimg,w,h);

    leftimg.load(BULLET_LEFT_PATH);
    leftimg = resizePic(leftimg,h,w);

    rightimg.load(BULLET_RIGHT_PATH);
    rightimg = resizePic(rightimg,h,w);

    upimg.load(BULLET_UP_PATH);
    upimg = resizePic(upimg,w,h);

    rect.setRect(-1,-1,0,0);

    //加载子弹爆炸图片
//    initBomb();
    bump3.load(BULLET_BOMB3_PATH);
    bump3 = resizePic(bump3, GAME_BASESIZE, GAME_BASESIZE);

    bomb_fade.load(BULLET_FADE_PATH);
    bomb_fade = resizePic(bomb_fade, GAME_BASESIZE, GAME_BASESIZE);
//    for(int i = 1;i <= BULLET_BOMB_NUM; i++)
//    {
//        QString str = QString (BULLET_BOMB_PATH).arg(i);
//        bulletPixAir.push_back(QPixmap(str));
//    }


}
//??????????????????????????????????????????????????????????
Bullet::Bullet(const Bullet &other)
{
    *this=other;
}

//设置子弹的状态
void Bullet::setActive(bool a)
{
    active = a;

    if(active == false)//如果子弹被设置为停止
    {
        bump = true;//开始爆炸
        //获取子弹爆炸点
        int x =rect.x();
        int y = rect.y();
        //消除偏移量
        if(dir == direct::up||dir == direct::down)
        {
            x-=(GAME_BASESIZE-w)/2;
        }
        else if (dir == direct::left||dir == direct::right)
        {
            y-=(GAME_BASESIZE-w)/2;
        }
        //这里是子弹真正爆炸点
        bumpx = x;
        bumpy = y;
        rect.setRect(-1,-1,0,0);
    }
}

//获取子弹此时是否发射
bool Bullet::getActive()
{
    return active;
}

//设置子弹移动
void Bullet::move()
{
    if(getActive() == false)//如果此时子弹没有发射
        return ;

    //如果子弹发射
    int x =  rect.x();
    int y =  rect.y();
    if(dir == direct::up)
    {
        y -= speed;
    }
    else if(dir == direct::down)
    {
        y += speed;
    }
    else if(dir == direct::left)
    {
        x -= speed;
    }
    else if(dir == direct::right)
    {
        x += speed;
    }

    //更新坐标
    if(canReachable(x, y, dir))//如果子弹可以到达该位置
    {
        rect.moveTo(x, y);
    }
    else {
        setActive(false);
    }
}

//设置子弹方向
void Bullet::setDir(direct dir)
{
    this->dir=dir;
}

//绘制子弹
void Bullet::display(QPainter &paint)
{
    if(!getActive())//如果此时子弹没有发射
    {
        return;
    }

    if(dir == direct::up)
    {
        paint.drawPixmap(rect.x(), rect.y(), upimg);
    }
    else if(dir == direct::down)
    {
        paint.drawPixmap(rect.x(), rect.y(), downimg);
    }
    else if(dir == direct::left)
    {
        paint.drawPixmap(rect.x(), rect.y(), leftimg);
    }
    else if(dir == direct::right)
    {
        paint.drawPixmap(rect.x(), rect.y(), rightimg);
    }
}

//判断子弹是否可到达该位置
bool Bullet::canReachable(int x, int y, direct dir)
{
    //转换map坐标
    x /= GAME_BASESIZE;
    y /= GAME_BASESIZE;
    int x1(0);
    int y1(0);
    if(dir == direct::up)
    {
        x1 = x + 1;
        y1 = y;
    }
    else if(dir == direct::down)
    {
        y1 = y;
        x1 = x+1;
    }
    else if(dir == direct::left)
    {
        x1 = x;
        y1 = y+1;
    }
    else if(dir == direct::down)
    {
        x1 = x;
        y1 = y + 1;
    }

    //将获取到的位置+1后判断是否越界
    if(x<0 || x1<0 || x>25 || x1>25 || y<0 || y1<0 || y>25 || y1>25)
    {
        return false;
    }

    //判断是否有障碍物 ,这里0是空白，1是草地，2是冰块，3是砖块，4是海洋，5是钢铁
    else if((MAP[y][x]<='2'||MAP[y][x]=='4')&&(MAP[y1][x1]<='2'||MAP[y1][x1]=='4'))
    {
        return true;//没有障碍
    }
    else //有障碍
    {
        //打砖块
        if(MAP[y][x] == '3')
        {
            MAP[y][x] = '0';
        }
        if(MAP[y1][x1] == '3')
        {
            MAP[y1][x1] = '0';
        }
        if(MAP[y][x] == '5'||MAP[y1][x1] == '5')//钢铁打不烂
        {
            QSound::play(SOUND_BULLET_HIT_STEEL);
        }
        return false;
    }
}

//虚函数？？其他对象使用bullet的属性和方法？？？？
Bullet &Bullet::operator=(const Bullet &other)
{
    if(this == &other)return *this;

    speed = other.speed;
    active = other.active;
    bump = other.bump;
    bumpx = other.bumpx;
    bumpy = other.bumpy;
    w = other.w;
    h = other.h;
    dir = other.dir;
    upimg = other.upimg;
    downimg = other.downimg;
    leftimg = other.leftimg;
    rightimg = other.rightimg;
//    bulletPixAir = other.bulletPixAir;
    bump3=other.bump3;
    rect=other.rect;

    return *this;
}

//显示爆炸
void Bullet::showExplosion(QPainter &paint)
{
//    for(int i = 0; i < BULLET_BOMB_NUM; i++)
//    {

//            paint.drawPixmap(bumpx,bumpy,m_bombs[i].m_pixArr[m_bombs[i].m_index]);

//    }
    paint.drawPixmap(bumpx,bumpy,bump3);
}

void Bullet::showExplosionFade(QPainter &paint)
{
    paint.drawPixmap(bumpx,bumpy,bomb_fade);
}

Bullet::~Bullet()
{

}

//void Bullet::initBomb()
//{
//    for (int i = 0; i <= BOMB_MAX; i++) {
//        QString str = QString(BOMB_PATH).arg(i);
//        bombs.push_back(QPixmap(str));
//    }

//    bomb_index = 0;
//    bomb_recorder = 0;
//}

//显示爆炸
//void Bullet::showExplosion(QPainter &paint)
//{
//    // 计算爆炸播放
//    for( int i = 0; i < BOMB_MAX; i++){
//        if(bombs[i].m_Free == false){
//            bombs[i].updateInfo();
//        }
//    }
//    for( int i = 0; i < BOMB_MAX; i++){
//        if(bombs[i].m_Free == false){
//            paint.drawPixmap(bumpx ,  bumpy, bombs[i].m_pixArr[i]);
//        }
//    }
//}







