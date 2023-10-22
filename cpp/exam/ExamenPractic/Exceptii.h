#pragma once
#include <string>
using std::string;

//modul cu clase de excpeite

class Exceptie {
private:
	string mesaj;
public:
	//Constructor cu string
	/*pre:mesaj0 este string
	Post:se creaza o entitate Exceptie de mesja mesaj0*/
	Exceptie(const string& mesaj0);

	/*returneaza mesajul Exceptiei
	Pre:true
	Post:returneaza string*/
	string getMesaj()const;
};

class ExceptieValidare :public Exceptie {
public:
	//Constructor cu string
	/*pre:mesaj0 este string
	Post:se creaza o entitate Exceptie de mesja mesaj0*/
	ExceptieValidare(const string& mesaj0);
};

class ExceptieRepo :public Exceptie {
public:
	//Constructor cu string
	/*pre:mesaj0 este string
	Post:se creaza o entitate Exceptie de mesja mesaj0*/
	ExceptieRepo(const string& mesaj0);
};

