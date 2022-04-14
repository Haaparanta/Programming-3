QT += testlib
QT -= gui

TARGET = tst_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test.cpp \
    ../../WelcomeToTampere/baddate.cc \
    ../../WelcomeToTampere/date.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../WelcomeToTampere/baddate.hh \
    ../../WelcomeToTampere/date.hh

INCLUDEPATH += \
    ../../WelcomeToTampere/

DEPENDPATH  +=
