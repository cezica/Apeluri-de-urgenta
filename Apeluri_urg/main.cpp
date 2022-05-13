#include "primapag.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrimaPag w;
    w.show();
    Conexiune* d = Conexiune::getinstance();
    return a.exec();
}
