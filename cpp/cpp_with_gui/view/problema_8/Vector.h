#pragma once

//modul cu tot ce tine de entitatea de Vector, inclusiv iteratorii

template<typename TElem>
class Vector;

#ifndef CAPACITATE_INITIALA
#define CAPACITATE_INITIALA 8
#endif

#include "TesteLocatar.h"

///Vector
///////////////////////////////////////////

template <typename TElem>
class Vector
{
private:
	TElem* elemente;
	int dimensiune;
	int capacitate;

	/*redimensioneaza vector
	Pre:->true
	Post:->v.capacitate'=v.capacitate*/
	void resize();

public:

	class Iterator;
	friend class Iterator;
	class IteratorC;
	friend class IteratorC;
	class IteratorNC;
	friend class IteratorNC;
	friend class TesteLocatar;

	//ma voi referi la "this", adica entitatea pe care se opereaza, prin vector

	/*constructor default pentru un vector vid
	Pre:->true
	Post:->vector este vid*/
	Vector()noexcept(false);

	/*copy constructor
	Pre:->v0 Vector
	Post:->vector are aceleasi elemente ca v0*/
	Vector(const Vector<TElem>& v0)noexcept(false);

	/*move constructor
	Pre:->v0 Vector temporar
	Post:->vector are aceleasi elemente ca v0
		 ->v0 este ditrus(pentru ca este temporar)*/
	Vector(Vector<TElem>&& v0)noexcept;

	/*copy assignemnt
	Pre:->v0 Vector
	Post:->vector are aceleasi elemente ca v0*/
	Vector<TElem>& operator=(const Vector<TElem>& v0)noexcept(false);

	/*move assignment
	Pre:->v0 Vector temporar
	Post:->vector are aceleasi elemente ca v0
		 ->v0 este ditrus(pentru ca este temporar)*/
	Vector<TElem>& operator=(Vector<TElem>&& v0)noexcept;

	/*insereaza la sfarsitul vectorului un element
	Pre:->element este TElem
	Post:->elemente este inserat la sfarsitul vectorului*/
	void push_back(const TElem& element);

	/*insereaza element pe pozitie iterator
	Pre:->it este Iterator valid
		->element este de tip TElem
	Post:->element este inserat pe pozitia iterator*/
	void insert(const Iterator& it, const TElem& element);

	/*sterge element de pe pozitie iterator
	Pre:->it este Iterator valid
	Post:->vector'=vector\{valoarea la care arata it}*/
	void erase(const Iterator& it)noexcept(false);

	/*returneaza iterator la inceputul lui vector constant
	Pre:->True
	Post:->returneaza IteratorC ce arata la inceputul vectorului,nepermitand modificari*/
	IteratorC begin()const noexcept; 

	/*returneaza iterator la sfarsitul lui vector constant
	Pre:->True
	Post:->returneaza IteratorC ce arata la sfarsitul vectorului (o pozitie dupa ultimul element valid),nepermitand modificari */
	IteratorC end()const noexcept; 

	/*returneaza iterator la inceputul lui vector neconstant
	Pre:->True
	Post:->returneaza IteratorNC ce arata la inceputul vectorului,permitand modificari*/
	IteratorNC begin() noexcept;


	/*returneaza iterator la sfarsitul lui vector neconstant
	Pre:->True
	Post:->returneaza IteratorNC ce arata la sfarsitul vectorului (o pozitie dupa ultimul element valid),permitand modificari*/
	IteratorNC end() noexcept;

	///*suprascize operatorul[], accesat ca vector[index] - modalitate de accesare a unui element din Vector neconstant dupa index
	//Pre:->index este int, 0<=index<vector.size()
	//Post:->returneaza o referinta modificabila la elementul de pe pozitia index*/
	//TElem& operator[](int index)noexcept;

	/*modalitate de accesare a unui element din Vector neconstant dupa index
	Pre:->index este int, 0<=index<vector.size()
	Post:->returneaza o referinta modificabila la elementul de pe pozitia index*/
	TElem& at(int index)noexcept;

	///*suprascize operatorul[], accesat ca vector[index] - modalitate de accesare a unui element din Vector constant dupa index
	//Pre:->index este int, 0<=index<vector.size()
	//Post:->returneaza o referinta constanta la elementul de pe pozitia index*/
	//const TElem& operator[](int index)const noexcept;

	/*modalitate de accesare a unui element din Vector constant dupa index
	Pre:->index este int, 0<=index<vector.size()
	Post:->returneaza o referinta constanta la elementul de pe pozitia index*/
	const TElem& at(int index)const noexcept;

	/*modalitate de accesare a unui element din Vector dupa index
	Pre:->index este int, 0<=index<vector.size()
	Post:->returneaza elementul de pe pozitia index*/
	TElem get(int index)const noexcept;

	/*returneaza dimensiunea vectorului
	Pre:->true
	Post:->returneaza int, dimensiunea vectorului*/
	int size()const noexcept;

