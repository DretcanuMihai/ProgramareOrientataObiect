//modul cu tot ce tine de vectori dinamici


#ifndef VECTOR_DINAMIC_H
#define VECTOR_DINAMIC_H
#include "EntitateProdus.h"

typedef void* TElement;
typedef void (*destructor)(TElement);
typedef TElement(*copiator)(TElement);
/*VECTORUL DINAMIC SE CONSIDERA INDEXAT DE LA 1 (ADICA PRIMA POZITIE ESTE POZITIA 1)*/
/*definirea structurii de vector dinamic, alcatuita din:
->capacitatea vectorului (capacitate)
->dimensiunea vectorului (nr_elemente)
->elementele vectorului (elemente)
->destructor (distruge, functia de distrugere specifica lui TElement)
->copiator (copie, functia de copiere specifica lui TElement)*/
typedef struct {
	unsigned int capacitate;
	unsigned int nr_elemente;
	TElement* elemente;
	destructor distruge;
	copiator copie;
}VectorDinamic;


/*functie ce creaza un vector dinamic gol
Pre:->capacitate_initiala de tip unsigned int, nenul; va fi capacitatea initiala a vectorului
	->distruge este o functie de tip destructor specifica elementelor din lista
	->copie este o functie de tip copiator specifica elementelor din lista
Post:->functia returneaza un pointer la un VectorDinamic vid, de capacitate_initala
!!!UN VECTOR DINAMIC CREAT TREBUIE ULTERIOR DISTRUS CU distruge_vector_dinamic*/
VectorDinamic* creeaza_vector_dinamic(unsigned int capacitate_initiala, destructor distruge, copiator copie);


/*functie ce distruge un vector dinamic
Pre:->v este pointer la un vector dinamic
Post:->v este distrus, memoria eliberata*/
void distruge_vector_dinamic(VectorDinamic* v);

/*functie ce redimensioneaza un vector dinamic
Pre:-> v este pointer la un vector dinamic
Post:->v->capacitate'=v->capacitate*2
*/
void redimensionare_vector_dinamic(VectorDinamic* v);

/*functie ce adauga un element intr-un vector dinamic
Pre:->v este pointer la un vector dinamic
	->elem este de tip TElement
Post:->v'=v+{elem}*/
void adauga_element_vector_dinamic(VectorDinamic* v, TElement elem);

/*functie ce adauga un element intr-un vector dinamic pe o pozitie
Pre:->v este pointer la un vector dinamic
	->elem este de tip TElement
	->index este de tip unsigned int, intre 1 si dimensiunea vecoturlui
Post:->v[index]=elem*/
void actualizeaza_element_vector_dinamic(VectorDinamic* v, TElement elem, unsigned int index);

/*functie ce sterge un element dintr-un vector dinamic dupa index
Pre:->v este pointer la un vector dinamic
	->index este de tip unsigned int, cuprins intre 1 si dimensiunea vectorului
Post:->v'=v-{v[i]}*/
void sterge_element_vector_dinamic(VectorDinamic* v, unsigned int index);

/*functie ce returneaza un element dintr-un vector dinamic dupa indexul acestuia
Pre:->v este pointer la un vector dinamic
	->index este de tip unsigned int cuprins intre 1 si dimensiunea vectorului
Post:->functia returneaza un TElement*/
TElement acceseaza_element_vector_dinamic(VectorDinamic* v, unsigned int index);

/*functie ce returneaza dimensiunea vectorului dinamic
Pre:->v este pointer la un vector dinamic
Post:->returneaza un unsigned int ce reprezinta dimensiunea vectorului*/
unsigned int dimensiune_vector_dinamic(VectorDinamic* v);

/*functie ce returneaza capacitatea vectorului dinamic
Pre:->v este pointer la un vector dinamic
Post:->returneaza un unsigned int ce reprezinta capacitatea vectorului*/
unsigned int capacitate_vector_dinamic(VectorDinamic* v);

#endif



