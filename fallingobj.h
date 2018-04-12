#ifndef FALLINGOBJ_H
#define FALLINGOBJ_H

#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include "game.h"

class game;
class Fallingobj :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fallingobj(game* scene,QGraphicsItem* parent = 0);
public slots:
    void move();
private:
    game* parentscene;
    bool photo;
};

#endif
