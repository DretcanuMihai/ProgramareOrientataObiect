// modul ce contine definirea structurii de produs si functii legate de aceasta

#ifndef ENTITATE_PRODUS_H_
#define ENTITATE_PRODUS_H_

/*Un definirea structurii de produs
*/
typedef struct{
	unsigned int id;
	char* tip;
	char* producator;
	char* model;
	double pret;
	unsigned int cantitate;
}Produs;

/*Functie ce creeaza un Produs
Pre:->id este unsigned int, reprezinta id-ul produsului
	->ptip este un pointer de char la adresa caruia se afla un sir de caractere ce reprezinta tipul 
	->pproducator este un pointer de char la adresa caruia se afla un sir de caractere ce reprezinta producatorul
	->pmodel este un pointer de char la adresa caruia se afla un sir de caractere ce reprezinta modelul 
	->pret este un double, reprezinta pretul
	->cantitate este un unsigned int, reprezinta cantitatea
Post:->creeaza o entitate de tip Produs alocata dinamic cu caracteristicile date de parametrii functiei
	 ->creeaza_produs=pointer la o entitate de tip Produs cu caracteristicile date ca parametrii
!!!UN PRODUS CREAT TREBUIE DISTRUS ULTERIOR CU distruge_produs*/
Produs* creeaza_produs(unsigned int id , char* tip, char* producator, char* model,double pret,unsigned int cantitate);

/*Functie ce distruge un produs
Pre:->produs este un pointer de produs la entitatea produs de distrus
Post:->produsul de la adresa produs este distrus, memoria ocupata de el fiind eliberata */
void distruge_produs(Produs* produs);

/*Functie ce returneaza id-ul unui produs
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
	->entitatea este valida
Post:->get_produs_id este de tip unsigned int, reprezentand id-ul produsului*/
unsigned int get_produs_id(Produs* produs);

/*Functie ce returneaza tipul unui produs
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
Post:->se returneaza un pointer de char unde se afla sirul cautat 
!!!STRINGUL TREBUIE ULTERIOR ELIBERAT CU free!!!*/
char* get_produs_tip(Produs* produs);

/*Functie ce seteaza tipul unui produs
Pre:->produs este pointer la Produs
Post:->produs.tip'=tip_nou*/
void set_produs_tip(Produs* produs, char* tip_nou);

/*Functie ce returneaza producatorul unui produs
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
Post:->se returneaza un pointer de char unde se afla sirul cautat
!!!STRINGUL TREBUIE ULTERIOR ELIBERAT CU free!!!*/
char* get_produs_producator(Produs* produs);

/*Functie ce seteaza producatorul unui produs
Pre:->produs este pointer la Produs
Post:->produs.producator'=producator_nou*/
void set_produs_producator(Produs* produs, char* producator_nou);

/*Functie ce returneaza modelul unui produs
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
Post:->se returneaza un pointer de char unde se afla sirul cautat
!!!STRINGUL TREBUIE ULTERIOR ELIBERAT CU free!!!*/
char* get_produs_model(Produs* produs);

/*Functie ce seteaza modelul unui produs
Pre:->produs este pointer la Produs
Post:->produs.model'=model_nou*/
void set_produs_model(Produs* produs, char* model_nou);

/*Functie ce returneaza pretul unui produs
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
	->entitatea este valida
Post:->get_produs_pret este de tip double, reprezentand pretul produsului*/
double get_produs_pret(Produs* produs);

/*Functie ce seteaza pretul unui produs cu un pret nou
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
	->entitatea este valida
	->pret_nou este un double ce reprezinta noua valoare a pretului produsului
Post:->pretul produsului aflat la adresa pprodus = pret_nou*/
void set_produs_pret(Produs* produs, double pret_nou);

/*Functie ce returneaza cantitatea unui produs
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
	->entitatea este valida
Post:->get_produs_cantitate este de tip unsigned int, reprezentand cantitatea produsului*/
unsigned int get_produs_cantitate(Produs* produs);

/*Functie ce seteaza cantitatea unui produs cu o cantitatea noua
Pre:->produs este un pointer de produs la entitatea produs pe care se opereaza
	->entitatea este valida
	->cantitate_noua este un double ce reprezinta noua valoare a cantitatii produsului
Post:->cantitatea produsului aflat la adresa pprodus = cantitate_noua*/
void set_produs_cantitate(Produs* produs, unsigned int cantitate_noua);

/*functie ce creaza o copie la un produs si returneaza un pointer la acesta
Pre:->produs este un pointer la un Produs
Post:->se returneaza un pointer la un Produs ce retine aceleasi date ca produs
!!!TREBUIE DISTRUS ULTERIOR CU distruge_produs()!!!*/
Produs* copie_produs(Produs* produs);

#endif