#ifndef NAMEINPUT_H
#define NAMEINPUT_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class NameInput : public QDialog{
    Q_OBJECT
public:
    NameInput();
    QLineEdit *lineEdit;
private:
    QLabel *label;
    QPushButton *playButton;
private slots:
    void lineEditTextChange();
};

#endif // NAMEINPUT_H
