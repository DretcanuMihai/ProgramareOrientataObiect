#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "TesteMain.h"
#include "EntitateProdus.h"
#include "ValidatorProdus.h"
#include "VectorDinamic.h"
#include "RepozitoriuProduse.h"
#include "ServiciuProduse.h"
#include "ConversiiDinString.h"
#include "PentruSortari.h"
#include "PentruFiltrari.h"
#ifndef EPSILON
#define EPSILON 0.0000001
#endif

void ruleaza_teste_produs_domeniu()
{
	printf("	Se ruleaza testele de domeniu...\n");
	unsigned int id = 23;
	char tip[20] = "laptop",tip2[20]="firigidier";
	char producator[20]="Dell",producator2[20]="midoricapu";
	char model[20] = "bun",model2[20]="nobun";
	double pret = 200.12,pret2=123.123;
	unsigned int cantitate = 5,cantitate2=10;
	Produs* prod = creeaza_produs(id, tip, producator, model, pret, cantitate);
	assert(get_produs_id(prod) == id);
	char* auxiliar;
	auxiliar=get_produs_tip(prod);
	assert(strcmp(auxiliar, tip) == 0);
	free(auxiliar);
	auxiliar=get_produs_producator(prod);
	assert(strcmp(auxiliar, producator) == 0);
	free(auxiliar);
	auxiliar=get_produs_model(prod);
	assert(strcmp(auxiliar, model) == 0);
	free(auxiliar);
	assert(fabs(get_produs_pret(prod) - pret) < EPSILON);
	assert(get_produs_cantitate(prod) == cantitate);
	Produs* prod2 = copie_produs(prod);
	assert(get_produs_id(prod2) == id);
	auxiliar = get_produs_tip(prod2);
	assert(strcmp(auxiliar, tip) == 0);
	free(auxiliar);
	auxiliar = get_produs_producator(prod2);
	assert(strcmp(auxiliar, producator) == 0);
	free(auxiliar);
	auxiliar = get_produs_model(prod2);
	assert(strcmp(auxiliar, model) == 0);
	free(auxiliar);
	assert(fabs(get_produs_pret(prod2) - pret) < EPSILON);
	assert(get_produs_cantitate(prod2) == cantitate);
	set_produs_tip(prod, tip2);
	auxiliar=get_produs_tip(prod);
	assert(strcmp(auxiliar, tip2) == 0);
	free(auxiliar);
	set_produs_producator(prod, producator2);
	auxiliar=get_produs_producator(prod);
	assert(strcmp(auxiliar, producator2) == 0);
	free(auxiliar);
	set_produs_model(prod, model2);
	auxiliar=get_produs_model(prod);
	assert(strcmp(auxiliar, model2) == 0);
	free(auxiliar);
	set_produs_pret(prod, pret2);
	assert((get_produs_pret(prod) - pret2) < EPSILON);
	set_produs_cantitate(prod, cantitate2);
	assert(get_produs_cantitate(prod) == cantitate2);
	distruge_produs(prod);
	distruge_produs(prod2);
	printf("	Testele de domeniu rulate cu succes;\n");
}

void ruleaza_teste_produs_validator()
{
	printf("	Se ruleaza testele de validator...\n");
	unsigned int id[2] = { 234,0 }, cantitate[2] = { 5,0 };
	double pret[2] = { +24.33,-0.002 };
	char tip[2][20],producator[2][20],model[2][20];
	strcpy(tip[0],"laptop");
	strcpy(tip[1],"");
	strcpy(producator[0],"intel");
	strcpy(producator[1], "");
	strcpy(model[0],"bun");
	strcpy(model[1], "");
	unsigned int i;
	for (i = 0; i < 64; i++)
	{
		Produs* prod = creeaza_produs(id[i & 1], tip[(i & 2)/2], producator[(i & 4)/4], model[(i & 8)/8], pret[(i & 16)/16], cantitate[(i & 32)/32]);
		assert(valideaza_produs(prod)==i);
		distruge_produs(prod);
	}
	Produs* prod = creeaza_produs(id[0], tip[0], producator[0], model[0], +0.01, cantitate[0]);
	assert(valideaza_produs(prod) ==0);
	distruge_produs(prod);
	printf("	Testele de validator rulate cu succes;\n");
}

