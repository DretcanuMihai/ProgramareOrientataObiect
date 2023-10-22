#pragma once
#include <QWidget>
#include "Observer_Observable.h"
#include "ServiciuLocatari.h"

class GUIlnReadOnly:public QWidget,public Observer
{
private:
	ListaNotificare& ln;
	ServiciuLocatari& serv;
	int hm;


	void update() override;
	void paintEvent(QPaintEvent* ev) override;
public:
	GUIlnReadOnly(ServiciuLocatari& serv0,ListaNotificare& ln0);
};

