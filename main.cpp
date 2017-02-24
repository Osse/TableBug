#include "tablebugdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TableBugDialog w;
    w.show();

    return a.exec();
}