void ruleaza_teste_vector_dinamic()
{
	printf("	Se ruleaza testele de vector dinamic...\n");
	VectorDinamic* v=creeaza_vector_dinamic(2,distruge_produs,copie_produs);
	assert(dimensiune_vector_dinamic(v) == 0);
	assert(capacitate_vector_dinamic(v) == 2);
	redimensionare_vector_dinamic(v);
	assert(dimensiune_vector_dinamic(v) == 0);
	assert(capacitate_vector_dinamic(v) == 4);
	unsigned int id = 1, cantitate = 20, id2 = 2, cantitate2 = 32;
	char tip[20] = "auci", producator[20] = "doare", model[20] = "tare",tip2[20]="hmm",producator2[20]="nasol",model2[20]="aaaaah";
	double pret = 20.0,pret2=33.3;
	Produs* produs1 = creeaza_produs(id, tip, producator, model, pret, cantitate);
	Produs* produs2 = creeaza_produs(id2, tip2, producator2, model2, pret2, cantitate2);
	Produs* prod_ret;
	adauga_element_vector_dinamic(v, produs1);
	prod_ret = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(prod_ret) == 1);
	distruge_produs(prod_ret);
	redimensionare_vector_dinamic(v);
	assert(dimensiune_vector_dinamic(v) == 1);
	assert(capacitate_vector_dinamic(v) == 8);
	prod_ret = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(prod_ret) == 1);
	distruge_produs(prod_ret);
	distruge_vector_dinamic(v);
	v = creeaza_vector_dinamic(2, distruge_produs, copie_produs);
	adauga_element_vector_dinamic(v, produs1);
	assert(dimensiune_vector_dinamic(v) == 1);
	prod_ret = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(prod_ret) == 1);
	distruge_produs(prod_ret);
	adauga_element_vector_dinamic(v, produs2);
	assert(dimensiune_vector_dinamic(v) == 2);
	assert(capacitate_vector_dinamic(v) == 2);
	adauga_element_vector_dinamic(v, produs1);
	assert(dimensiune_vector_dinamic(v) == 3);
	assert(capacitate_vector_dinamic(v) == 4);
	actualizeaza_element_vector_dinamic(v, produs2, 1);
	assert(dimensiune_vector_dinamic(v) == 3);
	assert(capacitate_vector_dinamic(v) == 4);
	prod_ret = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(prod_ret) == 2);
	distruge_produs(prod_ret);
	sterge_element_vector_dinamic(v, 1);
	assert(dimensiune_vector_dinamic(v) == 2);
	prod_ret = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(prod_ret) == 1);
	distruge_produs(prod_ret);
	distruge_produs(produs1);
	distruge_produs(produs2);
	distruge_vector_dinamic(v);
	printf("	Testele de vector dinamic rulate cu succes;\n");
}

