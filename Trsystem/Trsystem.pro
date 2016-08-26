#-------------------------------------------------
#
# Project created by QtCreator 2015-01-25T12:12:31
#
#-------------------------------------------------

QT       += core gui
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Trsystem
TEMPLATE = app


SOURCES += main.cpp\
        systemlog.cpp \
    cmysql.cpp \
    management.cpp \
    adoctor.cpp \
    disease.cpp \
    medicine.cpp \
    logm.cpp \
    guanyu.cpp \
    beiwanglu.cpp \
    zhishiku.cpp \
    check.cpp \
    zhanghao.cpp \
    print.cpp \
    riqi.cpp \
    showpic.cpp \
    changeuser.cpp

HEADERS  += systemlog.h \
    cmysql.h \
    management.h \
    adoctor.h \
    disease.h \
    medicine.h \
    logm.h \
    guanyu.h \
    beiwanglu.h \
    zhishiku.h \
    check.h \
    zhanghao.h \
    print.h \
    riqi.h \
    showpic.h \
    changeuser.h

FORMS    += systemlog.ui \
    management.ui \
    adoctor.ui \
    disease.ui \
    medicine.ui \
    logm.ui \
    guanyu.ui \
    beiwanglu.ui \
    zhishiku.ui \
    check.ui \
    zhanghao.ui \
    print.ui \
    riqi.ui \
    changeuser.ui

RESOURCES += \
    Image.qrc
