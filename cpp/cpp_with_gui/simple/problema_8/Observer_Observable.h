#pragma once

#include <vector>
using std::vector;

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer()=default;
};

class Observable{
private:
	vector<Observer*> observers;
public:
	void addObserver(Observer* obs0);
	void removeObserver(Observer* obs0);
	void notify();
	virtual ~Observable() = default;
};
