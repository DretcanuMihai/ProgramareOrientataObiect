#include "TesteLocatar.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include "Locatar.h"
#include "ExceptiiLocatar.h"
#include "ValidatorLocatar.h"
#include "RepozitoriuLocatari.h"
#include "ServiciuLocatari.h"
#include "Conversii.h"
#include "ListaNotificare.h"
#include <cmath>
//#include "Vector.h"
//#include "PentruSortari.h"
//#include "PentruFiltrari.h"
#include "ListaNotificare.h"
#include "RepozitoriuLocatariFisier.h"
#include "ActiuneUndo.h"
#include "RepozitoriuLocatariSp.h"

#ifndef EPSILON
#define EPSILON 0.0000001
#endif

using std::cout;

//Vector<int> TesteLocatar::vector_ajutor()const {
//	Vector<int> a;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
//	return a;
//}
//
//void TesteLocatar::ruleaza_teste_vector()const {
//	cout << "		Se ruleaza testele pentru vector;\n";
//	Vector<int> va;
//	va.push_back(3);
//	const auto cp0 = va.capacitate;
//	va.resize();
//	assert(va.capacitate == 2*cp0);
//	assert(va.at(0) == 3);
//	Vector<int> v;
//	assert(v.size() == 0);
//	v.push_back(5);
//	assert(v.size() == 1);
//	//assert(v[0] == 5);
//	assert(v.at(0) == 5);
//	assert(v.get(0) == 5);
//	v.push_back(7);
//	assert(v.size() == 2);
//	//assert(v[0] == 5);
//	assert(v.at(0) == 5);
//	assert(v.get(0) == 5);
//	//assert(v[1] == 7);
//	assert(v.at(1) == 7);
//	assert(v.get(1) == 7);
//	const Vector<int> v0(v);
//	assert(v0.size() == 2);
//	//assert(v0[0] == 5);
//	assert(v0.at(0) == 5);
//	//assert(v0[1] == 7);
//	assert(v0.at(1) == 7);
//	const Vector<int> v1 = v;
//	assert(v1.size() == 2);
//	assert(v1.at(0) == 5);
//	assert(v1.at(1) == 7);
//	v = Vector<int>();
//	v = v0;
//	assert(v.size() == 2);
//	assert(v.at(0) == 5);
//	assert(v.at(1) == 7);
//	const Vector<int> v2(this->vector_ajutor());
//	assert(v2.size() == 3);
//	assert(v2.at(0) == 1);
//	assert(v2.at(1) == 2);
//	assert(v2.at(2) == 3);
//	v = this->vector_ajutor();
//	assert(v.size() == 3);
//	assert(v.at(0) == 1);
//	assert(v.at(1) == 2);
//	assert(v.at(2) == 3);
//	v = v;
//	assert(v.size() == 3);
//	assert(v.at(0) == 1);
//	assert(v.at(1) == 2);
//	assert(v.at(2) == 3);
//	v = Vector<int>();
//	for (int i = 0; i < 10; i++)
//		v.push_back(i);
//	for (int i = 0; i < 10; i++)
//		assert(v.at(i) == i);
//	int contor = 0;
//	auto it0 = v.begin();
//	for (; it0 != v.end(); ++it0) {
//		assert(it0 == v.begin() + contor);
//		assert(it0.valid());
//		assert(*it0 == contor);
//		contor++;
//	}
//	assert(!it0.valid());
//	--it0;
//	assert(*it0 == 9);
//	auto p0 = v.begin()+2;
//	assert(*p0 == 2);
//	auto p1 = v.end()-2;
//	assert(*p1 == 8);
//	const Vector<int> v3(v);
//	contor = 0;
//	auto it00 = v3.begin();
//	for (; it00 != v3.end(); ++it00) {
//		assert(it00 == v3.begin() + contor);
//		assert(it00.valid());
//		assert(*it00 == contor);
//		contor++;
//	}
//	assert(!it00.valid());
//	--it00;
//	assert(*it00 == 9);
//	auto p00 = v3.begin() + 2;
//	assert(*p00 == 2);
//	auto p10 = v3.end() - 2;
//	assert(*p10 == 8);
//	v.erase(v.begin()+2);
//	v.erase(v.end() - 2);
//	assert(v.size() == 8);
//	assert(v.at(0) == 0);
//	assert(v.at(1) == 1);
//	assert(v.at(2) == 3);
//	assert(v.at(3) == 4);
//	assert(v.at(4) == 5);
//	assert(v.at(5) == 6);
//	assert(v.at(6) == 7);
//	assert(v.at(7) == 9);
//	v = Vector<int>();
//	for (int i = 0; i < 5; i++)
//		v.push_back(i);
//	for (int i = 0; i < 5; i++)
//		v.insert(v.begin() + i/2,10*i);
//	assert(v.size() == 10);
//	assert(v.at(0) == 10);
//	assert(v.at(1) == 30);
//	assert(v.at(2) == 40);
//	assert(v.at(3) == 20);
//	assert(v.at(4) == 0);
//	assert(v.at(5) == 0);
//	assert(v.at(6) == 1);
//	assert(v.at(7) == 2);
//	assert(v.at(8) == 3);
//	assert(v.at(9) == 4);
//	const auto It1 = v.begin();
//	auto It2 = v.begin();
//	assert(It1 == It2);
//	assert((It1 != It2)==false);
//	++It2;
//	assert(It1 != It2);
//	assert((It1 == It2) == false);
//	const auto It3 = v1.begin();
//	assert(It3 != It1);
//	assert((It3 == It1) == false);
//	Vector<int>& vs = v;
//	const auto It4 = vs.begin();
//	assert(It4 == It1);
//	assert((It4 != It1) == false);
//	cout << "		Teste de vector rulate cu succes;\n";
//}

