#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TitleScreen.h"
#include "Game.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow();
private:
    QMenu *fileMenu;
    QAction *closeAction;
    QAction *highScoresAction;
    QAction *playGameAction;
private slots:
    void ScoreProcess();
};

#endif // MAINWINDOW_H
