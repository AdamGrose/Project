
#include "Game.h"
#include <QTimer>
#include "Enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QAction>
#include <iostream>
#include "mainWindow.h"
#include "nameInput.h"
#include <QAudioOutput>

#include <QDebug>
Game::Game(){

    resize(350,500);

    this->spawnRate=1000;

    title = new Title;
    dialog = new NameInput;
    MainWindow *mainWin = new MainWindow;
    int width = mainWin->frameGeometry().width();
    int height = mainWin->frameGeometry().height();

    QDesktopWidget wid;

    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();

    mainWin->setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),350,500);

    mainWin->setCentralWidget(title);
    mainWin->show();

    backMusic = new QSound("C:/Users/agros_000/Desktop/ProjectV2/Background2.wav",this);

    QObject::connect(title,SIGNAL(accepted()),dialog,SLOT(show()));
    QObject::connect(title,SIGNAL(rejected()),mainWin,SLOT(close()));
    QObject::connect(dialog,SIGNAL(accepted()),this,SLOT(playGame()));
    QObject::connect(dialog,SIGNAL(accepted()),mainWin,SLOT(close()));
    backMusic->play();

}

void Game::playGame(){

    QTimer *scoreTimer = new QTimer(this);
    QTimer *timeTimer = new QTimer(this);

scene = new QGraphicsScene();
scene->setSceneRect(0,0,350,500);
setBackgroundBrush(QBrush(QImage(":/images/StarPic.png")));
setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(350,500);

player = new Player();
//player->setRect(0,0,100,100);
player->setPos(175,250);
player->setFlag(QGraphicsItem::ItemIsFocusable);
player->setFocus();
scene->addItem(player);

score = new Score();
scene->addItem(score);
score->setPos(score->x(),score->y()+25);
health = new Health();
health->setPos(health->x(),health->y()+50);
scene->addItem(health);
time = new Time();
time->setPos(time->x(),time->y()+75);
scene->addItem(time);

QTimer *increseDif = new QTimer(this);
timer = new QTimer(this);
QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
timer->start(spawnRate);
QObject::connect(increseDif,SIGNAL(timeout()),this,SLOT(incrDiff()));
QObject::connect(scoreTimer,SIGNAL(timeout()),this,SLOT(updateScore()));
QObject::connect(timeTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
increseDif->start(10000);
scoreTimer->start(1000);
timeTimer->start(1000);

show();

}

void Game::incrDiff(){
    spawnRate=spawnRate-10;
    timer->start(spawnRate);
}

void Game::updateScore(){
    score->increase();
}

void Game::updateTime(){
    time->increase();
}

