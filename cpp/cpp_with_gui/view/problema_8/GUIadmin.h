#pragma once
#include "MyWidget.h"
#include "ServiciuLocatari.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include "Observer_Observable.h"
#include "MyListModel.h"
#include <QListView>

class GUIadmin:public MyWidget,public Observer
{
private:
	//chestii separate
	ServiciuLocatari& serv;

	//		Suprafata1
	QListView* lstAps = new QListView;
	MyListModel* modLstAps = new MyListModel(this);
	QPushButton* btnRefresh = new QPushButton{ "Refresh" };
	QPushButton* btnRaport = new QPushButton{ "Raport" };


	//				butoanele pentru sort

	QPushButton* btnSort = new QPushButton{ "Sorteaza" };
	QRadioButton* btnSortNP = new QRadioButton{"Nume Proprietar"};
	QRadioButton* btnSortSp = new QRadioButton{ "Suprafata" };
	QRadioButton* btnSortTASp = new QRadioButton{ "Tip Apartament si Suprafata" };
	QCheckBox* cboxSortReverse = new QCheckBox{ "Reversed" };

	//				butoanele pentru Filtru
	QPushButton* btnFiltru = new QPushButton{ "Filtru" };
	QRadioButton* btnFiltruSp = new QRadioButton{ "Suprafata" };
	QRadioButton* btnFiltruTA = new QRadioButton{ "Tip Apartament" };
	QCheckBox* cboxFiltruReverse = new QCheckBox{ "Reversed" };



	//		Suprafata 2
	QPushButton* btnBack = new QPushButton{ "Inapoi" };


	//			Layout pentru LineEdits
	QLineEdit* infAp = new QLineEdit;
	QLineEdit* infNP = new QLineEdit;
	QLineEdit* infSp = new QLineEdit;
	QLineEdit* infTA = new QLineEdit;

	//				CRUD1
	QPushButton* btnAdauga = new QPushButton{ "Adauga" };
	QPushButton* btnModifica = new QPushButton{ "Modifica" };

	//				CRUD2 + undo
	QPushButton* btnSterge = new QPushButton{ "Sterge" };
	QPushButton* btnCauta = new QPushButton{ "Cauta" };
	QPushButton* btnUndo = new QPushButton{ "Undo" };






	//pentru constructor
	void asambleaza();
	void initializeaza();
	void conecteaza();

	//chestii
	void incarca_lista(const vector<Locatar>& vecl);
	void gui_refresh();
	void gui_raport();
	void gui_sort();
	void gui_filtru();
	void gui_adauga();
	void gui_modifica();
	void gui_sterge();
	void gui_cauta();
	void gui_undo();

	void update() override;


public:
	GUIadmin(ServiciuLocatari& serv0);
};

