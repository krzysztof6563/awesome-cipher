#ifndef NUMBERCIPHER_H
#define NUMBERCIPHER_H

#include "Cipher.h"

class NumberCipher : public Cipher {
	public:
		void cipher(std::string text);
		void decipher(std::string text);
		bool validateInput(std::string data, int mode);
};

#endif /* NUMBERCIPHER_H */
