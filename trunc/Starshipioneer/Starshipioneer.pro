#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T03:28:43
#
#-------------------------------------------------

QT       += opengl

TARGET = Starshipioneer
TEMPLATE = app

SOURCES += main.cpp \
    factory.cpp \
    drawable.cpp \
    mainwindow.cpp \
    texturemgr.cpp \
    timer.cpp \
    objmgr.cpp \
    gameobj.cpp \
    worldobj.cpp \
    gamemgr.cpp \
    screenmgr.cpp \
    screen.cpp \
    entitymgr.cpp \
    inputhandler.cpp \
    starship.cpp \
    inputmgr.cpp

HEADERS  += \
    factory.h \
    drawable.h \
    mainwindow.h \
    texturemgr.h \
    timer.h \
    objmgr.h \
    gameobj.h \
    worldobj.h \
    gamemgr.h \
    screenmgr.h \
    screen.h \
    entitymgr.h \
    inputhandler.h \
    basics.h \
    starship.h \
    inputmgr.h

RESOURCES += res.qrc

LIBS += -lglut -lSOIL -lGLU -lglfw -lGLEW

