#pragma once

//modul cu functii pentru sortari

#include "Vector.h"
#include "Locatar.h"
#include <functional>


/*compara 2 locatari dupa nume_proprietar, apoi dupa apartament
pre:->l0,l1 sunt Locatari
post:->returneaza int: =>-1 daca l0<l1
					   =>0 daca l0=l1
					   =>1 daca l0>l1*/
int compara_locatari_nume_proprietar(const Locatar& l0, const Locatar& l1);


/*compara 2 locatari dupa suprafata, apoi dupa apartament
pre:->l0,l1 sunt Locatari
post:->returneaza int: =>-1 daca l0<l1
					   =>0 daca l0=l1
					   =>1 daca l0>l1*/
int compara_locatari_suprafata(const Locatar& l0, const Locatar& l1) noexcept;

/*compara 2 locatari dupa tip_apartament,apoi dupa suprafata, apoi dupa apartament
pre:->l0,l1 sunt Locatari
post:->returneaza int: =>-1 daca l0<l1
					   =>0 daca l0=l1
					   =>1 daca l0>l1*/
int compara_locatari_tip_apartament_si_suprafata(const Locatar& l0, const Locatar& l1);


/*functie de sortare pentru vector
Pre:->begin si end sunt IteratorNC pentru acelasi vector si reprezinta limita inferioara si superioara de sortare
	->sens este de tip int, 1 pentru sensul crescator, -1 pentru descrescator
	->comparator este un pointer la functie de comparare ce primeste doua elemente de tip template TElem,ce returneaza -1 daca a<b, 0 daca a=b, 1 daca a>b
Post:->vectorul este sortat de la begin la end, oricare ar fi doua elemente consecutive comparator(a,b)==sens sau 0*/
template<typename TElem>
void sorteaza_vector(const typename Vector<TElem>::IteratorNC& begin,const typename Vector<TElem>::IteratorNC& end, int sens,std::function<int(const TElem&, const TElem&)> comparator)noexcept(false) {
	for (auto i_it = begin; i_it != end; ++i_it) {
		for (auto j_it = i_it + 1; j_it != end; ++j_it) {
			if (comparator(*i_it, *j_it) * sens == 1) {
				auto aux = *i_it;
				*i_it = *j_it;
				*j_it = aux;}
		}
	}
}
