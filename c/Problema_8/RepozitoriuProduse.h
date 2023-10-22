//modul ce contine tot ce are legatura cu repozitoriul de produse

#ifndef REPOZITORIU_PRODUSE_H
#define REPOZITORIU_PRODUSE_H

#include "VectorDinamic.h"

typedef struct {
	VectorDinamic* lista_elemente;
}RepoProduse;

/*functie ce creaza un repozitoriu gol
Pre:->True
Post:->functia returneaza un pointer la un RepoProduse gol*/
RepoProduse* creaza_repo_produse();

/*functie ce distruge un RepoProduse
Pre:->r este un pointer la un RepoProduse
Post:->RepoProduse este distrus, memoria eliberata*/
void distruge_repo_produse(RepoProduse*r);

/*functie ce adauga un element intr-un repo de produse
Pre:->r este un pointer la un RepoProduse
	->prod este de tip produs si valid
Post:->daca nu exista un element cu acelasi id ca prod: se returneaza 0 si repo'=repo+{elem}
	 ->altfel daca exista un element cu acelasi id, ce are si acelasi tip,producator,model si pret: se returneaza 1 si cantitate_entitate_din_repo 
	   creste cu cantitate_entitate_de_adaugat
	 ->altfel: se returneaza 2*/
unsigned int adauga_element_repo_produse(RepoProduse* r, Produs* prod);

/*functie ce sterge un element din repo
Pre:->r este un pointer la un RepoProduse
	->id este de tip unsigned int si nenul
Post:->daca exista element cu idul id in repo: se returneaza 0 si repo=repo-{elem cu idul id}
	 ->altfel se returneaza 1*/
unsigned int sterge_element_repo_produse(RepoProduse* r, unsigned int id);

/*functie ce actualizeaza un element din repo
Pre:->r este un pointer la un RepoProduse
	->prod este un Produs valid
Post:->daca exista un element cu id-ul lui prod: returneaza 0 si actualizeaza in repo elementul cu id-ul lui prod cu datele lui prod
	 ->altfel returneaza 1
*/
unsigned int actualizeaza_element_repo_produse(RepoProduse* r, Produs* prod);

/*functie ce returneaza toate elementele unui repo
Pre:->r este un pointer la un RepoProduse
Post:->functia returneaza un pointer la un VectorDinamic cu elementele repo-ului
!!!VECOTRUL DINAMIC TREBUIE ELIBERAT CU distruge_vector_dinamic ULTERIOR*/
VectorDinamic* get_toate_elementele_repo(RepoProduse* r);

#endif REPOZITORIU_PRODUSE_H