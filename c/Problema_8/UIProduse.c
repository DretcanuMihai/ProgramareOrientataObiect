#include "UIProduse.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "VectorDinamic.h"
#include "ServiciuProduse.h"
#include "EntitateProdus.h"
#include "ConversiiDinString.h"
#ifndef LIMITA_BUFFER
#define LIMITA_BUFFER 255
#endif

UIProduse* creaza_uiproduse(ServiciuProduse* serv)
{
	UIProduse* uip=(UIProduse*)malloc(sizeof(UIProduse));
	if(uip!=NULL)
		uip->serv = serv;
	return uip;
}

void distruge_uiproduse(UIProduse* uip)
{
	free(uip);
}

/*functie ce afiseaza un mesaj de eroare de buffer
Pre:->True
Post:->se afiseaza un mesaj*/
void eroare_buffer()
{
	printf("Ultima citire a depasit %d de caractere;\nIntoarcere in meniul principal;\n", LIMITA_BUFFER);
}

/*functie ce afiseaza un mesaj de eroare de validare
Pre:->ret este de tip unsigned int si reprezinta cod de eroare
Post:->se afieaza pe ecran un mesaj de eroare specific codului*/
void erori_validare(unsigned int ret)
{
	if ((ret & 1) != 0)
		printf("Eroare: id-ul trebuie sa fie nenul;\n");
	if ((ret & 2) != 0)
		printf("Eroare: tipul trebuie sa fie string nevid;\n");
	if ((ret & 4) != 0)
		printf("Eroare: producatorul trebuie sa fie string nevid;\n");
	if ((ret & 8) != 0)
		printf("Eroare: modelul trebuie sa fie string nevid;\n");
	if ((ret & 16) != 0)
		printf("Eroare: pretul trebuie sa fie mai mare sau egal cu 0.1;\n");
	if ((ret & 32) != 0)
		printf("Eroare: cantitatea trebuie sa fie nenula;\n");
}

/*functie ce afiseaza un mesaj de erare la citirea unei optiuni invalide meniului
Pre:True
Post:->afiseaza pe ecran mesajul de eroare*/
void eroare_optiune()
{
	printf("Optiune nerecunoscuta - Intoarcere in meniul principal;\n");
}

/*functie ce afiseaza un mesaj de eroare la citirea unui string
Pre:->val este de tip unsigned int si reprezinta codul de eroare
Post:->se afiseaza pe ecran un mesaj de eroare specific codului*/
void eroare_citire_string(unsigned int val)
{
	if (val == 1)
		eroare_buffer();
}

/*functie ce afiseaza un mesja de eroare la citirea unui unsigned int
Pre:->val este de tip unsigned int si reprezinta codul de eroare
Post:->se afiseaza pe ecran un mesaj de eroare specific codului*/
void eroare_citire_unsigned_int(unsigned int val)
{
	if (val == 1)
		eroare_buffer();
	else if (val == 2)
		printf("Valoarea citita nu poate avea mai mult de 9 caractere;\n");
	else if (val == 3)
		printf("Tip de data invalid - ar trebui sa se citeasca un numar natural;\n");
}

/*functie ce afiseaza un mesja de eroare la citirea unui double
Pre:->val este de tip unsigned int si reprezinta codul de eroare
Post:->se afiseaza pe ecran un mesaj de eroare specific codului*/
void eroare_citire_double(unsigned int val)
{
	if (val == 1)
		eroare_buffer();
	else if (val == 2)
		printf("Valoarea citita nu poate avea mai mult de 16 caractere;\n");
	else if (val == 3)
		printf("Tip de data invalid - ar trebui sa se citeasca un numar real;\n");
}

/*functie ce valideaza un input dat in consola 
Pre:->input este un pointer la sirul de caractere ce reprezinta ce s-a citit cu fgets
Post:->programul returneaza unsigned int
	 ->returneaza 0 daca este valid inputul (nu s-au citit mai multe caractere decat LIMITA_BUFFER
	 ->altfel returneaza 1*/
unsigned int valideaza_input(char* input)
{
	if (input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = '\0';
		return 0;
	}
	else
	{
		while (input[LIMITA_BUFFER] != '\n')
		{
			input[LIMITA_BUFFER] = '\n';
			fgets(input, LIMITA_BUFFER + 1, stdin);
		}
		return 1;
	}
}

