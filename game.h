#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QTimer>
#include <QGraphicsLineItem>
#include "fallingobj.h"
#include "opening.h"
#include "score.h"
#include "player.h"



class Opening;
class Fallingobj;
class Score;

class game : public QGraphicsScene
{
    Q_OBJECT
public:
     game(Opening* window = 0);
public slots:
     void spawn();
     void spawn_timer();
     Opening* get_parent();
     Score* get_score();
     Player* get_player();
     void stoptimers();
private:
     int points;
     int initial_rate;
     Opening* parentWindow;
     QTimer* rate;
     QTimer* spawn_rate;
     QGraphicsLineItem* bottom_line;
     Score* score;
     Player* play;
};


#endif