void ruleaza_teste_repo_produs()
{
	printf("	Se ruleaza testele de repo produs...\n");
	unsigned int id = 23;
	char tip[20] = "laptop", tip2[20] = "firigidier";
	char producator[20] = "Dell", producator2[20] = "midoricapu";
	char model[20] = "bun", model2[20] = "nobun";
	double pret = 200.12, pret2 = 123.123;
	unsigned int cantitate = 5, cantitate2 = 12;
	unsigned int ret;
	RepoProduse* repo=creaza_repo_produse();
	Produs* prod = creeaza_produs(id, tip, producator, model, pret, cantitate);
	VectorDinamic* v;
	v = get_toate_elementele_repo(repo);
	assert(dimensiune_vector_dinamic(v) == 0);
	distruge_vector_dinamic(v);
	ret = adauga_element_repo_produse(repo, prod);
	assert(ret == 0);
	v = get_toate_elementele_repo(repo);
	Produs* paux=acceseaza_element_vector_dinamic(v,1);
	assert(get_produs_id(paux) == 23);
	assert(get_produs_cantitate(paux) == 5);
	distruge_produs(paux);
	assert(dimensiune_vector_dinamic(v) == 1);
	distruge_vector_dinamic(v);
	ret = adauga_element_repo_produse(repo, prod);
	assert(ret == 1);
	v = get_toate_elementele_repo(repo);
	assert(dimensiune_vector_dinamic(v) == 1);
	paux = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(paux) == 23);
	assert(get_produs_cantitate(paux) == 10);
	distruge_produs(paux);
	distruge_vector_dinamic(v);
	distruge_produs(prod);
	prod = creeaza_produs(id, tip2, producator2, model2, pret2, cantitate2);
	ret = adauga_element_repo_produse(repo, prod);
	assert(ret == 2);
	v = get_toate_elementele_repo(repo);
	assert(dimensiune_vector_dinamic(v) == 1);
	paux = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(paux)==23);
	assert(get_produs_cantitate(paux) == 10);
	distruge_produs(paux);
	distruge_vector_dinamic(v);
	distruge_produs(prod);
	prod = creeaza_produs(2, tip2, producator2, model2, pret2, cantitate2);
	ret=adauga_element_repo_produse(repo, prod);
	assert(ret == 0);
	v = get_toate_elementele_repo(repo);
	assert(dimensiune_vector_dinamic(v) == 2);
	paux = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(paux) == 23);
	distruge_produs(paux);
	paux = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(paux) == 2);
	distruge_produs(paux);
	distruge_vector_dinamic(v);
	distruge_produs(prod);
	prod = creeaza_produs(5, tip, producator, model, pret, cantitate);
	ret=actualizeaza_element_repo_produse(repo, prod);
	distruge_produs(prod);
	assert(ret == 1);
	prod = creeaza_produs(2, tip, producator, model, pret, cantitate);
	ret = actualizeaza_element_repo_produse(repo, prod);
	distruge_produs(prod);
	assert(ret == 0);
	v = get_toate_elementele_repo(repo);
	prod = acceseaza_element_vector_dinamic(v,2);
	assert(get_produs_id(prod) == 2);
	char* auxiliar;
	auxiliar=get_produs_tip(prod);
	assert(strcmp(auxiliar, tip) == 0);
	free(auxiliar);
	auxiliar=get_produs_producator(prod);
	assert(strcmp(auxiliar, producator) == 0);
	free(auxiliar);
	auxiliar=get_produs_model(prod);
	assert(strcmp(auxiliar, model) == 0);
	free(auxiliar);
	assert(fabs(get_produs_pret(prod) - pret) < EPSILON);
	assert(get_produs_cantitate(prod) == cantitate);
	distruge_produs(prod);
	distruge_vector_dinamic(v);
	ret = sterge_element_repo_produse(repo, 1);
	assert(ret == 1);
	v = get_toate_elementele_repo(repo);
	assert(dimensiune_vector_dinamic(v) == 2);
	distruge_vector_dinamic(v);
	ret = sterge_element_repo_produse(repo, 23);
	v = get_toate_elementele_repo(repo);
	assert(dimensiune_vector_dinamic(v) == 1);
	paux = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(paux) == 2);
	distruge_produs(paux);
	distruge_vector_dinamic(v);
	distruge_repo_produse(repo);
	printf("	Testele de repo produs rulate cu succes;\n");
}

