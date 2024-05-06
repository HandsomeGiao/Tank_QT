#include "player.h"
#include<QDebug>

Player::Player(ePlayer p,QSize ws):player(p)
{
    rect.setSize(QSize(4,4));
    usizeH=ws.height();
    usizeW=ws.width();
    isAlive=false;
}

void Player::move(eDirection d)
{
    if(!isAlive)
        return;
    switch(d){
    case eDirection::up:{
        int ty=pixelPos.y();
        pixelPos.ry()-=speedy;
        if(pixelPos.y()<0)
            pixelPos.ry()=0;
        else if(ty%usizeH && (pixelPos.y()/usizeH != ty/usizeH) )
            pixelPos.ry()=(ty/usizeH*usizeH);   //取整

        setDir(d);

        rect.moveTopLeft(QPoint(pixelPos.x()/usizeW,pixelPos.y()/usizeH));
        break;
    }
    case eDirection::down:{
        pixelPos.ry()+=speedy;

        setDir(d);

        rect.moveTopLeft(QPoint(pixelPos.x()/usizeW,pixelPos.y()/usizeH+1));
        break;
    }
    case eDirection::left:{
        int tx=pixelPos.x();
        pixelPos.rx()-=speedx;

        if(pixelPos.x()<0)
            pixelPos.rx()=0;
        else if(tx%usizeW && (pixelPos.x()/usizeW != tx/usizeW))
            pixelPos.rx()=(tx/usizeW*usizeW);   //取整

        setDir(d);

        rect.moveTopLeft(QPoint(pixelPos.x()/usizeW,pixelPos.y()/usizeH));
        break;
    }
    case eDirection::right:{
        pixelPos.rx()+=speedx;

        setDir(d);

        rect.moveTopLeft(QPoint(pixelPos.x()/usizeW+1,pixelPos.y()/usizeH));
        break;
    }
    }
}

void Player::setWSize(QSize ws)
{
    speedx=ws.width() * speedRate;
    speedy=ws.height()* speedRate;
    usizeW=ws.width()/52.0;
    usizeH=ws.height()/52.0;

    pixelPos.rx()=rect.left()*usizeW;
    pixelPos.ry()=rect.top()*usizeH;
}

void Player::draw(QPainter& qpt)
{
    if(!isAlive)
        return;
    QImage img;
    switch(dirc){
    case eDirection::up:{
        if(flash){
            img=imgUp_0.scaled(usizeW*4,usizeH*4);
        }else{
            img=imgUp_1.scaled(usizeW*4,usizeH*4);
        }
        break;
    }
    case eDirection::down:{
        if(flash){
            img=imgDown_0.scaled(usizeW*4,usizeH*4);
        }else{
            img=imgDown_1.scaled(usizeW*4,usizeH*4);
        }
        break;
    }
    case eDirection::left:{
        if(flash){
            img=imgLeft_0.scaled(usizeW*4,usizeH*4);
        }else{
            img=imgLeft_1.scaled(usizeW*4,usizeH*4);
        }
        break;
    }
    case eDirection::right:{
        if(flash){
            img=imgRight_0.scaled(usizeW*4,usizeH*4);
        }else{
            img=imgRight_1.scaled(usizeW*4,usizeH*4);
        }
        break;
    }
    }

    flash=!flash;
    qpt.drawImage(pixelPos,img);

    //debug
    qpt.setPen(QPen(Qt::green, 2, Qt::SolidLine));
    QRect r;
    r.setSize(QSize(usizeW*4,usizeH*4));
    r.moveTopLeft(QPoint(rect.x()*usizeW,rect.y()*usizeH));
    qpt.drawRect(r);

}

void Player::revive()
{
    speedRate=speedRate_low;
    speedx=usizeW*speedRate;
    speedy=usizeH*speedRate;
    rstPos();
    isAlive=true;
    level=0;
    loadImg();
}

void Player::rstPos()
{
    if(player==ePlayer::P0){
        rect.moveTopLeft(QPoint(18,48));
    }else if(player == ePlayer::P1){
        rect.moveTopLeft(QPoint(30,48));
    }
    pixelPos=QPoint(
        rect.left()*usizeW,rect.top()*usizeH
        );
    dirc=eDirection::up;

    //qDebug()<<"rect.top="<<rect.top()<<" rect.left="<<rect.left();
    //qDebug()<<"rect.width="<<rect.width()<<" rect.height="<<rect.height();
}

bool Player::alive() const
{
    return isAlive;
}

