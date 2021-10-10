QT += core testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_wordtest.cpp \
    main.cpp \
    tst_word1.cpp  \
../chat/word.cpp


HEADERS += \
../chat/word.h
