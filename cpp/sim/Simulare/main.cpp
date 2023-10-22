#include <QtWidgets/QApplication>
#include "GUICarti.h"
#include "Teste.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ruleaza_teste();
    RepoCarti repo{ "date/carti.txt" };
    ValidatorCarti val;
    ServiciuCarti serv{ repo,val };
    GUICarti gui{ serv };
    gui.show();
    /*QWidget w;
    w.show();*/
    return a.exec();
}
