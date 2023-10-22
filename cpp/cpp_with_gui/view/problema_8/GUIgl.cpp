#include "GUIgl.h"
#include <QLabel>
#include "Conversii.h"
#include "GUIlnReadOnly.h"
#include <QMessageBox>

void GUIgl::asambleaza()
{
	//main Layout
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);

	//suprafete
	QVBoxLayout* lyS2 = new QVBoxLayout;
	QVBoxLayout* lyS3 = new QVBoxLayout;
	lyMain->addLayout(lyS2);
	lyMain->addLayout(lyS3);

	//S2
	lyS2->addWidget(new QLabel{ "Lista de apartamente:" });
	lyS2->addWidget(this->lstNot);
	lyS2->addWidget(this->btnRefreshNot);
	lyS2->addWidget(this->btnGoleste);
	QHBoxLayout* lyGenExp = new QHBoxLayout;
	lyS2->addLayout(lyGenExp);

	//Generate and Export
	QGroupBox* grpGenerate = new QGroupBox;
	QGroupBox* grpExport = new QGroupBox;
	lyGenExp->addWidget(grpGenerate);
	//this->grpGenerate->setStyleSheet("background-color: lime");
	lyGenExp->addWidget(grpExport);
	/*auto palExp = this->grpExport->palette();
	palExp.setColor(QPalette::Base, Qt::blue);
	this->grpExport->setPalette(palExp);*/
	//this->grpExport->setStyleSheet("background-color: lightblue");

	//Generate
	QVBoxLayout* lyGenerate = new QVBoxLayout;
	grpGenerate->setLayout(lyGenerate);
	lyGenerate->addWidget(this->btnGenerate);
	QFormLayout* lyNr = new QFormLayout;
	lyGenerate->addLayout(lyNr);
	lyNr->addRow("Numar:",this->infNr);

	//Export
	QVBoxLayout* lyExport = new QVBoxLayout;
	grpExport->setLayout(lyExport);
	lyExport->addWidget(this->btnExport);
	QFormLayout* lyNume = new QFormLayout;
	lyExport->addLayout(lyNume);
	lyNume->addRow("Nume:", this->infNume);
	lyExport->addWidget(this->btnHTML);
	lyExport->addWidget(this->btnCSV);

	//S3
	QFormLayout* lyInfo = new QFormLayout;
	lyS3->addLayout(lyInfo);
	lyS3->addWidget(this->btnAdauga);
	lyS3->addWidget(this->btnDesen);
	//this->btnAdauga->setStyleSheet("background-color: green");
	lyS3->addStretch();
	lyS3->addWidget(this->btnBack);
	//this->btnBack->setStyleSheet("background-color: red");


	//Info Apartament
	lyInfo->addRow("Apartament", this->infAp);
	lyInfo->addRow("Nume proprietar", this->infNP);
	lyInfo->addRow("Suprafata", this->infSp);
	lyInfo->addRow("Tip Apartament", this->infTA);


}

void GUIgl::initializeaza()
{
	//incarca lista cu toti locatarii
	this->lstNot->setModel(modLstNot);
	modLstNot->setVec(serv.ln_get_all());

	//Generate
	this->infNr->setMaxLength(MAXLENGTH);
	
	//Export
	this->infNume->setMaxLength(MAXLENGTH);
	this->btnHTML->setChecked(true);

	//info
	this->infAp->setMaxLength(MAXLENGTH);
	this->infNP->setMaxLength(MAXLENGTH);
	this->infNP->setReadOnly(true);
	this->infSp->setMaxLength(MAXLENGTH);
	this->infSp->setReadOnly(true);
	this->infTA->setMaxLength(MAXLENGTH);
	this->infTA->setReadOnly(true);

}

void GUIgl::conecteaza()
{


	//S2

	QObject::connect(this->lstNot->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		if (lstNot->selectionModel()->selectedIndexes().isEmpty()) {
			/*this->infAp->setText("");
			this->infNP->setText("");
			this->infSp->setText("");
			this->infTA->setText("");*/
			return;
		}
		auto itemInd = lstNot->selectionModel()->selectedIndexes().at(0);

		this->infAp->setText(itemInd.data(Qt::DisplayRole).toString());
		this->incearca(std::bind(&GUIgl::gui_cauta, this));

		});

	QObject::connect(this->btnRefreshNot, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIgl::gui_refresh_list_not, this));
		});

	QObject::connect(this->btnGoleste, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIgl::gui_ln_goleste, this));
		});

	QObject::connect(this->btnGenerate, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIgl::gui_ln_genereaza, this));
		});

	QObject::connect(this->btnExport, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIgl::gui_ln_export, this));
		});

	//S3

	QObject::connect(this->btnAdauga, &QPushButton::clicked, this, [this]() {
		this->incearca(std::bind(&GUIgl::gui_ln_adauga, this));
		});

	QObject::connect(this->btnDesen, &QPushButton::clicked, this, [this]() {
		GUIlnReadOnly* winDow = new GUIlnReadOnly(this->serv, this->ln);
		winDow->show();
		});

	QObject::connect(this->btnBack, &QPushButton::clicked, this, [this]() {
		this->close();
		});
}

void GUIgl::gui_cauta()
{
	string buffer;
	int ap = 0;
	buffer = this->infAp->text().toStdString();
	string2int(buffer, ap);

	auto l = this->serv.cauta(ap);
	this->infAp->setText(QString::number(l.get_apartament()));
	this->infNP->setText(QString::fromStdString(l.get_nume_proprietar()));
	this->infSp->setText(QString::number(l.get_suprafata(), 'f', 6));
	this->infTA->setText(QString::fromStdString(l.get_tip_apartament()));
}

void GUIgl::incarca_lista_not(const vector<Locatar>& vecl)
{
	modLstNot->setVec(vecl);
}

void GUIgl::gui_refresh_list_not()
{
	auto v = this->serv.ln_get_all();
	this->incarca_lista_not(v);
}

void GUIgl::gui_ln_goleste()
{
	this->serv.ln_goleste();
}

void GUIgl::gui_ln_genereaza()
{
	string buffer;
	int nr = 0;
	buffer = this->infNr->text().toStdString();
	string2int(buffer, nr);
	this->serv.ln_genereaza(nr);
}

void GUIgl::gui_ln_export()
{
	string nume;
	nume = this->infNume->text().toStdString();
	if (this->btnHTML->isChecked() == true)
		this->serv.ln_export_list_html(nume);
	else if (this->btnCSV->isChecked() == true)
		this->serv.ln_export_list_csv(nume);
	QMessageBox::information(this, "Succes!", "Exportare realizata cu succes!");
}

void GUIgl::gui_ln_adauga()
{
	string buffer;
	int ap = 0;
	buffer = this->infAp->text().toStdString();
	string2int(buffer, ap);
	this->serv.ln_adauga(ap);
	this->gui_cauta();
}

void GUIgl::update()
{
	this->incarca_lista_not(this->serv.ln_get_all());
}

GUIgl::GUIgl(ServiciuLocatari& serv0, ListaNotificare& ln0):serv{serv0},ln{ln0}
{
	this->ln.addObserver(this);
	this->asambleaza();
	this->initializeaza();
	this->conecteaza();
}
