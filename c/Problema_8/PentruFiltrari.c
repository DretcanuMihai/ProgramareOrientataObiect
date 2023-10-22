
#include "PentruFiltrari.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int filtru_producator(Produs* p, void* producator)
{
	int ret = 1;
	char* val = (char*)producator;
	char* aux = get_produs_producator(p);
	if (strstr(aux, val) == NULL)
		ret = -1;
	free(aux);
	return ret;
}

int filtru_pret(Produs* p, void* pret)
{
	double val = *((double*)pret);
	if (get_produs_pret(p) > val)
		return 1;
	if(get_produs_pret(p)<val)
		return -1;
	return 0;
}

int filtru_cantitate(Produs* p, void* cantitate)
{
	unsigned int val = *((unsigned int*)cantitate);
	if (get_produs_cantitate(p) > val)
		return 1;
	if(get_produs_cantitate(p)<val)
		return -1;
	return 0;
}

VectorDinamic* filtreaza_vector(VectorDinamic* v, int(*filtru)(Produs*, void*), void* val, int sens)
{
	VectorDinamic* de_returnat = creeaza_vector_dinamic(8,distruge_produs,copie_produs);
	unsigned int i, dim = dimensiune_vector_dinamic(v);
	for (i = 1; i <= dim; i++)
	{
		Produs* prod = acceseaza_element_vector_dinamic(v, i);
		if (filtru(prod, val) * sens != -1)
			adauga_element_vector_dinamic(de_returnat, prod);
		distruge_produs(prod);
	}
	return de_returnat;
}