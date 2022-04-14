TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        date.cc \
        fraction.cc \
        main.cpp \
        string.cc \
        vector.cc

DISTFILES += \
    Doxyfile

HEADERS += \
    date.hh \
    fraction.hh \
    string.hh \
    vector.hh
