#include "EntitateProdus.h"
#include <string.h>
#include <stdlib.h>

unsigned int valideaza_produs(Produs* prod)
{
	unsigned int value=0;
	char* aux;
	if (get_produs_id(prod) == 0)
		value = value | 1;
	aux=get_produs_tip(prod);
	if (strlen(aux) == 0)
		value = value | 2;
	free(aux);
	aux=get_produs_producator(prod);
	if (strlen(aux) == 0)
		value = value | 4;
	free(aux);
	aux=get_produs_model(prod);
	if (strlen(aux) == 0)
		value = value | 8;
	free(aux);
	if (get_produs_pret(prod) < +0.01)
		value = value | 16;
	if (get_produs_cantitate(prod) == 0)
		value = value | 32;
	return value;
}