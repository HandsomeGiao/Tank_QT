#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "protocol.h"
#include <QImage>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QPainter>

class Player:public QObject
{
    Q_OBJECT
public:
    Player()=delete;
    Player(ePlayer p,QSize ws);
    void move(eDirection d);
    void setWSize(QSize ws);
    void draw(QPainter &qpt);
    void revive();
    bool alive()const;
    void dead();
    QRect getRectMoved(eDirection d)const;
    void setDir(eDirection d);
    eDirection getDir()const;
    QRect getRect()const;
    void rstPos();

private:
    ePlayer player;
    QImage imgUp_0,imgUp_1;
    QImage imgDown_0,imgDown_1;
    QImage imgLeft_0,imgLeft_1;
    QImage imgRight_0,imgRight_1;

    bool flash=true;  //履带转动效果
    int level;
    QRect rect;
    QPoint pixelPos;
    int speedx,speedy;
    double speedRate;
    eDirection dirc;
    bool isAlive;

    int usizeW,usizeH;

private:
    void loadImg();

};

#endif // PLAYER_H
