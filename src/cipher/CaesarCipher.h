#ifndef CEASERCIPHER_H
#define CEASERCIPHER_H

#include "Cipher.h"

class CaesarCipher : public Cipher {
	public:
		void cipher();
		void decipher();
};

#endif /* CEASERCIPHER_H */
