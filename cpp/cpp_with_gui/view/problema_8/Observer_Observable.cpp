#include "Observer_Observable.h"

void Observable::addObserver(Observer* obs0)
{
	this->observers.push_back(obs0);
}

void Observable::removeObserver(Observer* obs0)
{
	this->observers.erase(std::remove(this->observers.begin(),this->observers.end(),obs0),this->observers.end());
}

void Observable::notify()
{
	for (const auto& elem : this->observers) {
		elem->update();
	}
}
