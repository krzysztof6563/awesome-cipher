#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include "Cipher.h"

class SubstitutionCipher : public Cipher {
	public:
		void cipher();
		void decipher();
};

#endif /* SUBSTITUTIONCIPHER_H */
