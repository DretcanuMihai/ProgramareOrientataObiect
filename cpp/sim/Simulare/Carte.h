#pragma once

//Modul cu definitia entitatii carte

#include <string>
using std::string;

class Carte
{
private:
	string titlu;
	string autor;
	string culoare;
	double grosime;
public:

	/*constructor cu titlu,autor,culoare si grosime:
	Pre:->t0 este string
	    ->a0 este string
		->c0 este string
		->g0 este double
	Post:->se creeaza o entitate cu titlu t0, autor a0, culoare c0, grosime g0
	*/
	Carte(string t0, string a0, string c0, double g0);

	/*reutrneaza titlul
	Pre:->true
	Post:->returneaza string*/
	string get_titlu()const;

	/*reutrneaza autor
	Pre:->true
	Post:->returneaza string*/
	string get_autor()const;

	/*reutrneaza culoare
	Pre:->true
	Post:->returneaza string*/
	string get_culoare()const;

	/*reutrneaza grosime
	Pre:->true
	Post:->returneaza double*/
	double get_grosime()const;
};

