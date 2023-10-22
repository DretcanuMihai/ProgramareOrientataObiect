#include "Exceptii.h"

Exceptie::Exceptie(const string& mesaj0):mesaj{mesaj0}
{
}

string Exceptie::getMesaj() const
{
	return mesaj;
}

ExceptieValidare::ExceptieValidare(const string& mesaj0):Exceptie{mesaj0}
{
}

ExceptieRepo::ExceptieRepo(const string& mesaj0):Exceptie(mesaj0)
{
}
