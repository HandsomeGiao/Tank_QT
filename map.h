#ifndef MAP_H
#define MAP_H

#include <QImage>
#include <QPainter>

class Map
{
public:
    Map();
    void loadmap(int lv);
    void drawMap(int wid,int height,QPainter* qpt);
    const QByteArray& getPixelMap()const;
    QByteArray& getPixelMap_modifiable();
private:
    QImage img_empty{":/pic/bg_black.jpg"};
    QImage img_forest{":/pic/forest.jpg"};
    QImage img_ice{":/pic/ice.jpg"};
    QImage img_wall{":/pic/wall.jpg"};
    QImage img_river0{":/pic/river-0.jpg"};
    QImage img_river1{":/pic/river-1.jpg"};
    bool riverCnt=false;
    QImage img_stone{":/pic/stone.jpg"};
    QByteArray map;
    QByteArray pixelMap;
private:
};

#endif // MAP_H
