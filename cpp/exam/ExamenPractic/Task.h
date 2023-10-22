#pragma once
#include <string>
using std::string;
#include <list>
using std::list;

class Task
{
private:
	int id;
	string descriere;
	list<string> programatori;
	string stare;

public:
	/*
	Constructor cu id, descriere, lista de programatori si stare
	Pre:->id este intreg
		->descriere este string
		->prog este list<string>
		->stare este string
	Post:->se creeaza entiatea cu atributele date
	*/
	Task(int id0, const string& descriere0,const list<string>& programatori0, const string& stare0);

	/*returneaza id-ul task-ului
	Pre:->true
	Post:->returneaza intreg*/
	int getId()const;
	/*returneaza descrierea task-ului
	Pre:->true
	Post:->returneaza string*/
	string getDescriere()const;

	/*returneaza o lista cu programatorii taskului
	Pre:->true
	Post:->returneaza list<string>*/
	list<string> getProgramatori()const;
	/*returneaza starea task-ului
	Pre:->true
	Post:->returneaza string*/
	string getStare()const;

};

