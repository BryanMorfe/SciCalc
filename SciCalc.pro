#-------------------------------------------------
#
# Project created by QtCreator 2019-08-12T16:47:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SciCalc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        scbinaryfunction.cpp \
        scbinaryoperator.cpp \
        scevaluator.cpp \
        scexpression.cpp \
        scexpressionparser.cpp \
        scexpressionvalidator.cpp \
        scfunction.cpp \
        scinexpression.cpp \
        scoperand.cpp \
        scoperator.cpp \
        scoutputdisplay.cpp \
        scparsedexpression.cpp \
        scstore.cpp \
        sctoken.cpp \
        sctokenoperations.cpp \
        sctokenrepresentable.cpp \
        scunaryfunction.cpp \
        scunaryoperator.cpp \
        scwindow.cpp

HEADERS += \
        scbinaryfunction.h \
        scbinaryoperator.h \
        scevaluator.h \
        scexpression.h \
        scexpressionparser.h \
        scexpressionvalidator.h \
        scfunction.h \
        scinexpression.h \
        scoperand.h \
        scoperator.h \
        scoutputdisplay.h \
        scparsedexpression.h \
        scstore.h \
        sctoken.h \
        sctokenoperations.h \
        sctokenrepresentable.h \
        sctokentypes.h \
        scunaryfunction.h \
        scunaryoperator.h \
        scwindow.h

FORMS += \
    scwindow.ui

QMAKE_LIBFLAGS += \VERBOSE

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
