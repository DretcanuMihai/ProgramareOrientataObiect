#pragma once
//modul ce contine definirea clasei de Lista de notificare


#include "RepozitoriuLocatariAbstract.h"
#include "Observer_Observable.h"

class ListaNotificare:public Observable
{
private:
	const RepozitoriuLocatariAbstract& repo_ref;
	vector<Locatar> apartamente;
public:
	/*constructor de lista de notificare cu referinta la repo
	Pre:->repo_ref0 referinta la Repozitoriu Locatar
	Post:->creaza o lista de notificare vida cu referinta la repo_ref0*/
	ListaNotificare(const RepozitoriuLocatariAbstract& repo_ref0)noexcept;

	/*functie ce goleste o lista de notificare
	Pre:->true
	Post:->lista este vida*/
	void goleste() noexcept;

	/*functie ce adauga un apartament intr-o lista de notificare
	Pre:->apartament este de tip int, apartament>0
	Post:->lista de notificare contine locatarul de apartament apartament
	@Daca nu exista un locatar cu apartamentul respectiv se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu exista un locatar cu acest apartament\n"*/
	void adauga(int apartament);

	/*functie ce genereaza un numar de locatari in lista de notificare
	Pre:->nr este int, nr>0
	Post:->lista de notificare are cu nr locatari mai mult
	@Daca nu exista locatari in repozitoriu se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu exista apartamente pentru adaugat;\n"*/
	void genereaza(int numar);

	/*functie ce exporta lista de locatari intr-un fisier .csv
	Pre:->name e string nevid
	Post:->se creaza un fisier name.csv cu informatiile din lista
	@Daca nu s-a putut crea fisieurl se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu s-a putut crea fisierul;\n"*/
	void export_list_csv(const string& name)const;
	
	/*functie ce exporta lista de locatari intr-un fisier .html
	Pre:->name e string nevid
	Post:->se creaza un fisier name.csv cu informatiile din lista
	@Daca nu s-a putut crea fisieurl se va ridica o ExceptieListaNotificare cu mesajul:
	"Eroare: Nu s-a putut crea fisierul;\n"*/
	void export_list_html(const string& name)const;

	/*functie ce returneaza elementele listei de locatari
	Pre:->true
	Post:->returneaza un vector de Locatari*/
	const vector<Locatar>& get_all()const noexcept;
};

