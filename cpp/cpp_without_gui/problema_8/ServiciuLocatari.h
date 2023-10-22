#pragma once

//modul cu tot ce tine de Serviciul de Locatari
#include "RepozitoriuLocatari.h"
#include "ValidatorLocatar.h"
#include "ListaNotificare.h"
#include "ActiuneUndo.h"
#include <list>
#include <memory>
using std::unique_ptr;
#include <unordered_map>
using std::unordered_map;


class ServiciuLocatari
{
private:
	RepozitoriuLocatariAbstract& repo;
	const ValidatorLocatar& validator;
	ListaNotificare& lista_notificare;
	std::list<unique_ptr<ActiuneUndo>> undo_list;

public:
	/*constructor implicit
	Pre:repo0 este de tip RepozitoriuLocatari, validator0 este de tip ValidatorLocatar
	Post:creeaza un ServiceLocatari cu campurile date*/
	ServiciuLocatari(RepozitoriuLocatariAbstract& repo0, const ValidatorLocatar& validator0, ListaNotificare& lista_notificare0)noexcept;

	/*adauga un locatar in repo
	Pre:apartament este de tip intreg
		nume_proprietar este de tip string
		suprafata este de tip double
		tip_apartament este de tip string
	Post:adauga un locatar cu informatiile de mai sus
	@Daca vreuna din date este incorecta, se va ridica o ExceptieValidareLocatar cu unul sau mai multe din mesajele:
	"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
	"Eroare: Numele proprietarului trebuie sa fie un string nevid;\n"
	"Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n"
	"Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n"
	@Daca exista deja un element cu apartamentul respectiv se va arunca o ExceptieRepozitoriuLocatar cu mesajul:
	"Eroare: Exista deja un locatar cu acest apartament\n"*/
	void adauga(int apartament, const string& nume_proprietar, double suprafata, const string& tip_apartament);

	/*sterge un element dupa apartament
	Pre:apartament este de tip intreg
	Post:locatarul cu apartamentul apartament este sters
	@Daca apartament este <=0 se va arunca o ExceptieValidareLocatar cu mesajul:
	"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
	@Daca nu exista un element cu apartamentul respectiv se va arunca o ExceptieRepozitoriuLocatar cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	void sterge(int apartament);

	/*modifica un locatar din repo
	Pre:apartament este de tip intreg
		nume_proprietar este de tip string
		suprafata este de tip double
		tip_apartament este de tip string
	Post:locatarul de apartament apartament are setate celelalte campuri la cele indicate
	@Daca vreuna din date este incorecta, se va ridica o ExceptieValidareLocatar cu unul sau mai multe din mesajele:
	"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
	"Eroare: Numele proprietarului trebuie sa fie un string nevid;\n"
	"Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n"
	"Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n"
	@Daca nu exista un element cu apartamentul respectiva se va arunca o ExceptieRepozitoriuLocatar cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	void modifica(int apartament, const string& nume_proprietar, double suprafata, const string& tip_apartament);
	
	/*cauta un element dupa apartament
	Pre:apartament este de tip intreg
	Post:returneaza un Locatar
	@Daca apartament este <=0 se va arunca o ExceptieValidareLocatar cu mesajul:
	"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
	@Daca nu exista un element cu apartamentul respectiva se va arunca o ExceptieRepozitoriuLocatar cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	const Locatar& cauta(int apartament)const;


	/*returneaza elementele din repo a caror tip de apartament contine sau nu un substring
	Pre:->val este de tip string
		->sens este de tip int = 1 -> pastreaza elementele ce contin stringul
							   =-1 -> pastreaza elementele ce nu contin stringul
	Post:->returneaza un Vector<Locatar> cu elementele cautate
	@Daca val este un string vid se va ridica o ExceptieValidareLocatar cu mesajul:
	"Eroare: Tipul apartamentului trebuie sa fie un string nevid;\n"*/
	vector<Locatar> filtreaza(const string& val, int sens)const;

