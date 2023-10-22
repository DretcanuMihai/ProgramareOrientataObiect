#pragma once

//modul cu functii ce ajuta la filtrari

#include "Vector.h"
#include "Locatar.h"
#include <functional>


/*functie de filtru locatar dupa tipul apartamentului
Pre:->l este Locatar, val este string
Post:->returneaza int; 1 daca val se gaseste ca substring in tipul apartamentului lui l
					   -1 altfel*/
int filtru_tip_apartament(const Locatar& l, const string& val);

/*functie de filtru locatar dupa suprafata
Pre:->l este Locatar, val este double
Post:->returneaza int; -1 daca suprafata lui l<val
					   altfel 1 daca suprafata lui l>val
					   altfel 0*/
int filtru_suprafata(const Locatar& l, const double& val) noexcept;

/*functie de filtrare vector dupa un criteriu
Pre:->begin si end sunt IteratorNC pentru acelasi vector si reprezinta limita inferioara si superioara de sortare
	->sens este de tip int, 1 pentru a pastra sensul normal al criteriului, -1 pentru a-l negat
	->crit este o valoare de tip template Value necesara functiei de filtru
	->filtru este o functie de filtrare ce primeste ca parametrii un element de tip template TElem, si un alt element de tip template Value,
	  functia returnand 1,-1 sau 0
Post:->returneaza un Vector ce contine elementele care prin filtru returneaza aceeasi valoare cu sensul sau 0*/
template<typename TElem,typename Value>
Vector<TElem> filtreaza_vector(const typename Vector<TElem>::IteratorC& begin, const typename Vector<TElem>::IteratorC& end, int sens, const Value& crit, std::function<int(const TElem&, const Value&)> filtru) {
	Vector<TElem> rezultat;
	for (auto it = begin; it != end; ++it) {
		if (filtru(*it, crit) * sens != -1) {
			rezultat.push_back(*it);
		}
	}
	return rezultat;
}