#include "ActiuneUndo.h"

UndoAdauga::UndoAdauga(RepozitoriuLocatariAbstract& repo0, int apartament0) noexcept:repo{repo0},apartament{apartament0}
{
}

void UndoAdauga::doUndo()
{
	this->repo.sterge(apartament);
}

UndoSterge::UndoSterge(RepozitoriuLocatariAbstract& repo0, const Locatar& l0) :repo{ repo0 }, l{ l0 }
{
}

void UndoSterge::doUndo()
{
	this->repo.adauga(l);
}

UndoModifica::UndoModifica(RepozitoriuLocatariAbstract& repo0, const Locatar& l0) :repo{ repo0 }, l{ l0 }
{
}

void UndoModifica::doUndo()
{
	this->repo.modifica(l);
}
