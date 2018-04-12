#include "game.h"
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include "fallingobj.h"
#include "score.h"
#include "player.h"

game::game(Opening* window) : QGraphicsScene(), parentWindow(window)
{

   this -> setSceneRect(0,0,500,700);
   this -> setBackgroundBrush(QBrush(QImage(":/Pictures/scenery.png")));

   play = new Player();    play->setPos(this->width()/2-play->pixmap().width()/2,this->height()-play->pixmap().height());
   play->setFlag(QGraphicsItem::ItemIsFocusable);
   play->setFocus();
   this->addItem(play);

   score = new Score();
   this-> addItem(score);

   initial_rate = 1500;
   rate = new QTimer();
   connect(rate,SIGNAL(timeout()),SLOT(spawn_timer()));
   rate->start(3000);

   spawn_rate = new QTimer(this);
   connect(spawn_rate,SIGNAL(timeout()),SLOT(spawn()));
   spawn_rate->start(initial_rate);
   play->setFocus();

}

void game::spawn(){
    Fallingobj* fallingobj  = new Fallingobj(this);
    this->addItem(fallingobj);
    QObject* timesend = sender();
    QTimer* timersend = qobject_cast<QTimer*>(timesend);
    timersend -> setInterval(initial_rate);
    play->setFocus();

}

void game::spawn_timer(){
    if(initial_rate > 100)
        initial_rate -= 30;
}


Opening* game::get_parent(){
    return parentWindow;
}

void game::stoptimers(){
    rate->stop();
    spawn_rate->stop();
}

Score* game::get_score(){
    return score;
}

Player* game::get_player(){
    return play;
}