/*functie pentru citirea si validarea unui string
Pre:->ret este pointer de char, adresa la care se citeste
Post:->programul reutnreaza unsigned int
	 ->daca citirea nu a avut succes, se returneaza 1
	 ->altfel se returneaza 0 iar la adresa ret se afla stringul*/
unsigned int citire_string(char* ret)
{
	char buffer[LIMITA_BUFFER+2];
	fgets(buffer, LIMITA_BUFFER + 2, stdin);
	if (valideaza_input(buffer) == 1)
	{
		return 1;
	}
	strcpy(ret, buffer);
	return 0;
}

/*functie pentru citirea si validarea unui unsigned int
Pre:->pval este pointer de unsigned int, adresa la care se citeste
Post:->programul returneaza unsigned int
	  ->daca citirea nu a avut succes, se returneaza un cod de eroare, diferit de 9
	  ->altfel se returneaza 0, iar la adresa pval se afla unsigned int-ul*/
unsigned int citire_unsigned_int(unsigned int* pval)
{
	char buffer[LIMITA_BUFFER+2];
	fgets(buffer, LIMITA_BUFFER + 2, stdin);
	if (valideaza_input(buffer) == 1)
	{
		return 1;
	}
	return str2ui(buffer, pval);
}

/*functie pentru citirea si validarea unui double
Pre:->pval este pointer de double, adresa la care se citeste
Post:->programul returneaza unsigned int
	  ->daca citirea nu a avut succes, se returneaza un cod de eroare, diferit de 9
	  ->altfel se returneaza 0, iar la adresa pval se afla double-ul*/
unsigned int citire_double(double* pval)
{
	char buffer[LIMITA_BUFFER + 2];
	fgets(buffer, LIMITA_BUFFER + 2, stdin);
	if (valideaza_input(buffer) == 1)
	{
		return 1;
	}
	return str2double(buffer,pval);
}


/*functie ce afiseaza pe ecran meniul cu comenzi
Pre:->True
Post:->afiseaza pe ecran meniul*/
void meniu()
{
	printf("Lista de comenzi:\n");
	printf("0.'exit' - opreste aplicatia;\n");
	printf("1.'meniu' - afiseaza un meniu cu comenzile posibile\n");
	printf("2.'afiseaza elemente' - afiseaza elementele din repozitoriu\n");
	printf("3.'adauga element' - adauga un element in repozitoriu\n");
	printf("4.'actualizeaza element' - actualizeaza un element din repozitoriu dupa anumite optiuni;\n");
	printf("5.'sterge element' - sterge un element din repozitoriu dupa id;\n");
	printf("6.'afiseaza elemente sortat' - afiseaza elementele din repositoriu sortate dupa un criteriu;\n");
	printf("7.'filtreaza elemente' - filtreaza elementele din repozitoriu dupa un criteriu;\n");
	printf("8.'clear' - curata consola;\n");
}
/*afiseaza pe ecran un produs
Pre:->p este de tip Produs
Post:->afiseaza pe ecran Produsul*/
void afiseaza_produs(Produs* p)
{
	printf("Produs - ");
	unsigned int id = get_produs_id(p),cantitate=get_produs_cantitate(p);
	double pret = get_produs_pret(p);
	char* tip;
	char* producator;
	char* model;
	model = get_produs_model(p);
	tip=get_produs_tip(p);
	producator=get_produs_producator(p);
	printf("id:%u; tip:%s; producator:%s; model:%s; pret:%0.2lf; cantitate:%u\n", id, tip, producator, model, pret, cantitate);
	free(tip);
	free(model);
	free(producator);
}

/*functie ce afiseaza pe ecran elementele retinute de un VectorDinamic
Pre:->v este pointer la VectorDinamic de produse
Post:->functia afieaza pe ecran fiecare element in parte, pe cate o linie noua(daca vectorul este gol, nu se va afisa nimic)*/
void afiseaza_vector_produse(VectorDinamic* v)
{
	unsigned int i, dim = dimensiune_vector_dinamic(v);
	for (i = 1; i <= dim; i++)
	{
		Produs* p = acceseaza_element_vector_dinamic(v, i);
		afiseaza_produs(p);
		distruge_produs(p);
	}
}

