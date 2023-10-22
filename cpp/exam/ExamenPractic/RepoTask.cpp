#include "RepoTask.h"
#include <fstream>
#include "Exceptii.h"

void RepoTask::incarcaDinFisier()
{
	std::ifstream fin(nume_fisier);
	if (fin.fail()) {
		throw ExceptieRepo("Eroare:Nu s-a putut deschide fisierul;\n");
	}
	v.clear();
	while (fin.good()) {
		string buffer;
		getline(fin, buffer);
		if (buffer == "")
			break;
		int id=stoi(buffer);
		string descriere;
		getline(fin, descriere);
		getline(fin, buffer);
		int prog_size = stoi(buffer);
		list<string> prog;
		for (int i = 0; i < prog_size; i++) {
			getline(fin, buffer);
			prog.push_back(buffer);
		}
		string stare;
		getline(fin, stare);
		v.push_back(Task(id, descriere, prog, stare));
	}
	fin.close();
}

void RepoTask::scrieInFisier()
{
	std::ofstream fout(nume_fisier);
	if (fout.fail()) {
		throw ExceptieRepo("Eroare:Nu s-a putut deschide fisierul;\n");
	}
	for (const auto& elem : v) {
		fout << elem.getId() << "\n" << elem.getDescriere() << "\n" << elem.getProgramatori().size() << "\n";
		for (const auto& p : elem.getProgramatori()) {
			fout << p << "\n";
		}
		fout << elem.getStare() << "\n";
	}
	fout.close();
}

RepoTask::RepoTask(const string& nf0) :nume_fisier{nf0}
{
	incarcaDinFisier();
}

void RepoTask::adauga(const Task& t)
{
	auto it = std::find_if(v.begin(), v.end(), [t](const Task& t0) {
		return t.getId() == t0.getId();
		});
	if (it != v.end()) {
		throw ExceptieRepo("Eroare:Exista deja un element cu acest id;\n");
	}
	auto it0 = std::find_if(v.begin(), v.end(), [t](const Task& t0) {
		return ((t.getDescriere() == t0.getDescriere()&&t.getId()<t0.getId())||t.getDescriere()<t0.getDescriere());
		});
	v.insert(it0, t);
	scrieInFisier();

}

void RepoTask::sterge(int id)
{
	auto it = std::find_if(v.begin(), v.end(), [id](const Task& t) {
		return t.getId() == id;
		});
	if (it == v.end()) {
		throw ExceptieRepo("Eroare:Nu exista un task cu acest id;\n");
	}
	v.erase(it);
	scrieInFisier();
}

const vector<Task>& RepoTask::getAll() const
{
	return v;
}
