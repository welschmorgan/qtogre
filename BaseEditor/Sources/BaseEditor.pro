#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T18:44:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#-------------------------------------------------
# Base Variables
#-------------------------------------------------
TARGET = BaseEditor
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

CONFIG += debug_and_release build_all console
CONFIG(debug, debug|release) {
    TARGET = BaseEditor_d
    LIBS += -lOgreMain_d
} else {
    TARGET = BaseEditor
    LIBS += -lOgreMain
}
INCLUDEPATH += /usr/include/
INCLUDEPATH += /usr/include/OGRE
INCLUDEPATH += /usr/include/OIS
INCLUDEPATH += /usr/include/boost
INCLUDEPATH += include

SOURCES += \
    source/application.cpp \
    source/main.cpp \
    source/valuetype.cpp \
    source/wizard/newitemwizard.cpp \
    source/project/projectitem.cpp \
    source/project/projectitemconfig.cpp \
    source/project/projectstore.cpp \
    source/project/projectwidget.cpp


HEADERS  += \
    application.h \
    include/application.h \
    include/platform.h \
    include/valuetype.h \
    include/enablers.hpp \
    include/wizards/newitemwizard.h \
    include/project/projectitem.h \
    include/project/projectitemconfig.h \
    include/project/projectstore.h \
    include/project/projectwidget.h

FORMS    += forms/mainwindow.ui \
    forms/newitemwizard.ui

RESOURCES += resources/resources.qrc
