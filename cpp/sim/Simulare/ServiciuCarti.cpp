#include "ServiciuCarti.h"
#include <algorithm>

ServiciuCarti::ServiciuCarti(RepoCarti& repo0, ValidatorCarti& val0):repo{repo0},val{val0}
{
}

vector<Carte> ServiciuCarti::sort_grosime() const
{
	vector<Carte> rez = repo.get_all();
	std::sort(rez.begin(), rez.end(), [](const Carte& c1, const Carte& c2) {
		return c1.get_grosime() < c2.get_grosime();
		});
	return rez;
}

vector<Carte> ServiciuCarti::sort_titlu() const
{
	vector<Carte> rez = repo.get_all();
	std::sort(rez.begin(), rez.end(), [](const Carte& c1, const Carte& c2) {
		return c1.get_titlu() < c2.get_titlu();
		});
	return rez;
}

const vector<Carte>& ServiciuCarti::get_all() const
{
	return repo.get_all();
}
