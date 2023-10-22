#include "PentruFiltrari.h"

int filtru_tip_apartament(const Locatar& l, const string& val) {
	if (l.get_tip_apartament().find(val) == string::npos) {
		return -1;
	}
	return 1;
}

int filtru_suprafata(const Locatar& l, const double& val)noexcept {
	if (l.get_suprafata() < val)
		return -1;
	if (l.get_suprafata() > val)
		return 1;
	return 0;
}