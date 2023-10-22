#pragma once
#include "Locatar.h"
#include <vector>
using std::vector;

///modul ce contine definitia clasei RepozitoriuLocatariAbstract (clasa pur abstracta)

class RepozitoriuLocatariAbstract
{
public:
	/*adauga locatar in repo
	Pre:locatar este un Locatar valid
	Post:repo'=repo+{locatar}
	@Daca exista deja un locatar cu apartamentul locatarului de adaugat, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Exista deja un locatar cu acest apartament"\n*/
	virtual void adauga(const Locatar& locatar) = 0;

	/*sterge locatar din repo
	Pre:apartament este int pozitiv, nenul
	Post:->repo'=repo-{locatar}, unde locatar.apartament==apartament
		 ->returneaza locatarul sters;
	@Daca nu exista un locatar cu apartamentul apartament, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	virtual Locatar sterge(int apartament) = 0;

	/*modifica locatar din repo
	Pre:locatar este un Locatar valid
	Post:->locatarul de apartament locatar.apartament va avea datele lui locatar
		 ->returneaza locatarul inainte de modificare;
	@Daca nu exista un locatar cu apartamentul lui locatar, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	virtual Locatar modifica(const Locatar& locatar) = 0;

	/*cauta locatar in repo
	Pre:apartament este int pozitiv, nenul
	Post:returneaza locatar de tip Locatar, unde locatar.apartament==apartament
	@Daca nu exista un locatar cu apartamentul apartament, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	virtual const Locatar& cauta(int apartament)const = 0;

	/*returneaza vector constant cu toti locatarii (o referinta)
	Pre:True
	Post:returneaza un vector de Locatari nemodificabil*/
	virtual vector<Locatar> get_all()const = 0;

	/*toti constructorii, setati pe default*/
	RepozitoriuLocatariAbstract() = default;
	RepozitoriuLocatariAbstract(const RepozitoriuLocatariAbstract&) = default;
	RepozitoriuLocatariAbstract(RepozitoriuLocatariAbstract&&) = default;
	RepozitoriuLocatariAbstract& operator=(const RepozitoriuLocatariAbstract&) = default;
	RepozitoriuLocatariAbstract& operator=(RepozitoriuLocatariAbstract&&) = default;

	/*destructor virual al clasei*/
	virtual ~RepozitoriuLocatariAbstract() = default;
};

