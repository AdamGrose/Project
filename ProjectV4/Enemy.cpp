#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Player.h"
#include "Game.h"
#include <typeinfo>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QString>

extern Game *game;
#include <QDebug>
Enemy::Enemy(){
    int random_number2 = rand() % 5 + 1;
    switch(random_number2){
    case 1:{
        setPixmap(QPixmap(":/images/ast3.png"));
        break;
    }
    case 2:{
        setPixmap(QPixmap(":/images/ast3.png"));
        break;
    }
    case 3:{
        setPixmap(QPixmap(":/images/ast3.png"));
        break;
    }
    case 4:{
        setPixmap(QPixmap(":/images/ast3.png"));
        break;
    }
    case 5:{
        setPixmap(QPixmap(":/images/ast1.png"));
        break;
    }
    }

    int random_number = rand() % 300+20;
    setPos(random_number,-40);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(25);
}

void Enemy::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            game->health->decrease();
            if (game->health->getHealth() == 0){
                updateFile();
                game->close();

            }
            game->player->setPos(game->player->pos().x(),game->player->pos().y()+25);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(),y()+5);
    if(pos().y() > 600){
        delete this;
    }

}

void Enemy::updateFile(){

    QDir dir;

    qDebug() << dir.absolutePath();
    dir.cdUp();

    QString name(game->dialog->lineEdit->text());

        QFile inputFile(dir.absolutePath() + "/ProjectV4/files/HighScores.txt");
        inputFile.open(QIODevice::ReadWrite);

        if(!inputFile.isOpen()){
            qDebug() << "- Error, unable to open" << "Scores.txt" << "for output";
        }

        QTextStream inStream(&inputFile);

    int scores[3];
    int times[3];
    QString names[3];
    inStream >> names[0] >> scores[0] >> times[0] >> names[1] >> scores[1]
            >> times[1] >> names[2] >> scores[2] >> times[2];
    inputFile.close();


    QFile outputFile(dir.absolutePath() + "/ProjectV4/files/HighScores.txt");
    outputFile.open(QIODevice::ReadWrite | QIODevice::Truncate);

    if(!outputFile.isOpen()){
        qDebug() << "- Error, unable to open" << "Scores.txt" << "for output";
    }

    QTextStream outStream(&outputFile);


    for(int i = 0; i<3; i++){
        if(game->score->getScore() > scores[i]){
            switch(i){
            case 0:{
                QString NewName1(name);
                QString NewName2(names[0]);
                QString NewName3(names[1]);
                scores[i+2] = scores[i+1];
                times[i+2] = times[i+1];
                scores[i+1] = scores[i];
                times[i+1] = times[i];
                scores[i] = game->score->getScore();
                times[i] = game->time->getTime();
                outStream << NewName1 << "\n" << scores[0] << "\n" << times[0] << '\n' << NewName2
                          << '\n' << scores[1] << "\n" << times[1] << '\n' << NewName3
                          << "\n" << scores[2] << "\n" << times[2];
                break;
            }case 1:{
                QString NewName1(names[0]);
                QString NewName2(name);
                QString NewName3(names[1]);
                scores[i+1] = scores[i];
                times[i+1] = times[i];
                scores[i] = game->score->getScore();
                times[i] = game->time->getTime();
                outStream << NewName1 << "\n" << scores[0] << "\n" << times[0] << '\n' << NewName2
                          << '\n' << scores[1] << "\n" << times[1] << '\n' << NewName3
                          << "\n" << scores[2] << "\n" << times[2];
                break;
            }case 2:{
                QString NewName1(names[0]);
                QString NewName2(names[1]);
                QString NewName3(name);
                scores[i] = game->score->getScore();
                times[i] = game->time->getTime();
                outStream << NewName1 << "\n" << scores[0] << "\n" << times[0] << '\n' << NewName2
                          << '\n' << scores[1] << "\n" << times[1] << '\n' << NewName3
                          << "\n" << scores[2] << "\n" << times[2];
                break;
            }
            }
            break;
        }
    }

        /*QFile outputFile("C:/Users/agros_000/Desktop/Project1/HighScores.txt");
        outputFile.open(QIODevice::ReadWrite | QIODevice::Truncate);

        if(!outputFile.isOpen()){
            qDebug() << "- Error, unable to open" << "Scores.txt" << "for output";
        }

        QTextStream outStream(&outputFile);
*/
    //outStream << NewName1 << "\n" << scores[0] << "\n" << NewName2 << '\n' << scores[1] << '\n'
      //                    << NewName2 << "\n" << scores[2];

    outputFile.close();


}