/*functie ce afiseaza pe ecran elementele din repo
Pre:->uip este pointer de UIProduse
Post:->afiseaza toate elementele din repo*/
void afiseaza_elemente(UIProduse* uip)
{
	VectorDinamic* v = get_toate_elementele_serviciu(uip->serv);
	unsigned int dim=dimensiune_vector_dinamic(v);
	if (dim == 0)
	{
		printf("Repozitoriu gol;\n");
	}
	else
	{
		printf("Elemente din repozitoriu:\n");
		afiseaza_vector_produse(v);
	}
	distruge_vector_dinamic(v);
}

/*functie ce adauga in repo un PRodus citit de la tastatura
Pre:->uip este pointer de UIProduse
Post:->se citesc de la tastatura datele pentru un Produs, iar apoi incearca sa adauge elementul in repo, rezultatul operatiei fiind afisat
	   pe ecran*/
void adauga_element(UIProduse* uip)
{
	unsigned int id, cantitate;
	double pret;
	char tip[LIMITA_BUFFER + 2], producator[LIMITA_BUFFER + 2], model[LIMITA_BUFFER + 2];
	unsigned int ret;

	printf("=>ID:");
	ret=citire_unsigned_int(&id);
	if (ret != 0)
	{
		eroare_citire_unsigned_int(ret);
		return;
	}

	printf("=>tip:");
	ret = citire_string(tip);
	if (ret != 0)
	{
		eroare_citire_string(ret);
		return;
	}

	printf("=>producator:");
	ret = citire_string(producator);
	if (ret != 0)
	{
		eroare_citire_string(ret);
		return;
	}

	printf("=>model:");
	ret = citire_string(model);
	if (ret != 0)
	{
		eroare_citire_string(ret);
		return;
	}

	printf("=>pret:");
	ret = citire_double(&pret);
	if (ret != 0)
	{
		eroare_citire_double(ret);
		return;
	}

	printf("=>cantitate:");
	ret = citire_unsigned_int(&cantitate);
	if (ret != 0)
	{
		eroare_citire_unsigned_int(ret);
		return;
	}
	ret = adauga_element_serviciu_produse(uip->serv, id, tip, producator, model, pret, cantitate);
	if (ret == 0)
		printf("Element adaugat cu succes;\n");
	else if (ret == 64)
		printf("Element deja existent - cantitate updatata cu succes;\n");
	else if (ret == 65)
		printf("Element deja existent - una din caracteristicile tip, producator, model, pret nu coincide - Repo neschimbat;\n");
	else
	{
		erori_validare(ret);
		printf("Intoarcere in meniul principal;\n");
	}
}

/*functie ce actualizeaza un element din repo dupa o optiune
Pre:->uip este pointer de UIProduse
Post:->se citesc de la tastatura un id, optiunea de actualizare a elementului si noua informatie de modific, ulteiror progrmaul incercand sa actualizeze
	   datele citite; Se va afisa pe ecran rezultatul operatiei facute*/
void actualizeaza_element(UIProduse* uip)
{
	unsigned int id;
	unsigned int ret;
	char optiune[LIMITA_BUFFER+2];
	printf("Introduceti id-ul elementului de modificat:\n=>ID:");
	ret = citire_unsigned_int(&id);
	if (ret != 0)
	{
		eroare_citire_unsigned_int(ret);
		return;
	}
	printf("Introduceti ce caracteristica o doriti modificata dintre cantitate si pret:\n=>Optiune:");
	ret = citire_string(optiune);
	if (ret != 0)
	{
		eroare_citire_string(ret);
		return;
	}
	void* p;
	if (strcmp(optiune, "cantitate") == 0)
	{
		unsigned int cantitate;
		printf("=>Cantitate:");
		ret = citire_unsigned_int(&cantitate);
		if (ret != 0)
		{
			eroare_citire_unsigned_int(ret);
			return;
		}
		p = (void*)(&cantitate);
		ret = actualizeaza_element_serviciu_produse_opt(uip->serv, id, 1, p);
	}
	else if (strcmp(optiune, "pret") == 0)
	{
		double pret;
		printf("=>Pret:");
		ret = citire_double(&pret);
		if (ret != 0)
		{
			eroare_citire_double(ret);
			return;
		}
		p = (void*)(&pret);
		ret = actualizeaza_element_serviciu_produse_opt(uip->serv, id, 0, p);
	}
	else
	{
		eroare_optiune();
		return;
	}
	if (ret == 0)
		printf("Actualizare realizata cu succes;\n");
	else if (ret < 64)
		erori_validare(ret);
	else if (ret == 64)
		printf("Nu exista un element cu acest id - Repo neschimbat;\n");
}


