#include "RepoCarti.h"
#include <fstream>

void RepoCarti::incarca_din_fisier()
{
	std::ifstream fin(nume_fisier);
	while (fin.good()) {
		string titlu;
		std::getline(fin, titlu);
		if (titlu == "") {
			break;
		}
		string autor;
		std::getline(fin, autor);
		string culoare;
		std::getline(fin, culoare);
		string buffer;
		std::getline(fin, buffer);
		double grosime=stod(buffer);
		v.push_back(Carte{ titlu,autor,culoare,grosime });
	}
	fin.close();
}

RepoCarti::RepoCarti(string nume_fisier0):nume_fisier{nume_fisier0}
{
	incarca_din_fisier();
}

const vector<Carte>& RepoCarti::get_all() const
{
	return v;
}
