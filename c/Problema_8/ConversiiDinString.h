//modul ce contine functii ce convertesc stringuri in valori numerice


/*functie ce face conversie din string in unsigned int
Pre:->buffer este cstring pentru care trebuie facuta conversia
	->pval este pointer la locatia in care trebuie salvat unsigned int-ul
Post:->returnul este de tip unsigned int
	 ->daca bufferul e mai lung de 9 caractere, se returneaza 2 si conversia a esuat
	 ->daca bufferul nu reprezinta un unsigned int valid, se va returna 3
	 ->daca numarul este valid, se va returna 0, iar in pval se va afla conversia*/
unsigned int str2ui(char* buffer, unsigned int* pval);


/*functie ce face conversie din string in double
Pre:->buffer este cstring pentru care trebuie facuta conversia
	->pval est epointer la un double unde trebuie salvata valoarea
Post:->returnul este de tip unsigned int
	 ->daca bufferul e mai lung de 16 caractere , se returneaza 2 si conversia a esuat
	 ->daca bufferul nu reprezinta o valoare reala valida, se va returna 3
	 ->daca numarul este valid, se va returna 0 iar in pval se va afla conversia*/
unsigned int str2double(char* buffer, double* pval);