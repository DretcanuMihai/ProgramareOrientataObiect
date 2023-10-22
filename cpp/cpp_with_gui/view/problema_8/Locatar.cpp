#include "Locatar.h"
#include <iomanip>
//#include <algorithm>
//using std::swap;

Locatar::Locatar()noexcept(false) :apartament{ 0 }, nume_proprietar{""}, suprafata{ +0.0 }, tip_apartament{""}{
}

Locatar::Locatar(int apartament0, const string& nume_proprietar0, double suprafata0, const string& tip_apartament0) :apartament{ apartament0 }, 
nume_proprietar{ nume_proprietar0 }, suprafata{ suprafata0 }, tip_apartament{ tip_apartament0 }{
}

Locatar::Locatar(const Locatar& locatar0):apartament{ locatar0.apartament },nume_proprietar{ locatar0.nume_proprietar }, suprafata{ locatar0.suprafata }, tip_apartament{ locatar0.tip_apartament }{
}

//Locatar::Locatar(Locatar&& locatar0) noexcept{
//	this->apartament = locatar0.apartament;
//	this->nume_proprietar = locatar0.nume_proprietar;
//	this->suprafata = locatar0.suprafata;
//	this->tip_apartament = locatar0.tip_apartament;
//	locatar0.apartament = -1;
//	locatar0.suprafata = -1.00;
//}


//Locatar& Locatar::operator=(const Locatar& locatar0) {
//	this->apartament = locatar0.apartament;
//	this->nume_proprietar = locatar0.nume_proprietar;
//	this->suprafata = locatar0.suprafata;
//	this->tip_apartament = locatar0.tip_apartament;
//	cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n";
//	return *this;
//}

//Locatar& Locatar::operator=(Locatar&& locatar0) noexcept{
//
//
//	swap(this->apartament, locatar0.apartament);
//	swap(this->nume_proprietar, locatar0.nume_proprietar);
//	swap(this->suprafata, locatar0.suprafata);
//	swap(this->tip_apartament, locatar0.tip_apartament);
//
//	return *this;
//}


int Locatar::get_apartament()const noexcept{
	return this->apartament;
}
string Locatar::get_nume_proprietar()const {
	return this->nume_proprietar;
}
double Locatar::get_suprafata()const noexcept{
	return this->suprafata;
}
string Locatar::get_tip_apartament()const {
	return this->tip_apartament;
}



void Locatar::set_nume_proprietar(const string& nume_proprietar0) {
	this->nume_proprietar = nume_proprietar0;
}
void Locatar::set_suprafata(double suprafata0) noexcept{
	this->suprafata = suprafata0;
}
void Locatar::set_tip_apartament(const string& tip_apartament0) {
	this->tip_apartament = tip_apartament0;
}

bool operator==(const Locatar& locatar0, const Locatar& locatar1) noexcept{
	return locatar0.apartament==locatar1.apartament;
}

bool operator!=(const Locatar& locatar0, const Locatar& locatar1) noexcept{
	return locatar0.apartament != locatar1.apartament;
}

ostream& operator<<(ostream& os, const Locatar& locatar0) {
	const auto pvechi = os.precision();
	const auto osflags = os.flags();
	os << std::fixed << std::setprecision(6);
	os << "Locatar - Apartament:" << locatar0.apartament << "; Proprietar:" << locatar0.nume_proprietar << "; Suprafata:" << locatar0.suprafata << "; Tip Apartament:" << locatar0.tip_apartament;
	os << std::setprecision(pvechi);
	os.flags(osflags);
	return os;
}

Locatar::~Locatar(){
	this->apartament = -1;
	this->suprafata = -1.00;
}