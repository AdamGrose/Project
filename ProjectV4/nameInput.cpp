#include "nameInput.h"
#include <QRegExp>
#include <QRegExpValidator>
#include <QLayout>


NameInput::NameInput(){
    resize(200,150);
    label = new QLabel;
    label->setText("Input initials. 3 letters or numbers only");
    lineEdit = new QLineEdit;
    playButton = new QPushButton;
    playButton->setText("PLAY");
    playButton->setEnabled(false);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(playButton);

    setLayout(layout);

    QRegExp regExp("[A-Za-z0-9]{3}");
    lineEdit->setValidator(new QRegExpValidator(regExp,this));

    QObject::connect(playButton,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(lineEditTextChange()));

}

void NameInput::lineEditTextChange(){
    playButton->setEnabled(lineEdit->hasAcceptableInput());
}
