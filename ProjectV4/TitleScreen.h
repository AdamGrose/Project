#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QtGui>
#include <QObject>

class Title : public QDialog{
    Q_OBJECT

public:
    Title();
private slots:
    void startScoreProcess();
};

#endif // TITLESCREEN_H

