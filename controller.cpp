#include "controller.h"
#include<QPainter>
#include<QKeyEvent>
#include<QRandomGenerator>
#include<QMessageBox>

Controller::Controller(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1145,781);

    timer_draw.start(33);
    connect(&timer_draw,&QTimer::timeout,this,&Controller::timerout_draw);
    connect(&timer_move,&QTimer::timeout,this,&Controller::timerout_move);
    connect(&timer_addTank,&QTimer::timeout,this,&Controller::timerout_addTank);
    connect(&timer_playerShootCheck,&QTimer::timeout,this,&Controller::timerout_playerShoot);
    connect(&timer_playerShootEnable,&QTimer::timeout,this,&Controller::timerout_rstShoot);
    connect(&timer_enemiesShoot,&QTimer::timeout,this,&Controller::timerout_enemiesShoot);
    connect(&timer_checkOver,&QTimer::timeout,this,&Controller::timerout_checkOver);

    init_newGame();
}

Controller::~Controller() {}

void Controller::keyPressEvent(QKeyEvent *event)
{
    switch (state) {
    case eState::prologue:{
        state=eState::select;
        break;
    }
    case eState::select:{
        if(event->key()==Qt::Key_W || event->key()==Qt::Key_S){
            rstSelect = (rstSelect==onePlayer?twoPlayer:onePlayer);
        }else if(event->key()==Qt::Key_Enter ||event->key()==Qt::Key_Return){
            init_newLv(1);
        }
        break;
    }
    case eState::showLevel:{

        break;
    }
    case eState::gamePlay:{
        switch(event->key()){
        case Qt::Key_W:{
            P0MoveUp=true;
            break;
        }
        case Qt::Key_S:{
            P0MoveDown=true;
            break;
        }
        case Qt::Key_A:{
            P0MoveLeft=true;
            break;
        }
        case Qt::Key_D:{
            P0MoveRight=true;
            break;
        }
        case Qt::Key_Up:{
            P1MoveUp=true;
            break;
        }
        case Qt::Key_Down:{
            P1MoveDown=true;
            break;
        }
        case Qt::Key_Left:{
            P1MoveLeft=true;
            break;
        }
        case Qt::Key_Right:{
            P1MoveRight=true;
            break;
        }
        case Qt::Key_G:{
            P0shoot=true;
            break;
        }
        case Qt::Key_L:{
            P1shoot=true;
            break;
        }
        }
    }
    default:
        break;
    }
    event->accept();
}

void Controller::keyReleaseEvent(QKeyEvent *event)
{
    switch(state){
    case eState::prologue:{
        break;
    }
    case eState::select:{
        break;
    }
    case eState::showLevel:{
        break;
    }
    case eState::gamePlay:{
        switch(event->key()){
        case Qt::Key_W:{
            P0MoveUp=false;
            break;
        }
        case Qt::Key_S:{
            P0MoveDown=false;
            break;
        }
        case Qt::Key_A:{
            P0MoveLeft=false;
            break;
        }
        case Qt::Key_D:{
            P0MoveRight=false;
            break;
        }
        case Qt::Key_Up:{
            P1MoveUp=false;
            break;
        }
        case Qt::Key_Down:{
            P1MoveDown=false;
            break;
        }
        case Qt::Key_Left:{
            P1MoveLeft=false;
            break;
        }
        case Qt::Key_Right:{
            P1MoveRight=false;
            break;
        }
        case Qt::Key_G:{
            P0shoot=false;
            break;
        }
        case Qt::Key_L:{
            P1shoot=false;
            break;
        }
        }
        break;
    }
    }

    event->accept();
}

