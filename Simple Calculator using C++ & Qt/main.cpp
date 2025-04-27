#include "calculator.h"
#include <QApplication>
#include <QIcon>  // <-- Include QIcon

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the application icon (from your Qt resource file)
    a.setWindowIcon(QIcon(":/icon.ico"));

    Calculator w;
    w.show();
    return a.exec();
}
