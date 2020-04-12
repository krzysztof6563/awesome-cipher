#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <regex>
#include <iostream>

class Cipher {
	public:
		Cipher();

		virtual void cipher(std::string text) = 0;
		virtual void decipher(std::string text) = 0;
		virtual bool validateInput(std::string data, int mode) = 0;
		std::string text = "";
};

#endif /* CIPHER_H */

