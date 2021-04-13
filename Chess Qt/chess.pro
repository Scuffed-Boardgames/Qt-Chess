QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Chess/Chess/ai.cpp \
    ../Chess/Chess/bishop.cpp \
    ../Chess/Chess/board.cpp \
    ../Chess/Chess/game.cpp \
    ../Chess/Chess/king.cpp \
    ../Chess/Chess/knight.cpp \
    ../Chess/Chess/pawn.cpp \
    ../Chess/Chess/piece.cpp \
    ../Chess/Chess/player.cpp \
    ../Chess/Chess/queen.cpp \
    ../Chess/Chess/rook.cpp \
    ../Chess/Chess/tile.cpp \
    chess.cpp \
    customgraphics.cpp \
    main.cpp

HEADERS += \
    ../Chess/Chess/ai.h \
    ../Chess/Chess/bishop.h \
    ../Chess/Chess/board.h \
    ../Chess/Chess/colour.h \
    ../Chess/Chess/error.h \
    ../Chess/Chess/game.h \
    ../Chess/Chess/king.h \
    ../Chess/Chess/knight.h \
    ../Chess/Chess/pawn.h \
    ../Chess/Chess/piece.h \
    ../Chess/Chess/player.h \
    ../Chess/Chess/queen.h \
    ../Chess/Chess/rook.h \
    ../Chess/Chess/tile.h \
    chess.h \
    customgraphics.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Pictures/Chess pieces/pawn black.png \
    ../../Pictures/Chess pieces/pawn white.png

RESOURCES += \
    pieces.qrc
