#include <stdlib.h>
#include <string.h>
#include "EntitateProdus.h"


Produs* creeaza_produs(unsigned int id, char* tip, char* producator, char* model, double pret, unsigned int cantitate)
{
	Produs* prod=(Produs*)malloc(sizeof(Produs));
	prod->id = id;
	prod->tip = (char*)malloc((strlen(tip) + 1) * sizeof(char));
	strcpy(prod->tip,tip);
	prod->producator = (char*)malloc((strlen(producator) + 1) * sizeof(char));
	strcpy(prod->producator, producator);
	prod->model = (char*)malloc((strlen(model) + 1) * sizeof(char));
	strcpy(prod->model, model);
	prod->pret = pret;
	prod->cantitate = cantitate;
	return prod;
}

void distruge_produs(Produs* produs)
{
	produs->id = 0;
	free(produs->model);
	produs->model = NULL;
	free(produs->producator);
	produs->producator = NULL;
	free(produs->tip);
	produs->tip = NULL;
	produs->pret = -1.0;
	produs->cantitate = 0;
	free(produs);
}

unsigned int get_produs_id(Produs* produs)
{
	return produs->id;
}

char* get_produs_tip(Produs* produs)
{
	char* ret_string = (char*)malloc((strlen(produs->tip) + 1) * sizeof(char));
	strcpy(ret_string, produs->tip);
	return ret_string;
}

void set_produs_tip(Produs* produs, char* tip_nou)
{
	free(produs->tip);
	produs->tip = (char*)malloc((strlen(tip_nou) + 1) * sizeof(char));
	strcpy(produs->tip, tip_nou);
}

char* get_produs_producator(Produs* produs)
{
	char* ret_string = (char*)malloc((strlen(produs->producator) + 1) * sizeof(char));
	strcpy(ret_string, produs->producator);
	return ret_string;
}

void set_produs_producator(Produs* produs, char* producator_nou)
{
	free(produs->producator);
	produs->producator = (char*)malloc((strlen(producator_nou) + 1) * sizeof(char));
	strcpy(produs->producator, producator_nou);
}

char* get_produs_model(Produs* produs)
{
	char* ret_string = (char*)malloc((strlen(produs->model) + 1) * sizeof(char));
	strcpy(ret_string, produs->model);
	return ret_string;
}

void set_produs_model(Produs* produs, char* model_nou)
{
	free(produs->model);
	produs->model = (char*)malloc((strlen(model_nou) + 1) * sizeof(char));
	strcpy(produs->model, model_nou);
}

double get_produs_pret(Produs* produs)
{
	return produs->pret;
}

void set_produs_pret(Produs* produs, double pret_nou)
{
	produs->pret = pret_nou;
}

unsigned int get_produs_cantitate(Produs* produs)
{
	return produs->cantitate;
}

void set_produs_cantitate(Produs* produs, unsigned int cantitate_noua)
{
	produs->cantitate = cantitate_noua;
}

Produs* copie_produs(Produs* produs)
{
	unsigned int id=get_produs_id(produs), cantitate=get_produs_cantitate(produs);
	char* tip=get_produs_tip(produs);
	char* producator=get_produs_producator(produs);
	char* model=get_produs_model(produs);
	double pret=get_produs_pret(produs);
	Produs* copie = creeaza_produs(id, tip, producator, model, pret, cantitate);
	free(tip);
	free(producator);
	free(model);
	return copie;
}