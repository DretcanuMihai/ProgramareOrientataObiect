#include "GUIadmin.h"
#include "ExceptiiLocatar.h"
#include <QMessageBox>
#include "Conversii.h"
#include <QTableWidget>
#include <QTableView>
#include "MyTableModel.h"

void GUIadmin::asambleaza()
{
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);

	//Main
	QVBoxLayout* lyS1 = new QVBoxLayout;
	QVBoxLayout* lyS2 = new QVBoxLayout;
	lyMain->addLayout(lyS1);
	lyMain->addStretch();
	lyMain->addLayout(lyS2);

	//S1	
	lyS1->addWidget(new QLabel{ "Lista apartamente:" });
	lyS1->addWidget(this->lstAps);
	lyS1->addWidget(this->btnRefresh);
	lyS1->addWidget(this->btnRaport);
	QHBoxLayout* lySortFiltru = new QHBoxLayout;
	lyS1->addLayout(lySortFiltru);

	
	//SortFiltru	
	QGroupBox* grpSort = new QGroupBox;
	QGroupBox* grpFiltru = new QGroupBox;
	lySortFiltru->addWidget(grpSort);
	lySortFiltru->addWidget(grpFiltru);

	//Sort
	QVBoxLayout* lySort = new QVBoxLayout;
	grpSort->setLayout(lySort);
	lySort->addWidget(this->btnSort);
	lySort->addWidget(new QLabel{ "Criteriu de sortare:" });
	lySort->addWidget(this->btnSortNP);
	lySort->addWidget(this->btnSortSp);
	lySort->addWidget(this->btnSortTASp);
	lySort->addWidget(this->cboxSortReverse);
	lySort->addStretch();

	//filtru
	QVBoxLayout* lyFiltru = new QVBoxLayout;
	grpFiltru->setLayout(lyFiltru);
	lyFiltru->addWidget(this->btnFiltru);
	lyFiltru->addWidget(new QLabel{ "Criteriu de filtrare:" });
	lyFiltru->addWidget(this->btnFiltruSp);
	lyFiltru->addWidget(this->btnFiltruTA);
	lyFiltru->addWidget(this->cboxFiltruReverse);
	lyFiltru->addStretch();





	//S2
	QFormLayout* lyInfo = new QFormLayout;
	QHBoxLayout* lyCRUD = new QHBoxLayout;
	QHBoxLayout* lyCRUD2 = new QHBoxLayout;
	lyS2->addLayout(lyInfo);
	lyS2->addLayout(lyCRUD);
	lyS2->addLayout(lyCRUD2);
	lyS2->addStretch();
	lyS2->addWidget(this->btnBack);

	
	//Info	
	lyInfo->addRow("Apartament", this->infAp);
	lyInfo->addRow("Nume Proprietar", this->infNP);
	lyInfo->addRow("Suprafata", this->infSp);
	lyInfo->addRow("Tip Apartament", this->infTA);

	//CRUD1
	lyCRUD->addWidget(this->btnAdauga);
	lyCRUD->addWidget(this->btnModifica);
	
	//CRUD2
	lyCRUD2->addWidget(this->btnSterge);
	lyCRUD2->addWidget(this->btnCauta);
	lyCRUD2->addWidget(this->btnUndo);

}

void GUIadmin::initializeaza()
{
	//incarca lista
	this->lstAps->setModel(this->modLstAps);
	this->incearca(std::bind(&GUIadmin::gui_refresh, this));
	

	//seteaza starea initiala a checkboxurilor
	this->cboxSortReverse->setChecked(false);
	this->btnFiltruSp->setChecked(true);
	this->cboxFiltruReverse->setChecked(false);
	this->btnSortNP->setChecked(true);

	//seteaza maxlength-ul LineEditurilor
	this->infAp->setMaxLength(MAXLENGTH);
	this->infNP->setMaxLength(MAXLENGTH);
	this->infSp->setMaxLength(MAXLENGTH);
	this->infTA->setMaxLength(MAXLENGTH);


}

void GUIadmin::conecteaza()
{
	//F1
	// 
	//Lista de apartamente
	QObject::connect(this->lstAps->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		if (this->lstAps->selectionModel()->selectedIndexes().isEmpty()) {
			/*this->infAp->setText("");
			this->infNP->setText("");
			this->infSp->setText("");
			this->infTA->setText("");*/
			return;
		}
		auto item = this->lstAps->selectionModel()->selectedIndexes().at(0);

		this->infAp->setText(item.data(Qt::DisplayRole).toString());
		this->incearca(std::bind(&GUIadmin::gui_cauta,this));

		});

	//refresh
	QObject::connect(this->btnRefresh, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_refresh,this));
		});

	//raport
	QObject::connect(this->btnRaport, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_raport,this));
		});

	//Sort
	QObject::connect(this->btnSort, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_sort, this));
		});
	//Filtru
	QObject::connect(this->btnFiltru, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_filtru,this));
		});


	//F2
	
	//CRUD+undo
	//adauga
	QObject::connect(this->btnAdauga, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_adauga, this));
		});
	//modifica
	QObject::connect(this->btnModifica, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_modifica,this));
		});
	//sterge
	QObject::connect(this->btnSterge, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_sterge,this));
		});
	//cauta
	QObject::connect(this->btnCauta, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_cauta,this));
		});
	//undo
	QObject::connect(this->btnUndo, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIadmin::gui_undo,this));
		});


	//back
	QObject::connect(this->btnBack, &QPushButton::clicked, this, [this]() {
		this->close();
		});
}



