#include "Teste.h"
#include "Carte.h"
#include "RepoCarti.h"
#include "ServiciuCarti.h"
#include <assert.h>

void test_carte() {
	Carte c{ "asd","dsa","rosu",23.3 };
	assert(c.get_titlu() == "asd");
	assert(c.get_autor() == "dsa");
	assert(c.get_culoare() == "rosu");
	assert(c.get_grosime() == 23.3);
}
void test_repo() {
	RepoCarti r{ "teste/test.txt" };
	const auto& v = r.get_all();
	assert(v.at(0).get_titlu() == "Ion");
	assert(v.at(0).get_autor() == "unIon");
	assert(v.at(0).get_culoare() == "rosie");
	assert(v.at(0).get_grosime() == 10.3);
	assert(v.at(1).get_titlu() == "AltIon");
	assert(v.at(1).get_autor() == "incaIon");
	assert(v.at(1).get_culoare() == "albastra");
	assert(v.at(1).get_grosime() == 3.3);
	assert(v.at(2).get_titlu() == "UltimIon");
	assert(v.at(2).get_autor() == "HaiIon");
	assert(v.at(2).get_culoare() == "verde");
	assert(v.at(2).get_grosime() == 7.5);
}

void test_serv() {
	ValidatorCarti val;
	RepoCarti r{ "teste/test.txt" };
	ServiciuCarti serv{ r,val };
	auto v = serv.get_all();
	assert(v.at(0).get_titlu() == "Ion");
	assert(v.at(0).get_autor() == "unIon");
	assert(v.at(0).get_culoare() == "rosie");
	assert(v.at(0).get_grosime() == 10.3);
	assert(v.at(1).get_titlu() == "AltIon");
	assert(v.at(1).get_autor() == "incaIon");
	assert(v.at(1).get_culoare() == "albastra");
	assert(v.at(1).get_grosime() == 3.3);
	assert(v.at(2).get_titlu() == "UltimIon");
	assert(v.at(2).get_autor() == "HaiIon");
	assert(v.at(2).get_culoare() == "verde");
	assert(v.at(2).get_grosime() == 7.5);
	v = serv.sort_grosime();
	assert(v.at(2).get_titlu() == "Ion");
	assert(v.at(2).get_autor() == "unIon");
	assert(v.at(2).get_culoare() == "rosie");
	assert(v.at(2).get_grosime() == 10.3);
	assert(v.at(0).get_titlu() == "AltIon");
	assert(v.at(0).get_autor() == "incaIon");
	assert(v.at(0).get_culoare() == "albastra");
	assert(v.at(0).get_grosime() == 3.3);
	assert(v.at(1).get_titlu() == "UltimIon");
	assert(v.at(1).get_autor() == "HaiIon");
	assert(v.at(1).get_culoare() == "verde");
	assert(v.at(1).get_grosime() == 7.5);
	v = serv.sort_titlu();
	assert(v.at(1).get_titlu() == "Ion");
	assert(v.at(1).get_autor() == "unIon");
	assert(v.at(1).get_culoare() == "rosie");
	assert(v.at(1).get_grosime() == 10.3);
	assert(v.at(0).get_titlu() == "AltIon");
	assert(v.at(0).get_autor() == "incaIon");
	assert(v.at(0).get_culoare() == "albastra");
	assert(v.at(0).get_grosime() == 3.3);
	assert(v.at(2).get_titlu() == "UltimIon");
	assert(v.at(2).get_autor() == "HaiIon");
	assert(v.at(2).get_culoare() == "verde");
	assert(v.at(2).get_grosime() == 7.5);

}

void ruleaza_teste()
{
	test_carte();
	test_repo();
	test_serv();
}
