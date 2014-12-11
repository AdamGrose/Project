#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include <typeinfo>

extern Game * game;
#include <QDebug>
Bullet::Bullet(){

    setPixmap(QPixmap(":/images/Bullet.png"));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(25);
}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);
    if(pos().y() + 261 <0){
        scene()->removeItem(this);
        delete this;
    }
}
