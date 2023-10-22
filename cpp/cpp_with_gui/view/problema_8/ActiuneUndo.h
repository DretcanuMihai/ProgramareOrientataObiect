#pragma once
//modul ce contine definitia actiunii de undo si a claselor derivate din aceasta
#include "RepozitoriuLocatari.h"


class ActiuneUndo
{
public:
	/*realizeaza actiunea de undo
	Pre:->true
	Post:->realizeaza actiunea de undo pentru actiunea precedenta*/
	virtual void doUndo() = 0;

	/*constructor default, lasat default
	Pre:->true
	Post:->se creaa un obiect de tip ActiuneUndo*/
	ActiuneUndo()noexcept = default;

	/*rule of 5, totul default*/
	ActiuneUndo(const ActiuneUndo&) = default;
	ActiuneUndo(ActiuneUndo&&) = default;
	ActiuneUndo& operator=(const ActiuneUndo&) = default;
	ActiuneUndo& operator=(ActiuneUndo&&) = default;
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga :public ActiuneUndo {
private:
	RepozitoriuLocatariAbstract& repo;
	int apartament;
public:
	/*constructor pentru UndoAdauga
	Pre:->repo0 referinta la repo-ul pe care s-ar efectua undo-ul
		->apartament0 este int, apartamentul ultimului apartament adaugat
	Post:->se creaza obiectul UndoAdauga cu informatiile precizate*/
	UndoAdauga(RepozitoriuLocatariAbstract& repo0, int apartament0)noexcept;
	/*realizeaza actiunea de undo asupra repo-ului
	Pre:->true
	Post:->duce repo-ul la starea dinaintea adaugarii obiectului*/
	void doUndo()override;

	/*rule of 5, totul default*/
	UndoAdauga(const UndoAdauga&) = default;
	UndoAdauga(UndoAdauga&&) = default;
	UndoAdauga& operator=(const UndoAdauga&) = default;
	UndoAdauga& operator=(UndoAdauga&&) = default;
	~UndoAdauga() = default;
};

class UndoSterge :public ActiuneUndo {
private:
	RepozitoriuLocatariAbstract& repo;
	Locatar l;
public:
	/*constructor pentru UndoSterge
	Pre:->repo0 referinta la repo-ul pe care s-ar efectua undo-ul
		->l0 este Locatar, este locatarul ce a fost sters
	Post:->se creaza obiectul UndoSterge cu informatiile precizate*/
	UndoSterge(RepozitoriuLocatariAbstract& repo0, const Locatar& l0);

	/*realizeaza actiunea de undo asupra repo-ului
	Pre:->true
	Post:->duce repo-ul la starea dinaintea stergerii obiectului*/
	void doUndo()override;

	/*rule of 5, totul default*/
	UndoSterge(const UndoSterge&) = default;
	UndoSterge(UndoSterge&&) = default;
	UndoSterge& operator=(const UndoSterge&) = default;
	UndoSterge& operator=(UndoSterge&&) = default;
	~UndoSterge() = default;
};

class UndoModifica :public ActiuneUndo {
private:
	RepozitoriuLocatariAbstract& repo;
	Locatar l;
public:
	/*constructor pentru UndoModifica
	Pre:->repo0 referinta la repo-ul pe care s-ar efectua undo-ul
		->l0 este Locatar, este locatarul dinainte de modificare
	Post:->se creaza obiectul UndoModifica cu informatiile precizate*/
	UndoModifica(RepozitoriuLocatariAbstract& repo0, const Locatar& l0);

	/*realizeaza actiunea de undo asupra repo-ului
	Pre:->true
	Post:->duce repo-ul la starea dinaintea modificarii obiectului*/
	void doUndo()override;

	/*rule of 5, totul default*/
	UndoModifica(const UndoModifica&) = default;
	UndoModifica(UndoModifica&&) = default;
	UndoModifica& operator=(const UndoModifica&) = default;
	UndoModifica& operator=(UndoModifica&&) = default;
	~UndoModifica()=default;
};
