//Modul principal ce porneste aplicatia


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "TesteMain.h"
#include "RepozitoriuProduse.h"
#include "ServiciuProduse.h"
#include "UIProduse.h"


/*functie ce ruleaza aplicatia
Pre:->True
Post:->True*/
int main()
{
	ruleaza_toate_testele();
	RepoProduse* repo = creaza_repo_produse();
	ServiciuProduse* serv = creeaza_serviciu_produse(repo);
	UIProduse* uip = creaza_uiproduse(serv);
	ruleaza_uip(uip);
	distruge_uiproduse(uip);
	distruge_serviciu_produse(serv);
	distruge_repo_produse(repo);
	_CrtDumpMemoryLeaks();
	return 0;
}