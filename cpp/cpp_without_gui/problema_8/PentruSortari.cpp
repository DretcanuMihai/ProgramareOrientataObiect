#include "PentruSortari.h"


int compara_locatari_nume_proprietar(const Locatar& l0, const Locatar& l1) {
	const auto val = l0.get_nume_proprietar().compare(l1.get_nume_proprietar());
	const auto c = l0.get_apartament() - l1.get_apartament();
	if (val < 0) {
		return -1;
	}
	if (val == 0) {
		if (c < 0)
			return -1;
		if (c == 0)
			return 0;
	}
	return 1;
}



int compara_locatari_suprafata(const Locatar& l0, const Locatar& l1) noexcept {
	const auto val = l0.get_suprafata() - l1.get_suprafata();
	const auto c = l0.get_apartament() - l1.get_apartament();
	if (val < 0) {
		return -1;
	}
	if (val == 0) {
		if (c < 0)
			return -1;
		if (c == 0)
			return 0;
	}
	return 1;
}

int compara_locatari_tip_apartament_si_suprafata(const Locatar& l0, const Locatar& l1) {
	const auto val1 = l0.get_tip_apartament().compare(l1.get_tip_apartament());
	const auto val = l0.get_suprafata() - l1.get_suprafata();
	const auto c = l0.get_apartament() - l1.get_apartament();
	if (val1 < 0) {
		return -1;
	}
	if (val1 == 0) {
		if (val < 0)
			return -1;
		if (val == 0) {
			if (c < 0)
				return -1;
			if (c == 0)
				return 0;
		}
	}
	return 1;
}