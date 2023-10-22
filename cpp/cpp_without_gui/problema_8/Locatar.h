#pragma once
//modul cu definitia clasei de locatar

#include <string>
#include <iostream>

using std::string;
using std::ostream;


class Locatar
{
private:
	int apartament;
	string nume_proprietar;
	double suprafata;
	string tip_apartament;
public:

	//ma voi referi la entitatea pe care se opereaza ca "locatar"

	/*constructor implicit cand nu sunt dati parametrii
	pre:true
	post:creeaza un Locatar cu campuri default*/
	Locatar()noexcept(false);

	//constructor implicit cu toate campurile
	//pre:apartament0 int, nume_proprietar0 string, suprafata0 double, tip_apartament0 string
	//post:creeaza entitatea cu caracteristicile precizate
	Locatar(int apartament0, const string& nume_proprietar0, double suprafata0,const string& tip_apartament0);

	//constructor implicit cu parametru un locatar
	//pre:locatar0 este de tip locatar
	//post:creeaza entitatea cu caracteristicile lui locatar0
	Locatar(const Locatar& locatar0);

	//constructor implicit cu parametru un locatar temporar
	//pre:locatar0 este de tip locatar
	//post:creeaza entitatea cu caracteristicile lui locatar0
	Locatar(Locatar&& locatar0) = default;


	//suprascrie operatorul =locatar pentru un locatar
	//pre:locatar0 este locatar;
	//post:campurile lui locatar iau valorile campurilor lui locatar0
	Locatar& operator=(const Locatar& locatar0)=default;

	//suprascrie operatorul =locatar temporar pentru un locatar
	//pre:locatar0 este locatar;
	//post:campurile lui locatar iau valorile campurilor lui locatar0
	Locatar& operator=(Locatar&& locatar0) =default;

	//returneaza apartamentul
	//pre:true
	//post:returneaza int
	int get_apartament()const noexcept;

	//returneaza numele proprietarului
	//pre:true
	//post:returneaza string
	string get_nume_proprietar()const;

	//returneaza suprafata
	//pre:true
	//post:returneaza double
	double get_suprafata()const noexcept;

	//returneaza tipul apartamentului
	//pre:true
	//post:returneaza string
	string get_tip_apartament()const;

	//schimba numele proprietarului
	//pre:nume_proprietar0 este string
	//post:locatar.nume_proprietar' = nume_proprietar0
	void set_nume_proprietar(const string& nume_proprietar0);

	//schimba suprafata
	//pre:suprafata0 este double
	//post:locatar.suprafata' = suprafata0
	void set_suprafata(double suprafata0)noexcept;

	//schimba tipul apartamentului
	//pre:tip_apartament0 este string
	//post:locatar.tip_apartament' = tip_apartament0
	void set_tip_apartament(const string& tip_apartament0);

	//suprscrie operatorul == intre 2 locatari
	//pre:locatar0 este locatar;
	//post:returneaza bool: true, daca locatar.apartament==locatar0.apartament, false altfel
	friend bool operator==(const Locatar& locatar0, const Locatar& locatar1)noexcept;

	//suprscrie operatorul != intre 2 locatari
	//pre:locatar0 este locatar;
	//post:returneaza bool: true, daca locatar.apartament!=locatar0.apartament, false altfel
	friend bool operator!=(const Locatar& locatar0, const Locatar& locatar1)noexcept;

	//suprascrie operatorul << al ostreamului
	//pre:os este ostream, locatar0 este Locatar
	//post:afiseaza la output Locatarul sub formatul:
	//Locatar - Apartament:locatar.apartament; Proprietar:locatar.nume_proprietar; Suprafata:locatar.suprafata; Tip Apartament:locatar.tip_apartament
	//unde locatar.suprafata este afisat cu exact 6 zecimale
	friend ostream& operator<<(ostream& os, const Locatar& locatar0);


	//destructor implicit al entitatii
	//Pre:true
	//Post:locatar.apartament=-1,locatar.nume_proprietar="",locatar.suprafata=-1.0,locatar.tip_apartament=""
	~Locatar();
};

