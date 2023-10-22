#pragma once

//Modul ce contine definitia clasei de GUICarti

#include "ServiciuCarti.h"
#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>

class GUICarti:public QWidget
{
private:

	//seriviciul
	ServiciuCarti& serv;

	//tabela de carti
	QTableWidget* tabCarti = new QTableWidget;

	//butoanele pentru sortari
	QPushButton* btnSortNO = new QPushButton{ "Nesortat" };
	QPushButton* btnSortGr = new QPushButton{ "Sortare Grosime" };
	QPushButton* btnSortTl = new QPushButton{ "Sortare Titlu" };
	
	//LineEdituri cu informatii extra
	QLineEdit* infCol = new QLineEdit;
	QLineEdit* infGros = new QLineEdit;

	//functii "active"
	
	/*incarca un vector in tabela de Carti tabCarti,afisandu-se titlul si autorul
	Pre:->v este vector<Carte>
	Post:->in tabCarti se incarca toate cartile din vectorul v*/
	void incarca_tabel(const vector<Carte>& v);





	//pentru initializare

	/*initializeaza plasamentul obiectelor pe ecran
	Pre:->true
	Post:->initializeaza plasamentul obiectelor pe ecran*/
	void estetic();

	/*initializeaza starea initiala a tuturor obiectelor modificabile (precum tabela)
	Pre:->true
	Post:->initializeaza starea initiala a tuturor obiectelor modificabile*/
	void stare_initiala();

	/*face conexiunile la obiectele la care este necesar
	Pre:->true
	Post:->se realizeaza conexiunile*/
	void conecteaza();

public:
	/*constructor de GUICarti ce primeste un serviciu
	Pre:->serv0 este de tip ServiciuCarti
	Post:->creeaza un GUICarti de service serv0 si initializeaza Widget-ul pentru rulare*/
	GUICarti(ServiciuCarti& serv0);
};