void GUIadmin::incarca_lista(const vector<Locatar>& vecl)
{
	this->modLstAps->setVec(vecl);
}

void GUIadmin::gui_refresh()
{
	auto v = this->serv.get_all();
	this->incarca_lista(v);
}

void GUIadmin::gui_raport()
{
	auto v = this->serv.raport_tip();

	//creeaza
	QWidget* winRaport = new QWidget(this,Qt::Window);
	QVBoxLayout* lyRaport = new QVBoxLayout;
	QTableView* lRaport = new QTableView;
	QPushButton* fbtnClose = new QPushButton{ "Inchide" };

	//asambleaza
	winRaport->setLayout(lyRaport);
	lyRaport->addWidget(new QLabel{"Raport:"});
	lyRaport->addWidget(lRaport);
	lyRaport->addWidget(fbtnClose);

	//seteaza
	QObject::connect(fbtnClose, &QPushButton::clicked,winRaport,&QWidget::close);
	MyTableModel* modlRaport = new MyTableModel(winRaport);
	lRaport->setModel(modlRaport);
	modlRaport->setVec(v);

	//sfarist
	winRaport->show();
}

void GUIadmin::gui_sort()
{
	int optiune = 0;
	int sens = 1;
	if (this->btnSortNP->isChecked())
		optiune = 0;
	else if (this->btnSortSp->isChecked())
		optiune = 1;
	else
		optiune = 2;
	if (this->cboxSortReverse->isChecked())
		sens = -1;
	auto v = this->serv.sorteaza(optiune,sens);
	this->incarca_lista(v);
}

void GUIadmin::gui_filtru()
{
	int sens = 1;
	string buffer;
	if (this->cboxFiltruReverse->isChecked())
		sens = -1;
	if (this->btnFiltruSp->isChecked()) {
		buffer = this->infSp->text().toStdString();
		double sp=0; 
		string2double(buffer, sp);
		vector<Locatar> v=this->serv.filtreaza(sp, sens);
		this->incarca_lista(v);
	}
	else {
		buffer = this->infTA->text().toStdString();
		vector<Locatar> v=this->serv.filtreaza(buffer, sens);
		this->incarca_lista(v);
	}
}

void GUIadmin::gui_adauga()
{
	string buffer;
	int ap=0;
	string np;
	double sp=0;
	string ta;
	buffer = this->infAp->text().toStdString();
	string2int(buffer, ap);
	np = this->infNP->text().toStdString();
	buffer = this->infSp->text().toStdString();
	string2double(buffer, sp);
	ta = this->infTA->text().toStdString();

	this->serv.adauga(ap, np, sp, ta);
	auto v = this->serv.get_all();
}

void GUIadmin::gui_modifica()
{
	string buffer;
	int ap = 0;
	string np;
	double sp = 0;
	string ta;
	buffer = this->infAp->text().toStdString();
	string2int(buffer, ap);
	np = this->infNP->text().toStdString();
	buffer = this->infSp->text().toStdString();
	string2double(buffer, sp);
	ta = this->infTA->text().toStdString();

	this->serv.modifica(ap, np, sp, ta);
	auto v = this->serv.get_all();
}

void GUIadmin::gui_sterge()
{
	string buffer;
	int ap = 0;
	buffer = this->infAp->text().toStdString();
	string2int(buffer, ap);

	this->serv.sterge(ap);
	auto v = this->serv.get_all();
}

void GUIadmin::gui_cauta()
{
	string buffer;
	int ap = 0;
	buffer = this->infAp->text().toStdString();
	string2int(buffer, ap);

	auto l = this->serv.cauta(ap);
	this->infAp->setText(QString::number(l.get_apartament()));
	this->infNP->setText(QString::fromStdString(l.get_nume_proprietar()));
	this->infSp->setText(QString::number(l.get_suprafata(),'f',6));
	this->infTA->setText(QString::fromStdString(l.get_tip_apartament()));

}

void GUIadmin::gui_undo()
{
	this->serv.undo();
	auto v = this->serv.get_all();
}

void GUIadmin::update()
{
	this->gui_refresh();
}

GUIadmin::GUIadmin(ServiciuLocatari& serv0) :serv{ serv0 }
{
	this->asambleaza();
	this->initializeaza();
	this->conecteaza();
	this->serv.addObserver(this);
}
