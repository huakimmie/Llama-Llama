#include "player.h"
#include "game.h"

#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>

#include <QDebug>
#include <QImage>
#include <QBrush>

Player::Player(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap (":/Pictures/llama.png"));
}

void Player::keyPressEvent(QKeyEvent *event){       //move left/right function
    if (event->key() == Qt::Key_Left){
         if (pos().x() > 0)
         setPos(x()-25,y());
     }
     else if (event->key() == Qt::Key_Right){
         if (pos().x() + 100 < 500)
         setPos(x()+25,y());
     }
}
