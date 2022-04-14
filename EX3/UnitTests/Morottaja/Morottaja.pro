#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T15:59:09
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = morottajatest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += morottajatest.cc \
    ../../WelcomeToTampere/morottaja.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../WelcomeToTampere/morottaja.hh

INCLUDEPATH += \
            ../../WelcomeToTampere/
