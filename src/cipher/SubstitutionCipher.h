#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include "Cipher.h"

class SubstitutionCipher : public Cipher {
	public:
		void cipher(std::string text);
		void decipher(std::string text);
		bool validateInput(std::string data, int mode);
};

#endif /* SUBSTITUTIONCIPHER_H */
