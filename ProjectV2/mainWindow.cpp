
#include "mainWindow.h"
#include "HighScores_Dialog.h"
#include "nameInput.h"
#include "Game.h"
#include "Game.h"

extern Game *game;
MainWindow::MainWindow(){

    QPixmap bg(":/images/projectTitle.jpg");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);


    HighScores *scores = new HighScores;


    closeAction = new QAction("&Close",this);
    connect(closeAction,SIGNAL(triggered()),this,SLOT(close()));
    highScoresAction = new QAction("&HIGH SCORES",this);
    connect(highScoresAction,SIGNAL(triggered()),scores,SLOT(show()));

    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(closeAction);
    fileMenu->addAction(highScoresAction);

}
