#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <iostream>

class Validator {
	public:
		Validator();

		static bool validateIntRangeInput(int data, int start, int end);
		// static bool validateCipherInput(std::string data, int algorithm);
};

#endif /* VALIDATOR_H */