void ruleaza_teste_serviciu_produs_ASA()
{
	printf("	Se ruleaza testele ASA de serviciu...\n");
	RepoProduse* repo = creaza_repo_produse();
	ServiciuProduse* serv = creeaza_serviciu_produse(repo);

	unsigned int id = 23;
	char tip[20] = "laptop", tipiv[20] = "";
	char producator[20] = "Dell";
	char model[20] = "bun";
	double pret = 200.12, pretiv = -123.123;
	unsigned int cantitate = 5;
	unsigned int ret;

	ret=adauga_element_serviciu_produse(serv, id, tipiv, producator, model, pretiv, cantitate);
	assert(ret == 18);
	VectorDinamic* v = get_toate_elementele_serviciu(serv);
	assert(dimensiune_vector_dinamic(v) == 0);
	distruge_vector_dinamic(v);
	ret = adauga_element_serviciu_produse(serv, id, tip, producator, model, pret, cantitate);
	assert(ret == 0);
	v = get_toate_elementele_serviciu(serv);
	Produs* p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 23);
	assert(get_produs_cantitate(p) == 5);
	distruge_produs(p);
	distruge_vector_dinamic(v);
	ret = adauga_element_serviciu_produse(serv, id, tip, producator, model, pret, 3);
	assert(ret == 64);
	v = get_toate_elementele_serviciu(serv);
	assert(dimensiune_vector_dinamic(v) == 1);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 23);
	assert(get_produs_cantitate(p) == 8);
	distruge_produs(p);
	distruge_vector_dinamic(v);
	ret = adauga_element_serviciu_produse(serv, id, tip, producator, model, 5.0, 3);
	assert(ret == 65);
	v = get_toate_elementele_serviciu(serv);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 23);
	assert(get_produs_cantitate(p) == 8);
	distruge_produs(p);
	assert(dimensiune_vector_dinamic(v) == 1);
	distruge_vector_dinamic(v);
	ret=adauga_element_serviciu_produse(serv,100,tip,producator,model,5.0,3);
	v = get_toate_elementele_serviciu(serv);
	assert(dimensiune_vector_dinamic(v) == 2);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 23);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(p) == 100);
	distruge_produs(p);
	distruge_vector_dinamic(v);

	double val = 2.00,valiv=-2.00;
	void* adr =(void*) &val;
	void* adriv = (void*)&valiv;
	ret = actualizeaza_element_serviciu_produse_opt(serv, 0, 0, adr);
	assert(ret == 1);
	ret = actualizeaza_element_serviciu_produse_opt(serv, 23, 0, adriv);
	assert(ret == 16);
	ret = actualizeaza_element_serviciu_produse_opt(serv, 23, 0, adr);
	assert(ret == 0);
	v = get_toate_elementele_serviciu(serv);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 23);
	assert(fabs(get_produs_pret(p) - val) < EPSILON);
	distruge_produs(p);
	distruge_vector_dinamic(v);
	unsigned int cantitate_noua = 100;
	adr = (void*)&cantitate_noua;
	ret = actualizeaza_element_serviciu_produse_opt(serv, 23, 1, adr);
	v = get_toate_elementele_serviciu(serv);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 23);
	assert(get_produs_cantitate(p)==100);
	distruge_produs(p);
	distruge_vector_dinamic(v);

	adr = (void*)&pret;
	ret = actualizeaza_element_serviciu_produse_opt(serv, 33, 1, adr);
	assert(ret == 64);

	ret=sterge_element_serviciu_produse(serv, 0);
	assert(ret == 1);
	v = get_toate_elementele_serviciu(serv);
	assert(dimensiune_vector_dinamic(v) == 2);
	distruge_vector_dinamic(v);
	ret = sterge_element_serviciu_produse(serv, 1);
	assert(ret == 64);
	v = get_toate_elementele_serviciu(serv);
	assert(dimensiune_vector_dinamic(v) == 2);
	distruge_vector_dinamic(v);
	ret = sterge_element_serviciu_produse(serv, 23);
	v = get_toate_elementele_serviciu(serv);
	assert(dimensiune_vector_dinamic(v) == 1);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 100);
	distruge_produs(p);
	distruge_vector_dinamic(v);
	distruge_repo_produse(repo);
	distruge_serviciu_produse(serv);
	printf("	Testele ASA de serviciu produs rulate cu succes;\n");
}

