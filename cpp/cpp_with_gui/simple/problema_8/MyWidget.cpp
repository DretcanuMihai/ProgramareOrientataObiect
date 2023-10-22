#include "MyWidget.h"
#include "ExceptiiLocatar.h"
#include <QMessageBox>

void MyWidget::schimba_fereastra(QWidget* win)
{
	this->hide();
	win->show();
}

void MyWidget::incearca(std::function<void()>metoda)
{
	try {
		metoda();
		//QMessageBox::information(this, "Mesaj", "Operatie realizata cu succes!");
	}
	catch (const ExceptieInputData& er) {
		QMessageBox::warning(this, "Eroare de Input", QString::fromStdString(er.get_mesaj()));
	}
	catch (const ExceptieValidareLocatar& er) {
		QMessageBox::warning(this, "Eroare de Validare", QString::fromStdString(er.get_mesaj()));
	}
	catch (const ExceptieRepozitoriuLocatar& er) {
		QMessageBox::warning(this, "Eroare de Repozitoriu", QString::fromStdString(er.get_mesaj()));
	}
	catch (const ExceptieUndo& er) {
		QMessageBox::warning(this, "Eroare de Undo", QString::fromStdString(er.get_mesaj()));
	}
	catch (const ExceptieListaNotificare& er) {
		QMessageBox::warning(this, "Eroare de Lista de Notificare", QString::fromStdString(er.get_mesaj()));
	}
}
