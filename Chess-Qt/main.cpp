#include <QApplication>
#include "chess.h"
#include "game.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    srand((unsigned)time(NULL));
    chess w(nullptr);
    w.show();
    return a.exec();

}