void ruleaza_teste_conversii()
{
	printf("	Se ruleaza testele de conversie...;\n");
	unsigned int ret;

	unsigned int uv;
	char vid[100]="",v1[100] = "12345678901",v2[100] ="1231d312",v3[100] ="3883!",v4[100] ="00443";
	ret = str2ui(v1, &uv);
	assert(ret == 2);
	ret = str2ui(vid, &uv);
	assert(ret == 3);
	ret = str2ui(v2, &uv);
	assert(ret == 3);
	ret = str2ui(v3, &uv);
	assert(ret == 3);
	ret = str2ui(v4, &uv);
	assert(ret == 0);
	assert(uv == 443);

	double dv;
	char vd1[100] = "1235345345.12323434534123",vd2[100] ="1.346..3",vd3[100] ="1231123as2321",vd4[100] ="3123.3s",vd5[100] ="-123.3a";
	char vd6[100] = "132.22", vd7[100] = "-0.2", vd8[100] = "+33.3", vd9[100] = "-.31";
	ret = str2double(vd1, &dv);
	assert(ret == 2);
	ret = str2double(vid, &dv);
	assert(ret == 3);
	ret = str2double(vd2, &dv);
	assert(ret == 3);
	ret = str2double(vd3, &dv);
	assert(ret == 3);
	ret = str2double(vd4, &dv);
	assert(ret == 3);
	ret = str2double(vd5, &dv);
	assert(ret == 3);
	ret = str2double(vd6, &dv);
	assert(ret == 0);
	assert(fabs(dv - 132.22) < EPSILON);
	ret = str2double(vd7, &dv);
	assert(ret == 0);
	assert(fabs(dv + 0.2) < EPSILON);
	ret = str2double(vd8, &dv);
	assert(ret == 0);
	assert(fabs(dv - 33.3) < EPSILON);
	ret = str2double(vd9, &dv);
	assert(ret == 0);
	assert(fabs(dv + 0.31) < EPSILON);

	printf("	Testele de conversie rulate cu succes\n");
}

void ruleaza_teste_pentru_sortari()
{
	printf("	Se ruleaza testele pentru sortari...\n");
	Produs* p1 = creeaza_produs(3, "", "", "", 1.00, 3);
	Produs* p2;
	p2 = creeaza_produs(0, "", "", "", 2.00, 3);
	assert(comparator_pret(p1, p2) == -1);
	distruge_produs(p2);
	p2 = creeaza_produs(0, "", "", "",0.23, 3);
	assert(comparator_pret(p1, p2) == 1);
	distruge_produs(p2);
	p2 = creeaza_produs(4, "", "", "", 1.00, 3);
	assert(comparator_pret(p1, p2) == 0);
	distruge_produs(p2);


	p2 = creeaza_produs(0, "", "", "", 2.00, 4);
	assert(comparator_cantitate(p1, p2) == -1);
	distruge_produs(p2);
	p2 = creeaza_produs(0, "", "","", 0.23, 2);
	assert(comparator_cantitate(p1, p2) == 1);
	distruge_produs(p2);
	p2 = creeaza_produs(4, "", "", "", 1.00, 3);
	assert(comparator_cantitate(p1, p2) == 0);
	distruge_produs(p2);
	

	p2 = creeaza_produs(4, "", "", "", 1.00, 4);
	assert(comparator_id(p1, p2) == -1);
	distruge_produs(p2);
	p2 = creeaza_produs(2, "", "", "", 3.21, 4);
	assert(comparator_id(p1, p2) == 1);
	distruge_produs(p2);
	p2 = creeaza_produs(3, "", "", "", 3123, 33);
	assert(comparator_id(p1, p2) == 0);
	distruge_produs(p2);
	
	distruge_produs(p1);


	VectorDinamic* v = creeaza_vector_dinamic(10,distruge_produs,copie_produs);
	p1 = creeaza_produs(3, "a", "b", "c", 123.00, 2);
	p2 = creeaza_produs(1, "a", "c", "S", 123.00, 1);
	Produs* p3 = creeaza_produs(2, "s", "13", "ddf", 145.00, 3);
	adauga_element_vector_dinamic(v,p1);
	adauga_element_vector_dinamic(v,p2);
	adauga_element_vector_dinamic(v,p3);
	distruge_produs(p1);
	distruge_produs(p2);
	distruge_produs(p3);
	sorteaza_vector(v, comparator_pret, -1);
	p1 = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p1) == 2);
	distruge_produs(p1);
	p1 = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(p1) == 1);
	distruge_produs(p1);
	p1 = acceseaza_element_vector_dinamic(v, 3);
	assert(get_produs_id(p1) == 3);
	distruge_produs(p1);

	sorteaza_vector(v, comparator_cantitate, 1);
	p1 = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p1) == 1);
	distruge_produs(p1);
	p1 = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(p1) == 3);
	distruge_produs(p1);
	p1 = acceseaza_element_vector_dinamic(v, 3);
	assert(get_produs_id(p1) == 2);
	distruge_produs(p1);

	distruge_vector_dinamic(v);
	printf("	Testele pentru sortari rulate cu succes;\n");
}

