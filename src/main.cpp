#include <iostream>
#include <vector>
#include <string>
#include "cipher/Cipher.h"
#include "cipher/CaesarCipher.h"
#include "cipher/NumberCipher.h"
#include "cipher/SubstitutionCipher.h"
#include "Validator.h"

void showIntro() {
	std::cout << "Krzysztof Kowalski [182632] " << std::endl
			  << "Krzysztof Michalski [171719] " << std::endl
	          << "Program szyfrujący i deszyfrujący tekst." << std::endl
	          << "Wybierz metodę działania programu:" << std::endl
	          << "[1] Zaszyfrowanie tesktu" << std::endl
	          << "[2] Odszyforwanie tekstu" << std::endl
	;
	return;
}

void showCipherSelect() {
	std::cout << "Wybierz alogrytm szyfrujący: " << std::endl
	          << "[1] Szyfr cezara" << std::endl
	          << "[2] Szyfr numeryczny" << std::endl
	          << "[3] Szyfr podstawieniowy" << std::endl
	;
	return;
}

void showDataInput() {
	std::cout << "Podaj tekst do przetworzenia:" << std::endl; 
	return;
}

Cipher* selectCipher(int choice) {
	switch (choice) {
		case 1: 
			return new CaesarCipher();
		case 2: 
			return new NumberCipher();
		case 3: 
			return new SubstitutionCipher();
	}
	return nullptr;
}

auto main(int argc, char* argv[]) -> int {
	int mode = 0;
	int algorithm = 0;
	std::string data;

	showIntro();
	do {
		std::cin >> mode;
	} while (!Validator::validateIntRangeInput(mode, 1, 2));
	
	showCipherSelect();
	do {
		std::cin >> algorithm;
	} while (!Validator::validateIntRangeInput(algorithm, 1, 3));
	Cipher* selectedCipher = selectCipher(algorithm);

	if (selectedCipher == nullptr) {
		throw "Nie znaleziono alogrytmu szyfrowania.";
	}

	showDataInput();
	do {
		std::cin >> data;
	} while (!selectedCipher->validateInput(data, mode));
	
	switch (mode) {
		case 1:
			selectedCipher->cipher(data);
			break;
		case 2:
			selectedCipher->decipher(data);
			break;
	}
	
	std::cout << selectedCipher->text;

	return 0;
}
 