	/*destructor de Vector
	Pre:->true
	Post:->vector este distrus*/
	~Vector();
};

///Iterator simplu
////////////////////////////////////////////////////////////////////

template<typename TElem>
class Vector<TElem>::Iterator {
private:
	friend class Vector<TElem>;
	//reprezentare
	int pozitie;
	const Vector<TElem>& v;

	//implementare

	/*Creaza un iterator pentru un vector v0 ce arata la elementul de pe pozitia pozitie0
	Pre:->v0 este Vector
		->pozitie0 este int
	Post:->creeaza iterator pentru vectorul v0 ce arata la pozitia pozitie0*/
	Iterator(const Vector<TElem>& v0, int pozitie0) noexcept :v{ v0 }, pozitie{ pozitie0 }{
	}

public:

	/*Spune daca iteratorul arata la un element valid
	Pre:->true
	Post:->returneaza true daca iteratorul este valid, false altfel*/
	bool valid()noexcept {
		return ((this->pozitie < this->v.dimensiune) && (this->pozitie >= 0));
	}

	/*suprascrie operatorul == intre doi iteratori
	Pre:it0,it1 Iteratori
	Post:->returneaza true daca cei doi iteratori arata la acelasi element in acelasi Vector,altfel false*/
	friend bool operator==(const Iterator& it0, const Iterator& it1) noexcept {
		return((it0.pozitie == it1.pozitie) && (&it0.v == &it1.v));
	}

	/*suprascrie operatorul != intre doi iteratori
	Pre:it0,it1 Iteratori
	Post:->returneaza false daca cei doi iteratori arata la acelasi element in acelasi Vector,altfel true*/
	friend bool operator!=(const Iterator& it0, const Iterator& it1) noexcept {
		return((it0.pozitie != it1.pozitie) || (&it0.v != &it1.v));
	}
};

///Iterator ce nu permite modificari
////////////////////////////////////////////////////////////////////

template<typename TElem>
class Vector<TElem>::IteratorC:public Vector<TElem>::Iterator {
	friend class Vector<TElem>;
public:
	using Vector<TElem>::Iterator::Iterator;

	/*suprescrie opertorul ++ pentru un IteratorC
	Pre:->true
	Post:->iterator arata la urmatorul element
		 ->returneaza noul iterator*/
	IteratorC operator++() noexcept {
		this->pozitie++;
		return *this;
	}

	/*suprescrie opertorul +int pentru un IteratorC
	Pre:->val este int
	Post:->iterator arata la elementul cu val pozitii in continuare
		 ->returneaza noul iterator*/
	IteratorC operator+(int val) noexcept {
		auto it = *this;
		it.pozitie += val;
		return it;
	}

	/*suprescrie opertorul -- pentru un IteratorC
	Pre:->true
	Post:->iterator arata la precedentul element
		 ->returneaza noul iterator*/
	IteratorC operator--() noexcept {
		this->pozitie--;
		return *this;
	}

	/*suprescrie opertorul -int pentru un IteratorC
	Pre:->val este int
	Post:->iterator arata la elementul cu val pozitii in urma
		 ->returneaza noul iterator*/
	IteratorC operator-(int val) noexcept {
		auto it = *this;
		it.pozitie -= val;
		return it;
	}

	/*suprascrie operatorul de dereferntiere
	Pre:->true
	Post:->returneaza o referinta nemodificabila la elementul la care arata iteratorul*/
	const TElem& operator*() noexcept {
		return this->v.elemente[this->pozitie];
	}

};


///Iterator ce permite modificari
////////////////////////////////////////////////////////////////////

template<typename TElem>
class Vector<TElem>::IteratorNC :public Vector<TElem>::Iterator {
	friend class Vector<TElem>;
public:
	using Vector<TElem>::Iterator::Iterator;

	/*suprescrie opertorul ++ pentru un IteratorNC
	Pre:->true
	Post:->iterator arata la urmatorul element
		 ->returneaza noul iterator*/
	IteratorNC operator++() noexcept {
		this->pozitie++;
		return *this;
	}

	/*suprescrie opertorul +int pentru un IteratorNC
	Pre:->val este int
	Post:->iterator arata la elementul cu val pozitii in continuare
		 ->returneaza noul iterator*/
	IteratorNC operator+(int val) noexcept {
		auto it = *this;
		it.pozitie += val;
		return it;
	}

	/*suprescrie opertorul -- pentru un IteratorNC
	Pre:->true
	Post:->iterator arata la precedentul element
		 ->returneaza noul iterator*/
	IteratorNC operator--() noexcept {
		this->pozitie--;
		return *this;
	}

	/*suprescrie opertorul -int pentru un IteratorNC
	Pre:->val este int
	Post:->iterator arata la elementul cu val pozitii in urma
		 ->returneaza noul iterator*/
	IteratorNC operator-(int val) noexcept {
		auto it = *this;
		it.pozitie -= val;
		return it;
	}

