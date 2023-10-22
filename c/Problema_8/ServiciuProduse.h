///modul ce contine tot ce are legatura cu service-ul de produse

#ifndef _SERVICIU_PRODUSE_H
#define _SERVICIU_PRODUSE_H

#include "RepozitoriuProduse.h"
#include "ValidatorProdus.h"
#include "VectorDinamic.h"

typedef struct {
	RepoProduse* repo;
}ServiciuProduse;

/*creaza un ServiciuProduse
Pre:->repo este un pointer la un RepoProduse
Post:->returneaza un pointer la un ServiciuProduse initializat cu repo*/
ServiciuProduse* creeaza_serviciu_produse(RepoProduse* repo);

/*distruge un ServiciuProduse
Pre:->serv este un pointer la un ServProduse
Post:->serv este distrus, memoria eliberata*/
void distruge_serviciu_produse(ServiciuProduse* serv);

/*adauga un element in ServiciuProduse
Pre:->serv este pointer la un ServiciuProduse
	->id este de tip unsigned int
	->tip este pointer la char de maxim 256 de caractere '\0' inclusiv
	->producator este pointer la char de maxim 256 de caractere '\0' inclusiv
	->model este pointer la char de maxim 256 de caractere '\0' inclusiv
	->pret este de tip double
	->cantitate este de tip unsigned int
Post:->daca datele introduse formeaza un element invalid se returneaza un unsigned int intre 1 si 63 ce reprezinta eroarea, fiecare bit semnificand
												astfel: ->0 daca id-ul este 0
														->1 daca tipul este un sir vid
														->2 daca producatorul este un sir vid
														->3 daca modelul este un sir vid
														->4 daca pretul este negativ sau 0
														->5 daca cantitatea este 0
     ->altfel daca elementul introdus are corespondent in repo ce are acelasi id, dar una din restul datelor, cu exceptia cantitatii difera,
	   se va returna 65
	 ->altfel daca elementul introdus are corespondent in repo cu acelasi id, se va returna 64 si cantiate'=cantitate_veche+cantitate_noua
	 ->altfel se va returna 0 si repo=repo+{elem}*/
unsigned int adauga_element_serviciu_produse(ServiciuProduse* serv, unsigned int id, char* tip, char* producator, char* model, double pret, unsigned int cantitate);


/*actualizeaza un element din ServiciuProduse
Pre:->serv este pointer la un SerivciuProduse
	->id este de tip unsigned int
	->opt este de tip unsigned int, egal cu 0 sau 1 (0 pentru pret, 1 pentru cantitate)
	->valoare este un pointer de void ce arata la valoarea noua cu care se updateaza
Post:->daca id-ul sau tipul de data introdus corespunzator optiunii alese este invalid, se va returna un unsigned int intre 1 si 64 unde bitii sunt
	   setati cu 1 astfel:->0 daca id-ul este 0
						  ->4 daca pretul este negativ sau 0
						  ->5 daca cantitatea este 0*
	 ->altfel daca nu exista un element cu id-ul dat se va returna un unsigned int egal cu 64
	 ->altfel se va actualiza elementul respectiv cu noua valoarea impusa si se va returna 0;
*/
unsigned int actualizeaza_element_serviciu_produse_opt(ServiciuProduse* serv,unsigned int id, unsigned int opt, void* valoare);


/*sterge un element din ServiciuProduse
Pre:->serv este pointer la un ServiciuProduse
	->id este de tip unsigned int;
Post:->daca id-ul este 0 se va returna 1;
	 ->altfel daca nu exista un element cu id-ul respectiv se va returna 64;
	 ->altfel repo=repo-{elem} si se va returna 0
*/
unsigned int sterge_element_serviciu_produse(ServiciuProduse* serv, unsigned int id);

/*returneaza un VectorDinamic cu toate elemente din repo-ul Serviciului
Pre:->serv este pointer la un ServiciuProduse
Post:->se va returna un pointer la un VectorDinamic cu elementele din repo
!!!VECTORULDINAMIC TREBUIE DISTRUS CU distruge_vector_dinamic ULTERIOR*/
VectorDinamic* get_toate_elementele_serviciu(ServiciuProduse* serv);

typedef struct {
	VectorDinamic* vector_rezultat;
	unsigned int eroare;
}VectorDinamicFiltreazaProduse;

/*functie ce returneaza un VectorDinamic cu toate elementele din repo-ul Serivicului, ordonate dupa o optiune
Pre:->serv este pointer la un ServiciuProduse
	->opt este de tip unsigned int, cu valorile 0(pret) sau 1(cantitate)
	->sens este de tip int, cu valorile 1(crescator) sau -1(descrescator)
Post:->functia returneaza un VectorDinamic
!!!VECTORULDINAMIC TREBUIE DISTRUS CU distruge_vector_dinamic ULTERIOR*/
VectorDinamic* sorteaza_produse(ServiciuProduse* serv, unsigned int opt, int sens);

/*returneaza unVectorDinamic cu toate elementele din repo-ul Seriviciului, filtrate printr-o optiune
Pre:->serv este pointer la un ServiciuProduse
	->opt este de tip unsigned int, una din valorile 1(producator), 2(pret) sau 3(cantitate)
	->val este de tip pointer de void, adresa la care se afla valoarea pentru filtru
	->sens este de tip int
Post:->functia returneaza un VectorDinamicFiltreazaProdus pentru care:~>daca val nu a fost un tip de data valid, eroare va fi o valoare intre 1 si 64,
																		reprezentand codul de eroare la validare, iar vector_rezultat va fi NULL;				
																	  ~>daca val este de tip valid, eroare va fi 0, iar in vector_rezultat se va afla un 
																	    pointer la un VectorDInamic cu entitatile cautate
!!!IN CAZUL 2, VECTORULDINAMIC TREBUIE DISTRUS CU distruge_vector_dinamic ULTERIOR!!!*/
VectorDinamicFiltreazaProduse filtreaza_produse(ServiciuProduse* serv, unsigned int opt, void* val,int sens);

#endif