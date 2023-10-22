//modul cu chestii pentru filtrare

#ifndef _PENTRU_FILTRARI_H
#define _PENTRU_FILTRARI_H

#include "EntitateProdus.h"
#include "VectorDinamic.h"


/*functie ce filtreaza un produs dupa producator (daca stringul este inclus in numele producatorului)
Pre:->p este pointer la entitate de tip Produs
	->producator este pointer la void, unde se afla adresa sirului
Post:->functia returneaza int: ~> 1 daca trece cu succes prin filtru	
							   ~>-1 in caz contrar*/
int filtru_producator(Produs* p, void* producator);

/*functie ce filtreaza un produs dupa pret (daca pretul este mai mare sau egal)
Pre:->p este pointer la entitate de tip Produs
	->pret este pointer la void, unde se afla pretul
Post:->functia returneaza int: ~> 1 daca trece cu succes prin filtru, dar preturile nu sunt egale
							   ~> altfel  0 daca preturile sunt egale
							   ~> altfel -1*/
int filtru_pret(Produs* p, void* pret);

/*functie ce filtreaza un produs dupa cantitate (daca cantitatea este mai mare sau egala)
Pre:->p este pointer la entitate de tip Produs
	->cantitate este pointer la void, unde se afla cantitatea
Post:->functia returneaza int: ~> 1 daca trece cu succes prin filtru, dar cantitatile nu suntegale
							   ~> altfel  0 daca cantitatile sunt egale
							   ~> altfel -1*/
int filtru_cantitate(Produs* p, void* cantitate);

/*functie ce filtreaza un vector si returneaza versiunea filtrata
Pre:->v este un pointer la un VectorDinamic
	->filtru este un pointer la o functie de filtrare, ce intoarce 1 daca respecta filtrul pentru sens normal, -1 daca respecta filtrul pentru sens opus, si 0 daca
	  respecta filtrul indiferent de caz
	->val este un pointer de void la care se afla valoarea necesara functiei de filtru
	->sens este de tip int, si este egal cu 1(daca se va respecta filtrul) sau -1 (daca nu se va respecta filtrul)
Post:->functia returneaza un VectorDinamic cu elementele filtrate*/
VectorDinamic* filtreaza_vector(VectorDinamic* v, int(*filtru)(Produs*, void*), void* val, int sens);

#endif