	/*suprascrie operatorul de dereferntiere
	Pre:->true
	Post:->returneaza o referinta modificabila la elementul la care arata iteratorul*/
	TElem& operator*() noexcept {
		return this->v.elemente[this->pozitie];
	}

};


///Implementare Vector
//////////////////////////////////////////////////////////////////////

template<typename TElem>
Vector<TElem>::Vector()noexcept(false) :dimensiune{ 0 }, capacitate{ CAPACITATE_INITIALA }, elemente{ new TElem[CAPACITATE_INITIALA] }{
}

template<typename TElem>
Vector<TElem>::Vector(const Vector<TElem>& v0)noexcept(false) : dimensiune{ v0.dimensiune }, capacitate{ v0.capacitate }, elemente{ new TElem[v0.capacitate] } {
	for (int i = 0; i < v0.dimensiune; i++)
		this->elemente[i] = v0.elemente[i];
}

template<typename TElem>
Vector<TElem>::Vector(Vector<TElem>&& v0)noexcept {
	this->dimensiune = v0.dimensiune;
	this->capacitate = v0.capacitate;
	this->elemente = v0.elemente;
	v0.capacitate = -1;
	v0.dimensiune = -1;
	v0.elemente = nullptr;
}

template<typename TElem>
Vector<TElem>& Vector<TElem>::operator=(const Vector<TElem>& v0)noexcept(false) {
	if (&v0 == this)
		return *this;
	this->dimensiune = v0.dimensiune;
	this->capacitate = v0.capacitate;
	delete[] this->elemente;
	this->elemente = new TElem[this->capacitate];
	for (int i = 0; i < this->dimensiune; i++)
		this->elemente[i] = v0.elemente[i];
	return *this;
}

template<typename TElem>
Vector<TElem>& Vector<TElem>::operator=(Vector<TElem>&& v0)noexcept {
	this->dimensiune = v0.dimensiune;
	this->capacitate = v0.capacitate;
	delete[] this->elemente;
	this->elemente = v0.elemente;
	v0.capacitate = -1;
	v0.dimensiune = -1;
	v0.elemente = nullptr;
	return *this;
}

template<typename TElem>
void Vector<TElem>::erase(const Iterator& it) noexcept(false){
	for (int i = it.pozitie; i < this->dimensiune - 1; i++)
		this->elemente[i] = this->elemente[i + 1];
	this->dimensiune--;
}

template<typename TElem>
void Vector<TElem>::resize() {
	TElem* aux = new TElem[this->capacitate * 2];
	if (aux != nullptr) {
		for (int i = 0; i < this->dimensiune; i++)
			aux[i] = this->elemente[i];
		delete[] this->elemente;
		this->elemente = aux;
		this->capacitate *= 2;
	}
}

template<typename TElem>
void Vector<TElem>::push_back(const TElem& element) {
	if (this->dimensiune == this->capacitate) {
		this->resize();
	}

	this->elemente[this->dimensiune] = element;
	this->dimensiune++;
}

template<typename TElem>
void Vector<TElem>::insert(const Iterator& it, const TElem& element) {
	if (this->dimensiune == this->capacitate) {
		this->resize();
	}
	for (int i = this->dimensiune; i > it.pozitie; i--)
		this->elemente[i] = this->elemente[i - 1];
	this->elemente[it.pozitie] = element;
	this->dimensiune++;
}


template<typename TElem>
typename Vector<TElem>::IteratorC Vector<TElem>::begin()const noexcept {
	return IteratorC(*this, 0);
}

template<typename TElem>
typename Vector<TElem>::IteratorC Vector<TElem>::end()const noexcept {
	return IteratorC(*this, this->dimensiune);
}



template<typename TElem>
typename Vector<TElem>::IteratorNC Vector<TElem>::begin()noexcept {
	return IteratorNC(*this, 0);
}

template<typename TElem>
typename Vector<TElem>::IteratorNC Vector<TElem>::end()noexcept {
	return IteratorNC(*this, this->dimensiune);
}



//template<typename TElem>
//TElem& Vector<TElem>::operator[](int index)noexcept {
//	return this->elemente[index];
//}

template<typename TElem>
TElem& Vector<TElem>::at(int index)noexcept {
	return this->elemente[index];
}

//template<typename TElem>
//const TElem& Vector<TElem>::operator[](int index)const noexcept {
//	return this->elemente[index];
//}

template<typename TElem>
const TElem& Vector<TElem>::at(int index)const noexcept {
	return this->elemente[index];
}
template<typename TElem>
TElem Vector<TElem>::get(int index)const noexcept {
	return this->elemente[index];
}


template<typename TElem>
int Vector<TElem>::size()const noexcept {
	return this->dimensiune;
}

template<typename TElem>
Vector<TElem>::~Vector() {
	this->dimensiune = -1;
	this->capacitate = -1;
	delete[] this->elemente;
	this->elemente = nullptr;
}