#include "map.h"
#include <QByteArray>
#include <QFile>
#include <QDebug>
#include <QRegularExpression>
#include <algorithm>
#include <QThread>
#include <QMessageBox>

Map::Map() {

}

void Map::loadmap(int lv)
{
    QFile qf(":/pic/map.txt");
    if (!qf.open(QIODevice::ReadOnly | QIODevice::Text)) {
        exit(EXIT_FAILURE);
    }
    QByteArray bary=qf.readAll();
    qf.close();

    auto it = std::remove(bary.begin(),bary.end(),'\n');
    bary.erase(it,bary.end());

    map=bary.mid((lv-1)*26*26,26*26);
    pixelMap.resize(52*52);
    for(int y=0;y<52;++y)
        for(int x=0;x<52;++x){
            pixelMap[y*52+x]=map[y/2*26+x/2];
        }
}

void Map::drawMap(int wid, int height, QPainter *qpt)
{
    for(int y=0;y<52;++y){
        for(int x=0;x<52;++x){
            QImage qimg;
            switch(pixelMap[y*52+x]){
            case '0':{
                qimg=img_empty.scaled(wid/52.0,height/52.0);
                break;
            }
            case '1':{
                qimg=img_forest.scaled(wid/52.0,height/52.0);
                break;
            }
            case '2':{
                qimg=img_ice.scaled(wid/52.0,height/52.0);
                break;
            }
            case '4':{
                if(riverCnt)
                    qimg=img_river0.scaled(wid/52.0,height/52.0);
                else
                    qimg=img_river1.scaled(wid/52.0,height/52.0);
                riverCnt=!riverCnt;
                break;
            }
            case '5':{
                qimg=img_stone.scaled(wid/52.0,height/52.0);
                break;
            }
            case '3':{
                qimg=img_wall.scaled(wid/52.0,height/52.0);
                break;
            }
            }
            qpt->drawImage(x*wid/52.0,y*height/52.0,qimg);
        }
    }
}

const QByteArray &Map::getPixelMap()const
{
    return pixelMap;
}

QByteArray &Map::getPixelMap_modifiable()
{
    return pixelMap;
}