	/*returneaza elementele din repo a caror suprafata este <= sau >= ca o valoare
	Pre:->val este de tip double
		->sens este de tip int = 1 -> pastreaza elementele ce respecta >=val
							   =-1 -> pastreaza elementele ce respecta <=val
	Post:->returneaza un Vector<Locatar> cu elementele cautate
	@Daca val este <=+0.0 se va arunca o ExceptieValidareLocatar cu mesajul:
	"Eroare: Suprafata trebuie sa fie un numar real strict pozitiv;\n"*/
	vector<Locatar> filtreaza(double val, int sens)const;


	/*returneaza elementele din repo sortate
	Pre:->optiune este int =0 -> sorteaza dupa nume proprietar
						   =1 -> sorteaza dupa suprafata
						   =2 -> sorteaza dupa tip apartament si suprafata
		->sens este int =1  -> sorteaza crescator
						=-1 -> sorteaza descrescator
	Post:->returneaza vector de Locatari, ordonati dupa optiunile de mai sus*/
	vector<Locatar> sorteaza(int optiune,int sens)const;

	/*returneaza toti locatari asociati serviciului
	Pre:true
	Post:returneaza un vector de Locatari*/
	vector<Locatar> get_all()const;

	/*functie ce goleste lista de notificare
	Pre:->true
	Post:->lista este vida*/
	void ln_goleste() noexcept;

	/*functie ce adauga un apartament in lista de notificare
	Pre:->apartament este de tip int
	Post:->lista de notificare contine locatarul de apartament apartament
	@Daca apartamentul este negativ se va ridica o ExceptieListaNotifiare cu mesajul:
	"Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n"
	@Daca nu exista un locatar cu apartamentul respectiv se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	void ln_adauga(int apartament);

	/*functie ce genereaza un numar de locatari in lista de notificare
	Pre:->nr este int
	Post:->lista de notificare are cu nr locatari mai mult
	@Daca apartamentul este negativ se va ridica o ExceptieListaNotifiare cu mesajul:
	"Eroare: Numarul trebuie sa fie un intreg strict pozitiv;\n"
	@Daca nu exista locatari in repozitoriu se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu exista apartamente pentru adaugat;\n"*/
	void ln_genereaza(int numar);

	/*functie ce exporta lista de locatari intr-un fisier .csv
	Pre:->name e string nevid
	Post:->se creaza un fisier name.csv cu informatiile din lista
	@Daca name este vid se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Stringul nu poate fi vid;\n"
	@Daca nu s-a putut crea fisieurl se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu s-a putut crea fisierul;\n"*/
	void ln_export_list_csv(const string& name)const;

	/*functie ce exporta lista de locatari intr-un fisier .html
	Pre:->name e string nevid
	Post:->se creaza un fisier name.csv cu informatiile din lista
	@Daca name este vid se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Stringul nu poate fi vid;\n"
	@Daca nu s-a putut crea fisieurl se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu s-a putut crea fisierul;\n"*/
	void ln_export_list_html(const string& name)const;

	/*functie ce returneaza elementele listei de locatari
	Pre:->true
	Post:->returneaza un vector de Locatari*/
	const vector<Locatar>& ln_get_all()const noexcept;

	/*functie ce aduce repo-ul la o forma anterioara
	Pre:->true
	Post:->repo'=repo(precedent)
	@Daca nu exista actiuni precedente, se va arunca o ExceptieUndo cu mesajul:
	"Eroare:Nu exista actiuni precedente pentru a da undo;\n"
	*/
	void undo();

	/*functie ce creeaza un raport ce asociaza fiecarui tip numarul de dati in care apare in repo
	Pre:->true
	Post:->returneaza un map<string, DTO_tip>, cheile fiind tipurile,DTO_tip continand numarul respectiv de aparitii*/
	unordered_map<string, int> raport_tip()const;

};

