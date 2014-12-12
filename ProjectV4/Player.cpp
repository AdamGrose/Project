#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>

extern Game *game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/playerShip.png"));

    bulletTimer = new QTimer(this);
    setBool(true);
    QObject::connect(bulletTimer,SIGNAL(timeout()),this,SLOT(enableBullet()));
}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        if(pos().x()>0){
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){

        if(pos().x() + 40 < 350){
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Up){

        if(pos().y() > 0){
            setPos(x(),y()-10);
        }
    }
    else if(event->key() == Qt::Key_Down){

        if(pos().y() + 80 < 600){
            setPos(x(),y()+10);
        }
    }
    else if(event->key() == Qt::Key_Space && bulAccept == true){
            Bullet *bullet = new Bullet();
            bullet->setPos(x()-240,y()-181);
            scene()->addItem(bullet);
            setBool(false);
            bulletTimer->start(2000);
        }
    else if(event->key() == Qt::Key_Escape){
        game->close();
    }


}

void Player::spawn(){

    Enemy *enemy = new Enemy;
    scene()->addItem(enemy);
}

void Player::enableBullet(){
    setBool(true);
    bulletTimer->stop();
}