void Controller::paintEvent(QPaintEvent *event)
{
    switch(state){
    case eState::prologue:{
        QPoint pos;
        pos.rx()=0;
        pos.ry()=height()*(60-cnt_prologue)/60.0;
        QImage img=img_prologue.scaled(width(),height());
        QPainter qpt(this);
        qpt.drawImage(pos,img);
        break;
    }
    case eState::select:{
        QImage img=img_prologue.scaled(width(),height());
        QPainter qpt(this);
        qpt.drawImage(0,0,img);

        QPoint tpos;
        tpos.rx()=0.26*width();
        if(rstSelect==onePlayer){
            tpos.ry()=0.57*height();
        }
        else if(rstSelect==twoPlayer){
            tpos.ry()=height()*0.64;
        }
        img=img_choosePlayer.scaled(width()/30,height()/30);
        qpt.drawImage(tpos,img);
        break;
    }
    case eState::showLevel:{
        //qDebug()<<"paintEvent showLevel begin";
        QPainter qpt(this);
        QImage qimg(width(),height(),QImage::Format_ARGB32);
        qimg.fill(Qt::black);
        qpt.drawImage(0,0,qimg);
        qpt.setPen(Qt::red);
        QFont tf=qpt.font();
        tf.setPointSize(30);
        qpt.setFont(tf);
        qpt.drawText(width()/2.5,height()/2,QString("level %1").arg(level));

        //qDebug()<<"paintEvent showLevel done";

        break;
    }
    case eState::gamePlay:{
        QPainter qpt(this);
        if(p1.alive())
            p1.draw(qpt);
        if(p0.alive())
            p0.draw(qpt);
        for(auto& blt:bullets)
            blt.draw(qpt);
        for(auto&e:enemies)
            e.draw(qpt);
        map.drawMap(width(),height(),&qpt);
        break;
    }
    }

    ////////////////debug
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine));

    int width = this->width();
    int height = this->height();
    int cellWidth = width / 52;
    int cellHeight = height / 52;

    // 绘制垂直线
    for (int i = 0; i <= 52; ++i) {
        int x = i * cellWidth;
        painter.drawLine(x, 0, x, height);
    }

    // 绘制水平线
    for (int i = 0; i <= 52; ++i) {
        int y = i * cellHeight;
        painter.drawLine(0, y, width, y);
    }

    /////////////////////
    event->accept();
}

void Controller::resizeEvent(QResizeEvent *event)
{
    p0.setWSize(size());
    p1.setWSize(size());
    for(auto& blt:bullets)
        blt.setWs(size());
    event->accept();
}

void Controller::timerout_draw()
{
    //qDebug()<<"timerout draw begin";
    switch(state){
    case eState::prologue:{
        ++cnt_prologue;
        if(cnt_prologue>=60)
            state=eState::select;
        break;
    }
    case eState::select:{

        break;
    }
    case eState::showLevel:{
        //qDebug()<<"timer out draw show level";
        ++showLevelCnt;
        if(showLevelCnt>=60){
            state=eState::gamePlay;
            timer_addTank.start(1000);
        }
        break;
    }
    case eState::gamePlay:{
        break;
    }
    }
    //qDebug()<<"timeout Draw done";
    update();
}

