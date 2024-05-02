#include "bkmanage.h"
#include <QPainter>
#include<QDebug>
bkManager::bkManager()
{

}

void bkManager::draw_gamein(int wid,int height, int cnt,QPainter *qpt)
{
    QPoint pos;
    pos.rx()=0;
    if(cnt>60)
        pos.ry()=0;
    else
        pos.ry()=height*double(60-cnt)/60;
    QImage qimg=gameIn_pic.scaled(wid,height);
    qpt->drawImage(pos,qimg);
    qDebug()<<"cnt = "<<cnt;
    qDebug()<<"posx ="<<pos.x()<<" posy="<<pos.y();
}

void bkManager::draw_select(int wid, int height, bool chsone,QPainter*qpt)
{
    QImage qimg=gameIn_pic.scaled(wid,height);
    qpt->drawImage(0,0,qimg);
    QPoint tpos;
        tpos.rx()=0.26*wid;
        tpos.ry()=0.57*height;
    if(!chsone)
        tpos.ry()+=height*0.07;
    qimg=selectPlayer_flag.scaled(wid/30,height/30);
    qpt->drawImage(tpos,qimg);
}

void bkManager::draw_enterLevel(int wid, int height, QPainter *qpt, int lv)
{
    QImage qimg(wid,height,QImage::Format_ARGB32);
    qimg.fill(Qt::black);
    qpt->drawImage(0,0,qimg);
    qpt->setPen(Qt::red);
    QFont tf=qpt->font();
    tf.setPointSize(30);
    qpt->setFont(tf);
    qpt->drawText(wid/2.5,height/2,QString("level %1").arg(lv));
}