void TesteLocatar::ruleaza_teste_domeniu()const {
	cout << "		Se ruleaza testele domeniului...\n";
	Locatar l0;
	assert(l0.get_apartament() == 0);
	assert(l0.get_nume_proprietar().compare("") == 0);
	assert(l0.get_suprafata() == +0.0);
	assert(l0.get_tip_apartament().compare("") == 0);
	Locatar l(1, "john", 10.0, "pent");
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("john")==0);
	assert(l.get_suprafata() == 10.0);
	assert(l.get_tip_apartament().compare("pent")==0);
	l.set_nume_proprietar("Dan");
	l.set_suprafata(3.0);
	l.set_tip_apartament("house");
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("Dan") == 0);
	assert(l.get_suprafata() == 3.0);
	assert(l.get_tip_apartament().compare("house") == 0);
	Locatar l1(2, "john", 10.0, "pent"), l2(1, "dan", 3, "d");
	assert((l == l1) == false);
	assert((l == l2) == true);
	assert((l != l1) == true);
	assert((l != l2) == false);
	l2 = l1;
	assert(l2.get_apartament() == 2);
	assert(l2.get_nume_proprietar().compare("john") == 0);
	assert(fabs(l2.get_suprafata() - 10.00)<EPSILON);
	assert(l2.get_tip_apartament().compare("pent") == 0);
	std::ofstream fout("testing/test_ostream_locatar.txt");
	const auto fflags = fout.flags();
	const auto fprec = fout.precision();
	assert(fout.flags() == fflags);
	assert(fout.precision() == fprec);
	fout << l;
	assert(fout.precision() == fprec);
	assert(fout.flags() == fflags);
	fout.close();
	std::ifstream fin("testing/test_ostream_locatar.txt");
	string locatar_citit;
	getline(fin, locatar_citit);
	assert(locatar_citit.compare("Locatar - Apartament:1; Proprietar:Dan; Suprafata:3.000000; Tip Apartament:house") == 0);
	fin.close();
	Locatar l3(l2);
	assert(l3.get_apartament() == 2);
	assert(l3.get_nume_proprietar().compare("john") == 0);
	assert(fabs(l3.get_suprafata() - 10.00) < EPSILON);
	assert(l3.get_tip_apartament().compare("pent") == 0);
	cout << "		Teste de domeniu rulate cu succes;\n";
}

void TesteLocatar::ajutor_oops()const {
	throw ExceptieGenerala("oops");
}

