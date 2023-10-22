#include "ValidatorTask.h"
#include "Exceptii.h"

void ValidatorTask::valideaza(const Task& t)
{
	string erori;
	if (t.getDescriere() == "") {
		erori += "Eroare:Descrierea trebuie sa fie nevida;\n";
	}
	if (t.getProgramatori().size() < 1 || t.getProgramatori().size() > 4) {
		erori += "Eroare:Numarul de programatori trebuie sa fie intre 1 si 4\n";
	}
	if (t.getStare() != "open" && t.getStare() != "closed" && t.getStare() != "inprogress") {
		erori += "Eroare:Starea trebuie sa fie open,closed sau inprogress;\n";
	}
	if (erori.size() > 0)
		throw ExceptieValidare(erori);
}
