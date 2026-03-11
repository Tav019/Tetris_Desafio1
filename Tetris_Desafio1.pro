TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        chips.cpp \
        game.cpp \
        main.cpp

HEADERS += \
    board.h \
    chips.h \
    game.h
