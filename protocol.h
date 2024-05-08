#ifndef PROTOCOL_H
#define PROTOCOL_H
/*地图标记约定：
    0 空地
    1 森林
    2 冰
    3 墙
    4 河流
    5 石头
*/

//e开头然后一个大写字母的变量均为枚举变量

enum eState{
    prologue,
    select,
    showLevel,       //显示进入某一关卡的过渡画面
    gamePlay        //正式开始
};

enum eRstSelect{
    onePlayer,
    twoPlayer
};

enum eKind{
    enemy,
    p0,
    p1
};

enum eDirection{
    left,
    up,
    right,
    down
};

enum ePlayer{
    P0,
    P1
};

//速度不能超过0.019！否则碰撞检测可能失效
const double speedRate_low=0.30;
const double speedRate_mid=0.40;
const double speedRate_high=0.50;
const double speedRate_veryHigh=0.60;
const double speedRate_fly=0.70;
const double speedRate_ultra=0.80;

#endif // PROTOCOL_H
