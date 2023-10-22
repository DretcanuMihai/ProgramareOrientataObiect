
#include "PentruSortari.h"

int comparator_pret(Produs* p1, Produs* p2)
{
	if (get_produs_pret(p1) < get_produs_pret(p2))
		return -1;
	if (get_produs_pret(p1) > get_produs_pret(p2))
		return 1;
	return 0;
}

int comparator_cantitate(Produs* p1, Produs* p2)
{
	if (get_produs_cantitate(p1) < get_produs_cantitate(p2))
		return -1;
	if (get_produs_cantitate(p1) > get_produs_cantitate(p2))
		return 1;
	return 0;
}

int comparator_id(Produs* p1, Produs* p2)
{
	if (get_produs_id(p1) < get_produs_id(p2))
		return -1;
	if (get_produs_id(p1) > get_produs_id(p2))
		return 1;
	return 0;
}

void sorteaza_vector(VectorDinamic* v, int(*comparator)(Produs*, Produs*), int sens)
{
	unsigned int i, j, dim = dimensiune_vector_dinamic(v);
	for (i = 1; i < dim; i++)
	{
		Produs* p1, * p2;
		for (j = i + 1; j <= dim; j++)
		{
			p1 = acceseaza_element_vector_dinamic(v, i);
			p2 = acceseaza_element_vector_dinamic(v, j);
			if ((comparator(p1, p2) * sens == 1)||(comparator(p1,p2)==0 && comparator_id(p1,p2)==1))
			{
				actualizeaza_element_vector_dinamic(v, p1, j);
				actualizeaza_element_vector_dinamic(v, p2, i);
			}
			distruge_produs(p1);
			distruge_produs(p2);
		}
	}
}