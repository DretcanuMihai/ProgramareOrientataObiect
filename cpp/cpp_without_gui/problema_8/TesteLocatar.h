#pragma once
//#include "Vector.h"

//modul cu o clasa de functii de testare

class TesteLocatar
{
public:
	void ruleaza_toate_testele()const;
private:
	//Vector<int> vector_ajutor()const;
	//void ruleaza_teste_vector()const;
	void ruleaza_teste_domeniu()const;
	void ajutor_oops()const;
	void ruleaza_teste_exceptie_generala()const;
	void ruleaza_teste_validator()const;
	void ruleaza_teste_repozitoriu()const;
	void ruleaza_teste_serviciu()const;
	void ruleaza_teste_conversii()const;
	//void ruleaza_teste_pentru_sortari()const;
	//void ruleaza_teste_pentru_filtrari()const;
	void ruleaza_teste_pentru_serviciu_sort_filtru()const;
	void ruleaza_teste_lista_notificare()const;
	void ruleaza_teste_serviciu_ln()const;
	void ruleaza_teste_repo_fisier()const;
	void ruleaza_teste_actiune_undo()const;
	void ruleaza_teste_undo()const;
	void ruleaza_teste_raport()const;
	void ruleaza_teste_repo_sp()const;
};

