#pragma once
//modul ce contine definitia clasei de GUI
#include "MyWidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "ServiciuLocatari.h"
#include "GUIadmin.h"
#include "GUIgl.h"
#include <QtWidgets/QApplication>

//clasa de GUI
class GUImain :public MyWidget
{
private:
	ServiciuLocatari& serv;
	ListaNotificare& ln;
	QApplication& app;

	QVBoxLayout* lyMain=new QVBoxLayout;
	QPushButton* btnAdmin = new QPushButton{ "Administrare" };
	QPushButton* btnGL = new QPushButton{ "Gestionare Lista" };
	QPushButton* btnClose = new QPushButton{"Inchidere"};


	void asambleaza();
	void initializeaza();


public:
	GUImain(ServiciuLocatari& serv0, ListaNotificare& ln0, QApplication& app0);
};

