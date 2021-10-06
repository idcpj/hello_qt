QT += core testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_wordtest.cpp


HEADERS += \
../chat/word.h

SOURCES += \
../chat/word.cpp