void Controller::timerout_move()
{
    //qDebug()<<"timeout move begin";
    if(p0.alive()){
        if(P0MoveUp){
            p0.setDir(eDirection::up);
            if(!Player_Map_collisionCheck(eDirection::up,ePlayer::P0))
                 p0.move(eDirection::up);
        }
        else     if(P0MoveDown){
            p0.setDir(eDirection::down);
            if(!Player_Map_collisionCheck(eDirection::down,ePlayer::P0))
                 p0.move(eDirection::down);
        }
        else     if(P0MoveLeft){
            p0.setDir(eDirection::left);
            if(!Player_Map_collisionCheck(eDirection::left,ePlayer::P0))
                p0.move(eDirection::left);
        }
        else     if(P0MoveRight){
            p0.setDir(eDirection::right);
            if(!Player_Map_collisionCheck(eDirection::right,ePlayer::P0))
                p0.move(eDirection::right);
        }
    }

    if(p1.alive()){
        if(P1MoveUp){
            p1.setDir(eDirection::up);
            if(!Player_Map_collisionCheck(eDirection::up,ePlayer::P1))
                p1.move(eDirection::up);
        }
        else     if(P1MoveDown){
            p1.setDir(eDirection::down);
            if(!Player_Map_collisionCheck(eDirection::down,ePlayer::P1))
                p1.move(eDirection::down);
        }
        else     if(P1MoveLeft){
            p1.setDir(eDirection::left);
            if(!Player_Map_collisionCheck(eDirection::left,ePlayer::P1))
                p1.move(eDirection::left);
        }
        else     if(P1MoveRight){
            p1.setDir(eDirection::right);
            if(!Player_Map_collisionCheck(eDirection::right,ePlayer::P1))
                p1.move(eDirection::right);
        }
    }
    //qDebug()<<"time out move done";
    for(auto& blt:bullets)
        blt.move();

    //enemies AI
    for(auto& enemy:enemies){
        //没有撞就一直沿着这个方向前进
        if(!enemy.checkLastCollision()){
            if(Enemy_Map_collisionCheck(enemy.getDir(),enemy))
                enemy.setLastCollision(true);
            else
                enemy.move(enemy.getDir());
            continue;
        }

        int t=QRandomGenerator::global()->bounded(4);
        eDirection d;
        switch (t) {
        case 0:{
            d=eDirection::up;
            break;
        }
        case 1:{
            d=eDirection::down;
            break;
        }
        case 2:{
            d=eDirection::left;
            break;
        }
        case 3:{
            d=eDirection::right;
            break;
        }
        }

        enemy.setDir(d);
        if(Enemy_Map_collisionCheck(d,enemy)){
            enemy.setLastCollision(true);
            continue;
        }
        enemy.move(d);
        enemy.setLastCollision(false);
    }

    dealCollisionWithBlts();
}

void Controller::timerout_addTank()
{
    //qDebug()<<"timeout addTank begin";
    if(P0lives>0 && !p0.alive())
        p0.revive();
    if(P1lives>0 && !p1.alive())
        p1.revive();

    if(enemies.size()+deadEnemies<totalEnemies && enemies.size()<5){
        //lv 1~4
        int lv=QRandomGenerator::global()->bounded(4)+1;
        int pos=QRandomGenerator::global()->bounded(3);
        enemies.emplace_back(size(),lv,pos);
    }

    //qDebug()<<"timeout addTank done";
}

void Controller::timerout_rstShoot()
{
    P0shootEnable=P1shootEnable=true;
}

void Controller::timerout_playerShoot()
{
    if(p0.alive() && P0shoot && P0shootEnable){
        bullets.emplace_back(p0.getDir(),p0.getRect().topLeft(),eKind::p0,size());
        P0shootEnable=false;
    }
    if(p1.alive() && P1shoot && P1shootEnable){
        bullets.emplace_back(p1.getDir(),p1.getRect().topLeft(),eKind::p1,size());
        P1shootEnable=false;
    }
}

void Controller::timerout_enemiesShoot()
{
    for(const auto& enemy:enemies){
        bullets.emplace_back(enemy.getDir(),enemy.getRect().topLeft(),eKind::enemy,size());
    }
}

void Controller::init_newGame()
{
    state=eState::prologue;
    cnt_prologue=0;

    rstSelect=onePlayer;

    timer_addTank.stop();
    timer_move.stop();
    timer_playerShootCheck.stop();
    timer_playerShootEnable.stop();
    timer_enemiesShoot.stop();
}

void Controller::init_moveState()
{
    P0MoveUp=P0MoveDown=P0MoveLeft=P0MoveRight=false;
    P1MoveUp=P1MoveDown=P1MoveLeft=P1MoveRight=false;
}

void Controller::init_newLv(int lv)
{
    win=true;
    over=false;
    deadEnemies=0;

    level=lv;
    state=eState::showLevel;
    showLevelCnt=0;

    map.loadmap(level);

    if(rstSelect==eRstSelect::onePlayer){
        P0lives=5;
        P1lives=0;
    }
    if(rstSelect==eRstSelect::twoPlayer){
        P0lives=P1lives=5;
    }
    init_moveState();

    timer_addTank.start(1000);
    timer_move.start(33);
    timer_playerShootCheck.start(50);
    timer_playerShootEnable.start(1000);
    timer_enemiesShoot.start(2000);
    timer_checkOver.start(2000);
}

