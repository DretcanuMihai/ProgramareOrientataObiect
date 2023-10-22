#pragma once
#include "ValidatorTask.h"
#include "RepoTask.h"


class ServiciuTask
{
private:
	ValidatorTask& val;
	RepoTask& repo;
public:
	/*constructor cu validator si repo
	Pre:->val0 este ValidatorTask
		->repo0 este RepoTask
	Post:->se creeaza entitatea ceruta*/
	ServiciuTask(ValidatorTask& val0, RepoTask& repo0);

	/*functie ce adauga un task dupa id,descriere,lista de programatori si stare
	Pre:->id este intreg
		->descriere este string
		->prog este list<string>
		->stare este string
	Post:->se adauga in repo Task-ul cerut
	@Daca sunt erori de validare, se va arunca o ExceptieValidare cu erorile respective
	@Daca exista deja un task cu id-ul dat, se va arunca o ExceptieRepo cu mesaj adecvat*/
	void adauga(int id,const string& descriere,const list<string>& prog,const string& stare);

	/*functie ce sterge toate taskurile ce au ca programator un programatorul cu numele nume
	Pre:->nume este string
	Post:->toate elementele din repo ce aveau programatorul cautat sunt sterse*/
	void stergePg(const string& nume);

	/*functie ce returneaza toate elementele asociate serviceului dat
	Pre:true
	Post:returneaza vector<Task>*/
	const vector<Task>& getAll()const;
};

