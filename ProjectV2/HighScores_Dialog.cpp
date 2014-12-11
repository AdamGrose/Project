#include "HighScores_Dialog.h"
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QFile>
#include <QTextStream>

#include <QDebug>

HighScores::HighScores(){
    resize(230,220);

    QLabel *Label1 = new QLabel;
    QLabel *Label2 = new QLabel;
    QLabel *Label3 = new QLabel;
    QLabel *LabelName1 = new QLabel;
    QLabel *LabelName2 = new QLabel;
    QLabel *LabelName3 = new QLabel;
    QLabel *LabelScore1 = new QLabel;
    QLabel *LabelScore2 = new QLabel;
    QLabel *LabelScore3 = new QLabel;
    QLabel *Points = new QLabel;
    QLabel *Times = new QLabel;
    QLabel *Name = new QLabel;

    QFile inputFile("C:/Users/agros_000/Desktop/ProjectV2/HighScores.txt");
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

    Points->setText("POINTS   ");
    Points->setStyleSheet("font: 15pt; color: black;");
    Times->setText("TIME");
    Times->setStyleSheet("font: 15pt; color: black;");
    Name->setText("NAME  ");
    Name->setStyleSheet("font: 15pt; color: black;");

    Label1->setNum(scores[0]);
    Label1->setStyleSheet("font: 15pt; color: black;");
    Label2->setNum(scores[1]);
    Label2->setStyleSheet("font: 15pt; color: black;");
    Label3->setNum(scores[2]);
    Label3->setStyleSheet("font: 15pt; color: black;");
    LabelName1->setText(names[0]);
    LabelName1->setStyleSheet("font: 15pt; color: black;");
    LabelName2->setText(names[1]);
    LabelName2->setStyleSheet("font: 15pt; color: black;");
    LabelName3->setText(names[2]);
    LabelName3->setStyleSheet("font: 15pt; color: black;");
    LabelScore1->setNum(times[0]);
    LabelScore1->setStyleSheet("font: 15pt; color: black;");
    LabelScore2->setNum(times[1]);
    LabelScore2->setStyleSheet("font: 15pt; color: black;");
    LabelScore3->setNum(times[2]);
    LabelScore3->setStyleSheet("font: 15pt; color: black;");

    setWindowTitle("HIGH SCORES");
    QPushButton *close = new QPushButton;
    close->setText("CLOSE");
    QPixmap bg(":/images/ScoreImage.jpg");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);

    QVBoxLayout *set1 = new QVBoxLayout;
    set1->addWidget(Points);
    set1->addWidget(Label1);
    set1->addWidget(Label2);
    set1->addWidget(Label3);

    QVBoxLayout *set2 = new QVBoxLayout;
    set2->addWidget(Name);
    set2->addWidget(LabelName1);
    set2->addWidget(LabelName2);
    set2->addWidget(LabelName3);

    QVBoxLayout *set3 = new QVBoxLayout;
    set3->addWidget(Times);
    set3->addWidget(LabelScore1);
    set3->addWidget(LabelScore2);
    set3->addWidget(LabelScore3);

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(close);

    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addLayout(set1);
    titleLayout->addLayout(set2);
    titleLayout->addLayout(set3);
    titleLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    QObject::connect(close,SIGNAL(clicked()),this,SLOT(close()));
}
