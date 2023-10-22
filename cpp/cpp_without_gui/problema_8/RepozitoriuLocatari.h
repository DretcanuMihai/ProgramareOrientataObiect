#pragma once

//modul cu tot ceea ce tine de Repozitoriul de Locatari

#include "RepozitoriuLocatariAbstract.h"

class RepozitoriuLocatari:public RepozitoriuLocatariAbstract
{
protected:
	vector<Locatar> elemente;
public:

	//creator implicit
	//Pre:True
	//Post: returneaza un RepozitoriuLocatari gol
	RepozitoriuLocatari()=default;


	/*copy constructor
	Pre:->r0 este RepozitoriuLocatari
	Post:->entitatatii pe care se opereaza i se atribuie atributele lui r0*/
	RepozitoriuLocatari(const RepozitoriuLocatari& r0) = default;
	/*move constructor
	Pre:->r0 este RepozitoriuLocatari
	Post:->entitatatii pe care se opereaza i se atribuie atributele lui r0*/
	RepozitoriuLocatari& operator=(const RepozitoriuLocatari& r0) = default;
	/*copy assignment
	Pre:->r0 este RepozitoriuLocatari
	Post:->entitatatii pe care se opereaza i se atribuie atributele lui r0*/
	RepozitoriuLocatari(RepozitoriuLocatari&& r0) = default;
	/*move assignment
	Pre:->r0 este RepozitoriuLocatari
	Post:->entitatatii pe care se opereaza i se atribuie atributele lui r0*/
	RepozitoriuLocatari& operator=(RepozitoriuLocatari&& r0) = default;

	/*adauga locatar in repo
	Pre:locatar este un Locatar valid
	Post:repo'=repo+{locatar}
	@Daca exista deja un locatar cu apartamentul locatarului de adaugat, se va arunca o ExceptieRepozitoriuLocatari cu mesajul:
	"Eroare: Exista deja un locatar cu acest apartament"\n*/
	void adauga(const Locatar& locatar) override;

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
	Locatar modifica(const Locatar& locatar) override;

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

	/*destructor virtual al clasei*/
	virtual ~RepozitoriuLocatari() = default;

};

