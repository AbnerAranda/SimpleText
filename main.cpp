#include "simpletext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleText w;
    w.show();
    return a.exec();
}
