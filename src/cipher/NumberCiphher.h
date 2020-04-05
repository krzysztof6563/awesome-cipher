#ifndef NUMBERCIPHER_H
#define NUMBERCIPHER_H

#include "Cipher.h"

class NumberCipher : public Cipher {
	public:
		void cipher();
		void decipher();
};

#endif /* NUMBERCIPHER_H */
