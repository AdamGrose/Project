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
    nameInput.h \
    Time.h \
    mainWindow.h

RESOURCES += \
    res.qrc

OTHER_FILES += \
    files/Background2.wav \
    files/HighScores.txt \
    files/HighScoreProcess.exe

copydata.commands = $(COPY_DIR) \"$$PWD/files\" \"$$OUT_PWD/files\"
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
