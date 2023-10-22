// modul ce contine Validatoare pentru entitatea de tip Produs

#ifndef VALIDATOR_PRODUS_H_
#define VALIDATOR_PRODUS_H_

#include "EntitateProdus.h"

/*functie ce valideaza o entitate de tip produs
Pre:->prod este un pointer la entitatea Produs de validat
Post:->valideaza_prdus este de tip unsigned int
	 ->valideaza_produs= 0 daca produsul este valid
						 altfel va fi un nr. nenul care bitii sunt setati cu 1 bitii:
														->0 daca id-ul este 0
														->1 daca tipul este un sir vid
														->2 daca producatorul este un sir vid
														->3 daca modelul este un sir vid
														->4 daca pretul este mai mic ca 0.01
														->5 daca cantitatea este 0
*/
unsigned int valideaza_produs(Produs* prod);

#endif