void ruleaza_teste_serviciu_sort()
{
	printf("	Se ruleaza testele de sortare serviciu...\n");
	RepoProduse* r = creaza_repo_produse();
	ServiciuProduse* serv = creeaza_serviciu_produse(r);

	adauga_element_serviciu_produse(serv, 100, "a", "b", "c", 101.00, 103);
	adauga_element_serviciu_produse(serv, 103, "a", "b", "c", 102.00, 101);
	adauga_element_serviciu_produse(serv, 102, "a", "b", "c", 100.00, 102);
	adauga_element_serviciu_produse(serv, 101, "a", "b", "c", 102.00, 102);
	VectorDinamic* v = sorteaza_produse(serv,0,1);
	Produs* p;
	p= acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 102);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(p) == 100);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 3);
	assert(get_produs_id(p) == 101);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 4);
	assert(get_produs_id(p) == 103);
	distruge_produs(p);
	distruge_vector_dinamic(v);

	v = sorteaza_produse(serv, 1, -1);
	p = acceseaza_element_vector_dinamic(v, 1);
	assert(get_produs_id(p) == 100);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 2);
	assert(get_produs_id(p) == 101);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 3);
	assert(get_produs_id(p) == 102);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(v, 4);
	assert(get_produs_id(p) == 103);
	distruge_produs(p);
	distruge_vector_dinamic(v);

	distruge_serviciu_produse(serv);
	distruge_repo_produse(r);
	printf("	Testele de sortare serviciu rulate cu succes;\n");
}

void ruleaza_teste_pentru_filtrari()
{
	printf("	Se ruleaza testele pentru filtrari...\n");
	void* aux;
	Produs* p = creeaza_produs(3, "a", "Ninitiendo", "c", 123.00, 100);
	char producator[20] = "tiendo", producator2[20] = "initt",producator3[20]="Ninitiendo";
	aux = (void*)producator;
	int ret = filtru_producator(p, aux);
	assert(ret == 1);
	aux = (void*)producator2;
	ret = filtru_producator(p, aux);
	assert(ret == -1);
	aux = (void*)producator3;
	ret = filtru_producator(p, aux);
	assert(ret == 1);

	double pret1 = 123.00, pret2 = 50.33, pret3 = 123.33;
	aux = (void*)(&pret1);
	ret = filtru_pret(p, aux);
	assert(ret == 0);
	aux = (void*)(&pret2);
	ret = filtru_pret(p, aux);
	assert(ret == 1);
	aux = (void*)(&pret3);
	ret = filtru_pret(p, aux);
	assert(ret == -1);

	unsigned int c1 = 100, c2 = 123, c3 = 77;
	aux = (void*)(&c1);
	ret = filtru_cantitate(p, aux);
	assert(ret == 0);
	aux = (void*)(&c2);
	ret = filtru_cantitate(p, aux);
	assert(ret == -1);
	aux = (void*)(&c3);
	ret = filtru_cantitate(p, aux);
	assert(ret == 1);
	distruge_produs(p);

	VectorDinamic* v = creeaza_vector_dinamic(8,distruge_produs,copie_produs);
	p = creeaza_produs(1, "a", "Daniel", "a", 1, 3);
	adauga_element_vector_dinamic(v, p);
	distruge_produs(p);
	p = creeaza_produs(2, "a", "Adandanache", "a", 1, 7);
	adauga_element_vector_dinamic(v, p);
	distruge_produs(p);
	p = creeaza_produs(3, "a", "aDanut", "a", 1, 1);
	adauga_element_vector_dinamic(v, p);
	distruge_produs(p);
	p = creeaza_produs(4, "A", "Bobeica", "a", 1, 1);
	adauga_element_vector_dinamic(v, p);
	distruge_produs(p);

	char paux[20] = "Dan";
	aux = (void*)paux;

	VectorDinamic* rez = filtreaza_vector(v, filtru_producator, aux, 1);
	assert(dimensiune_vector_dinamic(rez) == 2);
	p = acceseaza_element_vector_dinamic(rez, 1);
	assert(get_produs_id(p) == 1);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(rez, 2);
	assert(get_produs_id(p) == 3);
	distruge_produs(p);
	distruge_vector_dinamic(rez);

	rez = filtreaza_vector(v, filtru_producator, aux, -1);
	assert(dimensiune_vector_dinamic(rez) == 2);
	p = acceseaza_element_vector_dinamic(rez, 1);
	assert(get_produs_id(p) == 2);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(rez, 2);
	assert(get_produs_id(p) == 4);
	distruge_produs(p);
	distruge_vector_dinamic(rez);


	unsigned int c = 3;
	aux = (void*)(&c);
	rez = filtreaza_vector(v, filtru_cantitate, aux, 1);
	assert(dimensiune_vector_dinamic(rez) == 2);
	p = acceseaza_element_vector_dinamic(rez, 1);
	assert(get_produs_id(p) == 1);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(rez, 2);
	assert(get_produs_id(p) == 2);
	distruge_produs(p);
	distruge_vector_dinamic(rez);

	rez = filtreaza_vector(v, filtru_cantitate, aux, -1);
	assert(dimensiune_vector_dinamic(rez) == 3);
	p = acceseaza_element_vector_dinamic(rez, 1);
	assert(get_produs_id(p) == 1);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(rez, 2);
	assert(get_produs_id(p) == 3);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(rez, 3);
	assert(get_produs_id(p) == 4);
	distruge_produs(p);
	distruge_vector_dinamic(rez);

	distruge_vector_dinamic(v);
	printf("	Testele pentru filtrari rulate cu succes;\n");
}

