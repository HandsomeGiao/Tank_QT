#ifndef BULLET_H
#define BULLET_H

#include"protocol.h"
#include<QImage>
#include<QRect>
#include<QPoint>

class Bullet
{
public:
    Bullet()=delete;
    Bullet(eDirection d,QPoint pt,eKind k,QSize q);
    void move();
    QRect getRect()const;
    void draw(QPainter& qpt);
    void setWs(QSize s);
private:
    void loadImg();
private:
    int lv;
    double speedRate;
    QPoint pixelPos;
    QRect rect;
    int usizeW,usizeH;
    eKind kind;

    eDirection dirc;
    QImage img;
};

#endif // BULLET_H
