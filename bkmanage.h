#ifndef BKMANAGE_H
#define BKMANAGE_H

#include "mainwidget.h"

class bkManager
{
/****************
*  public func  *
****************/
public:
    bkManager();
    bkManager(const bkManager&)=delete;
    void draw_gamein(int wid,int height,int cnt,QPainter*qpt);
    void draw_select(int wid,int height,bool chsone,QPainter*qpt);
    void draw_enterLevel(int wid,int height,QPainter* qpt,int lv);
/****************
* private func  *
****************/
private:

/****************
*  private var  *
****************/
private:
    //gamaIn
    QImage gameIn_pic{":/bkpic/pic/select_player.jpg"};
    //selectPlayer
    QImage selectPlayer_flag{":/bkpic/pic/playertank-ico.jpg"};
};

#endif // BKMANAGE_H
