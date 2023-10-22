#include "UILocatari.h"
#include "ExceptiiLocatar.h"
#include "Conversii.h"
#include <iostream>

using std::cout;
using std::cin;
using std::getline;

UILocatari::UILocatari(ServiciuLocatari& serv0) :serv{ serv0 } {
	this->initializare_comenzi_const();
	this->initializare_comenzi_non_const();
}

void UILocatari::initializare_comenzi_non_const() {
	this->comenzi_non_const["adauga locatar"] = &UILocatari::ui_adauga_locatar;
	this->comenzi_non_const["sterge locatar"] = &UILocatari::ui_sterge_locatar;
	this->comenzi_non_const["modifica locatar"] = &UILocatari::ui_modifica_locatar;
	this->comenzi_non_const["undo"] = &UILocatari::ui_undo;
	this->comenzi_non_const_ln["goleste lista"]=&UILocatari::ui_ln_goleste;
	this->comenzi_non_const_ln["adauga in lista"]=&UILocatari::ui_ln_adauga;
	this->comenzi_non_const_ln["genereaza lista"]=&UILocatari::ui_ln_genereaza;
}

void UILocatari::initializare_comenzi_const() {
	this->comenzi_const["meniu"] = &UILocatari::ui_meniu;
	this->comenzi_const["afiseaza locatari"] = &UILocatari::ui_afiseaza_locatari;
	this->comenzi_const["cauta locatar"] = &UILocatari::ui_cauta_locatar;
	this->comenzi_const["sorteaza locatari"] = &UILocatari::ui_sorteaza_locatari;
	this->comenzi_const["filtreaza locatari"] = &UILocatari::ui_filtreaza_locatari;
	this->comenzi_const["raport tip"] = &UILocatari::ui_raport_tip;
	this->comenzi_const_ln["meniu"] = &UILocatari::ui_ln_meniu;
	this->comenzi_const_ln["export"] = &UILocatari::ui_ln_export;
	this->comenzi_const_ln["afiseaza lista"] = &UILocatari::ui_ln_afiseaza;
}

void UILocatari::ui_ln_goleste()
{
	this->serv.ln_goleste();
	cout << "Lista a fost golita cu succes;\n";
}

void UILocatari::ui_ln_adauga()
{
	string buffer;
	int apartament;
	cout << "Apartament:";
	getline(cin, buffer);
	string2int(buffer, apartament);
	this->serv.ln_adauga(apartament);
	cout << "Operatie efectuata cu succes;\n";
}

void UILocatari::ui_ln_genereaza()
{
	string buffer;
	int numar;
	cout << "Numar de apartamente de adaugat:";
	getline(cin, buffer);
	string2int(buffer, numar);
	this->serv.ln_genereaza(numar);
	cout << "Operatie efectuata cu succes;\n";
}

void UILocatari::ui_ln_export() const
{
	string buffer;
	cout << "Tipul fisierului de export(csv/html):";
	getline(cin, buffer);
	if (buffer == "csv"||buffer=="html") {
		string nume;
		cout << "Numele fisierului:";
		getline(cin, nume);
		if (buffer == "csv")
			this->serv.ln_export_list_csv(nume);
		else
			this->serv.ln_export_list_html(nume);
		cout << "Operatie efectuata cu succes;\n";
	}
	else {
		cout << "Tipul fisieurlui de export invalid;\n";
	}
}

void UILocatari::ui_ln_afiseaza() const
{
	const vector<Locatar>& l = this->serv.ln_get_all();
	cout << "Lista de nofiicare:\n";
	this->afiseaza_vector_locatari(l);
}

void UILocatari::ui_ln_meniu() const
{
	cout << "Lista de comenzi:\n0.'exit' - iesire din interfata de lista notificare;\n1.'meniu' - afiseaza o lista cu comenzile posibile;\n";
	cout << "2.'goleste lista' - goleste lista de notificare;\n3.'adauga in lista' - adauga locatar in lista de notificare;\n4.'genereaza lista'";
	cout << " - genereaza elemente in lista de notificare;\n5.'export' - exporta locatari din lista de notificare;\n6.'afiseaza lista' - afiseaza lista de notificare;\n";
}


