TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Card.cpp \
        CardDeck.cpp \
        Table.cpp \
        TheGame.cpp \
        main.cpp

HEADERS += \
    Card.h \
    CardDeck.h \
    Table.h \
    TheGame.h
