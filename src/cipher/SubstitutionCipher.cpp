#include "SubstitutionCipher.h"

SubstitutionCipher::SubstitutionCipher() {
    std::string choice;
    std::cin.ignore();
    std::cout << "Czy chesz zaladowac wlasna tablice szyfrujaca? [t/n]" << std::endl;
    do {
        std::cin >> choice;
        if (!(choice == "t" || choice == "n")) {
            std::cout << "[t/n]?" << std::endl;
        }
    } while (!(choice == "t" || choice == "n"));
    if (choice == "t") {
        std::string inputName;
        std::cout << "Podaj nazwe pliku: ";
        std::cin >> inputName;
        std::ifstream tabInput;
        std::string tempStr;

        tabInput.open(inputName, std::ios::in);
        if (tabInput.good()) {
            std::cin.ignore();
            std::getline(tabInput, tempStr);
            if (tempStr.length() == 27) {
                for (auto & c: tempStr) c = tolower(c);
                this->cipher_alphabet = tempStr;
                for (auto & c: tempStr) c = toupper(c);
                this->cipher_alphabet_upper = tempStr;
                std::cout << "Wczytano tablice szyfrujaca!!" << std::endl;
            } else {
                std::cin.ignore();
                std::cout << "Niepoprawna tablica szyfrujaca, tablica musi posidac 27 znakow. Uzywanie domyslnej tablicy." << std::endl;
            }
        } else {
            std::cin.ignore();
            std::cout << "Nie udalo sie wczytac pliku, uzywanie domyslnej tablicy" << std::endl;
        }
    } else {
        std::cin.ignore();
    }
}

void SubstitutionCipher::cipher(std::string text) {
    for (char c : text) {
        bool isUpper = std::isupper(c);
        if (isUpper) {
            for (int i = 0; i < alphabet_upper.length() - 1; i++) {
                if (c == alphabet_upper[i]){
                    std::cout << cipher_alphabet_upper[i];
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < alphabet.length() - 1; i++) {
                if (c == alphabet[i]) {
                    std::cout << cipher_alphabet[i];
                    break;
                }
            }
        }
        if (c == ' ') {
            std::cout << " ";
        }
    }
}

void SubstitutionCipher::decipher(std::string text) {
    for (char c : text) {
        bool isUpper = std::isupper(c);
        if (isUpper) {
            for (int i = 0; i < cipher_alphabet_upper.length() - 1; i++) {
                if (c == cipher_alphabet_upper[i]) {
                    std::cout << alphabet_upper[i];
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < cipher_alphabet.length() - 1; i++) {
                if (c == cipher_alphabet[i]) {
                    std::cout << alphabet[i];
                    break;
                }
            }
        }
        if (c == ' ') {
            std::cout << " ";
        }
    }
}

bool SubstitutionCipher::validateInput(std::string data, int mode) {
    std::regex validationRegex("[A-Za-z ]+");
    bool match = std::regex_match(data, validationRegex);
    if (match) {
        return true;
    } else {
        std::cout << "Nieprawidlowy format danych." << std::endl;
        std::cout << "Wpisz jedynie litery alfabetu (bez polskich znakow) i spacje." << std::endl;
        return false;
    }
}
