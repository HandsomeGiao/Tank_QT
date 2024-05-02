#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "bkmanage.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

mainWidget::mainWidget(QWidget *parent)
    :QWidget(parent)
    , ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    drawTimer->start(33);   //将整个画面控制在30帧左右
    setWindowTitle("Tank");

    bkmngr=new bkManager();
    gameInCnt=0;

    connect(drawTimer,&QTimer::timeout,this,&mainWidget::timerTimeout);
}

mainWidget::~mainWidget()
{
    delete ui;
}

void mainWidget::paintEvent(QPaintEvent *event)
{
    switch(state){
    case State::gameIn:
    {
        ++gameInCnt;
        QPainter qpt(this);
        bkmngr->draw_gamein(width(),height(),gameInCnt,&qpt);
        if(gameInCnt>=60)
            state=State::selectPlayer;
        break;
    }
    case State::selectPlayer:
    {
        QPainter qpt(this);
        bkmngr->draw_select(width(),height(),selectOne,&qpt);
        break;
    }
    case State::enterPlay:{
        QPainter qpt(this);
        ++enterCnt;
        if(enterCnt>90)
            state = State::gamePlay;
        bkmngr->draw_enterLevel(width(),height(),&qpt,level);
        break;
    }
    case State::gamePlay:{

        break;
    }
    }
    event->accept();
}

void mainWidget::keyPressEvent(QKeyEvent *event)
{
    switch(state){
    case State::gameIn:{
        state=State::selectPlayer;
        break;
    }
    case State::selectPlayer:{
        if(event->key()==Qt::Key_W ||event->key()==Qt::Key_S){
            selectOne=!selectOne;
        }else if(event->key()==Qt::Key_Enter ||event->key()==Qt::Key_Return){
            state=State::enterPlay;
            enterCnt=0;
            qDebug()<<"key enter!";
        }
        break;
    }
    case State::enterPlay:{

        break;
    }
    case State::gamePlay:{

    }
    break;
    }

    event->accept();
}

void mainWidget::timerTimeout()
{
    this->update();
}