/*functie ce sterge din repo un Produs dupa un id citit de la tastatura
Pre:->uip este pointer de UIProduse
Post:->se citeste de la tastatura id-ul Produsului de sters, iar progrmaul incearca sa il stearga din repo; rezultatul operatiei se afiseaza pe ecran*/
void sterge_element(UIProduse* uip)
{
	unsigned int id;
	unsigned int ret;
	printf("=>ID:");
	ret = citire_unsigned_int(&id);
	if (ret != 0)
	{
		eroare_citire_unsigned_int(ret);
		return;
	}
	ret = sterge_element_serviciu_produse(uip->serv, id);
	if (ret == 0)
		printf("Operatie realizata cu succes;\n");
	else if (ret < 64)
		erori_validare(ret);
	else if(ret==64)
		printf("Nu exista un element cu acest id in repo - Repozitoriu nemodificat;\n");
}

/*functie ce afiseaza pe ecran elementele din repo sortate dupa un criteriu
Pre:->uip este pointer de UIProduse
Post:->se citeste de la tastatura criteriile de sortate, apoi afiseaza pe ecran elementele din repo, sortate*/
void afiseaza_elemente_sortat(UIProduse* uip)
{
	char optiune[LIMITA_BUFFER + 2];
	printf("Introduceti criteriul de sortare(pret sau cantitate):");
	unsigned ret = citire_string(optiune);
	unsigned int opt;
	int sens;
	if (ret != 0)
	{
		eroare_citire_string(ret);
		return;
	}
	if (strcmp(optiune, "pret") == 0)
	{
		opt = 0;
	}
	else if (strcmp(optiune, "cantitate") == 0)
	{
		opt = 1;
	}
	else
	{
		eroare_optiune();
		return;
	}
	printf("Introduceti ordinea elementelor(crescator sau descrescator):");
	ret = citire_string(optiune);
	if (ret != 0)
	{
		eroare_citire_string(ret);
		return;
	}
	if (strcmp(optiune, "crescator") == 0)
	{
		sens = 1;
	}
	else if (strcmp(optiune, "descrescator") == 0)
	{
		sens = -1;
	}
	else
	{
		eroare_optiune();
		return;
	}
	VectorDinamic* v = sorteaza_produse(uip->serv, opt, sens);
	unsigned int dim = dimensiune_vector_dinamic(v);
	if (dim == 0)
	{
		printf("Repozitoriu gol;\n");
	}
	else
	{
		printf("Elemente din repozitoriu:\n");
		afiseaza_vector_produse(v);
	}
	distruge_vector_dinamic(v);
}

