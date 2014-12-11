#-------------------------------------------------
#
# Project created by QtCreator 2014-12-04T11:39:26
#
#-------------------------------------------------

QT       += core gui
QT        += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project1
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Score.cpp \
    Player.cpp \
    Game.cpp \
    Health.cpp \
    TitleScreen.cpp \
    HighScores_Dialog.cpp \
    EndGame.cpp \
    nameInput.cpp \
    Time.cpp \
    mainWindow.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Score.h \
    Game.h \
    Player.h \
    Health.h \
    TitleScreen.h \
    HighScores_Dialog.h \
    EndGame.h \
    nameInput.h \
    Time.h \
    mainWindow.h \
    GameInstance.h

RESOURCES += \
    res.qrc

OTHER_FILES += \
    Background2.wav \
    HighScores.txt \
    crash.wav
