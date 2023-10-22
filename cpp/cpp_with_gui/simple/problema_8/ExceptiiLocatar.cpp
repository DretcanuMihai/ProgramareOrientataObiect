#include "ExceptiiLocatar.h"


ExceptieGenerala::ExceptieGenerala(const string& mesaj0) :mesaj{ mesaj0 } {

}


const string& ExceptieGenerala::get_mesaj() const noexcept{
	return this->mesaj;
}