/*functie ce filtreaza elementele din repo
Pre:->uip pointer la UIPrdouse
Post:->se citeste de la tastatura criteriile de afisare, apoi incearca sa filtreze elementele, daca apar erori acestea fiind afisate pe ecran*/
void filtreaza_elemente(UIProduse* uip)
{
	VectorDinamicFiltreazaProduse rezultat;
	unsigned int ret;
	unsigned int opt;
	int sens;
	char cmd[LIMITA_BUFFER + 2];
	printf("Introduceti criteriul de filtrare(producator, pret sau cantitate):");
	ret=citire_string(cmd);
	if (ret != 0)
	{
		eroare_citire_string(ret);
	}
	if (strcmp(cmd, "producator") == 0)
	{
		char filtru[LIMITA_BUFFER + 2];
		opt = 1;
		printf("Introduceti stringul pentru filtru:");
		ret = citire_string(filtru);
		if (ret != 0)
		{
			eroare_citire_string(ret);
			return;
		}
		printf("Doriti ca stringul sa fie continut?(da/nu):");
		ret = citire_string(cmd);
		if (ret != 0)
		{
			eroare_citire_string(ret);
			return;
		}
		if (strcmp(cmd, "da") == 0)
			sens = 1;
		else if (strcmp(cmd, "nu") == 0)
			sens = -1;
		else
		{
			eroare_optiune();
			return;
		}
		void* val = (void*)filtru;
		rezultat = filtreaza_produse(uip->serv, opt, val, sens);
	}
	else if (strcmp(cmd, "pret") == 0)
	{
		double pret;
		opt = 2;
		printf("Introduceti pretul pentru filtru:");
		ret = citire_double(&pret);
		if (ret != 0)
		{
			eroare_citire_double(ret);
			return;
		}
		printf("Doriti ca filtrarea pretului sa fie mai mare sau egala('mai mare') sau sa fie mai mic sau egala('mai mic'):");
		ret = citire_string(cmd);
		if (ret != 0)
		{
			eroare_citire_string(ret);
			return;
		}
		if (strcmp(cmd, "mai mare") == 0)
			sens = 1;
		else if (strcmp(cmd, "mai mic") == 0)
			sens = -1;
		else
		{
			eroare_optiune();
			return;
		}
		void* val = (void*)(&pret);
		rezultat = filtreaza_produse(uip->serv, opt, val, sens);
	}
	else if (strcmp(cmd, "cantitate") == 0)
	{
		unsigned int cantitate;
		opt = 3;
		printf("Introduceti cantitatea pentru filtru:");
		ret = citire_unsigned_int(&cantitate);
		if (ret != 0)
		{
			eroare_citire_double(ret);
			return;
		}
		printf("Doriti ca filtrarea cantitatii sa fie mai mare sau egala('mai mare') sau sa fie mai mic sau egala('mai mic'):");
		ret = citire_string(cmd);
		if (ret != 0)
		{
			eroare_citire_string(ret);
			return;
		}
		if (strcmp(cmd, "mai mare") == 0)
			sens = 1;
		else if (strcmp(cmd, "mai mic") == 0)
			sens = -1;
		else
		{
			eroare_optiune();
			return;
		}
		void* val = (void*)(&cantitate);
		rezultat = filtreaza_produse(uip->serv, opt, val, sens);
	}
	else
	{
		eroare_optiune();
		return;
	}
	if (rezultat.eroare != 0)
	{
		erori_validare(rezultat.eroare);
		return;
	}
	unsigned int dim = dimensiune_vector_dinamic(rezultat.vector_rezultat);
	if (dim == 0)
		printf("Nu exista elemente in repozitoriu ce sa satisfaca filtrul");
	else
	{
		printf("Elemente ce respecta filtrul:\n");
		afiseaza_vector_produse(rezultat.vector_rezultat);
	}
	distruge_vector_dinamic(rezultat.vector_rezultat);
}

/*functie ce da clear la consola
Pre:True
Post:->da clear la consola (elibereaza consola de ce era scris inainte)*/
void clear()
{
	unsigned int i;
	for (i = 0; i < 64; i++)
		printf("\n");
}

void ruleaza_uip(UIProduse* uip)
{
	clear();
	printf("Aplicatie pornita cu succes;\n");
	printf("Pentru a vizulaiza un meniu cu comenzile posibile, introduceti 'meniu'\n");
	printf("!!!TOATE DATELE INTRODUSE POT FI DE MAXIM %d DE CARACTERE!!!\n", LIMITA_BUFFER);
	printf("!!!ESTE POSIBIL CA PRETURILE INTRODUSE SA FIE ROTUNJITE ULTERIOR!!!\n");
	char comanda[LIMITA_BUFFER+2];
	unsigned int ret;
	while (1)
	{
		printf("\n>>>");
		ret=citire_string(comanda);
		if (ret != 0)
			eroare_citire_string(ret);
		else if (strcmp(comanda, "exit") == 0)
		{
			printf("Iesire din aplicatie...");
			return;
		}
		else if (strcmp(comanda, "meniu") == 0)
			meniu();
		else if (strcmp(comanda, "afiseaza elemente") == 0)
			afiseaza_elemente(uip);
		else if (strcmp(comanda, "adauga element") == 0)
			adauga_element(uip);
		else if (strcmp(comanda, "actualizeaza element") == 0)
			actualizeaza_element(uip);
		else if (strcmp(comanda, "sterge element") == 0)
			sterge_element(uip);
		else if (strcmp(comanda, "afiseaza elemente sortat") == 0)
			afiseaza_elemente_sortat(uip);
		else if (strcmp(comanda, "filtreaza elemente") == 0)
			filtreaza_elemente(uip);
		else if (strcmp(comanda, "clear")==0)
			clear();
		else
			printf("Comanda invalida;\nIntroduceti 'meniu' pentru a vedea o lista cu comenzile posibile\n");
	}
}