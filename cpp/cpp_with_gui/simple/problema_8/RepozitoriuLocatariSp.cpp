#include "RepozitoriuLocatariSp.h"
#include "ExceptiiLocatar.h"
#include <random>

RepozitoriuLocatariSp::RepozitoriuLocatariSp(double probabilitate0)noexcept(false) :probabilitate{ probabilitate0 } {}

void RepozitoriuLocatariSp::soarta() const
{
	std::mt19937 mt{ std::random_device{}() };
	const std::uniform_real_distribution<double> distributie(0.0, 1.0);
	const double val = distributie(mt);
	if (val < this->probabilitate)
		throw ExceptieRepozitoriuLocatar("Eroare: >:(  ;\n");
}

void RepozitoriuLocatariSp::adauga(const Locatar& locatar)
{
	this->soarta();
	if(this->elemente.find(locatar.get_apartament())!=this->elemente.end())
		throw ExceptieRepozitoriuLocatar("Eroare: Exista deja un locatar cu acest apartament\n");
	this->elemente[locatar.get_apartament()] = locatar;
}

Locatar RepozitoriuLocatariSp::sterge(int apartament)
{
	this->soarta();
	auto it = this->elemente.find(apartament);
	if(it==this->elemente.end())
		throw ExceptieRepozitoriuLocatar("Eroare: Nu exista un locatar cu acest apartament\n");
	Locatar ret = (*it).second;
	this->elemente.erase(it);
	return ret;
}

Locatar RepozitoriuLocatariSp::modifica(const Locatar& locatar)
{
	this->soarta();
	auto it = this->elemente.find(locatar.get_apartament());
	if (it == this->elemente.end())
		throw ExceptieRepozitoriuLocatar("Eroare: Nu exista un locatar cu acest apartament\n");
	Locatar ret = this->elemente[locatar.get_apartament()];
	this->elemente[locatar.get_apartament()]= locatar;
	return ret;
}

const Locatar& RepozitoriuLocatariSp::cauta(int apartament) const
{
	this->soarta();
	for (const auto& elem : this->elemente)
		if (elem.first == apartament)
			return elem.second;
	throw ExceptieRepozitoriuLocatar("Eroare: Nu exista un locatar cu acest apartament\n");
}

vector<Locatar> RepozitoriuLocatariSp::get_all() const
{
	this->soarta();
	vector<Locatar> rezultat;
	for (const auto& elem : this->elemente)
		rezultat.push_back(elem.second);
	return rezultat;
}
