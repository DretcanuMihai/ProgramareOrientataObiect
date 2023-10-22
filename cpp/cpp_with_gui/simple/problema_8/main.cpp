#include <QtWidgets/QApplication>
#include "TesteLocatar.h"

#include "GUImain.h"
#include "ServiciuLocatari.h"
//#include "RepozitoriuLocatari.h"
#include "RepozitoriuLocatariFisier.h"
//#include "RepozitoriuLocatariSp.h"
#include "ValidatorLocatar.h"
#include "ListaNotificare.h"

int main(int argc, char *argv[])
{
    {
        TesteLocatar teste;
        teste.ruleaza_toate_testele();
    }
    {
        QApplication a(argc, argv);

        //RepozitoriuLocatari repo;
        RepozitoriuLocatariFisier repo("repo_files/locatari.txt");
        //RepozitoriuLocatariSp repo(0.5);
        ListaNotificare lista(repo);
        ValidatorLocatar validator;
        ServiciuLocatari serv(repo, validator, lista);
        GUImain gui(serv,lista, a);
        gui.show();
        a.exec();
    }

    return 0;
}
