#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "TesteLocatar.h"
//#include "RepozitoriuLocatari.h"
#include "RepozitoriuLocatariFisier.h"
//#include "RepozitoriuLocatariSp.h"
#include "ValidatorLocatar.h"
#include "ServiciuLocatari.h"
#include "ListaNotificare.h"
#include "UILocatari.h"

int main()
{
	{
		TesteLocatar testing;
		testing.ruleaza_toate_testele();

		//RepozitoriuLocatari repo;
		RepozitoriuLocatariFisier repo("repo_files/locatari.txt");
		//RepozitoriuLocatariSp repo(0.5);
		ValidatorLocatar validator;
		ListaNotificare lista_notificare(repo);
		ServiciuLocatari serv(repo, validator,lista_notificare);
		UILocatari uil(serv);
		uil.ruleaza();
	}
	
	_CrtDumpMemoryLeaks();

	return 0;
}