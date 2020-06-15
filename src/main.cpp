#include <iostream>
#include <vector>
#include <string>
#include "cipher/Cipher.h"
#include "cipher/CaesarCipher.h"
#include "cipher/NumberCipher.h"
#include "cipher/SubstitutionCipher.h"
#include "Validator.h"

void showIntro() {
	std::cout << "----------------------------------------------" << std::endl
		<< "|        Krzysztof Kowalski [182632]         |" << std::endl
		<< "|        Krzysztof Michalski [171719]        |" << std::endl
		<< "|  Program szyfrujacy i deszyfrujacy tekst.  |" << std::endl
		<< "----------------------------------------------" << std::endl
		<< std::endl
		<< "Program ma za zadanie zaszyfrowywac i odszyfrowywac wprowadzony tekst." << std::endl
		<< "Uzytkownik wybiera metode dzialania i algorym szyfrujacy tekst." << std::endl
		<< "Nastepnie podaje tekst/szyfr do zaszyfrowania/odszyfrowania." << std::endl
		<< "Wiecej informacji znajduje sie w pliku Readme.txt w folderze" << std::endl
		<< std::endl
		<< "Wybierz metode dzialania programu:" << std::endl
		<< "[1] Zaszyfrowanie tesktu" << std::endl
		<< "[2] Odszyforwanie tekstu" << std::endl
		<< std::endl;
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
	std::string tmpChoice;
	std::string data;

	showIntro();
	do {
		std::cin >> tmpChoice;
		try {
			mode = std::stoi(tmpChoice);
		} catch (...) {
			std::cout << "Proszę podać tylko cyfry." << std::endl;
			mode = -1;
		}
	} while (!Validator::validateIntRangeInput(mode, 1, 2));
	
	showCipherSelect();
	do {
		std::cin >> tmpChoice;
		try {
			algorithm = std::stoi(tmpChoice);
		} catch (...) {
			std::cout << "Proszę podać tylko cyfry." << std::endl;
			algorithm = -1;
		}
	} while (!Validator::validateIntRangeInput(algorithm, 1, 3));
	Cipher* selectedCipher = selectCipher(algorithm);

	if (selectedCipher == nullptr) {
		throw "Nie znaleziono alogrytmu szyfrowania.";
	}

	showDataInput();
	do {
		std::getline(std::cin, data);
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
 