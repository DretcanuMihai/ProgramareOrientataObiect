#pragma once

//modul ce contine definitia clasei de ServiciuCarti


#include "RepoCarti.h"
#include "ValidatorCarti.h"
class ServiciuCarti
{
private:
	RepoCarti& repo;
	ValidatorCarti& val;
public:
	/*constructor de ServiciuCarti ce primeste un repo si un validator
	Pre:->repo0 este de tip RepoCarti
		->val0 este de tip ValidatorCarti
	Post:->se creeaza un ServiciuCarti de repozitoriu repo0 si validator val0*/
	ServiciuCarti(RepoCarti& repo0, ValidatorCarti& val0);

	/*returneaza toate cartile, ordonate crescator dupa grosime
	Pre:->true
	Post:->returneaza un vector<Carte>*/
	vector<Carte> sort_grosime()const;

	/*returneaza toate cartile, ordonate crescator (alfabetic) dupa titlu
	Pre:->true
	Post:->returneaza un vector<Carte>*/
	vector<Carte> sort_titlu()const;

	/*returneaza toate cartile
	Pre:->true
	Post:->returneaza un const vector<Carte>&*/
	const vector<Carte>& get_all()const;
};