void UILocatari::ui_meniu()const{
	cout << "Lista de comenzi:\n0.'exit' - iesire din interfata de admininstrator;\n1.'meniu' - afiseaza o lista cu comenzile posibile;\n";
	cout << "2.'afiseaza locatari' - afiseaza locatarii din repozitoriu;\n";
	cout << "3.'adauga locatar' - adauga un locatar;\n4.'sterge locatar' - sterge un locatar;\n5.'modifica locatar' - modifica un locatar;\n6.'cauta locatar' - cauta un locatar;\n";
	cout << "7.'filtreaza locatari' - filtreaza locatarii dupa un criteriu;\n8.'sorteaza locatari' - sorteaza locatari dupa un criteriu;\n9.'undo' - anuleaza ultima operatie;\n";
}

void UILocatari::afiseaza_vector_locatari(const vector<Locatar>& v)const {
	cout << "Locatari(" << v.size() << "):\n";
	for (const auto& elem : v)
		cout << elem << "\n";
}

void UILocatari::ui_afiseaza_locatari()const {
	vector<Locatar>v = this->serv.get_all();
	if (v.size() == 0) {
		cout << "Repozitoriu gol;\n";
		return;
	}
	this->afiseaza_vector_locatari(v);
}

void UILocatari::ui_adauga_locatar() {
	string input;
	int apartament;
	string nume_proprietar, tip_apartament;
	double suprafata;


	cout << "Apartamentul:";
	getline(cin, input);
	string2int(input, apartament);

	cout << "Numele proprietarului:";
	getline(cin, nume_proprietar);

	cout << "Suprafata:";
	getline(cin, input);
	string2double(input, suprafata);


	cout << "Tipul apartamentului:";
	getline(cin, tip_apartament);

	this->serv.adauga(apartament, nume_proprietar, suprafata, tip_apartament);
	cout << "Operatie efectuata cu succes;\n";

}

void UILocatari::ui_sterge_locatar() {
	string input;
	int apartament;

	cout << "Apartamentul:";
	getline(cin, input);
	string2int(input, apartament);

	this->serv.sterge(apartament);
	cout << "Operatie efectuata cu succes;\n";

}

void UILocatari::ui_modifica_locatar() {
	string input;
	int apartament;
	string nume_proprietar, tip_apartament;
	double suprafata;


	cout << "Apartamentul:";
	getline(cin, input);
	string2int(input, apartament);

	cout << "Numele proprietarului:";
	getline(cin, nume_proprietar);

	cout << "Suprafata:";
	getline(cin, input);
	string2double(input, suprafata);


	cout << "Tipul apartamentului:";
	getline(cin, tip_apartament);

	this->serv.modifica(apartament, nume_proprietar, suprafata, tip_apartament);
	cout << "Operatie efectuata cu succes;\n";

}

void UILocatari::ui_cauta_locatar() const{
	string input;
	int apartament;

	cout << "Apartamentul:";
	getline(cin, input);
	string2int(input, apartament);

	const Locatar& l=this->serv.cauta(apartament);
	cout <<"Locatarul cautat:\n"<<l<<"\n";

}

void UILocatari::ui_sorteaza_locatari()const {
	string input;
	int crit=0;
	int sens=0;
	cout << "Optiuni criteriu de sortare:\n1.Dupa numele proprietarului;\n2.Dupa suprafata;\n3.Dupa tipul apartamentului si suprafata;\n->Optiune:";
	getline(cin, input);
	string2int(input, crit);
	if (crit <= 0 || crit>3) {
		cout << "Optiune introdusa nerecunoscuta;\n";
		return;
	}
	crit--;
	cout << "Optiuni ordine de sortare:\n1.Crescator;\n2.Descrescator;\n->Optiune:";
	getline(cin, input);
	string2int(input, sens);
	if (sens <= 0 || sens>2) {
		cout << "Optiune introdusa nerecunoscuta;\n";
		return;
	}
	if (sens == 2)
		sens = -1;
	const vector<Locatar> v = this->serv.sorteaza(crit, sens);
	if (v.size() == 0) {
		cout << "Repozitoriu gol;\n";
		return;
	}
	this->afiseaza_vector_locatari(v);
}

