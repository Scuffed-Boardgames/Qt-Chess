QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ai.cpp \
    bishop.cpp \
    board.cpp \
    boardview.cpp \
    chess.cpp \
    game.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    pawn.cpp \
    piece.cpp \
    player.cpp \
    queen.cpp \
    rook.cpp \
    tile.cpp

HEADERS += \
    ai.h \
    bishop.h \
    board.h \
    boardview.h \
    chess.h \
    colour.h \
    error.h \
    game.h \
    king.h \
    knight.h \
    pawn.h \
    piece.h \
    player.h \
    queen.h \
    rook.h \
    tile.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \

RESOURCES += \
    pieces.qrc
