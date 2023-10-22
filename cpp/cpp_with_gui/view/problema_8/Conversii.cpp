#include "Conversii.h"
#include "ExceptiiLocatar.h"
#include <regex>
using std::regex;
using std::regex_match;

void string2int(const string& str, int& val) {
	regex expression("([+-]?)([0-9]{1,9})");
	if (!regex_match(str, expression))
		throw ExceptieInputData("Eroare: Acest camp primeste intregi de pana la 9 cifre;\n");
	val = std::stoi(str);
}

void string2double(const string& str, double& val) {
	regex expression("[+-]?([0-9]{1,6})([.][0-9]{1,6})?");
	if (str.length() >= 15 || !regex_match(str, expression))
		throw ExceptieInputData("Eroare: Acest camp primeste valori reale cu maxim 6 cifre inainte si dupa virgula;\n");
	val = std::stod(str);
}