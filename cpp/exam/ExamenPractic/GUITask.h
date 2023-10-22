#pragma once
#include "ServiciuTask.h"
#include <QWidget>
#include <QTableView>
#include "TaskTableModel.h"
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>

class GUITask:public QWidget
{
private:
	//widgets si chestii
	QTableView* tab_task = new QTableView;
	TaskTableModel* mod_task = new TaskTableModel;
	QLineEdit* inf_id = new QLineEdit;
	QLineEdit* inf_descriere = new QLineEdit;
	vector<QLineEdit*> inf_prog;
	QLineEdit* inf_stare = new QLineEdit;
	QPushButton* btn_adauga = new QPushButton{ "Adauga" };

	QLineEdit* inf_de_sters = new QLineEdit;
	QPushButton* btn_sterge = new QPushButton{ "Sterge" };
	QVBoxLayout* ly_box = new QVBoxLayout;
	vector<QCheckBox*> my_box;


	//functii speciale

	/*functie de adauga GUI
	Pre:->true
	Post:->true*/
	void adauga();

	/*functie de sterge GUI
	Pre:->true
	Post:->true*/
	void sterge();

	/*functie de update GUI
	Pre:->true
	Post:->true*/
	void updateBox();


	//basic
	ServiciuTask& serv;
	/*asambleaza componentele grafice
	Pre:->true
	Post:->true*/
	void asambleaza();
	/*initializeaza componentele grafice
	Pre:->true
	Post:->true*/
	void initializeaza();
	/*conecteaza componentele grafice
	Pre:->true
	Post:->true*/
	void conecteaza();
public:

	//constructor cu ServiciuTask
	GUITask(ServiciuTask& serv0);

};