void TesteLocatar::ruleaza_teste_exceptie_generala()const {
	cout << "		Se ruleaza testele pentru exceptie generala;\n";

	ExceptieGenerala e("aceasta este o eroare");
	assert(e.get_mesaj().compare("aceasta este o eroare") == 0);
	try {
		this->ajutor_oops();
		assert(false);
	}
	catch (const ExceptieGenerala& eroare) {
		assert(eroare.get_mesaj().compare("oops") == 0);
	}

	cout << "		Teste de exceptie generala rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_validator()const {
	cout << "		Se ruleaza testele de validare;\n";
	ValidatorLocatar val;
	vector<int> nr;
	nr.push_back(0);
	nr.push_back(1);
	vector<string> n;
	n.push_back("");
	n.push_back("Geo");
	vector<double> s ;
	s.push_back(+0.0);
	s.push_back(12);
	vector<string> t;
	t.push_back("");
	t.push_back("penthouse");
	for (int i = 0; i < 16; i++) {
		Locatar l(nr.at(i%2),n.at((i/2)%2),s.at((i/4)%2),t.at((i/8)%2));
		try {
			val.valideaza_locatar(l);
			if (i != 15)
				assert(false);}
		catch (const ExceptieValidareLocatar& er) {
			if (i == 15)
				assert(false);
			string eroare{ "" };
			if (i%2==0)
				eroare += "Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n";
			if ((i/2)%2==0)
				eroare += "Eroare: Numele proprietarului trebuie sa fie un string nevid;\n";
			if ((i/4)%2==0)
				eroare += "Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n";
			if ((i/8)%2==0)
				eroare += "Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n";
			assert(er.get_mesaj().compare(eroare)==0);
		}
	}
	val.valideaza_apartament(3);
	try {
		val.valideaza_apartament(0);
		assert(false);
	}
	catch (const ExceptieValidareLocatar& er) {
		assert(er.get_mesaj().compare("Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n") == 0);
	}

	val.valideaza_suprafata(4);
	try {
		val.valideaza_suprafata(+0.0);
		assert(false);
	}
	catch (const ExceptieValidareLocatar& er) {
		assert(er.get_mesaj().compare("Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n") == 0);
	}

	val.valideaza_tip_apartament("gondola");
	try {
		val.valideaza_tip_apartament("");
		assert(false);
	}
	catch (const ExceptieValidareLocatar& er) {
		assert(er.get_mesaj().compare("Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n") == 0);
	}

	cout << "		Teste de validare rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_repozitoriu()const {
	cout << "		Se ruleaza testele de repozitoriu;\n";

	RepozitoriuLocatari repo;
	const vector<Locatar>& v0 = repo.get_all();
	assert(v0.size() == 0);
	Locatar l(1, "a", 1.00, "c");
	repo.adauga(l);
	const vector<Locatar>& v = repo.get_all();
	assert(v.size() == 1);
	auto it = v.begin();
	l = *it;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	try {
		repo.adauga(l);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Exista deja un locatar cu acest apartament\n") == 0);
	}



	l=Locatar(2, "g", 10.02, "d");
	repo.adauga(l);
	const vector<Locatar>& v3 = repo.get_all();
	auto it1 = v3.begin();
	l = *it1;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	++it1;
	l = *it1;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	vector<Locatar> ve = repo.get_all();

	auto ite = ve.begin();
	l = *ite;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	++ite;
	l = *ite;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	*ite = Locatar(100,"100",100,"100");

	ve = repo.get_all();

	auto ite1 = ve.begin();
	l = *ite1;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	++ite1;
	l = *ite1;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	l = Locatar(1, "z", 5.55, "x");
	Locatar lrez = repo.modifica(l);
	assert(lrez.get_apartament() == 1);
	assert(lrez.get_nume_proprietar() == "a");
	const vector<Locatar>& v4 = repo.get_all();

	assert(v4.size() == 2);
	auto it4 = v4.begin();
	l =*it4;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("z") == 0);
	assert(l.get_suprafata() == 5.55);
	assert(l.get_tip_apartament().compare("x") == 0);

	++it4;
	l = *it4;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);
	l = Locatar(3, "a", 30, "d");
	try {
		repo.modifica(l);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	l = repo.cauta(2);
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);



	try {
		repo.cauta(3);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	try {
		repo.sterge(3);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	lrez = repo.sterge(1);
	assert(lrez.get_apartament() == 1);
	const vector<Locatar>& v5 = repo.get_all();
	assert(v.size() == 1);

	auto it5 = v5.begin();
	l = *it5;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);
	

	cout << "		Teste de repozitoriu rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_serviciu() const{

	cout << "		Se ruleaza testele pentru serviciu;\n";
	RepozitoriuLocatari repo;
	ValidatorLocatar valid;
	ListaNotificare lista_n(repo);
	ServiciuLocatari serv(repo,valid,lista_n);
	const vector<Locatar>& v0 = serv.get_all();
	assert(v0.size() == 0);
	serv.adauga(1, "Klein", 10.0, "loop");
	const vector<Locatar>& v = serv.get_all();
	assert(v.size() == 1);
	auto it = v.begin();
	Locatar l = *it;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("Klein") == 0);
	assert(l.get_suprafata() == 10.0);
	assert(l.get_tip_apartament().compare("loop") == 0);
	try {
		serv.adauga(1, "", -2.0, "dans");
		assert(false);
	}
	catch (const ExceptieValidareLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Numele proprietarului trebuie sa fie un string nevid;\nEroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n") == 0);
	}
	try {
		serv.adauga(1, "da", 2, "d");
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Exista deja un locatar cu acest apartament\n") == 0);
	}
	serv.adauga(3, "da", 10.0, "penthouse");

	l = serv.cauta(1);
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("Klein") == 0);
	assert(l.get_suprafata() == 10.0);
	assert(l.get_tip_apartament().compare("loop") == 0);


	try {
		serv.cauta(-1);
		assert(false);
	}
	catch (const ExceptieValidareLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n") == 0);
	}
	try {
		serv.cauta(2);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	serv.modifica(1, "ciaociao", 13.33, "dubas");
	const vector<Locatar>& v1 = serv.get_all();
	assert(v1.size() == 2);
	l = serv.cauta(1);
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("ciaociao") == 0);
	assert(l.get_suprafata() == 13.33);
	assert(l.get_tip_apartament().compare("dubas") == 0);

	l = serv.cauta(3);
	assert(l.get_apartament() == 3);
	assert(l.get_nume_proprietar().compare("da") == 0);
	assert(l.get_suprafata() == 10.00);
	assert(l.get_tip_apartament().compare("penthouse") == 0);

	try {
		serv.modifica(1, "", -2.0, "dans");
		assert(false);
	}
	catch (const ExceptieValidareLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Numele proprietarului trebuie sa fie un string nevid;\nEroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n") == 0);
	}
	try {
		serv.modifica(4, "da", 2, "d");
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	try {
		serv.sterge(-1);
		assert(false);
	}
	catch (const ExceptieValidareLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n") == 0);
	}
	try {
		serv.sterge(2);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	serv.sterge(1);
	const vector<Locatar>& v3 = serv.get_all();
	assert(v3.size() == 1);
	l = serv.cauta(3);
	assert(l.get_apartament() == 3);
	assert(l.get_nume_proprietar().compare("da") == 0);
	assert(l.get_suprafata() == 10.00);
	assert(l.get_tip_apartament().compare("penthouse") == 0);

	cout << "		Teste de serviciu rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_conversii()const {
	cout << "		Se ruleaza testele pentru conversii;\n";

	int valoare;
	string2int("-123", valoare);
	assert(valoare == -123);
	try {
		string2int("-123a", valoare);
		assert(false);
	}
	catch (const ExceptieInputData& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Acest camp primeste intregi de pana la 9 cifre;\n") == 0);
	}
	try {
		string2int("1000000000", valoare);
		assert(false);
	}
	catch (const ExceptieInputData& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Acest camp primeste intregi de pana la 9 cifre;\n") == 0);
	}

	assert(valoare == -123);

	double val;
	string2double("12.33", val);
	assert(fabs(val-12.33) <EPSILON);

	try {
		string2double("12.33.33", val);
		assert(false);
	}
	catch (const ExceptieInputData& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Acest camp primeste valori reale cu maxim 6 cifre inainte si dupa virgula;\n") == 0);
	}
	try {
		string2double("1.0000000000000", val);
		assert(false);
	}
	catch (const ExceptieInputData& eroare) {
		assert(eroare.get_mesaj().compare("Eroare: Acest camp primeste valori reale cu maxim 6 cifre inainte si dupa virgula;\n") == 0);
	}

	assert(fabs(val - 12.33) < EPSILON);

	cout << "		Teste conversii rulate cu succes;\n";
}

//void TesteLocatar::ruleaza_teste_pentru_sortari()const {
//	cout << "		Se ruleaza testele pentru sortari;\n";
//
//	Vector<int> v;
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(4);
//	v.push_back(-2);
//	v.push_back(-100);
//	v.push_back(4);
//	Vector<int> vc(v);
//	Vector<int> vc2(v);
//	vc2.at(5) = -43;
//	std::function<int(const int&, const int&)> comp = [](const int& a, const int& b)noexcept {if (a < b)return -1; if (a == b)return 0; return 1; };
//	sorteaza_vector(v.begin(), v.end(), 1, comp);
//	sorteaza_vector(vc.begin(), vc.end(), -1, comp);
//	sorteaza_vector(vc2.begin() + 2, vc2.end() - 1, 1, comp);
//	assert(v.at(0) == -100);
//	assert(v.at(1) == -2);
//	assert(v.at(2) == 2);
//	assert(v.at(3) == 3);
//	assert(v.at(4) == 4);
//	assert(v.at(5) == 4);
//	assert(vc.at(5) == -100);
//	assert(vc.at(4) == -2);
//	assert(vc.at(3) == 2);
//	assert(vc.at(2) == 3);
//	assert(vc.at(1) == 4);
//	assert(vc.at(0) == 4);
//	assert(vc2.at(0) == 3);
//	assert(vc2.at(1) == 2);
//	assert(vc2.at(2) == -100);
//	assert(vc2.at(3) == -2);
//	assert(vc2.at(4) == 4);
//	assert(vc2.at(5) == -43);
//
//	Locatar l1(1, "1", 1, "1");
//	Locatar l2(2, "2", 2, "2");
//	Locatar l3(3, "1", 1, "1");
//	Locatar l4(4, "1", 2, "1");
//	assert(compara_locatari_nume_proprietar(l1, l2) == -1);
//	assert(compara_locatari_nume_proprietar(l1, l3) == -1);
//	assert(compara_locatari_nume_proprietar(l1, l1) == 0);
//	assert(compara_locatari_nume_proprietar(l2, l1) == 1);
//
//	assert(compara_locatari_suprafata(l1, l2) == -1);
//	assert(compara_locatari_suprafata(l1, l3) == -1);
//	assert(compara_locatari_suprafata(l1, l1) == 0);
//	assert(compara_locatari_suprafata(l2, l1) == 1);
//
//
//	assert(compara_locatari_tip_apartament_si_suprafata(l1, l2) == -1);
//	assert(compara_locatari_tip_apartament_si_suprafata(l1, l4) == -1);
//	assert(compara_locatari_tip_apartament_si_suprafata(l1, l3) == -1);
//	assert(compara_locatari_tip_apartament_si_suprafata(l1, l1) == 0);
//	assert(compara_locatari_tip_apartament_si_suprafata(l4, l1) == 1);
//
//
//
//	cout << "		Teste pentru sortari rulate cu succes;\n";
//}
//
//void TesteLocatar::ruleaza_teste_pentru_filtrari()const {
//	cout << "		Se ruleaza testele pentru filtrari;\n";
//	Vector<int> v0;
//	v0.push_back(2);
//	v0.push_back(6);
//	v0.push_back(3);
//	v0.push_back(10);
//	v0.push_back(3);
//	v0.push_back(4);
//	v0.push_back(1);
//
//	const Vector<int> v(v0);
//
//	std::function<int(const int&,const int&)> filtru_int= [](const int& a, const int& crit)noexcept {if (a < crit) return -1; if (a == crit)return 0; return 1; };
//
//	Vector<int> rez = filtreaza_vector(v.begin(), v.end(), 1, 4, filtru_int);
//	assert(rez.at(0) == 6);
//	assert(rez.at(1) == 10);
//	assert(rez.at(2) == 4);
//
//	rez = filtreaza_vector(v.begin() + 2, v.end() - 1, -1, 4, filtru_int);
//
//	assert(rez.at(0) == 3);
//	assert(rez.at(1) == 3);
//	assert(rez.at(2) == 4);
//
//	Locatar l(1, "Dan", 13, "dopamine");
//	assert(filtru_tip_apartament(l, "dopa") == 1);
//	assert(filtru_tip_apartament(l, "dope") == -1);
//	assert(filtru_suprafata(l, 13.01) == -1);
//	assert(filtru_suprafata(l, 13) == 0);
//	assert(filtru_suprafata(l, 12.99) == 1);
//
//
//	cout << "		Teste pentru filtrari rulate cu succes;\n";
//}

void TesteLocatar::ruleaza_teste_pentru_serviciu_sort_filtru()const {
	cout << "		Se ruleaza testele pentru sortare si filtrare serviciu;\n";

	RepozitoriuLocatari repo;
	ValidatorLocatar validator;
	ListaNotificare lista_n(repo);
	ServiciuLocatari serv(repo, validator, lista_n);
	serv.adauga(100, "200", 200, "200");
	serv.adauga(200, "100", 200, "200");
	serv.adauga(300, "300", 300, "200");
	serv.adauga(400, "100", 400, "400");
	serv.adauga(500, "500", 500, "100");
	vector<Locatar> v = serv.sorteaza(0, 1);
	assert(v.at(0).get_apartament() == 200);
	assert(v.at(1).get_apartament() == 400);
	assert(v.at(2).get_apartament() == 100);
	assert(v.at(3).get_apartament() == 300);
	assert(v.at(4).get_apartament() == 500);
	v = serv.sorteaza(2, -1);
	assert(v.at(0).get_apartament() == 400);
	assert(v.at(1).get_apartament() == 300);
	assert(v.at(2).get_apartament() == 200);
	assert(v.at(3).get_apartament() == 100);
	assert(v.at(4).get_apartament() == 500);
	v = serv.sorteaza(1, -1);
	assert(v.at(0).get_apartament() == 500);
	assert(v.at(1).get_apartament() == 400);
	assert(v.at(2).get_apartament() == 300);
	assert(v.at(3).get_apartament() == 200);
	assert(v.at(4).get_apartament() == 100);


	try {
		serv.filtreaza("", 1);
		assert(false);
	}
	catch (const ExceptieValidareLocatar& ex) {
		assert(ex.get_mesaj().compare("Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n") == 0);
	}

	v = serv.filtreaza("20", 1);
	assert(v.size() == 3);
	assert(v.at(0).get_apartament() == 100);
	assert(v.at(1).get_apartament() == 200);
	assert(v.at(2).get_apartament() == 300);
	v = serv.filtreaza("20", -1);

	assert(v.size() == 2);
	assert(v.at(0).get_apartament() == 400);
	assert(v.at(1).get_apartament() == 500);


	try {
		serv.filtreaza(+0.0, -1);
		assert(false);
	}
	catch (const ExceptieValidareLocatar& ex) {
		assert(ex.get_mesaj().compare("Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n") == 0);
	}

	v = serv.filtreaza(300, 1);
	assert(v.size() == 3);
	assert(v.at(0).get_apartament() == 300);
	assert(v.at(1).get_apartament() == 400);
	assert(v.at(2).get_apartament() == 500);


	v = serv.filtreaza(300, -1);
	assert(v.size() == 3);
	assert(v.at(0).get_apartament() == 100);
	assert(v.at(1).get_apartament() == 200);
	assert(v.at(2).get_apartament() == 300);



	cout << "		Teste pentru sortare si filtrare serviciu rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_lista_notificare() const
{
	cout << "		Se ruleaza testele pentru lista de notificare;\n";
	RepozitoriuLocatari r;
	ListaNotificare l(r);
	try {
		l.adauga(1);
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n")==0);
	}
	try {
		l.genereaza(2);
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Nu exista apartamente pentru adaugat;\n")==0);
	}
	r.adauga(Locatar(1,"1",1,"1"));
	l.adauga(1);
	const auto v = l.get_all();
	assert(v.size() == 1);
	assert(v.at(0).get_apartament() == 1);
	r.adauga(Locatar(2, "2", 2, "2"));
	r.adauga(Locatar(10, "10", 10, "10"));
	l.genereaza(10);
	const auto v2 = l.get_all();
	assert(v2.size() == 11);
	for (const auto& elem : v2) {
		const auto ap = elem.get_apartament();
		assert(ap == 1 || ap == 2 || ap == 10);
	}
	l.goleste();
	const auto v3 = l.get_all();
	assert(v3.size() == 0);
	l.adauga(1);
	l.adauga(10);
	l.adauga(2);
	try {
		l.export_list_csv("asd/asd");
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Nu s-a putut crea fisierul;\n") == 0);
	}

	try {
		l.export_list_html("asd/asd");
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Nu s-a putut crea fisierul;\n") == 0);
	}

	l.export_list_csv("testing/csv_test");
	std::ifstream fin("testing/csv_test.csv");
	string temp_cont;
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("1;1;1;1") == 0);
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("10;10;10;10") == 0);
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("2;2;2;2") == 0);
	std::getline(fin, temp_cont);
	assert(fin.eof());
	fin.close();
	l.export_list_html("testing/html_test");
	fin.open("testing/html_test.html");
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("<html><body>")==0);
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("1;1;1;1<br>") == 0);
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("10;10;10;10<br>") == 0);
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("2;2;2;2<br>") == 0);
	std::getline(fin, temp_cont);
	assert(temp_cont.compare("</body></html>")==0);
	assert(fin.eof());
	fin.close();

	cout << "		Teste pentru lista de notificare rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_serviciu_ln() const
{
	cout << "		Se ruleaza testele serviciu lista de notificare;\n";
	RepozitoriuLocatari r;
	ListaNotificare l(r);
	ValidatorLocatar v;
	ServiciuLocatari serv(r, v, l);
	serv.adauga(1, "1", 1, "1");
	serv.adauga(3, "3", 3, "3");
	try {
		serv.ln_adauga(0);
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n") == 0);
	}
	serv.ln_adauga(3);
	serv.ln_adauga(1);
	const vector<Locatar>& l1 = serv.ln_get_all();
	assert(l1.size() == 2);
	assert(l1.at(0).get_apartament() == 3);
	serv.ln_goleste();
	const auto& l2 = serv.ln_get_all();
	assert(l2.size() == 0);
	try {
		serv.ln_genereaza(0);
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Numarul trebuie sa fie un intreg strict pozitiv;\n") == 0);
	}
	serv.ln_genereaza(3);
	const auto& l3 = serv.ln_get_all();
	assert(l3.size() == 3);
	serv.ln_goleste();
	serv.ln_adauga(1);
	serv.ln_adauga(3);
	serv.ln_adauga(1);
	try {
		serv.ln_export_list_csv("");
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Stringul nu poate fi vid;\n") == 0);
	}
	serv.ln_export_list_csv("testing/serv_csv");
	std::ifstream fin;
	fin.open("testing/serv_csv.csv");
	string s;
	std::getline(fin, s);
	assert(s.compare("1;1;1;1") == 0);
	fin.close();
	try {
		serv.ln_export_list_html("");
		assert(false);
	}
	catch (const ExceptieListaNotificare& er) {
		assert(er.get_mesaj().compare("Eroare: Stringul nu poate fi vid;\n") == 0);
	}
	serv.ln_export_list_html("testing/serv_html");
	fin.open("testing/serv_html.html");
	std::getline(fin, s);
	assert(s.compare("<html><body>") == 0);
	std::getline(fin, s);
	assert(s.compare("1;1;1;1<br>") == 0);
	fin.close();

	cout << "		Teste serviciu lista de notificare rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_repo_fisier() const
{
	cout << "		Se ruleaza testele de repo de fisier;\n";
	RepozitoriuLocatariFisier repfals;
	repfals.nume_fisier = "testing/nu/nu_exista";
	try {
		repfals.incarca_din_fisier();
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj().compare("Eroare: Fisierul cautat nu poate fi deschis;\n") == 0);
	}
	try {
		repfals.salveaza_in_fisier();
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj().compare("Eroare: Fisierul cautat nu poate fi deschis;\n") == 0);
	}
	RepozitoriuLocatariFisier repgood;
	repgood.nume_fisier = "testing/test_repgood.txt";
	repgood.elemente.push_back(Locatar(4, "4", 4, "4"));
	repgood.elemente.push_back(Locatar(3, "3", 3, "3"));
	repgood.salveaza_in_fisier();

	std::ifstream fin("testing/test_repgood.txt");
	string buff;
	int k = 4;
	while(k>0){
		k--;
		getline(fin, buff);
		if(k!=1)
			assert(buff.compare("4") == 0);
		else
			assert(buff.compare("4.000000") == 0);
	}
	k = 4;
	while(k>0){
		k--;
		getline(fin, buff);
		if (k != 1)
			assert(buff.compare("3") == 0);
		else
			assert(buff.compare("3.000000") == 0);
	}
	getline(fin, buff);
	assert(fin.eof());
	fin.close();

	repgood.elemente.clear();
	assert(repgood.elemente.size() == 0);
	repgood.incarca_din_fisier();
	const auto l1 = repgood.elemente.at(1);
	const auto l2 = repgood.elemente.at(0);
	assert(l1.get_apartament() == 4);
	assert(l1.get_nume_proprietar() == "4");
	assert(l1.get_suprafata() == 4);
	assert(l1.get_tip_apartament() == "4");
	assert(l2.get_apartament() == 3);
	assert(l2.get_nume_proprietar() == "3");
	assert(l2.get_suprafata() == 3);
	assert(l2.get_tip_apartament() == "3");

	RepozitoriuLocatariFisier repo_fisier("testing/test_repgood.txt");
	const auto& v1 = repo_fisier.get_all();
	assert(v1.size() == 2);
	assert(v1.at(1).get_apartament() == 4);
	assert(v1.at(0).get_apartament() == 3);
	repo_fisier.adauga(Locatar(1, "1", 1, "1"));
	assert(repo_fisier.get_all().size() == 3);
	assert(repo_fisier.get_all().at(0).get_apartament() == 1);
	Locatar lrez = repo_fisier.sterge(3);
	assert(lrez.get_apartament() == 3);
	assert(repo_fisier.get_all().size() == 2);
	assert(repo_fisier.get_all().at(1).get_apartament() == 4);
	lrez = repo_fisier.modifica(Locatar(1, "2", 3, "4"));
	assert(lrez.get_apartament() == 1);
	assert(lrez.get_nume_proprietar() == "1");
	assert(repo_fisier.get_all().size() == 2);
	assert(repo_fisier.get_all().at(0).get_apartament() == 1);
	assert(repo_fisier.get_all().at(0).get_nume_proprietar() == "2");
	assert(repo_fisier.get_all().at(0).get_suprafata() == 3);
	assert(repo_fisier.get_all().at(0).get_tip_apartament() == "4");

	cout << "		Teste repo de fisier rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_actiune_undo() const
{
	cout << "		Se ruleaza testele pentru actiune undo;\n";
	RepozitoriuLocatari r;
	r.adauga(Locatar(1, "1", 1, "1"));
	UndoAdauga ua(r, 1);
	ua.doUndo();
	assert(r.get_all().size() == 0);
	r.adauga(Locatar(1,"1",1,"1"));
	UndoSterge us(r, Locatar(2, "2", 2, "2"));
	us.doUndo();
	assert(r.get_all().size() == 2);
	assert(r.get_all().at(1).get_apartament() == 2);
	UndoModifica um(r, Locatar(1, "2", 3, "4"));
	um.doUndo();
	assert(r.get_all().size() == 2);
	assert(r.get_all().at(0).get_apartament() == 1);
	assert(r.get_all().at(0).get_nume_proprietar() == "2");


	cout << "		Teste pentru actiune undo rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_undo() const{
	cout << "		Se ruleaza testele pentru undo;\n";
	RepozitoriuLocatari repo;
	const ValidatorLocatar valid;
	ListaNotificare listan(repo);
	ServiciuLocatari serv(repo, valid, listan);
	try {
		serv.undo();
		assert(false);
	}
	catch (const ExceptieUndo& eroare) {
		assert(eroare.get_mesaj().compare("Eroare:Nu exista actiuni precedente pentru a da undo;\n") == 0);
	}
	serv.adauga(3, "3", 3, "3");
	serv.adauga(1, "1", 1, "1");
	serv.modifica(1, "2", 3, "4");
	serv.sterge(3);
	assert(serv.get_all().size() == 1);
	serv.undo();
	assert(serv.get_all().size() == 2);
	assert(serv.get_all().at(1).get_apartament() == 3);
	assert(serv.get_all().at(0).get_apartament() == 1);
	assert(serv.get_all().at(0).get_nume_proprietar() == "2");
	serv.undo();
	assert(serv.get_all().size() == 2);
	assert(serv.get_all().at(1).get_apartament() == 3);
	assert(serv.get_all().at(0).get_apartament() == 1);
	assert(serv.get_all().at(0).get_nume_proprietar() == "1");
	serv.undo();
	assert(serv.get_all().size() == 1);
	assert(serv.get_all().at(0).get_apartament() == 3);
	serv.undo();
	assert(serv.get_all().size() == 0);
	try {
		serv.undo();
		assert(false);
	}
	catch (const ExceptieUndo& eroare) {
		assert(eroare.get_mesaj().compare("Eroare:Nu exista actiuni precedente pentru a da undo;\n") == 0);
	}
	cout << "		Teste pentru undo rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_raport() const
{
	cout << "		Se ruleaza teste de raport...\n";
	ValidatorLocatar valid;
	RepozitoriuLocatari  repo;
	ListaNotificare listn(repo);
	ServiciuLocatari serv(repo, valid, listn);

	serv.adauga(1, "1", 1, "1");
	serv.adauga(2, "1", 1, "asd");
	serv.adauga(3, "1", 1, "3");
	serv.adauga(4, "1", 1, "4");
	serv.adauga(5, "1", 1, "4");
	serv.adauga(6, "1", 1, "4");
	serv.adauga(7, "1", 1, "asd");
	serv.adauga(8, "1", 1, "1");
	const auto rez = serv.raport_tip();
	assert(rez.at("1") == 2);
	assert(rez.at("asd") == 2);
	assert(rez.at("3") == 1);
	assert(rez.at("4") == 3);

	cout << "		Teste de raport rulate cu succes;\n";
}

void TesteLocatar::ruleaza_teste_repo_sp() const
{
	cout << "		Se ruleaza testele de repo special...\n";


	RepozitoriuLocatariSp repo(0);
	const vector<Locatar>& v0 = repo.get_all();
	assert(v0.size() == 0);
	Locatar l(1, "a", 1.00, "c");
	repo.adauga(l);
	const vector<Locatar>& v = repo.get_all();
	assert(v.size() == 1);
	auto it = v.begin();
	l = *it;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	try {
		repo.adauga(l);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Exista deja un locatar cu acest apartament\n") == 0);
	}



	l = Locatar(2, "g", 10.02, "d");
	repo.adauga(l);
	const vector<Locatar>& v3 = repo.get_all();
	auto it1 = v3.begin();
	l = *it1;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	++it1;
	l = *it1;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	vector<Locatar> ve = repo.get_all();

	auto ite = ve.begin();
	l = *ite;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	++ite;
	l = *ite;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	*ite = Locatar(100, "100", 100, "100");

	ve = repo.get_all();

	auto ite1 = ve.begin();
	l = *ite1;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("a") == 0);
	assert(l.get_suprafata() == 1.00);
	assert(l.get_tip_apartament().compare("c") == 0);

	++ite1;
	l = *ite1;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	l = Locatar(1, "z", 5.55, "x");
	Locatar lrez = repo.modifica(l);
	assert(lrez.get_apartament() == 1);
	assert(lrez.get_nume_proprietar() == "a");
	const vector<Locatar>& v4 = repo.get_all();

	assert(v4.size() == 2);
	auto it4 = v4.begin();
	l = *it4;
	assert(l.get_apartament() == 1);
	assert(l.get_nume_proprietar().compare("z") == 0);
	assert(l.get_suprafata() == 5.55);
	assert(l.get_tip_apartament().compare("x") == 0);

	++it4;
	l = *it4;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);
	l = Locatar(3, "a", 30, "d");
	try {
		repo.modifica(l);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	l = repo.cauta(2);
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);



	try {
		repo.cauta(3);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	try {
		repo.sterge(3);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& err) {
		assert(err.get_mesaj().compare("Eroare: Nu exista un locatar cu acest apartament\n") == 0);
	}

	lrez = repo.sterge(1);
	assert(lrez.get_apartament() == 1);
	const vector<Locatar>& v5 = repo.get_all();
	assert(v.size() == 1);

	auto it5 = v5.begin();
	l = *it5;
	assert(l.get_apartament() == 2);
	assert(l.get_nume_proprietar().compare("g") == 0);
	assert(l.get_suprafata() == 10.02);
	assert(l.get_tip_apartament().compare("d") == 0);

	repo.soarta();
	repo.soarta();
	repo.soarta();

	RepozitoriuLocatariSp repos(1);
	try {
		repos.soarta();
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj() == "Eroare: >:(  ;\n");
	}
	try {
		repos.sterge(1);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj() == "Eroare: >:(  ;\n");
	}
	try {
		repos.adauga(Locatar(1,"1",1,"1"));
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj() == "Eroare: >:(  ;\n");
	}
	try {
		repos.modifica(Locatar(1, "1", 1, "1"));
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj() == "Eroare: >:(  ;\n");
	}
	try {
		repos.cauta(1);
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj() == "Eroare: >:(  ;\n");
	}
	try {
		repos.get_all();
		assert(false);
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		assert(er.get_mesaj() == "Eroare: >:(  ;\n");
	}




	cout << "		Toate testele de repo special rulate cu succes;\n";
}

void TesteLocatar::ruleaza_toate_testele() const{
	cout << "Se ruleaza toate testele...\n";
	//this->ruleaza_teste_vector();
	this->ruleaza_teste_domeniu();
	this->ruleaza_teste_exceptie_generala();
	this->ruleaza_teste_validator();
	this->ruleaza_teste_repozitoriu();
	this->ruleaza_teste_serviciu();
	this->ruleaza_teste_conversii();
	//this->ruleaza_teste_pentru_sortari();
	//this->ruleaza_teste_pentru_filtrari();
	this->ruleaza_teste_pentru_serviciu_sort_filtru();
	this->ruleaza_teste_lista_notificare();
	this->ruleaza_teste_serviciu_ln();
	this->ruleaza_teste_repo_fisier();
	this->ruleaza_teste_actiune_undo();
	this->ruleaza_teste_undo();
	this->ruleaza_teste_raport();
	this->ruleaza_teste_repo_sp();
	cout << "Toate testele rulate cu succes;\n";
}