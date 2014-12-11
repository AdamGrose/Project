#include "Time.h"
#include <QFont>


Time::Time(QGraphicsItem *parent): QGraphicsTextItem(parent){

    time = 0;

    setPlainText(QString("Time: ") + QString::number(time) + QString(" Sec"));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));
}

void Time::increase(){
time++;
setPlainText(QString("Time: ") + QString::number(time) + QString(" Sec"));
}

int Time::getTime(){
return time;
}
