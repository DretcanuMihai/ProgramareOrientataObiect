#pragma once

//modul ce contine definitia clasei de RepoCarti

#include "Carte.h"
#include <vector>
using std::vector;

class RepoCarti
{
private:
	string nume_fisier;
	vector<Carte> v;
	
	/*functie ce incarca Cartile din fisierul repo-ului
	Pre:->true
	Post:->Repo-ul are incarcate in v cartile din fisier*/
	void incarca_din_fisier();

public:
	/*consturctor cu nume de fisier
	Pre:->nume_fisier0 este string ce desemneaza un nume de fisier valid, accesibil, in care se afla entitati de tip Carte valide
	Post:->repo-ul este legat de fisierul cu nume nume_fisier0
		 ->repo-ul este incarcat cu cartile din acest fisier*/
	RepoCarti(string nume_fisier0);

	/*returneaza toate cartile
	Pre:->true
	Post:->returneaza un const vector<Carte>&*/
	const vector<Carte>& get_all()const;
};

