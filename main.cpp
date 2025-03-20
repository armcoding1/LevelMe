#include <QApplication>
#include "app_initializer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    app_initializer initializer;
    initializer.initialize();

    return a.exec();
}
