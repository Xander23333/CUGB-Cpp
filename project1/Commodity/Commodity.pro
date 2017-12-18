TEMPLATE = app
CONFIG += console c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    function.cpp \
    data.cpp \
    help.cpp

HEADERS += \
    function.h \
    datatype.h \
    data.h \
    help.h \
    header.h
