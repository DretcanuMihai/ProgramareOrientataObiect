#pragma once
#include "MyWidget.h"
#include "ServiciuLocatari.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include "Observer_Observable.h"

class GUIgl :public MyWidget,public Observer
{
private:
	//chestii
	ServiciuLocatari& serv;
	ListaNotificare& ln;
	
	//main layout
	QHBoxLayout* lyMain = new QHBoxLayout;
	
	//	Suprafete
	QVBoxLayout* lyS2 = new QVBoxLayout;
	QVBoxLayout* lyS3 = new QVBoxLayout;

	//		S2
	QListWidget* lstNot = new QListWidget;
	QPushButton* btnRefreshNot = new QPushButton{ "Refresh" };
	QPushButton* btnGoleste = new QPushButton{ "Goleste" };
	QHBoxLayout* lyGenExp=new QHBoxLayout;

	//			Generate and Export
	QGroupBox* grpGenerate = new QGroupBox;
	QVBoxLayout* lyGenerate = new QVBoxLayout;
	QGroupBox* grpExport = new QGroupBox;
	QVBoxLayout* lyExport = new QVBoxLayout;



	//				Generate

	QPushButton* btnGenerate = new QPushButton{ "Genereaza" };
	QFormLayout* lyNr = new QFormLayout;
	QLineEdit* infNr = new QLineEdit;


	//				Export
	QPushButton* btnExport = new QPushButton{ "Export" };
	QFormLayout* lyNume = new QFormLayout;
	QLineEdit* infNume = new QLineEdit;
	QRadioButton* btnHTML = new QRadioButton{"HTML"};
	QRadioButton* btnCSV = new QRadioButton{"CSV"};

	
	//		S3
	QFormLayout* lyInfo = new QFormLayout;
	QPushButton* btnAdauga = new QPushButton{"Adauga"};
	QPushButton* btnDesen = new QPushButton{ "Desen" };
	QPushButton* btnBack = new QPushButton{ "Inchide" };

	//			Info
	QLineEdit* infAp = new QLineEdit;
	QLineEdit* infNP = new QLineEdit;
	QLineEdit* infSp = new QLineEdit;
	QLineEdit* infTA = new QLineEdit;




	//pentru constructor
	void asambleaza();
	void initializeaza();
	void conecteaza();

	//chestii
	void gui_cauta();
	void incarca_lista_not(const vector<Locatar>& vecl);
	void gui_refresh_list_not();
	void gui_ln_goleste();
	void gui_ln_genereaza();
	void gui_ln_export();


	void gui_ln_adauga();


	void update() override;


public:
	GUIgl(ServiciuLocatari& serv0, ListaNotificare& ln0);
};

