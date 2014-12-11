#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QObject>
#include <QString>
#include <QSound>
#include "Bullet.h"
#include "Score.h"
#include "Health.h"
#include "Game.h"
#include "Player.h"
#include "TitleScreen.h"
#include "nameInput.h"
#include "Time.h"
#include <QMenu>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    Score *score;
    Health *health;
    Time *time;
    Title *title;
    NameInput *dialog;
    QSound *backMusic;
private:
    int spawnRate;
    QTimer *timer;
public slots:
    void playGame();
    void incrDiff();
    void updateScore();
    void updateTime();
};

#endif // GAME_H
