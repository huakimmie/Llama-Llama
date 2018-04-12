
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <ctime>
#include <stdlib.h>
#include <QGraphicsProxyWidget>
#include "game.h"
#include "fallingobj.h"
extern int random_number;

Fallingobj::Fallingobj(game* scene,QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent), parentscene(scene){
    random_number = (rand() % 400)+5;       //random object (apple/mushroom) generator
    if(random_number%2==0){
    setPixmap(QPixmap (":/Pictures/apple.png"));
    photo=true;
    }
    else{
    setPixmap(QPixmap(":/Pictures/mushroom.png"));
    photo=false;
    }

   setPos(random_number,0);

    QTimer* time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(move()));
    time ->start(30);

}

void Fallingobj::move(){    //implements events to occur with related falling object
    setPos(x(), y()+5);
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if(photo==true){
         if( pos().y()+pixmap().height()>300){
              if(colliding_items.size() >=1){
                  parentscene->get_score()->add();
                  delete this;
        }


              else if( pos().y()+pixmap().height()>700){
                 parentscene -> get_parent() -> reset();
                 parentscene -> stoptimers();
                 parentscene -> clear();
        }

}
}
    else{
         if( pos().y()+pixmap().height()>300){
               if(colliding_items.size() >=1){
                 parentscene -> get_parent() -> reset();
                 parentscene -> stoptimers();
                 parentscene -> clear();
            }

             else if( pos().y()+pixmap().height()>700){
                  parentscene->get_score()->add();
                  delete this;
             }

         }

    }
}
