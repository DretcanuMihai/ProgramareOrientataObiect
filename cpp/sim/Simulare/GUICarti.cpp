#include "GUICarti.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QString>

void GUICarti::incarca_tabel(const vector<Carte>& v)
{
	tabCarti->clear();
	tabCarti->setRowCount(v.size());
	tabCarti->setColumnCount(2);
	int contor = 0;
	for (const auto& elem : v) {
		QTableWidgetItem* item1 = new QTableWidgetItem{ QString::fromStdString(elem.get_titlu())};
		item1->setData(Qt::UserRole, QString::fromStdString(elem.get_culoare()));
		tabCarti->setItem(contor, 0, item1);
		QTableWidgetItem* item2 = new QTableWidgetItem{ QString::fromStdString(elem.get_autor()) };
		tabCarti->setItem(contor, 1, item2);
		item2->setData(Qt::UserRole, QString::number(elem.get_grosime()));
		contor++;
	}
}

void GUICarti::estetic()
{
	//main Layout
	QVBoxLayout* lyMain=new QVBoxLayout;
	this->setLayout(lyMain);

	lyMain->addWidget(tabCarti);
	QFormLayout* lyInf = new QFormLayout;
	lyMain->addLayout(lyInf);
	lyMain->addWidget(btnSortNO);
	lyMain->addWidget(btnSortGr);
	lyMain->addWidget(btnSortTl);

	//info layout
	lyInf->addRow("Culoare", infCol);
	lyInf->addRow("Grosime", infGros);

}

void GUICarti::stare_initiala()
{
	incarca_tabel(serv.get_all());
	infCol->setReadOnly(true);
	infGros->setReadOnly(true);
}

void GUICarti::conecteaza()
{
	QObject::connect(tabCarti, &QTableWidget::itemSelectionChanged, this, [this]() {
		if (tabCarti->selectedItems().isEmpty()) {
			return;
		}
		int rw = tabCarti->selectedItems().at(0)->row();
		auto item = tabCarti->item(rw, 0);
		auto info = item->data(Qt::UserRole).toString();
		infCol->setText(info);
		auto item1 = tabCarti->item(rw, 1);
		auto info1 = item1->data(Qt::UserRole).toString();
		infGros->setText(info1);
		QPalette pal = infCol->palette();
		if (info == "rosie") {
			pal.setColor(QPalette::Base, Qt::red);
			infCol->setPalette(pal);
		}
		else if (info == "albastra") {
			pal.setColor(QPalette::Base, Qt::blue);
			infCol->setPalette(pal);
		}
		else if (info == "verde") {
			pal.setColor(QPalette::Base, Qt::green);
			infCol->setPalette(pal);
		}
		else if (info == "galbena") {
			pal.setColor(QPalette::Base, Qt::yellow);
			infCol->setPalette(pal);
		}
		});
	QObject::connect(btnSortNO, &QPushButton::clicked, this, [this]() {
		this->incarca_tabel(this->serv.get_all());
		});
	QObject::connect(btnSortGr, &QPushButton::clicked, this, [this]() {
		this->incarca_tabel(this->serv.sort_grosime());
		});
	QObject::connect(btnSortTl, &QPushButton::clicked, this, [this]() {
		this->incarca_tabel(this->serv.sort_titlu());
		});
}

GUICarti::GUICarti(ServiciuCarti& serv0):serv{serv0}
{
	estetic();
	stare_initiala();
	conecteaza();
}