//会碰撞返回true
bool Controller::Player_Map_collisionCheck(eDirection d, ePlayer p)
{
    //debug
    //return false;
    QRect rect;
    if(p==ePlayer::P0){
        rect=p0.getRectMoved(d);
    }else if(p==ePlayer::P1){
        rect=p1.getRectMoved(d);
    }

    qDebug()<<"player map collisionCheck movedRect top="<<rect.top()<<" left="<<rect.left();

    QRect biggestRect;
    biggestRect.setSize(QSize(52,52));
    biggestRect.moveTopLeft(QPoint(0,0));
    if(!biggestRect.contains(rect,false))
        return true;
    const QByteArray btarr=map.getPixelMap();
    for(int y=rect.top();y<=rect.bottom();++y)
        for(int x=rect.left();x<=rect.right();++x){
            qDebug()<<QString("map[y][x]=%1").arg(btarr[y*52+x]);
            if(btarr[y*52+x] >'2')
                return true;
        }
    return false;
}

bool Controller::Enemy_Map_collisionCheck(eDirection d, const Enemy &e)
{
    // getRectMoved有bug  靠此规避
    if((e.getRect().top()<=0 && d==eDirection::up)||
        (e.getRect().left()<=0 && d==eDirection::left))
        return true;

    QRect rect;
    rect=e.getRectMoved(d);

    QRect biggestRect;
    biggestRect.setSize(QSize(52,52));
    biggestRect.moveTopLeft(QPoint(0,0));
    if(!biggestRect.contains(rect,false))
        return true;

    const QByteArray btarr=map.getPixelMap();
    for(int y=rect.top();y<=rect.bottom();++y)
        for(int x=rect.left();x<=rect.right();++x){
            if(btarr[y*52+x] >'2')
                return true;
        }
    return false;
}

void Controller::dealCollisionWithBlts()
{
    QByteArray& tmap=map.getPixelMap_modifiable();
    bullets.removeIf([&](const Bullet& blt){
        QRect trect = blt.getRect();
        //blts with map
        QRect biggestRect;
        biggestRect.setSize(QSize(52,52));
        biggestRect.moveTopLeft(QPoint(0,0));
        if(!biggestRect.contains(trect,false))
            return true;

        bool collision=false;
        for(int y=trect.top();y<=trect.bottom();++y)
            for(int x=trect.left();x<=trect.right();++x){
                if(tmap[y*52+x]>'2'){
                    tmap[y*52+x]='0';
                    collision=true;
                }
            }

        // blts with enemies
        if(blt.getKind() != eKind::enemy){
            enemies.removeIf([&](const Enemy& e){
                if(e.getRect().intersects(blt.getRect())){
                    collision=true;
                    ++deadEnemies;
                    if(deadEnemies>=totalEnemies){
                        win=true;
                        over=true;
                    }
                    return true;
                }
                return false;
            });
        }
        //blts with player
        else{
            if(p0.alive() && p0.getRect().intersects(blt.getRect())){
                playerDead(ePlayer::P0);
            }
            if(p1.alive() && p1.getRect().intersects(blt.getRect())){
                playerDead(ePlayer::P1);
            }
        }

        return collision;
    });

    //blts with enemies

    //blts with player

}

void Controller::playerDead(ePlayer p)
{
    if(p == ePlayer::P0){
        --P0lives;
        p0.dead();
    }else if(p == ePlayer::P1){
        --P1lives;
        p1.dead();
    }
    if(!P0lives && !P1lives){
        win=false;
        over=true;
    }
}

void Controller::timerout_checkOver()
{
    if(!over)
        return;
    //重置位置
    p0.dead();
    p1.dead();
    if(win){
        if(level>35){
            QMessageBox::information(this,"Tank","恭喜你通关游戏");
            init_newGame();
        }else{
            init_newLv(level+1);
        }
    }else{
        QMessageBox::information(this,"Tank","GameOver!");
        init_newGame();
    }
}
