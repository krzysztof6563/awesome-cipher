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
		std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
		
		int offset = 7;
};

#endif /* CEASERCIPHER_H */
