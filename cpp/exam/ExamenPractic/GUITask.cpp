#include "GUITask.h"
#include <QFormLayout>
#include <QMessageBox>
#include "Exceptii.h"
#include <set>
using std::set;

void GUITask::adauga()
{
	bool ok = true;
	int id = inf_id->text().toInt(&ok);
	string descriere = inf_descriere->text().toStdString();
	list<string> prog;
	for (int i = 0; i < 4; i++) {
		string s = inf_prog.at(i)->text().toStdString();
		if (s != "") {
			prog.push_back(s);
		}
	}
	string stare = inf_stare->text().toStdString();
	if (ok == false) {
		QMessageBox::warning(this, "Eroare input", "Eroare:id-ul trebuie sa fie intreg;\n");
		return;
	}
	try {
		serv.adauga(id, descriere, prog, stare);
	}
	catch (const ExceptieValidare& e) {
		QMessageBox::warning(this, "Eroare validare", QString::fromStdString(e.getMesaj()));
	}
	catch (const ExceptieRepo& e) {
		QMessageBox::warning(this, "Eroare repo", QString::fromStdString(e.getMesaj()));
	}
	mod_task->setVector(serv.getAll(), my_box);
}

void GUITask::updateBox()
{
	for (const auto& b : my_box) {
		ly_box->removeWidget(b);
		delete b;
	}
	my_box.clear();//golim vectorul
	auto v = serv.getAll();
	set<string> s;
	for (const auto& elem : v) {
		for (const auto& p : elem.getProgramatori()) {
			s.insert(p);
		}
	}
	int contor=0;
	for (const auto& elem : s) {
		my_box.push_back(new QCheckBox(QString::fromStdString(elem)));
		ly_box->addWidget(my_box.at(contor));
		QObject::connect(my_box.at(contor), &QCheckBox::stateChanged, this, [this]() {
			
			this->mod_task->setVector(serv.getAll(), my_box);

			});
		contor++;
	}
	mod_task->setVector(serv.getAll(), my_box);
}

void GUITask::asambleaza()
{
	//layout main
	QVBoxLayout* ly_main = new QVBoxLayout;
	setLayout(ly_main);
	ly_main->addWidget(tab_task);
	QFormLayout* ly_inf = new QFormLayout;
	ly_main->addLayout(ly_inf);
	ly_main->addWidget(btn_adauga);
	QFormLayout* ly_inf_del = new QFormLayout;
	ly_main->addLayout(ly_inf_del);
	ly_main->addWidget(btn_sterge);
	ly_main->addLayout(ly_box);

	//layout info
	ly_inf->addRow("Id:", inf_id);
	ly_inf->addRow("Descriere:", inf_descriere);
	ly_inf->addRow("Programatori:", inf_prog.at(0));
	for (int i = 1; i < 4; i++)
		ly_inf->addRow("", inf_prog.at(i));
	ly_inf->addRow("Stare:", inf_stare);


	//layout info delete
	ly_inf_del->addRow("Nume:", inf_de_sters);

}

void GUITask::initializeaza()
{
	tab_task->setModel(mod_task);
	updateBox();
}

void GUITask::conecteaza()
{
	QObject::connect(btn_adauga, &QPushButton::clicked, this, [this]() {
		this->adauga();
		});
	QObject::connect(btn_sterge, &QPushButton::clicked, this, [this]() {
		this->sterge();
		});
}

GUITask::GUITask(ServiciuTask& serv0):serv{serv0}
{
	for (int i = 0; i < 4; i++) {
		inf_prog.push_back(new QLineEdit);
	}
	asambleaza();
	initializeaza();
	conecteaza();
}

void GUITask::sterge()
{
	string de_sters = inf_de_sters->text().toStdString();
	serv.stergePg(de_sters);
	updateBox();
}
