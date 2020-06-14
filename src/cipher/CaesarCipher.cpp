#include "CaesarCipher.h"

void CaesarCipher::cipher(std::string text) {
    std::string processedData = "";
    for (char c : text) {
        bool isUpper = std::isupper(c);
        if (isUpper) {
            c = std::tolower(c);
        }
        std::size_t found = alphabet.find(c);
        if (found != std::string::npos) {
            char newChar = alphabet[(found+offset)%alphabet.length()];
            if (isUpper) {
                newChar = std::toupper(newChar);
            }
            processedData += isUpper ? std::toupper(newChar) : newChar;
        }
        if (c == ' ') {
            processedData += " ";
        }
    }
    this->text = processedData;
}

void CaesarCipher::decipher(std::string text) {
    std::string processedData = "";
    for (char c : text) {
        bool isUpper = std::isupper(c);
        if (isUpper) {
            c = std::tolower(c);
        }
        std::size_t found = alphabet.find(c);
        if (found != std::string::npos) {
            int newPos = found-offset;
            if (newPos < 0) {
                newPos = alphabet.length() + newPos;
            } 
            char newChar = alphabet[newPos];
            if (isUpper) {
                newChar = std::toupper(newChar);
            }
            processedData += isUpper ? std::toupper(newChar) : newChar;
        }
        if (c == ' ') {
            processedData += " ";
        }
    }
    this->text = processedData;
}

bool CaesarCipher::validateInput(std::string data, int mode) {
    std::regex validationRegex("[A-Za-z ]+");
    bool match = std::regex_match(data, validationRegex);
    if (match) {
        return true;
    } else {
        std::cout << "Nieprawidłowy format danych." << std::endl;
        std::cout << "Wpisz jedynie litery alfabetu (bez polskich znakow) i spacje." << std::endl;
        return false;
    }
}
