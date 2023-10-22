#pragma once
#include "Task.h"
#include <vector>
using std::vector;

class RepoTask
{
private:
	vector <Task> v;
	string nume_fisier;

	//functie ce scrie datele in fisier
	/*pre:true
	post:datele sunt incarcate din fisier
	@Daca fisierul nu exista, se arunca o exceptie ExceptieRepo de mesaj
	"Eroare:Nu s-a putut deschide fisierul;\n"*/
	void incarcaDinFisier();
	/*pre:true
	post:datele sunt incarcate in fisier
	@Daca fisierul nu exista, se arunca o exceptie ExceptieRepo de mesaj
	"Eroare:Nu s-a putut deschide fisierul;\n"*/
	void scrieInFisier();

	friend void testRepo();

public:

	/*constructor cu nume de fisiser
	Pre:nf0 este string
	Post:se creaza entitatea cu numele de fisier nf0*/
	RepoTask(const string& nf0);

	/*functie ce adauga in repo un task
	Pre:t este task
	Post:repo=repo+{t}
	@Daca exista deja un taks cu id-ul lui t, se arunca o ExceptieRepo
	"Eroare:Exista deja un element cu acest id;\n"*/
	void adauga(const Task& t);

	/*functie ce sterge un task din repo dupa id
	Pre:id este intreg
	Post:repo=repo-{t},unde t are id-ul id
	@Daca nu exista un task cu id-ul id, se arunce o ExceptieRepo de mesaj:
	"Eroare:Nu exista un element cu acest id;\n"*/
	void sterge(int id);

	/*functie ce returneaza toate elementele din repo
	Pre:true
	Post:returneaza vector<Task>*/
	const vector<Task>& getAll()const;
};

