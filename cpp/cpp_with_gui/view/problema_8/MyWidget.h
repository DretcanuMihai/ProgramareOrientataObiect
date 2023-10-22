#pragma once
//modul ce defineste clasa MyWidget
#include <QWidget>
#include <functional>
#define MAXLENGTH 20



class MyWidget:public QWidget
{
protected:
	//e aici doar pentru ca sunt lenes
	void schimba_fereastra(QWidget* win);

	//super folositoare
	void incearca(std::function<void()> metoda);
};

