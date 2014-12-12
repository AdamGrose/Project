#include "TitleScreen.h"
#include "Game.h"
#include "nameInput.h"
#include <QPixmap>
#include <QLayout>
#include <QProcess>

extern Game *game;
Title::Title(){
    resize(400,400);

    setWindowTitle("Space Game");
    QPushButton *start = new QPushButton(this);
    start->setText("START");
    QPushButton *close = new QPushButton(this);
    close->setText("CLOSE");
    QPushButton *Scores = new QPushButton(this);
    Scores->setText("HIGH SCORES");
    QLabel *titleFont = new QLabel;
    titleFont->setPixmap(QPixmap(":/images/AsteroidRun.png"));

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(start);
    buttonLayout->addWidget(Scores);
    buttonLayout->addWidget(close);

    QVBoxLayout *titleLayout = new QVBoxLayout;
    titleLayout->addWidget(titleFont);
    titleLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    QObject::connect(start,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(close,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(Scores,SIGNAL(clicked()),this,SLOT(startScoreProcess()));

}

void Title::startScoreProcess(){
    QDir dir;
    QProcess *process = new QProcess;
    dir.cdUp();
    process->start(dir.absolutePath() + "/ProjectV4/files/HighScoreProcess.exe");
}
