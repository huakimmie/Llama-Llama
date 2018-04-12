#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QThread>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "opening.h"
#include "game.h"





extern int globalscore;

Opening::Opening(QWidget *parent) : QMainWindow(parent)
{


    setFixedSize(500,700); //Set size for game window

    QPalette background = palette();    //Set background image
    background.setBrush(QPalette::Background, QPixmap(":/Pictures/opening.png"));
    this->setAutoFillBackground(true);
    this->setPalette(background);

    title = new QLabel("Llama! Llama!", this);           //Create opening title
    title->setStyleSheet("QLabel {color : darkMagenta; }");
    title -> setGeometry(55,100,500,200);
    QFont titleFont("Helvetica", 60, QFont::Bold, true);
    title -> setFont(titleFont);
    fade_in_effect(title,1000);

    QFont buttonFont("Helvetica", 25, QFont::Bold, true);   //Set button style/font

    start_button = new QPushButton("Start",this);           //Create pushbutton for start button

    start_button -> setFont(buttonFont);
    start_button -> setGeometry(40,300,160,70);
    style_button(start_button);
    fade_in_effect(start_button, 2000);
    connect(start_button, SIGNAL (released()), this, SLOT(handleStart()));

    info_button = new QPushButton("How to Play",this);             //Create PushButton for Info button
    info_button -> setGeometry(260,300,160,70);
    info_button -> setFont(buttonFont);
    style_button(info_button);
    fade_in_effect(info_button, 3000);
    connect(info_button, SIGNAL (released()), this, SLOT(handleInfo()));

    exit_button = new QPushButton("Exit", this);            //Create PushButton for Exit button
    exit_button -> setGeometry(150,390,160,70);
    exit_button->setFont(buttonFont);
    style_button(exit_button);
    fade_in_effect(exit_button, 4000);
    connect(exit_button, SIGNAL (released()), this, SLOT(handleExit()));

    back_button = new QPushButton("Back",this);             //Create PushButton for Back button
    back_button -> setGeometry(150,400,160,70);
    back_button -> setFont(buttonFont);
    style_button(back_button);
    back_button -> setVisible(false);
    connect(back_button, SIGNAL (released()), this, SLOT(handleBack()));

    game_over = new QLabel("Game Over!", this);     //Create Game Over text
    game_over ->setVisible(false);
    game_over -> setStyleSheet("QLabel {color : DarkMagenta;}");
    game_over -> setGeometry(70,30,350,200);
    game_over -> setFont(titleFont);

    play_again = new QPushButton("Play Again",this);             //Create PushButton for Back button
    play_again -> setGeometry(150,300,160,70);
    play_again -> setFont(buttonFont);
    style_button(play_again);
    play_again -> setVisible(false);
    connect(play_again, SIGNAL (released()), this, SLOT(handlePlay()));

    score_label = new QLabel(this);
    score_label -> setText(QString("Your Score: ") + QString::number(globalscore));
    score_label->setStyleSheet("QLabel {color : DarkMagenta; }");
    score_label -> setGeometry(175,120,250,200);
    score_label -> setFont(buttonFont);
    score_label -> setVisible(false);

    description = new QLabel("Welcome to Llama! Llama!\n \n"                        //Create Label for description on how to play game
                             "Click the Llama to be able to move it! \n \n"
                             "Then, use the left and right arrows to move him.\n \n"
                             "Don't let the apples fall to the ground. \n \nAnd try to dodge the mushrooms!", this);
    description->setStyleSheet("QLabel {color : DarkMagenta; }");
    description -> setGeometry(50,40,450,350);
    QFont paragraphFont("Helvetica", 20, QFont::Normal, true);
    description -> setFont(paragraphFont);
    description ->setVisible(false);

}

/* ******IMPLEMENTATION OF BUTTON FUNCTIONS*/
void Opening::handleStart(){

    fade_out_effect(title, 1000);
    fade_out_effect(start_button, 1000);
    fade_out_effect(info_button, 1000);
    fade_out_effect(exit_button, 1000);
    delay();
    hide_all();
    game_scene = new game(this);
    game_view = new QGraphicsView(this);
    game_view -> setScene(game_scene);
    this -> setCentralWidget(game_view);
    game_scene->get_player()->setFocus();
}

void Opening::handleInfo(){
    fade_out_effect(title, 1000);
    fade_out_effect(start_button, 1000);
    fade_out_effect(info_button, 1000);
    fade_out_effect(exit_button, 1000);

    fade_in_effect(description, 1000);
    fade_in_effect(back_button,2000);
    back_button -> setVisible(true);
    description -> setVisible(true);
}

void Opening::handleExit(){
    this->close();
}

void Opening::handleBack(){

    fade_out_effect(description, 1000);
    fade_out_effect(back_button, 1000);
    fade_in_effect(title,1000);
    fade_in_effect(start_button,2000);
    fade_in_effect(info_button,3000);
    fade_in_effect(exit_button,4000);
    delay();
    description -> setVisible(false);
    back_button -> setVisible(false);

}

void Opening::handlePlay(){
    fade_out_effect(game_over, 1000);
    fade_out_effect(play_again, 1000);
    fade_out_effect(exit_button, 1000);
    fade_out_effect(score_label, 1000);
    delay();
    game_over -> setVisible(false);
    play_again -> setVisible(false);
    exit_button -> setVisible(false);
    score_label -> setVisible(false);
    game_scene = new game(this);
    game_view = new QGraphicsView(this);
    game_view->setScene(game_scene);
    this -> setCentralWidget(game_view);

}


/* **** FADE IN/OUT EFFECT ****** */
void Opening::fade_in_effect(QWidget *w, int duration){
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *ani = new QPropertyAnimation(eff,"opacity");
    ani->setDuration(duration);
    ani->setStartValue(0);
    ani->setEndValue(1);
    ani->setEasingCurve(QEasingCurve::InBack);
    ani->start(QPropertyAnimation::DeleteWhenStopped);
    w -> setGraphicsEffect(eff);
}

void Opening::fade_out_effect(QWidget *w, int duration){
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *ani = new QPropertyAnimation(eff,"opacity");
    ani->setDuration(duration);
    ani->setStartValue(1);
    ani->setEndValue(0);
    ani->setEasingCurve(QEasingCurve::OutBack);
    ani->start(QPropertyAnimation::DeleteWhenStopped);
    w -> setGraphicsEffect(eff);
}

void Opening::hide_all(){
    title ->setVisible(false);
    start_button ->setVisible(false);
    info_button -> setVisible(false);
    exit_button -> setVisible(false);
}

void Opening::show_all(){
    score_label -> setText(QString("Score: ") + QString::number(globalscore));
    fade_in_effect(game_over, 1000);
    fade_in_effect(play_again, 3000);
    fade_in_effect(exit_button, 4000);
    fade_in_effect(score_label, 2000);
    game_over ->setVisible(true);
    play_again ->setVisible(true);
    exit_button -> setVisible(true);
    score_label -> setVisible(true);
}

void Opening::delay(){
    QTime endTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < endTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Opening::style_button(QPushButton* w){
    w -> setStyleSheet("background-color: DarkMagenta;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: white;"
            "color: white;"
            "min-width: 10em;"
            "padding: 4px;");
}

void Opening::reset(){
    this->setCentralWidget(0);
    this->show_all();
}

QGraphicsView* Opening::get_view(){
    return game_view;
}

game* Opening::get_scene(){
    return game_scene;
}




