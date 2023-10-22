#include "ServiciuLocatari.h"
#include "ExceptiiLocatar.h"
#include <algorithm>
using std::make_unique;

ServiciuLocatari::ServiciuLocatari(RepozitoriuLocatariAbstract& repo0, const ValidatorLocatar& validator0, ListaNotificare& lista_notificare0)noexcept :repo{ repo0 }, validator{ validator0 },
lista_notificare{lista_notificare0}{}

void ServiciuLocatari::adauga(int apartament, const string& nume_proprietar, double suprafata, const string& tip_apartament) {
	Locatar l(apartament, nume_proprietar, suprafata, tip_apartament);
	this->validator.valideaza_locatar(l);
	this->repo.adauga(l);

	unique_ptr<UndoAdauga> act = make_unique<UndoAdauga>(this->repo, apartament);
	this->undo_list.push_back(move(act));
	this->notify();
}
void ServiciuLocatari::sterge(int apartament) {
	this->validator.valideaza_apartament(apartament);
	const auto lrez = this->repo.sterge(apartament);
	unique_ptr<UndoSterge> act = make_unique<UndoSterge>(this->repo, lrez);
	this->undo_list.push_back(move(act));
	this->notify();
}


void ServiciuLocatari::modifica(int apartament, const string& nume_proprietar, double suprafata, const string& tip_apartament) {
	Locatar l(apartament, nume_proprietar, suprafata, tip_apartament);
	this->validator.valideaza_locatar(l);
	const auto lrez = this->repo.modifica(l);
	unique_ptr<UndoModifica> act = make_unique<UndoModifica>(this->repo, lrez);
	this->undo_list.push_back(move(act));
	this->notify();
}

const Locatar& ServiciuLocatari::cauta(int apartament)const {
	this->validator.valideaza_apartament(apartament);
	return this->repo.cauta(apartament);
}

vector<Locatar> ServiciuLocatari::filtreaza(const string& val, int sens)const {
	this->validator.valideaza_tip_apartament(val);
	const vector<Locatar>& v = this->repo.get_all();
	vector<Locatar> rez(v.size());
	auto it = copy_if(v.begin(), v.end(), rez.begin(), [val, sens](Locatar l) {bool ad = l.get_tip_apartament().find(val) != string::npos; if (sens == 1)return ad; return !ad;   });
	rez.resize(std::distance(rez.begin(),it));
	return rez;
}

vector<Locatar> ServiciuLocatari::filtreaza(double val, int sens)const {
	this->validator.valideaza_suprafata(val);
	const vector<Locatar>& v = this->repo.get_all();
	vector<Locatar> rez(v.size());
	auto it = copy_if(v.begin(), v.end(), rez.begin(), [val, sens](Locatar l)noexcept {if (sens == 1) return l.get_suprafata() >= val; return l.get_suprafata() <= val; });
	rez.resize(std::distance(rez.begin(), it));
	return rez;
}

vector<Locatar> ServiciuLocatari::sorteaza(int optiune, int sens)const {
	vector<Locatar> rezultat = this->repo.get_all();
	switch (optiune) {
	case 1:
	{
		std::sort(rezultat.begin(), rezultat.end(), [sens](const Locatar& l1, const Locatar& l2) noexcept
			{const bool rez = (l1.get_suprafata() < l2.get_suprafata()) || (l1.get_suprafata() == l2.get_suprafata() && l1.get_apartament() < l2.get_apartament());
			if (sens == 1)return rez; return !rez; });
		break; 
	}
	case 2:
	{
		std::sort(rezultat.begin(), rezultat.end(), [sens](const Locatar& l1, const Locatar& l2)
			{const bool rez = (l1.get_tip_apartament() < l2.get_tip_apartament()) || (l1.get_tip_apartament() == l2.get_tip_apartament() && l1.get_suprafata() < l2.get_suprafata()) ||
			(l1.get_tip_apartament() == l2.get_tip_apartament() && l1.get_suprafata() == l2.get_suprafata() && l1.get_apartament()<l2.get_apartament());
			if (sens == 1)return rez; return !rez; });
		break;
	}
	default:
	{
		std::sort(rezultat.begin(), rezultat.end(), [sens](const Locatar& l1, const Locatar& l2)
			{const bool rez = (l1.get_nume_proprietar() < l2.get_nume_proprietar()) || (l1.get_nume_proprietar() == l2.get_nume_proprietar() && l1.get_apartament() < l2.get_apartament());
			if (sens == 1)return rez; return !rez; });
		break;
	}
	}
	return rezultat;
}

vector<Locatar> ServiciuLocatari::get_all() const{
	return this->repo.get_all();
}

void ServiciuLocatari::ln_goleste() noexcept
{
	this->lista_notificare.goleste();
}

void ServiciuLocatari::ln_adauga(int apartament)
{
	if (apartament <= 0)
		throw ExceptieListaNotificare("Eroare: Apartamentul trebuie sa fie un numar intreg strict pozitiv;\n");
	this->lista_notificare.adauga(apartament);
}

void ServiciuLocatari::ln_genereaza(int numar)
{
	if (numar <= 0)
		throw ExceptieListaNotificare("Eroare: Numarul trebuie sa fie un intreg strict pozitiv;\n");
	this->lista_notificare.genereaza(numar);
}

void ServiciuLocatari::ln_export_list_csv(const string& name) const
{
	if (name == "")
		throw ExceptieListaNotificare("Eroare: Stringul nu poate fi vid;\n");
	this->lista_notificare.export_list_csv(name);
}

void ServiciuLocatari::ln_export_list_html(const string& name) const
{
	if (name == "")
		throw ExceptieListaNotificare("Eroare: Stringul nu poate fi vid;\n");
	this->lista_notificare.export_list_html(name);
}

const vector<Locatar>& ServiciuLocatari::ln_get_all() const noexcept
{
	return this->lista_notificare.get_all();
}

void ServiciuLocatari::undo()
{
	if (this->undo_list.size() == 0)
		throw ExceptieUndo("Eroare: Nu exista actiuni precedente pentru a da undo;\n");
	this->undo_list.back()->doUndo();
	this->undo_list.pop_back();
	this->notify();
}

unordered_map<string, int> ServiciuLocatari::raport_tip() const
{
	unordered_map<string, int> raport;
	const vector<Locatar> v = this->get_all();
	for (const auto& elem : v) {
		const string tip = elem.get_tip_apartament();
		auto it = raport.find(tip);
		if (it == raport.end()) {
			raport[tip] = 0;
		}
		raport[tip]++;
	}
	return raport;
}
