#pragma once

//modul cu functii de conversie

#include <string>
using std::string;

/*functie ce converteste string in int
Pre:str este string
	val este int dat prin referinta
Post:val'=conversia lui str in int
@Daca string-ul nu reprezinta un intreg sau intregul este mai mare de 9 caractere, se ridica o ExceptieInputData cu mesaj:
"Eroare: Acest camp primeste intregi de pana la 9 cifre;\n"
Daca se ridica vreo eroare, val ramane nemodificat
*/
void string2int(const string& str, int& val);


/*functie ce converteste string in double
Pre:str este string
	val este double dat prin referinta
Post:val'=conversia lui str in double
@Daca string-ul nu reprezinta un double sau double-ul este mai mare de 6 caractere dupa sau inainte de virgula, se ridica o ExceptieInputData cu mesaj:
"Eroare: Acest camp primeste valori reale cu maxim 6 cifre inainte si dupa virgula;\n"
Daca se ridica vreo eroare, val ramane nemodificat
*/
void string2double(const string& str, double& val);