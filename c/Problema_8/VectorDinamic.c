#include "VectorDinamic.h"
#include <malloc.h>

VectorDinamic* creeaza_vector_dinamic(unsigned int capacitate_initiala, destructor distruge, copiator copie)
{
	VectorDinamic* v = (VectorDinamic*)malloc(sizeof(VectorDinamic));
	v->capacitate = capacitate_initiala;
	v->nr_elemente = 0;
	v->elemente = (TElement*)malloc(capacitate_initiala * sizeof(TElement));
	v->distruge = distruge;
	v->copie = copie;
	return v;
}

void distruge_vector_dinamic(VectorDinamic* v)
{
	unsigned int i;
	for (i = 0; i < v->nr_elemente; i++)
		v->distruge(v->elemente[i]);
	free(v->elemente);
	free(v);
}


/*functie ce redimensioneaza un vector dinamic
Pre:-> v este pointer la un vector dinamic
Post:->v->capacitate'=v->capacitate*2   
*/
void redimensionare_vector_dinamic(VectorDinamic* v)
{
	v->capacitate = v->capacitate * 2;
	TElement* auxiliar = (TElement*)malloc(v->capacitate * sizeof(TElement));
	unsigned int i;
	for (i = 0; i < v->nr_elemente; i++)
		auxiliar[i] = v->elemente[i];
	free(v->elemente);
	v->elemente = auxiliar;
}

void adauga_element_vector_dinamic(VectorDinamic* v, TElement elem)
{
	if (v->capacitate == v->nr_elemente)
		redimensionare_vector_dinamic(v);
	v->elemente[v->nr_elemente] =v->copie(elem);
	v->nr_elemente++;
}

void actualizeaza_element_vector_dinamic(VectorDinamic* v, TElement elem, unsigned int index)
{
	v->distruge(v->elemente[index - 1]);
	v->elemente[index-1] =v->copie(elem);
}

void sterge_element_vector_dinamic(VectorDinamic* v, unsigned int index)
{
	v->distruge(v->elemente[index - 1]);
	unsigned int i;
	for (i=index-1;i< v->nr_elemente-1; i++)
		v->elemente[i] = v->elemente[i + 1];
	v->nr_elemente--;
}

TElement acceseaza_element_vector_dinamic(VectorDinamic* v, unsigned int index)
{
	return v->copie(v->elemente[index - 1]);
}

unsigned int dimensiune_vector_dinamic(VectorDinamic* v)
{
	return v->nr_elemente;
}

unsigned int capacitate_vector_dinamic(VectorDinamic* v)
{
	return v->capacitate;
}