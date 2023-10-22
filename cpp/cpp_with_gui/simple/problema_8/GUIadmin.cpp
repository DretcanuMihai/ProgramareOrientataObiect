#include "GUIadmin.h"
#include "ExceptiiLocatar.h"
#include <QMessageBox>
#include "Conversii.h"
#include <QTableWidget>

void GUIadmin::asambleaza()
{
	this->setLayout(this->lyMain);

	//Main
	this->lyMain->addLayout(this->lyS1);
	this->lyMain->addStretch();
	this->lyMain->addLayout(this->lyS2);

	//S1	
	this->lyS1->addWidget(new QLabel{ "Lista apartamente:" });
	this->lyS1->addWidget(this->lstAps);
	this->lyS1->addWidget(this->btnRefresh);
	this->lyS1->addWidget(this->btnRaport);
	this->lyS1->addLayout(this->lySortFiltru);

	
	//SortFiltru	
	this->lySortFiltru->addWidget(this->grpSort);
	this->lySortFiltru->addWidget(this->grpFiltru);

	//Sort
	this->grpSort->setLayout(this->lySort);
	this->lySort->addWidget(this->btnSort);
	this->lySort->addWidget(new QLabel{ "Criteriu de sortare:" });
	this->lySort->addWidget(this->btnSortNP);
	this->lySort->addWidget(this->btnSortSp);
	this->lySort->addWidget(this->btnSortTASp);
	this->lySort->addWidget(this->cboxSortReverse);
	this->lySort->addStretch();

	//filtru
	this->grpFiltru->setLayout(this->lyFiltru);
	this->lyFiltru->addWidget(this->btnFiltru);
	this->lyFiltru->addWidget(new QLabel{ "Criteriu de filtrare:" });
	this->lyFiltru->addWidget(this->btnFiltruSp);
	this->lyFiltru->addWidget(this->btnFiltruTA);
	this->lyFiltru->addWidget(this->cboxFiltruReverse);
	this->lyFiltru->addStretch();





	//S2
	this->lyS2->addLayout(this->lyInfo);
	this->lyS2->addLayout(this->lyCRUD);
	this->lyS2->addLayout(this->lyCRUD2);
	this->lyS2->addStretch();
	this->lyS2->addWidget(this->btnBack);

	
	//Info	
	this->lyInfo->addRow("Apartament", this->infAp);
	this->lyInfo->addRow("Nume Proprietar", this->infNP);
	this->lyInfo->addRow("Suprafata", this->infSp);
	this->lyInfo->addRow("Tip Apartament", this->infTA);

	//CRUD1
	this->lyCRUD->addWidget(this->btnAdauga);
	this->lyCRUD->addWidget(this->btnModifica);
	
	//CRUD2
	this->lyCRUD2->addWidget(this->btnSterge);
	this->lyCRUD2->addWidget(this->btnCauta);
	this->lyCRUD2->addWidget(this->btnUndo);

}

void GUIadmin::initializeaza()
{
	//incarca lista
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
	QObject::connect(this->lstAps, &QListWidget::itemSelectionChanged, [this]() {
		if (this->lstAps->selectedItems().isEmpty()) {
			/*this->infAp->setText("");
			this->infNP->setText("");
			this->infSp->setText("");
			this->infTA->setText("");*/
			return;
		}
		auto item = this->lstAps->selectedItems().at(0);

		this->infAp->setText(item->text());
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
	this->lstAps->clear();
	for (const auto& elem : vecl) {
		QListWidgetItem* item0 = new QListWidgetItem(QString::number(elem.get_apartament()));
		this->lstAps->addItem(item0);


	}
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
	QTableWidget* lRaport = new QTableWidget(v.size(), 2);
	QPushButton* fbtnClose = new QPushButton{ "Inchide" };

	//asambleaza
	winRaport->setLayout(lyRaport);
	lyRaport->addWidget(new QLabel{"Raport:"});
	lyRaport->addWidget(lRaport);
	lyRaport->addWidget(fbtnClose);

	//seteaza
	QObject::connect(fbtnClose, &QPushButton::clicked,winRaport,&QWidget::close);
	int contor = 0;
	for (const auto& elem : v) {
		QTableWidgetItem* e1 = new QTableWidgetItem(QString::fromStdString(elem.first));
		lRaport->setItem(contor, 0, e1);
		QTableWidgetItem* e2 = new QTableWidgetItem(QString::number(elem.second));
		lRaport->setItem(contor, 1, e2);
		contor++;
	}

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
