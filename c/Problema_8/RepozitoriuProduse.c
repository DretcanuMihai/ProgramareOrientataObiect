
#include <malloc.h>
#include "RepozitoriuProduse.h"
#include <math.h>
#include <string.h>
#ifndef EPSILON
#define EPSILON 0.0000001
#endif

RepoProduse* creaza_repo_produse()
{
	RepoProduse* repo = (RepoProduse*)malloc(sizeof(RepoProduse));
	repo->lista_elemente = creeaza_vector_dinamic(8,distruge_produs,copie_produs);
	return repo;
}

void distruge_repo_produse(RepoProduse* r)
{
	distruge_vector_dinamic(r->lista_elemente);
	free(r);
}

unsigned int adauga_element_repo_produse(RepoProduse* r, Produs* prod)
{
	unsigned int dim = dimensiune_vector_dinamic(r->lista_elemente),i;
	unsigned int index = 0,ok=0;
	Produs* prod_final=copie_produs(prod);
	for (i = 1; i <= dim; i++)
	{
		Produs* prod_ret = acceseaza_element_vector_dinamic(r->lista_elemente,i);
		ok = get_produs_id(prod_ret) == get_produs_id(prod);
		if (ok)
		{
			unsigned int c1, c2, c3, c4;
			char* aux1;
			char* aux2;
			aux1=get_produs_model(prod);
			aux2=get_produs_model(prod_ret);
			c1 = strcmp(aux1, aux2) == 0;
			free(aux1);
			free(aux2);
			aux1=get_produs_producator(prod);
			aux2=get_produs_producator(prod_ret);
			c2 = strcmp(aux1, aux2) == 0;
			free(aux1);
			free(aux2);
			aux1=get_produs_tip(prod);
			aux2=get_produs_tip(prod_ret);
			c3 = strcmp(aux1, aux2) == 0;
			free(aux1);
			free(aux2);
			c4 = fabs(get_produs_pret(prod) - get_produs_pret(prod_ret)) < EPSILON;
			if (c1 && c2 && c3 && c4)
			{
				index = i;
				set_produs_cantitate(prod_final, get_produs_cantitate(prod) + get_produs_cantitate(prod_ret));
			}
		}
		distruge_produs(prod_ret);
	}
	if (ok == 0)
	{
		adauga_element_vector_dinamic(r->lista_elemente, prod_final);
	}
	else if (index)
	{
		actualizeaza_element_vector_dinamic(r->lista_elemente, prod_final, index);
	}
	distruge_produs(prod_final);
	if (ok == 0)
		return 0;
	else if (index)
		return 1;
	else
		return 2;
}

unsigned int sterge_element_repo_produse(RepoProduse* r, unsigned int id)
{
	unsigned int i,dim=dimensiune_vector_dinamic(r->lista_elemente);
	unsigned int index = 0;
	for (i = 1; i <= dim; i++)
	{
		Produs* prod = acceseaza_element_vector_dinamic(r->lista_elemente, i);
		if (get_produs_id(prod) == id)
			index = i;
		distruge_produs(prod);
	}
	if (index == 0)
		return 1;
	sterge_element_vector_dinamic(r->lista_elemente, index);
	return 0;
}

unsigned int actualizeaza_element_repo_produse(RepoProduse* r, Produs* prod)
{
	unsigned int i, dim = dimensiune_vector_dinamic(r->lista_elemente);
	unsigned int index = 0;
	for (i = 1; i <= dim; i++)
	{
		Produs* prod_aux = acceseaza_element_vector_dinamic(r->lista_elemente, i);
		if (get_produs_id(prod_aux) == get_produs_id(prod))
		{
			index = i;
			actualizeaza_element_vector_dinamic(r->lista_elemente, prod, index);
		}
		distruge_produs(prod_aux);
	}
	if (index == 0)
		return 1;
	return 0;
}

VectorDinamic* get_toate_elementele_repo(RepoProduse* r)
{
	VectorDinamic* v_nou=creeaza_vector_dinamic(capacitate_vector_dinamic(r->lista_elemente),distruge_produs,copie_produs);
	unsigned int i, dim = dimensiune_vector_dinamic(r->lista_elemente);
	for (i = 1; i <= dim; i++)
	{
		Produs* p = acceseaza_element_vector_dinamic(r->lista_elemente, i);
		adauga_element_vector_dinamic(v_nou,p);
		distruge_produs(p);
	}
	return v_nou;
}