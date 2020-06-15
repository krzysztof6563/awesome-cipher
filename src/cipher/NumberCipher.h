#ifndef NUMBERCIPHER_H
#define NUMBERCIPHER_H

#include <vector>
#include "Cipher.h"

class NumberCipher : public Cipher {
	public:
		NumberCipher();
		void cipher(std::string text);
		void decipher(std::string text);
		bool validateInput(std::string data, int mode);

	private:
		int offset = 0xFA;
		std::vector<int> loadedNumbers;
};

#endif /* NUMBERCIPHER_H */
