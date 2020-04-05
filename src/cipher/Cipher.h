#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
	public:
		Cipher();
		Cipher(std::string text);

		void setText(std::string text);
		std::string getText();
		virtual void cipher() = 0;
		virtual void decipher() = 0;

	private:
		std::string text = "";
};

#endif /* CIPHER_H */

