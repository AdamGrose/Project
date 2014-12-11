#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TitleScreen.h"
#include "Game.h"

class MainWindow : public QMainWindow{
public:
    MainWindow();
private:
    QMenu *fileMenu;
    QAction *closeAction;
    QAction *highScoresAction;
    QAction *playGameAction;
};

#endif // MAINWINDOW_H
