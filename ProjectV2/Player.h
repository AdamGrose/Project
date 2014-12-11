#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "Game.h"

class Player : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    bool bulAccept;
    void setBool(bool n){bulAccept = n;};
private:
    QTimer *bulletTimer;
public slots:
    void spawn();
    void enableBullet();
};

#endif // MYRECT_H