void ruleaza_teste_serviciu_filtreaza()
{
	printf("	Se ruleaza testele de filtrare serviciu...\n");
	RepoProduse* repo = creaza_repo_produse();
	ServiciuProduse* serv = creeaza_serviciu_produse(repo);


	adauga_element_serviciu_produse(serv, 107, "a", "Producator", "dddd", 107, 100);
	adauga_element_serviciu_produse(serv, 101, "a", "Producator", "dddd", 100, 101);
	adauga_element_serviciu_produse(serv, 103, "a", "Producator", "dddd", 103.12, 102);
	void* aux;
	char producator[20] = "";
	aux = (void*)producator;
	VectorDinamicFiltreazaProduse ret = filtreaza_produse(serv, 1, aux, 1);
	assert(ret.vector_rezultat == NULL);
	assert(ret.eroare == 4);


	double pret = 103.12;
	aux = (void*)(&pret);
	ret = filtreaza_produse(serv, 2,aux,1);
	assert(ret.eroare == 0);
	assert(dimensiune_vector_dinamic(ret.vector_rezultat) == 2);
	Produs* p = acceseaza_element_vector_dinamic(ret.vector_rezultat, 1);
	assert(get_produs_id(p) == 107);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(ret.vector_rezultat, 2);
	assert(get_produs_id(p) == 103);
	distruge_produs(p);
	distruge_vector_dinamic(ret.vector_rezultat);

	unsigned int cantitate = 101;
	aux = (void*)(&cantitate);
	ret = filtreaza_produse(serv, 3, aux, -1);
	assert(ret.eroare == 0);
	assert(dimensiune_vector_dinamic(ret.vector_rezultat) == 2);
	p = acceseaza_element_vector_dinamic(ret.vector_rezultat, 1);
	assert(get_produs_id(p) == 107);
	distruge_produs(p);
	p = acceseaza_element_vector_dinamic(ret.vector_rezultat, 2);
	assert(get_produs_id(p) == 101);
	distruge_produs(p);
	distruge_vector_dinamic(ret.vector_rezultat);


	distruge_serviciu_produse(serv);
	distruge_repo_produse(repo);
	printf("	Testele de filtrare serviciu rulate cu succes;\n");
}

void ruleaza_toate_testele()
{
	printf("Se ruleaza testele...\n");
	ruleaza_teste_conversii();
	ruleaza_teste_produs_domeniu();
	ruleaza_teste_produs_validator();
	ruleaza_teste_vector_dinamic();
	ruleaza_teste_repo_produs();
	ruleaza_teste_serviciu_produs_ASA();
	ruleaza_teste_pentru_sortari();
	ruleaza_teste_serviciu_sort();
	ruleaza_teste_pentru_filtrari();
	ruleaza_teste_serviciu_filtreaza();
	printf("Teste rulate cu succes;\n");
}