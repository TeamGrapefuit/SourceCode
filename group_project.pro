#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T13:52:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4):
{
    QT += widgets
    QT += printsupport
}

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphdialog.cpp \
    listclass.cpp \
    plusminuslist.cpp \
    attributeretriever.cpp \
    Director.cpp \
    Grant_rowObject.cpp \
    GrantRowBuilder.cpp \
    rowObject.cpp \
    RowObjectArray.cpp \
    PresentationRowBuilder.cpp \
    PublicationRowBuilder.cpp \
    TeachingRowBuilder.cpp \
    Pres_rowObject.cpp \
    Pub_rowObject.cpp \
    Teach_rowObject.cpp \
    ListBuilder.cpp \
    barchartdialog.cpp \
    graphclass.cpp \
    piechartdialog.cpp \
    ErrorChecker.cpp \
    Pres_ListBuilder.cpp \
    Pub_ListBuilder.cpp \
    Teach_ListBuilder.cpp

HEADERS  += mainwindow.h \
    graphdialog.h \
    listclass.h \
    plusminuslist.h \
    attributeretriever.h \
    Director.h \
    Grant_rowObject.h \
    GrantRowBuilder.h \
    rowObject.h \
    RowObjectArray.h \
    ColIndex.h \
    PresentationRowBuilder.h \
    Pub_rowObject.h \
    PublicationRowBuilder.h \
    Teach_rowObject.h \
    TeachingRowBuilder.h \
    Pres_rowObject.h \
    ListBuilder.h \
    barchartdialog.h \
    graphclass.h \
    piechartdialog.h \
    ErrorChecker.h \
    Pres_ListBuilder.h \
    Pub_ListBuilder.h \
    Teach_ListBuilder.h

FORMS    += mainwindow.ui \
    graphdialog.ui

DISTFILES += \
    Grants_changed.csv
