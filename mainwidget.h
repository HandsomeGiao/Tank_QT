#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPoint>
#include <QImage>
#include <QPainter>

class bkManager;

QT_BEGIN_NAMESPACE
namespace Ui {
class mainWidget;
}
QT_END_NAMESPACE

//定义当前状态的枚举变量
enum State{
    gameIn,
    selectPlayer,
    enterPlay,       //显示进入某一关卡的过渡画面
    gamePlay         //正式开始
};

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:


private:
    Ui::mainWidget *ui;
    QTimer* drawTimer=new QTimer(this);

    State state=State::gameIn;
    //gamaIn
    int gameInCnt;
    bkManager* bkmngr;
    //selectPlayer
    bool selectOne=true;
    //enterPlay
    int enterCnt;
    //gamePlay
    int level=1;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
private slots:
    void timerTimeout();
};
#endif // MAINWIDGET_H
