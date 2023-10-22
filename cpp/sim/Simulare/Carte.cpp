#include "Carte.h"

Carte::Carte(string t0, string a0, string c0, double g0):titlu{t0},autor{a0},culoare{c0},grosime{g0}
{
}

string Carte::get_titlu() const
{
	return titlu;
}

string Carte::get_autor() const
{
	return autor;
}

string Carte::get_culoare() const
{
	return culoare;
}

double Carte::get_grosime() const
{
	return grosime;
}
