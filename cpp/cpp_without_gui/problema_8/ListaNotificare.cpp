#include "ListaNotificare.h"
#include "ExceptiiLocatar.h"
#include <fstream>
#include <random>

ListaNotificare::ListaNotificare(const RepozitoriuLocatariAbstract& repo_ref0) noexcept:repo_ref{ repo_ref0 }, apartamente{}{
};

void ListaNotificare::goleste() noexcept {
	this->apartamente.clear();
}

void ListaNotificare::adauga(int apartament){
	try {
		const Locatar& l = repo_ref.cauta(apartament);
		this->apartamente.push_back(l);
	}
	catch (const ExceptieRepozitoriuLocatar& ex) {
		throw(ExceptieListaNotificare(ex.get_mesaj()));}
}

void ListaNotificare::genereaza(int numar)
{
	const vector<Locatar>& generator_list = this->repo_ref.get_all();
	if (generator_list.size() == 0)
		throw(ExceptieListaNotificare("Eroare: Nu exista apartamente pentru adaugat;\n"));
	const std::uniform_int_distribution<> dist(0, generator_list.size() - 1);
	while (numar > 0) {
		std::mt19937 mt{ std::random_device{}() };
		this->apartamente.push_back(generator_list.at(dist(mt)));
		numar--;
	}
}



void ListaNotificare::export_list_csv(const string& name)const{
	std::ofstream csv_out(name + ".csv");
	if (csv_out.fail())
		throw ExceptieListaNotificare("Eroare: Nu s-a putut crea fisierul;\n");
	for (const auto& elem : this->apartamente)
		csv_out << elem.get_apartament() << ";" << elem.get_nume_proprietar() << ";" << elem.get_suprafata() << ";" << elem.get_tip_apartament() << "\n";
	csv_out.close();
}

void ListaNotificare::export_list_html(const string& name)const {
	std::ofstream html_out(name + ".html");
	if (html_out.fail())
		throw ExceptieListaNotificare("Eroare: Nu s-a putut crea fisierul;\n");
	html_out << "<html><body>\n";
	for (const auto& elem : this->apartamente)
		html_out << elem.get_apartament() << ";" << elem.get_nume_proprietar() << ";" << elem.get_suprafata() << ";" << elem.get_tip_apartament() << "<br>\n";
	html_out << "</body></html>";
	html_out.close();
}

const vector<Locatar>& ListaNotificare::get_all() const noexcept
{
	return this->apartamente;
}
