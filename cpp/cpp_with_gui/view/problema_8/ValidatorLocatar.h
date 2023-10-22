#pragma once

//modul cu o clasa de validator locatar

#include "Locatar.h"

class ValidatorLocatar
{
	public:
		//functie ce valideaza un locatar
		//Pre:locatar este de tip locatar
		//Post:true
		//@ arunca o ExceptieValidareLocatar cu un mesaj alcatuit prin concatenarea unuia sau mai multor mesaje dintre urmatoarele:
		//"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
		//"Eroare: Numele proprietarului trebuie sa fie un string nevid;\n"
		//"Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n"
		//"Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n"
		void valideaza_locatar(const Locatar& locatar)const;

		//functie ce valideaza un apartament
		//Pre:apartament este de tip int
		//Post:true
		//@ arunca o ExceptieValidareLocatar cu urmatorul mesaj daca apartamentul este nul sau negativ:
		//"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
		void valideaza_apartament(int apartament)const;

		//functie ce valideaza o suprafata
		//Pre:suprafata este de tip double
		//Post:true
		//@ arunca o ExceptieValidareLocatar cu urmatorul mesaj daca suprafata este <=+0.0:
		//"Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n"
		void valideaza_suprafata(double suprafata)const;

		//functie ce valideaza un tip de apartament
		//Pre:tip_apartament este strng
		//Post:true
		//@ arunca o ExceptieValidareLocatar cu urmatorul mesaj daca tip_apartament este vid:
		//"Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n"
		void valideaza_tip_apartament(const string& tip_apartament)const;
};

