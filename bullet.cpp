#include "bullet.h"
#include<QPainter>
#include<QDebug>

Bullet::Bullet(eDirection d, QPoint pt,eKind k,QSize ws)
{
    qDebug()<<"bullet create";
    usizeH=ws.height()/52;
    usizeW=ws.width()/52;
    dirc=d;

    rect.setSize(QSize(4,4));
    rect.moveTopLeft(pt);

    pixelPos.rx()=rect.x()*usizeW;
    pixelPos.ry()=rect.y()*usizeH;
    kind=k;
    speedRate=speedRate_ultra;
    loadImg();
}

void Bullet::move()
{
    qDebug()<<" blt move";
    switch(dirc){
    case eDirection::up:{
        pixelPos.ry()-=(usizeH * speedRate);
        break;
    }
    case eDirection::down:{
        pixelPos.ry()+=(usizeH * speedRate );
        break;
    }
    case eDirection::left:{
        pixelPos.rx()-=(usizeW * speedRate );
        break;
    }
    case eDirection::right:{
        pixelPos.rx()+=(usizeW * speedRate);
        break;
    }
    }
    rect.moveTopLeft(QPoint(pixelPos.x()/usizeW,pixelPos.y()/usizeH));
    qDebug()<<"blt move end";
}

QRect Bullet::getRect()const
{
    return rect;
}

void Bullet::draw(QPainter& qpt)
{
    qDebug()<<"blt draw";

    QImage timg=img.scaled(QSize(4*usizeW,4*usizeH));
    qpt.drawImage(pixelPos,timg);

    //debug
    qpt.setPen(QPen(Qt::green, 4, Qt::SolidLine));
    QRect r;
    r.setSize(QSize(usizeW*4,usizeH*4));
    r.moveTopLeft(QPoint(rect.x()*usizeW,rect.y()*usizeH));
    qpt.drawRect(r);
}

void Bullet::setWs(QSize s)
{
    qDebug()<<"blt setWS";
    usizeH=s.height()/52;
    usizeW=s.width()/52;

    pixelPos.rx()=rect.left()*usizeW;
    pixelPos.ry()=rect.top()*usizeH;
}

eKind Bullet::getKind() const
{
    return kind;
}

void Bullet::loadImg()
{
    qDebug()<<"load img";

    switch (dirc) {
    case eDirection::up:
        img.load(":/pic/bullet-1.jpg");
        break;
    case eDirection::down:
        img.load(":/pic/bullet-3.jpg");
        break;
    case eDirection::left:
        img.load(":/pic/bullet-0.jpg");
        break;
    case eDirection::right:
        img.load(":/pic/bullet-2.jpg");
        break;
    }
}
