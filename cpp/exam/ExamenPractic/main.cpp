#include <QtWidgets/QApplication>
#include "GUITask.h"
#include "Testing.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testAll();
    RepoTask repo{ "date/tasks.txt" };
    ValidatorTask val;
    ServiciuTask serv{ val,repo };
    GUITask gui{ serv };
    gui.show();
    return a.exec();
}
