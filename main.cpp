#include "MLImageDenoiser.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MLImageDenoiser w;
    w.show();
    return a.exec();
}
