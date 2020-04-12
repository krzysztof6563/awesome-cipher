#ifndef CEASERCIPHER_H
#define CEASERCIPHER_H

#include "Cipher.h"

/*!
* We are using rotation by 13 pieces
*
*/

class CaesarCipher : public Cipher {
	public:
		void cipher(std::string text);
		void decipher(std::string text);
		bool validateInput(std::string data, int mode);

	private:
		int offset = 13;
};

#endif /* CEASERCIPHER_H */
