#ifndef ENEMY_H
#define ENEMY_H

#include"protocol.h"
#include<QSize>
#include<QPainter>
#include<QRect>

class Enemy
{
public:
    Enemy()=delete;
    Enemy(QSize ws,int lv,int rt);
    void move(eDirection d);
    void setWSize(QSize ws);
    void draw(QPainter &qpt);
    QRect getRectMoved(eDirection d)const;
    void setDir(eDirection d);
    eDirection getDir()const;
    QRect getRect()const;
    bool checkLastCollision()const;
    void setLastCollision(bool c);

private:
    QImage imgUp_0,imgUp_1;
    QImage imgDown_0,imgDown_1;
    QImage imgLeft_0,imgLeft_1;
    QImage imgRight_0,imgRight_1;
    bool flash=true;
    int level;

    QRect rect;
    QPoint pixelPos;
    int speedx,speedy;
    double speedRate;
    eDirection dirc;
    bool isAlive;

    int usizeW,usizeH;

    bool lastCollision;//上一次移动是否发生了碰撞
};

#endif // ENEMY_H
