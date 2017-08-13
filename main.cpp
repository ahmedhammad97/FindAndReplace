#include "findandreplace.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindAndReplace w;
    w.show();

    return a.exec();
}
