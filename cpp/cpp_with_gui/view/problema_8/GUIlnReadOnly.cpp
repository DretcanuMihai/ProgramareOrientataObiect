#include "GUIlnReadOnly.h"
#include <QPainter>
#include <random>

void GUIlnReadOnly::update()
{
	this->hm = this->serv.ln_get_all().size();
	QWidget::repaint();
}

void GUIlnReadOnly::paintEvent(QPaintEvent* ev)
{
	QPainter p{ this };
	if (height() > 50 && width() > 50) {
		const std::uniform_int_distribution<> disty(0, height() - 50);
		const std::uniform_int_distribution<> distx(0, width() - 50);
		//int h = height();
		//int w = width();
		for (int i = 0; i < this->hm; i++) {
			std::mt19937 mt{ std::random_device{}() };
			p.drawImage(distx(mt), disty(mt), QImage{ "poze/TheKing2.png" });
			//p.drawImage((i * 50) % w, (i * 50) % h, QImage{ "poze/TheKing2.png" });
		}
	}
}

GUIlnReadOnly::GUIlnReadOnly(ServiciuLocatari& serv0, ListaNotificare& ln0):serv{serv0},ln{ln0}
{
	this->ln.addObserver(this);
	this->update();
}
