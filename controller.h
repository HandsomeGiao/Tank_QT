#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<QWidget>
#include<QTimer>
#include<QImage>
#include<QMetaEnum>
#include<QList>

#include"protocol.h"
#include"bullet.h"
#include"player.h"
#include"map.h"
#include"enemy.h"

class Controller : public QWidget
{
    Q_OBJECT
/*************
  public func
**************/
public:
    Controller(QWidget *parent = nullptr);
    ~Controller();
/********************
  QWidget interface *
*********************/
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

/**************
 * private var
***************/
private:
    int level;//从1开始
    eState state;
    // timer
    QTimer timer_draw;
    QTimer timer_move;
    QTimer timer_addTank;
    QTimer timer_playerShootCheck;
    QTimer timer_playerShootEnable;
    QTimer timer_enemiesShoot;
    QTimer timer_checkOver;
    //prologue
    int cnt_prologue;
    QImage img_prologue{":/pic/select_player.jpg"};
    //select
    eRstSelect rstSelect;
    QImage img_choosePlayer{":/pic/playertank-ico.jpg"};
    //showLevel
    int showLevelCnt;
    //gamePlay
    Map map;
    Player p0{ePlayer::P0,size()};
    Player p1{ePlayer::P1,size()};
    bool win,over;
    const int totalEnemies=10;
    int deadEnemies;
        //control player
    int P0lives,P1lives;
    bool P0MoveUp,P0MoveDown,P0MoveLeft,P0MoveRight;
    bool P1MoveUp,P1MoveDown,P1MoveLeft,P1MoveRight;
    bool P0shoot,P1shoot;
    bool P0shootEnable,P1shootEnable;
        //bullets
    QList<Bullet> bullets;
        //enemy
    QList<Enemy> enemies;

/***************
   private func*
****************/
private:
    void init_newGame();
    void init_moveState();
    void init_newLv(int lv);
    bool Player_Map_collisionCheck(eDirection d,ePlayer p);
    bool Enemy_Map_collisionCheck(eDirection d,const Enemy& e);
    void dealCollisionWithBlts();
    void playerDead(ePlayer p);
    void timerout_checkOver();
private slots:
    void timerout_draw();
    void timerout_move();
    void timerout_addTank();
    void timerout_rstShoot();
    void timerout_playerShoot();
    void timerout_enemiesShoot();
};
#endif // CONTROLLER_H
