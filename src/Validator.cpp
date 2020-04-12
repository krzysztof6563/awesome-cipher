#include "Validator.h"

Validator::Validator() {

}

bool Validator::validateIntRangeInput(int data, int start, int end) {
	bool passed = data >= start && data <= end; 
	if (!passed) {
		std::cout << "Nieprawidłowy wybór. Proszę wpisać liczbę całkowitą z zakres od " << start << " do " << end << std::endl;
	}
	return passed; 
}

// bool Validator::validateCipherInput(std::string data, int algorithm) {
// 	return true;
// }