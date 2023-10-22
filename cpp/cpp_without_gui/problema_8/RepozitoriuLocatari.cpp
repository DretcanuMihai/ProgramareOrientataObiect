#include "RepozitoriuLocatari.h"
#include "ExceptiiLocatar.h"

void RepozitoriuLocatari::adauga(const Locatar& locatar){
	auto it = std::find_if(this->elemente.begin(), this->elemente.end(), [locatar](const Locatar& l)noexcept {return locatar.get_apartament() <= l.get_apartament(); });
	if (it != this->elemente.end() && *it == locatar)
		throw ExceptieRepozitoriuLocatar("Eroare: Exista deja un locatar cu acest apartament\n");
	this->elemente.insert(it, locatar);
}

Locatar RepozitoriuLocatari::sterge(int apartament) {
	auto it = std::find_if(this->elemente.begin(), this->elemente.end(), [apartament](const Locatar& l)noexcept {return l.get_apartament() == apartament; });
	if(it==this->elemente.end())
		throw ExceptieRepozitoriuLocatar("Eroare: Nu exista un locatar cu acest apartament\n");
	Locatar ret = *it;
	this->elemente.erase(it);
	return ret;
}
Locatar RepozitoriuLocatari::modifica(const Locatar& locatar) {
	auto it = find(this->elemente.begin(), this->elemente.end(), locatar);
	if(it==this->elemente.end())
		throw ExceptieRepozitoriuLocatar("Eroare: Nu exista un locatar cu acest apartament\n");
	Locatar ret = *it;
	*it = locatar;
	return ret;
}

const Locatar& RepozitoriuLocatari::cauta(int apartament)const {
	for (const auto& elem : this->elemente)
		if (elem.get_apartament() == apartament)
			return elem;
	/*auto it = std::find_if(this->elemente.begin(), this->elemente.end(), [apartament](const Locatar& l)noexcept {return l.get_apartament() == apartament; });
	if (it != this->elemente.end())
		return *it;*/
	throw ExceptieRepozitoriuLocatar("Eroare: Nu exista un locatar cu acest apartament\n");
}

vector<Locatar> RepozitoriuLocatari::get_all()const{
	return this->elemente;
}