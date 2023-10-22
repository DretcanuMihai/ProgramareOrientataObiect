#include "GUImain.h"
#include <QBrush>

void GUImain::asambleaza()
{
	this->setLayout(this->lyMain);
	QLabel* aux = new QLabel{ "Meniu:" };
	aux->setAlignment(Qt::AlignCenter);
	this->lyMain->addWidget(aux);
	this->lyMain->addWidget(this->btnAdmin);
	this->btnAdmin->setStyleSheet("background-color: blue");
	this->lyMain->addWidget(this->btnGL);
	this->btnGL->setStyleSheet("background-color: green");
	this->lyMain->addWidget(this->btnClose);
	this->btnClose->setStyleSheet("background-color: red");
	auto pal = this->palette();
	pal.setColor(QPalette::Window, Qt::gray);
	this->setPalette(pal);

}

void GUImain::initializeaza()
{
	QObject::connect(this->btnAdmin, &QPushButton::clicked, this, [this](){
		GUIadmin* winAdmin = new GUIadmin(serv);
		winAdmin->show();
		//this->schimba_fereastra(this->winAdmin);
		});
	QObject::connect(this->btnGL, &QPushButton::clicked, this, [this]() {
		GUIgl* winLN = new GUIgl(serv,ln);
		winLN->show();
		//this->schimba_fereastra(this->winGL);
		});
	QObject::connect(this->btnClose, &QPushButton::clicked, &this->app, &QCoreApplication::quit);
}

GUImain::GUImain(ServiciuLocatari& serv0, ListaNotificare& ln0, QApplication& app0) :serv{ serv0 }, ln{ ln0 },app{ app0 }
{
	this->initializeaza();
	this->asambleaza();
}