QRect Player::getRectMoved(eDirection d)const
{
    QRect trect;
    trect.setSize(QSize(4,4));
    QPoint tpt=pixelPos;
    QPoint ttpt=tpt;
    //qDebug()<<"pixelPos.x="<<pixelPos.x()<<" pixelPos.y="<<pixelPos.y();
    //qDebug()<<"usizeW="<<usizeW<<" usizeH="<<usizeH;
    switch(d){
    case eDirection::up:{
        tpt.ry()-=speedy;
        qDebug()<<"speedy="<<speedy;

        if(dirc == eDirection::left || dirc==eDirection::right){
            int t= pixelPos.x()%usizeW;
            tpt.rx()-=t;
        }

        if(ttpt.y()%usizeH && (tpt.y()/usizeH != ttpt.y()/usizeH) )
            tpt.ry()=(ttpt.y()/usizeH*usizeH);   //取整

        trect.moveTopLeft(QPoint(tpt.x()/usizeW,tpt.y()/usizeH));
        break;
    }
    case eDirection::down:{
        tpt.ry()+=speedy;
        if(dirc == eDirection::left || dirc==eDirection::right){
            int t= pixelPos.x()%usizeW;
            tpt.rx()-=t;
        }

        if(ttpt.y()%usizeH && (tpt.y()/usizeH != ttpt.y()/usizeH) )
            tpt.ry()=(ttpt.y()/usizeH*usizeH + 1);   //取整

        trect.moveTopLeft(QPoint(tpt.x()/usizeW,tpt.y()/usizeH+1));
        break;
    }
    case eDirection::left:{
        tpt.rx()-=speedx;
        if(dirc == eDirection::down || dirc==eDirection::up){
            int t= pixelPos.y()%usizeH;
            tpt.ry()-=t;
        }

        if(ttpt.x()%usizeW && (tpt.x()/usizeW != ttpt.x()/usizeW) )
            tpt.rx()=(ttpt.x()/usizeW*usizeW);   //取整

        trect.moveTopLeft(QPoint(tpt.x()/usizeW,tpt.y()/usizeH));
        break;
    }
    case eDirection::right:{
        tpt.rx()+=speedx;
        if(dirc == eDirection::down || dirc==eDirection::up){
            int t= pixelPos.y()%usizeH;
            tpt.ry()-=t;
        }

        if(ttpt.x()%usizeW && (tpt.x()/usizeW != ttpt.x()/usizeW) )
            tpt.rx()=(ttpt.x()/usizeW*usizeW + 1);   //取整

        trect.moveTopLeft(QPoint(tpt.x()/usizeW+1,tpt.y()/usizeH));
        break;
    }
    }
    return trect;
}

void Player::setDir(eDirection d)
{
    dirc=d;
}

eDirection Player::getDir() const
{
    return dirc;
}

QRect Player::getRect() const
{
    return rect;
}

//在等级变更时，需要重新加载图片
void Player::loadImg()
{
    if(player==ePlayer::P0){
        imgDown_0.load(QString(":/pic/0Player/m%1-3-2.jpg").arg(level));
        imgDown_1.load(QString(":/pic/0Player/m%1-3-1.jpg").arg(level));
        imgUp_0.load(QString(":/pic/0Player/m%1-1-2.jpg").arg(level));
        imgUp_1.load(QString(":/pic/0Player/m%1-1-1.jpg").arg(level));
        imgLeft_0.load(QString(":/pic/0Player/m%1-0-2.jpg").arg(level));
        imgLeft_1.load(QString(":/pic/0Player/m%1-0-1.jpg").arg(level));
        imgRight_0.load(QString(":/pic/0Player/m%1-2-2.jpg").arg(level));
        imgRight_1.load(QString(":/pic/0Player/m%1-2-1.jpg").arg(level));
    }if(player == ePlayer::P1){
        imgDown_0.load(QString(":/pic/1Player/m%1-3-2.jpg").arg(level));
        imgDown_1.load(QString(":/pic/1Player/m%1-3-1.jpg").arg(level));
        imgUp_0.load(QString(":/pic/1Player/m%1-1-2.jpg").arg(level));
        imgUp_1.load(QString(":/pic/1Player/m%1-1-1.jpg").arg(level));
        imgLeft_0.load(QString(":/pic/1Player/m%1-0-2.jpg").arg(level));
        imgLeft_1.load(QString(":/pic/1Player/m%1-0-1.jpg").arg(level));
        imgRight_0.load(QString(":/pic/1Player/m%1-2-2.jpg").arg(level));
        imgRight_1.load(QString(":/pic/1Player/m%1-2-1.jpg").arg(level));
    }
}
