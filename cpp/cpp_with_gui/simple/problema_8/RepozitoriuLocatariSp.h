#pragma once

#include "RepozitoriuLocatariAbstract.h"
#include <map>
using std::map;

class RepozitoriuLocatariSp:public RepozitoriuLocatariAbstract
{
private:
	map<int, Locatar> elemente;
	double probabilitate;

	friend class TesteLocatar;

	/*functie ce posibil sa arunce exceptie
	Pre:->true
	Post:->ture
	@Are o probabilitate*100 % de a arunca aleatoriu o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: >:(  ;\n"*/
	void soarta()const;

public:

	//Toate metodele au o sansa de probabilitate*100 % de a arunca aleatoriu o ExceptieRepozitoriuLocatari cu mesajul:
	//"Eroare: >:(  ;\n"

	/*adauga locatar in repo
	Pre:locatar este un Locatar valid
	Post:repo'=repo+{locatar}
	@Daca exista deja un locatar cu apartamentul locatarului de adaugat, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Exista deja un locatar cu acest apartament"\n*/
	void adauga(const Locatar & locatar) override;

	/*sterge locatar din repo
	Pre:apartament este int pozitiv, nenul
	Post:->repo'=repo-{locatar}, unde locatar.apartament==apartament
		 ->returneaza locatarul sters;
	@Daca nu exista un locatar cu apartamentul apartament, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	Locatar sterge(int apartament) override;

	/*modifica locatar din repo
	Pre:locatar este un Locatar valid
	Post:->locatarul de apartament locatar.apartament va avea datele lui locatar
		 ->returneaza locatarul inainte de modificare;
	@Daca nu exista un locatar cu apartamentul lui locatar, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	Locatar modifica(const Locatar & locatar) override;

	/*cauta locatar in repo
	Pre:apartament este int pozitiv, nenul
	Post:returneaza locatar de tip Locatar, unde locatar.apartament==apartament
	@Daca nu exista un locatar cu apartamentul apartament, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	const Locatar& cauta(int apartament)const override;

	/*returneaza vector constant cu toti locatarii (o referinta)
	Pre:True
	Post:returneaza un vector de Locatari nemodificabil*/
	vector<Locatar> get_all()const override;

	/*constructor RepozitoriuLocatariSp cu probabilitate
	Pre:->probabilitate0 este double
	Post:->construieste obiectul*/
	RepozitoriuLocatariSp(double probabilitate0)noexcept(false);


	RepozitoriuLocatariSp(const RepozitoriuLocatariSp & r0) = default;
	RepozitoriuLocatariSp& operator=(const RepozitoriuLocatariSp & r0) = default;
	RepozitoriuLocatariSp(RepozitoriuLocatariSp && r0) = default;
	RepozitoriuLocatariSp& operator=(RepozitoriuLocatariSp && r0) = default;
	virtual ~RepozitoriuLocatariSp() = default;

};

