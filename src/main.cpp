#include <cstdio>
#include <iostream>
#include "cipher/Cipher.h"
#include "cipher/CaesarCipher.h"

auto main(int argc, char* argv[]) -> int {
	std::cout << "Liczba argumentów: " << argc << std::endl;
	std::cout << "Argumenty programu: " << std::endl;
	for(int i=1; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

	Cipher* c = new CaesarCipher();
	c->setText("TEST ALGORYTMU");
	c->cipher();
	std::cout << c->getText() << std::endl;
	delete c;
	
	return 0;
}
 