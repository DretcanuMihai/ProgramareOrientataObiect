#pragma once

//definitie a clasei RepozitoriuLocatariFisier, un repozitoriu ce modifica datele unui fisier.

#include "RepozitoriuLocatari.h"
#include <string>
using std::string;


class RepozitoriuLocatariFisier:public RepozitoriuLocatari
{
private:
	string nume_fisier;

	friend class TesteLocatar;

	/*functie ce salveaza in fisier datele din repo
	Pre:->true;
	Post:->salveaza datele din repo in fisier*/
	void salveaza_in_fisier();

	/*functie ce incarca repo-ul cu elemente dn fisier
	Pre:->true
	Post:->repo-ul are entitatile descrie in fisier*/
	void incarca_din_fisier();

	/*functie ce creeaza un repo cu nume_fisier string vid, fara elemente - facut pentru testing
	Pre:->true
	Post:->numele fisierului este vid, iar lista de elemente este vida*/
	RepozitoriuLocatariFisier() = default;

public:

	/*constructor de RepozitoriuLocatariFisier dupa nume_fisier
	Pre:->nume_fisier0 este un string
	Post:->se creeaza un RepozitoriuLocatariFisier asociat fisierului dat, ce contine intrarile din fisier*/
	RepozitoriuLocatariFisier(const string& nume_fisier0);

	/*adauga locatar in repo
	Pre:locatar este un Locatar valid
	Post:repo'=repo+{locatar}
	@Daca exista deja un locatar cu apartamentul locatarului de adaugat, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Exista deja un locatar cu acest apartament"\n*/
	void adauga(const Locatar& locatar)override;

	/*sterge locatar din repo
	Pre:apartament este int pozitiv, nenul
	Post:->repo'=repo-{locatar}, unde locatar.apartament==apartament
	     ->returneaza locatarul sters;
	@Daca nu exista un locatar cu apartamentul apartament, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	Locatar sterge(int apartament)override;

	/*modifica locatar din repo
	Pre:locatar este un Locatar valid
	Post:->locatarul de apartament locatar.apartament va avea datele lui locatar
	     ->returneaza locatarul inainte de modificare;
	@Daca nu exista un locatar cu apartamentul lui locatar, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	Locatar modifica(const Locatar& locatar)override;
};

