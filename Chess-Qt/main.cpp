#include <QApplication>
#include "chess.h"
#include "game.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game k;
    chess w(nullptr, k.giveBoard());
    w.show();
    return a.exec();
}
