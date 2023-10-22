
#include <stdlib.h>
#include "ServiciuProduse.h"
#include "PentruSortari.h"
#include "PentruFiltrari.h"

ServiciuProduse* creeaza_serviciu_produse(RepoProduse* repo)
{
	ServiciuProduse* serv = (ServiciuProduse*)malloc(sizeof(ServiciuProduse));
	serv->repo = repo;
	return serv;
}

void distruge_serviciu_produse(ServiciuProduse* serv)
{
	free(serv);
}

unsigned int adauga_element_serviciu_produse(ServiciuProduse* serv, unsigned int id, char* tip, char* producator, char* model, double pret, unsigned int cantitate)
{
	Produs* prod = creeaza_produs(id, tip, producator, model, pret, cantitate);
	unsigned int ret = valideaza_produs(prod);
	if (ret != 0)
	{
		distruge_produs(prod);
		return ret;
	}
	ret = adauga_element_repo_produse(serv->repo, prod);
	if (ret != 0)
	{
		ret = ret + 63;
	}
	distruge_produs(prod);
	return ret;
}

unsigned int actualizeaza_element_serviciu_produse_opt(ServiciuProduse* serv, unsigned int id, unsigned int opt, void* valoare)
{
	char aux_char[20] = "aux";
	double aux_double = 1.0;
	unsigned int aux_ui = 20;
	Produs* prod_aux=creeaza_produs(id,aux_char,aux_char,aux_char,aux_double,aux_ui);
	if (opt == 0)
	{
		double* auxp = (double*)valoare;
		double aux = *auxp;
		set_produs_pret(prod_aux, aux);
	}
	if (opt == 1)
	{
		unsigned int* auxp = (unsigned int*)valoare;
		unsigned int aux = *auxp;
		set_produs_cantitate(prod_aux, aux);
	}
	unsigned int ret = valideaza_produs(prod_aux);
	distruge_produs(prod_aux);
	if (ret != 0)
		return ret;
	ret = 64;
	VectorDinamic* v = get_toate_elementele_repo(serv->repo);
	unsigned int i, dim = dimensiune_vector_dinamic(v);
	for (i = 1; i <= dim; i++)
	{
		Produs* p = acceseaza_element_vector_dinamic(v, i);
		if (get_produs_id(p) == id)
		{
			if (opt == 0)
			{
				double* auxp = (double*)valoare;
				double aux = *auxp;
				set_produs_pret(p, aux);
			}
			else if(opt==1)
			{
				unsigned int* auxp = (unsigned int*)valoare;
				unsigned int aux = *auxp;
				set_produs_cantitate(p, aux);
			}
			ret=actualizeaza_element_repo_produse(serv->repo, p);
		}
		distruge_produs(p);
	}
	distruge_vector_dinamic(v);
	return ret;
}

unsigned int sterge_element_serviciu_produse(ServiciuProduse* serv, unsigned int id)
{
	if (id == 0)
		return 1;
	unsigned int ret = sterge_element_repo_produse(serv->repo, id);
	if (ret == 1)
		ret = 64;
	return ret;
}

VectorDinamic* get_toate_elementele_serviciu(ServiciuProduse* serv)
{
	return get_toate_elementele_repo(serv->repo);
}

VectorDinamic* sorteaza_produse(ServiciuProduse* serv, unsigned int opt, int sens)
{
	VectorDinamic* v = get_toate_elementele_repo(serv->repo);
	int (*comp[2])(Produs*, Produs*) = { comparator_pret,comparator_cantitate };
	sorteaza_vector(v, comp[opt], sens);
	return v;
}

VectorDinamicFiltreazaProduse filtreaza_produse(ServiciuProduse* serv, unsigned int opt, void* val, int sens)
{
	VectorDinamicFiltreazaProduse de_returnat;
	de_returnat.eroare = 0;
	de_returnat.vector_rezultat = NULL;
	Produs* de_verificat = creeaza_produs(1, "a", "b", "c", 1.00, 1);
	char* filtru_producator_v;
	double filtru_pret_v;
	unsigned int filtru_cantitate_v;
	int (*filtre[3])(Produs*, void*) = {filtru_producator,filtru_pret,filtru_cantitate};
	switch (opt)
	{
	case 1:
		filtru_producator_v = (char*)val;
		set_produs_producator(de_verificat, filtru_producator_v);
		break;
	case 2:
		filtru_pret_v = *((double*)val);
		set_produs_pret(de_verificat, filtru_pret_v);
		break;
	case 3:
		filtru_cantitate_v = *((unsigned int*)val);
		set_produs_cantitate(de_verificat, filtru_cantitate_v);
		break;
	}
	unsigned int ret = valideaza_produs(de_verificat);
	distruge_produs(de_verificat);
	if (ret != 0)
	{
		de_returnat.eroare = ret;
		return de_returnat;
	}
	VectorDinamic* v = get_toate_elementele_repo(serv->repo);

	de_returnat.vector_rezultat = filtreaza_vector(v, filtre[opt-1], val, sens);

	distruge_vector_dinamic(v);
	return de_returnat;
}
