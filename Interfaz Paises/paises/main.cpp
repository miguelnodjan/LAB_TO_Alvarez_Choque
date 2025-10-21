#include <QApplication>
#include "countryinfo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CountryInfoWindow window;
    window.show();

    return app.exec();
}
