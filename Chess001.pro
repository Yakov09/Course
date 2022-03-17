QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    chessboard.cpp \
    chessfield.cpp \
    engine.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraphicsview.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp \
    test_bishop.cpp \
    test_chessboard.cpp \
    test_king.cpp \
    test_knight.cpp \
    test_pawn.cpp \
    test_queen.cpp \
    test_rook.cpp

HEADERS += \
    bishop.h \
    chessboard.h \
    chessfield.h \
    engine.h \
    king.h \
    knight.h \
    mainwindow.h \
    mygraphicsview.h \
    pawn.h \
    piece.h \
    queen.h \
    rook.h \
    test_bishop.h \
    test_chessboard.h \
    test_king.h \
    test_knight.h \
    test_pawn.h \
    test_queen.h \
    test_rook.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
