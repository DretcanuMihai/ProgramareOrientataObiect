#pragma once
#include "Task.h"

class ValidatorTask
{
public:
	/*functie ce valideaza un task t
	Pre:->true
	Post:->true
	@Daca task-ul este invalid, se arunca o exceptie cu mesajele adecvate:
	"Eroare:Descrierea trebuie sa fie nevida;\n";
	"Eroare:Numarul de programatori trebuie sa fie intre 1 si 4\n";
	"Eroare:Starea trebuie sa fie open,closed sau inprogress;\n";
	*/
	void valideaza(const Task& t);
};

