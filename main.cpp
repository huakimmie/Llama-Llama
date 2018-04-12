#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <ctime>
#include <cstdlib>
#include "opening.h"
#include "player.h"
#include "game.h"

int globalscore;
int random_number;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app (argc,argv);
    Opening window;
    window.show();
    return app.exec();
}
