
#pragma once

//modul cu tot ce tine de clasa de UILocatar

#include "ServiciuLocatari.h"
#include <map>

using std::map;

class UILocatari
{
public:
	/*constructor implicit
	Pre:serv0 este de tip ServiciuLocatari
	Post:creeaza UILocatar cu ServiciuLocatari serv0 si initializeaza dictionarele de comenzi*/
	UILocatari(ServiciuLocatari& serv0);

	/*ruleaza ui-ul
	Pre:true
	Post:porneste ui-ul*/
	void ruleaza();
private:
	ServiciuLocatari& serv;
	map<string, void(UILocatari::*)()> comenzi_non_const;
	map<string, void(UILocatari::*)()const> comenzi_const;
	map<string, void(UILocatari::*)()> comenzi_non_const_ln;
	map<string, void(UILocatari::*)()const> comenzi_const_ln;
	
	/*afiseaza un meniu cu comenzi pentru interfata de administrator
	Pre:true
	Post:afiseaza pe ecran meniul*/
	void ui_meniu()const;

	/*afiseaza pe ecran elementele unui vector de locatari
	Pre:true
	Post:afiseaza pe ecran locatarii din vector*/
	void afiseaza_vector_locatari(const vector<Locatar>& v)const;
	
	/*afiseaza pe ecran locatarii
	Pre:true
	Post:afiseaza pe ecran locatarii din repo*/
	void ui_afiseaza_locatari()const;

	/*deschide interfata utilizator pentru adaugarea de locatari
	Pre:true
	Post:deschide interfata*/
	void ui_adauga_locatar();

	/*deschide interfata utilizator pentru stergerea de locatari
	Pre:true
	Post:deschide interfata*/
	void ui_sterge_locatar();

	/*deschide interfata utilizator pentru modificarea de locatari
	Pre:true
	Post:deschide interfata*/
	void ui_modifica_locatar();

	/*deschide interfata utilizator pentru cautarea de locatari
	Pre:true
	Post:deschide interfata*/
	void ui_cauta_locatar()const;

	/*deschide interfata utilizator pentru sortare
	Pre:true
	Post:deschide interfata*/
	void ui_sorteaza_locatari()const;

	/*deschide interfata utilizator pentru filtrare
	Pre:true
	Post:deschide interfata*/
	void ui_filtreaza_locatari()const;

	/*deschide interfata utilizator pentru undo
	Pre:true
	Post:deschide interfata*/
	void ui_undo();

	/*initializeaza comenzile ce pot modifica chestii in interiorul clasei
	Pre:true
	Post:comenzile sunt initializate in propriul dictionar de comenzi*/
	void initializare_comenzi_non_const();

	/*initializeaza comenzile ce nu modifica chestii in interiorul clasei
	Pre:true
	Post:comenzile sunt initializate in propriul dictionar de comenzi*/
	void initializare_comenzi_const();

	/*deschide interfata utilizator pentru golirea listei de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_ln_goleste();

	/*deschide interfata utilizator pentru adaugarea unui apartament in lista de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_ln_adauga();

	/*deschide interfata utilizator pentru generarea unor apartamente intr-o lista de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_ln_genereaza();

	/*deschide interfata utilizator pentru exportarea listei de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_ln_export()const;

	/*deschide interfata utilizator pentru afisarea elementelor din lista de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_ln_afiseaza()const;

	/*afiseaza un meniu cu comenzi pentru interfata de administrator
	Pre:true
	Post:afiseaza pe ecran meniul*/
	void ui_ln_meniu()const;

	/*deschide interfata utilizator pentru tot ce tine de lista de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_lista_notificare();

	/*deschide interfata utilizator pentru tot ce tine de lista de notificare
	Pre:->true
	Post:->deschide interfata*/
	void ui_administrare();

	/*deschide interfata utilizator pentru raport dupa tip
	Pre:->true
	Post:->deschide interfata*/
	void ui_raport_tip() const;
};

