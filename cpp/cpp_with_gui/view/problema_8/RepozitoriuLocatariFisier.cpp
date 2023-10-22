#include "RepozitoriuLocatariFisier.h"
#include "ExceptiiLocatar.h"
#include <fstream>
#include <iomanip>
#include "Conversii.h"

void RepozitoriuLocatariFisier::salveaza_in_fisier()
{
	std::ofstream f_out(this->nume_fisier);
	if (f_out.fail())
		throw(ExceptieRepozitoriuLocatar("Eroare: Fisierul cautat nu poate fi deschis;\n"));
	f_out << std::fixed << std::setprecision(6);
	for (const auto& elem : this->elemente)
		f_out <<  elem.get_apartament() << "\n" << elem.get_nume_proprietar() << "\n" << elem.get_suprafata() << "\n" << elem.get_tip_apartament() << "\n";
	f_out.close();
}

void RepozitoriuLocatariFisier::incarca_din_fisier()
{
	std::ifstream f_in(this->nume_fisier);
	if (f_in.fail())
		throw(ExceptieRepozitoriuLocatar("Eroare: Fisierul cautat nu poate fi deschis;\n"));
	while (!f_in.eof()) {
		string buffer;
		int apartament=0;
		string nume_proprietar, tip_apartament;
		double suprafata=0;
		std::getline(f_in, buffer);
		if (f_in.eof())
			break;
		string2int(buffer, apartament);
		std::getline(f_in, nume_proprietar);
		std::getline(f_in, buffer);
		string2double(buffer, suprafata);
		std::getline(f_in, tip_apartament);
		const Locatar l(apartament, nume_proprietar, suprafata, tip_apartament);
		RepozitoriuLocatari::adauga(l);
	}
	f_in.close();
}

RepozitoriuLocatariFisier::RepozitoriuLocatariFisier(const string& nume_fisier0) :RepozitoriuLocatari(),nume_fisier { nume_fisier0 }
{
	this->incarca_din_fisier();
}

void RepozitoriuLocatariFisier::adauga(const Locatar& locatar)
{
	RepozitoriuLocatari::adauga(locatar);
	this->salveaza_in_fisier();
}

Locatar RepozitoriuLocatariFisier::sterge(int apartament)
{
	Locatar ret = RepozitoriuLocatari::sterge(apartament);
	this->salveaza_in_fisier();
	return ret;
}

Locatar RepozitoriuLocatariFisier::modifica(const Locatar& locatar)
{
	Locatar ret = RepozitoriuLocatari::modifica(locatar);
	this->salveaza_in_fisier();
	return ret;
}
