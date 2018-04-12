#include "score.h"
#include<QFont>

extern int globalscore;

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent){
    globalscore = 0;
    setPlainText(QString("Score: ") + QString::number(globalscore));
    QFont font("Times", 30, QFont::Helvetica, true);
    setFont(font);
    setDefaultTextColor(Qt::darkMagenta);
    setX(300);
    setY(0);
}

void Score::add(){
    ++globalscore;
    setPlainText(QString("Score: ") + QString::number(globalscore));
}

