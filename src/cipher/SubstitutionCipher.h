#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include "Cipher.h"
#include <string>

class SubstitutionCipher : public Cipher {
	public:
		SubstitutionCipher();
		void cipher(std::string text);
		void decipher(std::string text);
		bool validateInput(std::string data, int mode);

	private:
		std::string alphabet = "abcdefghijklmnopqrstuvwxyz ";
		std::string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
		std::string cipher_alphabet = "tifozrsbncgmdpaehvjkqyluxw ";
		std::string cipher_alphabet_upper = "TIFOZRSBNCGMDPAEHVJKQYLUXW ";
};

#endif /* SUBSTITUTIONCIPHER_H */
