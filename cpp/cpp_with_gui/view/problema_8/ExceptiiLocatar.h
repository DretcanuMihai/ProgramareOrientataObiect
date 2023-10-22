#pragma once

//modul cu clase de exceptii speciale

#include <string>
using std::string;

/*exceptie generala - pentru orice problema*/
class ExceptieGenerala {
public:

	//creeaza o exceptie generala de mesaj mesaj0
	//pre:mesaj0 string
	//post:creeaza o ExceptieGenerala de mesaj mesaj0
	ExceptieGenerala(const string& mesaj0);

	//returneaza o referinta nemodificabila la mesajul exceptiei
	//pre:true
	//post:returneaza string
	const string& get_mesaj()const noexcept;
	
private:
	string mesaj;
};
/*exceptie de validare locatar - pentru erorile la validare de locatari*/
class ExceptieValidareLocatar : public ExceptieGenerala {
	using ExceptieGenerala::ExceptieGenerala;
};

/*exceptie de repozitoriu locatari - pentru erorile ce tin de repo locatari*/
class ExceptieRepozitoriuLocatar : public ExceptieGenerala {
	using ExceptieGenerala::ExceptieGenerala;
};

/*exceptie pentru input data - pentru erorile legate de datele introduse de la tastatura*/
class ExceptieInputData : public ExceptieGenerala {
	using ExceptieGenerala::ExceptieGenerala;
};

/*exceptie de lista notificare - pentru erorile ce tin de lista de notificare*/
class ExceptieListaNotificare : public ExceptieGenerala {
	using ExceptieGenerala::ExceptieGenerala;
};

/*exceptie de undo - pentru erorile ce tin de undo*/
class ExceptieUndo : public ExceptieGenerala {
	using ExceptieGenerala::ExceptieGenerala;
};