void UILocatari::ui_filtreaza_locatari() const{
	string input;
	int crit = 0;
	int sens = 0;
	cout << "Optiuni criteriu de filtrare:\n1.Tipul apartamentului contine substring;\n2.Suprafata mai mare sau egala cu o valoare;\n->Optiune:";
	getline(cin, input);
	string2int(input, crit);
	if (crit <= 0 || crit > 2) {
		cout << "Optiune introdusa nerecunoscuta;\n";
		return;
	}
	crit--;
	cout << "Optiuni sens de filtrare:\n1.Respecta criteriul de baza;\n2.Respecta opusul criteriului de baza;\n->Optiune:";
	getline(cin, input);
	string2int(input, sens);
	if (sens <= 0 || sens > 2) {
		cout << "Optiune introdusa nerecunoscuta;\n";
		return;
	}
	if (sens == 2)
		sens = -1;
	switch (crit) {
	case 1: {
		cout << "Introduceti suprafata de comparatie:";
		getline(cin, input);
		double val = 0;
		string2double(input, val);
		const vector<Locatar> rez = this->serv.filtreaza(val, sens);
		afiseaza_vector_locatari(rez);
		break;
	}
	default: {
		cout << "Introduceti substring pentru tipul apartamentului:";
		string substr;
		getline(cin, substr);
		const vector<Locatar> rez = this->serv.filtreaza(substr, sens);
		afiseaza_vector_locatari(rez);
	}
	}
}

void UILocatari::ui_raport_tip() const
{
	const auto rez = this->serv.raport_tip();
	cout << "Raportul locatarilor dupa tip('tip' - 'numar aparitii'):\n";
	for (const auto& elem : rez) {
		cout << elem.first << " - " << elem.second << "\n";
	}
}

void UILocatari::ui_undo()
{
	this->serv.undo();
	cout << "Actiune realizata cu succes;\n";
}

void UILocatari::ui_lista_notificare()
{
	cout << "\nInterfata lista de notificare;\n";
	while (true) {
		cout << "\nNumar curent de locatari in lista: "<<this->serv.ln_get_all().size()<<";\n";
		string comanda;
		cout << "\n>>>";
		getline(cin, comanda);
		if (comanda.compare("exit") == 0) {
			cout << "Iesire din interfata de lista de notificare...\n";
			return;
		}
		else if (this->comenzi_const_ln.find(comanda) != this->comenzi_const_ln.end()) {
			try {
				(this->*this->comenzi_const_ln[comanda])();
			}
			catch (const ExceptieInputData& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieListaNotificare& eroare) {
				cout << eroare.get_mesaj();
			}
		}
		else if (this->comenzi_non_const_ln.find(comanda) != this->comenzi_non_const_ln.end()) {
			try {
				(this->*this->comenzi_non_const_ln[comanda])();
			}
			catch (const ExceptieInputData& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieListaNotificare& eroare) {
				cout << eroare.get_mesaj();
			}
		}
		else {
			cout << "Eroare: Comanda nerecunoscuta - introduceti comanda 'meniu' pentur a vedea lista cu comenzi posibile\n";
		}
	}
}

void UILocatari::ui_administrare()
{
	cout << "\nInterfata administrator;\n";
	while (true) {
		string comanda;
		cout << "\n>>>";
		getline(cin, comanda);
		if (comanda.compare("exit") == 0) {
			cout << "Iesire din interfata de administrator...\n";
			return;
		}
		else if (this->comenzi_const.find(comanda) != this->comenzi_const.end()) {
			try {
				(this->*this->comenzi_const[comanda])();
			}
			catch (const ExceptieInputData& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieValidareLocatar& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieRepozitoriuLocatar& eroare) {
				cout << eroare.get_mesaj();
			}
		}
		else if (this->comenzi_non_const.find(comanda) != this->comenzi_non_const.end()) {
			try {
				(this->*this->comenzi_non_const[comanda])();
			}
			catch (const ExceptieInputData& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieValidareLocatar& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieRepozitoriuLocatar& eroare) {
				cout << eroare.get_mesaj();
			}
			catch (const ExceptieUndo& eroare) {
				cout << eroare.get_mesaj();
			}
		}
		else {
			cout << "Eroare: Comanda nerecunoscuta - introduceti comanda 'meniu' pentur a vedea lista cu comenzi posibile\n";
		}
	}
}

void UILocatari::ruleaza() {
	cout << "\nAplicatie pornita cu succes;\n";
	while (true) {
		cout << "Lista interfete:\n1.'admin' - deschide interfata de administrator; \n2.'lista notificare' - deschide interfata de lista notificare; \n";
		cout << "Pentru a iesi introduceti 'exit';\n";
		string comanda;
		cout << "\n>>>";
		getline(cin, comanda);
		if (comanda == "exit") {
			cout << "Iesire din aplicatie...\n";
			return;
		}
		else if (comanda == "admin")
			this->ui_administrare();
		else if (comanda == "lista notificare")
			this->ui_lista_notificare();
		else
			cout << "Comanda nerecunoscuta;\n";
	}
}