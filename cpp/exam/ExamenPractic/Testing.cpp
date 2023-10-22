#include "Testing.h"
#include <cassert>
#include "Task.h"
#include "Exceptii.h"
#include "ValidatorTask.h"
#include "RepoTask.h"
#include "ServiciuTask.h"
#include <fstream>

void testTask() {
	list<string> prog;
	prog.push_back("1");
	prog.push_back("2");
	Task t(1,"chestie",prog,"open");
	assert(t.getId() == 1);
	assert(t.getDescriere() == "chestie");
	auto l = t.getProgramatori();
	assert(l.size() == 2);
	assert(l.front() == "1");
	assert(l.back() == "2");
	assert(t.getStare() == "open");
}

void testExceptii() {
	Exceptie e{ "oh" };
	assert(e.getMesaj() == "oh");
	ExceptieValidare f{ "sd" };
	assert(f.getMesaj() == "sd");
	ExceptieRepo g{ "ad" };
	assert(g.getMesaj() == "ad");
}

void testRepo() {
	std::ofstream fout("test/test.txt");
	fout << "3\nchestii\n2\ndan\ndandan\nopen";
	fout.close();
	RepoTask repo{ "test/test.txt" };
	auto v = repo.getAll();
	assert(v.size() == 1);
	assert(v.at(0).getId() == 3);
	repo.v.push_back(Task(4, "chestiii", list<string>{"1", "2"}, "open"));
	repo.nume_fisier = "test/test0.txt";
	repo.scrieInFisier();
	std::ofstream fout2("test/gol.txt");
	fout2.close();
	RepoTask rf{ "test/gol.txt" };
	rf.nume_fisier = "test/test0.txt";
	rf.incarcaDinFisier();
	auto v0 = rf.getAll();
	assert(v0.size() == 2);
	assert(v0.at(0).getId() == 3);
	auto t = v0.at(1);
	assert(t.getId() == 4);
	assert(t.getDescriere() == "chestiii");
	auto l = t.getProgramatori();
	assert(l.size() == 2);
	assert(l.front() == "1");
	assert(l.back() == "2");
	assert(t.getStare() == "open");
	rf.nume_fisier = "test/fa/ls";
	try {
		rf.incarcaDinFisier();
		assert(false);
	}
	catch (const ExceptieRepo& e) {
		assert(e.getMesaj() == "Eroare:Nu s-a putut deschide fisierul;\n");
	}
	try {
		rf.scrieInFisier();
		assert(false);
	}
	catch (const ExceptieRepo& e) {
		assert(e.getMesaj() == "Eroare:Nu s-a putut deschide fisierul;\n");
	}
	try {
		repo.adauga(Task(3, "chestiie", list<string>{"1"}, "closed"));
		assert(false);
	}
	catch (const ExceptieRepo& e) {
		assert(e.getMesaj() == "Eroare:Exista deja un element cu acest id;\n");
	}
	repo.adauga(Task(1, "chestiii", list<string>{"1"}, "closed"));
	auto v2 = repo.getAll();
	assert(v2.at(0).getId() == 3);
	assert(v2.at(1).getId() == 1);
	assert(v2.at(2).getId() == 4);
	repo.sterge(1);
	auto v3 = repo.getAll();
	assert(v3.at(0).getId() == 3);
	assert(v3.at(1).getId() == 4);
	try {
		repo.sterge(1);
		assert(false);
	}
	catch (const ExceptieRepo& e) {
		assert(e.getMesaj() == "Eroare:Nu exista un task cu acest id;\n");
	}


}

void testValidator() {
	ValidatorTask val;
	try {
		val.valideaza(Task(2, "", list<string>{"", "", "", "", ""}, "nu"));
		assert(false);
	}
	catch (const ExceptieValidare& e) {
		string erori;
		erori += "Eroare:Descrierea trebuie sa fie nevida;\n";
		erori += "Eroare:Numarul de programatori trebuie sa fie intre 1 si 4\n";
		erori += "Eroare:Starea trebuie sa fie open,closed sau inprogress;\n";
		assert(e.getMesaj() == erori);
	}
	try {
		val.valideaza(Task(3, "da", list<string>{}, "closed"));
		assert(false);
	}
	catch (const ExceptieValidare& e) {
		string erori;
		erori += "Eroare:Numarul de programatori trebuie sa fie intre 1 si 4\n";
		assert(e.getMesaj() == erori);
	}
	val.valideaza(Task(3, "da", list<string>{"hm"}, "closed"));
}

void testServiciu() {
	std::ofstream fout("test/test.txt");
	fout << "3\nchestii\n2\ndan\ndandan\nopen";
	fout.close();
	RepoTask repo{ "test/test.txt" };
	ValidatorTask val;
	ServiciuTask serv{ val,repo };
	assert(serv.getAll().size() == 1);
	assert(serv.getAll().at(0).getId() == 3);
	try {
		serv.adauga(3, "chestiie", list<string>{"1"}, "closed");
		assert(false);
	}
	catch (const ExceptieRepo& e) {
		assert(e.getMesaj() == "Eroare:Exista deja un element cu acest id;\n");
	}
	try {
		serv.adauga(2, "da", list<string>{}, "ope");
		assert(false);
	}
	catch (const ExceptieValidare& e) {
		string erori;
		erori += "Eroare:Numarul de programatori trebuie sa fie intre 1 si 4\n";
		erori += "Eroare:Starea trebuie sa fie open,closed sau inprogress;\n";
		assert(e.getMesaj() == erori);
	}
	serv.adauga(4, "ad", list<string>{"1"}, "open");
	assert(serv.getAll().size() == 2);
	assert(serv.getAll().at(0).getId() == 4);
	assert(serv.getAll().at(1).getId() == 3);
	serv.adauga(5, "ad", list<string>{"2","1"}, "open");
	serv.adauga(6, "ad", list<string>{"3"}, "open");
	serv.stergePg("1");
	assert(serv.getAll().size() == 2);
	assert(serv.getAll().at(0).getId() == 6);
	assert(serv.getAll().at(1).getId() == 3);

}

void testAll()
{
	testTask();
	testExceptii();
	testRepo();
	testValidator();
	testServiciu();
}
