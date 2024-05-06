#include "enemy.h"
#include<QRandomGenerator>

Enemy::Enemy(QSize ws,int lv,int rt)
{
    lastCollision=true;

    level=lv;
    usizeH=ws.height()/52;
    usizeW=ws.width()/52;

    switch (lv) {
    case 1:
        speedx=usizeW*speedRate_low;
        speedy=usizeH*speedRate_low;
        break;
    case 2:
        speedx=usizeW*speedRate_mid;
        speedy=usizeH*speedRate_mid;
        break;
    case 3:
        speedx=usizeW*speedRate_high;
        speedy=usizeH*speedRate_high;
        break;
    case 4:
        speedx=usizeW*speedRate_veryHigh;
        speedy=usizeH*speedRate_veryHigh;
        break;
    }

    //rt 决定重生位置
    switch(rt){
    case 0:{
        pixelPos.rx()=pixelPos.ry()=0;
        break;
    }
    case 1:{
        pixelPos.rx()=usizeW*25;
        pixelPos.ry()=0;
        break;
    }
    case 2:{
        pixelPos.rx()=usizeW*(52-4-1);
        pixelPos.ry()=0;
        break;
    }
    }

    rect.setSize(QSize(4,4));
    rect.moveTopLeft(QPoint(pixelPos.x()/usizeW,pixelPos.y()/usizeH));

    //load image
    imgDown_0.load(QString(":/pic/gray-tank/%1-4-1.jpg").arg(level));
    imgDown_1.load(QString(":/pic/gray-tank/%1-4-2.jpg").arg(level));
    imgUp_0.load(QString(":/pic/gray-tank/%1-2-1.jpg").arg(level));
    imgUp_1.load(QString(":/pic/gray-tank/%1-2-2.jpg").arg(level));
    imgLeft_0.load(QString(":/pic/gray-tank/%1-1-1.jpg").arg(level));
    imgLeft_1.load(QString(":/pic/gray-tank/%1-1-2.jpg").arg(level));
    imgRight_0.load(QString(":/pic/gray-tank/%1-3-1.jpg").arg(level));
    imgRight_1.load(QString(":/pic/gray-tank/%1-3-2.jpg").arg(level));
}

void Enemy::move(eDirection d)
{
    switch(d){
    case eDirection::up:{
        int ty=pixelPos.y();
        pixelPos.ry()-=speedy;
        if(pixelPos.y()<0)
            pixelPos.ry()=0;
        else if(ty%usizeH && (pixelPos.y()/usizeH != ty/usizeH))
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

void Enemy::setWSize(QSize ws)
{
    usizeH=ws.height()/52;
    usizeW=ws.width() /52;
    pixelPos.rx()=rect.left()*usizeW;
    pixelPos.ry()=rect.top()*usizeH;
}

void Enemy::draw(QPainter &qpt)
{
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

QRect Enemy::getRectMoved(eDirection d) const
{
    QRect trect;
    trect.setSize(QSize(4,4));
    QPoint tpt=pixelPos;
    QPoint ttpt=tpt;
    switch(d){
    case eDirection::up:{
        tpt.ry()-=speedy;
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

void Enemy::setDir(eDirection d)
{
    dirc=d;
}

eDirection Enemy::getDir() const
{
    return dirc;
}

QRect Enemy::getRect() const
{
    return rect;
}

bool Enemy::checkLastCollision() const
{
    return lastCollision;
}

void Enemy::setLastCollision(bool c)
{
    lastCollision=c;
}

