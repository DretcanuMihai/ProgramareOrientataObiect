//modul cu chestii pentru sortari

#ifndef _PENTRU_SORTARI_H
#define _PENTRU_SORTARI_H

#include "EntitateProdus.h"
#include "VectorDinamic.h"

/*functie ce compara doua produse dupa pret
Pre:->p1,p2 pointer la Produs
Post:->functia returneaza int: ~>-1, daca pret1<pret2
							   ~>0, daca pret1==pret2
							   ~>1, daca pret1>pret2*/
int comparator_pret(Produs* p1, Produs* p2);

/*functie ce compara doua produse dupa cantitate
Pre:->p1,p2 pointer la Produs
Post:->functia returneaza int: ~>-1, daca cantitate1<cantitate2
							   ~>0, daca cantitate1==cantitate2
							   ~>1, daca cantitate1>cantitate2*/
int comparator_cantitate(Produs* p1, Produs* p2);

/*functie ce compara doua produse dupa id
Pre:->p1,p2 pointer la Produs
Post:->functia returneaza int: ~>-1, daca id1<id2
							   ~>0, daca id1==id2
							   ~>1, daca id1>id2*/
int comparator_id(Produs* p1, Produs* p2);

/*functie ce sorteaza un VectorDinamic
Pre:->v este vector de pointeri de produse
	->comparator este un pointer la o functie de comparatie
	->sens este de tip int, egal cu 1 sau -1 (1 pentru crescator, -1 descrescator)
Post:->elementele vectorului v vor fi sortate in ordinea data de comparator si sens*/
void sorteaza_vector(VectorDinamic* v, int(*comparator)(Produs*, Produs*), int sens);

#endif