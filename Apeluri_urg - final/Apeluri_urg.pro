QT       += core gui
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CerereStergeri.cpp \
    addisp.cpp \
    apel.cpp \
    cerereapel.cpp \
    cereredisp.cpp \
    cerereinreg.cpp \
    cerereistoricadm.cpp \
    cerereistoriccl.cpp \
    cerereistoricdisp.cpp \
    cererelog.cpp \
    cerereutilz.cpp \
    detalii_suplimentare.cpp \
    detaliiapel.cpp \
    icerere.cpp \
    main.cpp \
    primapag.cpp

HEADERS += \
    CerereStergeri.h \
    addisp.h \
    apel.h \
    cerereapel.h \
    cereredisp.h \
    cerereinreg.h \
    cerereistoricadm.h \
    cerereistoriccl.h \
    cerereistoricdisp.h \
    cererelog.h \
    cerereutilz.h \
    detalii_suplimentare.h \
    detaliiapel.h \
    icerere.h \
    primapag.h \
    tcpclient.h

FORMS += \
    addisp.ui \
    apel.ui \
    detalii_suplimentare.ui \
    detaliiapel.ui \
    primapag.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon_window.png

RESOURCES += \
    resurse.qrc
