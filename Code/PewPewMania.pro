#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T11:37:00
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PewPewMania
TEMPLATE = app


SOURCES +=\
    Enemy.cpp \
    Game.cpp \
    main.cpp \
    Player.cpp \
    mediaplayer.cpp \
    Bullet.cpp

HEADERS  += \
    Enemy.h \
    Player.h \
    Game.h \
    mediaplayer.h \
    Bullet.h
