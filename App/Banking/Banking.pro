TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    client.cpp \
    account.cpp \
    bank.cpp \
    interface.cpp

HEADERS += \
    client.h \
    account.h \
    bank.h \
    interface.h
