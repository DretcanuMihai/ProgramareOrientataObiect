
#include <string.h>

unsigned int str2ui(char* buffer, unsigned int* pval)
{
	unsigned int val = 0, aux;
	unsigned int i, dim;
	char caux;
	dim = strlen(buffer);
	if (dim > 9)
		return 2;
	if (dim == 0)
		return 3;
	for (i = 0; i < dim; i++)
	{
		caux = buffer[i];
		if (caux < '0' || caux>'9')
			return 3;
		aux = ((unsigned int)caux) - ((unsigned int)'0');
		val = val * 10 + aux;
	}
	pval[0] = val;
	return 0;
}

unsigned int str2double(char* buffer, double* pval)
{
	double val = 0.0;
	double semn;
	unsigned int dim = strlen(buffer);
	unsigned int i, poz_p = 20, inceput;
	if (dim > 16)
		return 2;
	if (dim == 0)
		return 3;
	for (i = 0; i < dim; i++)
		if (buffer[i] == '.')
			if (poz_p == 20)
				poz_p = i;
			else
				return 3;
	inceput = 0;
	semn = 1;
	if (buffer[0] == '+')
		inceput = 1;
	if (buffer[0] == '-')
	{
		inceput = 1;
		semn = -1;
	}
	double stanga = 0, dreapta = 0, p = 1;
	double auxd;
	char aux;
	for (i = inceput; i < dim; i++)
	{
		aux = buffer[i];
		if (i != poz_p && (aux < '0' || aux >'9'))
			return 3;
		if (i < poz_p)
		{
			aux = aux - '0';
			auxd = (double)aux;
			stanga = stanga * 10 + aux;
		}
		if (i > poz_p)
		{
			aux = aux - '0';
			auxd = (double)aux;
			dreapta = dreapta * 10 + aux;
			p = p * 10;
		}
	}
	val = semn * (stanga + dreapta / p);
	pval[0] = val;
	return 0;
}