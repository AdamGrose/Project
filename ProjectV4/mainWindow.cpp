
#include "mainWindow.h"
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



    closeAction = new QAction("&Close",this);
    connect(closeAction,SIGNAL(triggered()),this,SLOT(close()));
    highScoresAction = new QAction("&HIGH SCORES",this);
    connect(highScoresAction,SIGNAL(triggered()),this,SLOT(ScoreProcess()));

    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(closeAction);
    fileMenu->addAction(highScoresAction);

}

void MainWindow::ScoreProcess(){
    QDir dir;
    QProcess *process = new QProcess;
    process->start(dir.absolutePath() + "/files/HighScoreProcess.exe");
}
