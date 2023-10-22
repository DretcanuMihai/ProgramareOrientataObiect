#include "ValidatorLocatar.h"
#include <string>
#include "ExceptiiLocatar.h"

using std::string;

void ValidatorLocatar::valideaza_locatar(const Locatar& locatar) const{
	string eroare{ "" };
	if (locatar.get_apartament() <= 0)
		eroare += "Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n";
	if (locatar.get_nume_proprietar().compare("") == 0)
		eroare += "Eroare: Numele proprietarului trebuie sa fie un string nevid;\n";
	if (locatar.get_suprafata() <= +0.00)
		eroare += "Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n";
	if(locatar.get_tip_apartament().compare("")==0)
		eroare+="Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n";
	if (eroare.length() != 0)
		throw ExceptieValidareLocatar(eroare);
}

void ValidatorLocatar::valideaza_apartament(int apartament)const {
	if (apartament<= 0)
		throw ExceptieValidareLocatar("Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n");
}

void ValidatorLocatar::valideaza_suprafata(double suprafata)const {
	if (suprafata <= +0.00)
		throw ExceptieValidareLocatar("Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n");
}

void ValidatorLocatar::valideaza_tip_apartament(const string& tip_apartament)const {
	if(tip_apartament.compare("")==0)
		throw ExceptieValidareLocatar("Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n");
}