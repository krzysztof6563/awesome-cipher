#include "CaesarCipher.h"

void CaesarCipher::cipher(std::string text) {
    std::string processedData = "";
    for (char c : text) {
        int newChar = c+this->offset;
        if (c >= 65 && c <= 90) {
            if (newChar > 90) {
                newChar = 65 + (newChar - 90 - 1);
            }
        } else if (c >= 97 && c <= 122) {
            if (newChar > 122) {
                newChar = 97 + (newChar - 122 - 1);
            }
        }
        processedData += (char)newChar;
    }
    this->text = processedData;
}

void CaesarCipher::decipher(std::string text) {
    std::string processedData = "";
    for (char c : text) {
        int newChar = c-this->offset;
        if (c >= 65 && c <= 90) {
            if (newChar < 65) {
                newChar = 90 - (65 - newChar - 1);
            }
        } else if (c >= 97 && c <= 122) {
            if (newChar < 97) {
                newChar = 122 - (97 - newChar - 1);
            }
        }
        processedData += (char)newChar;
    }
    this->text = processedData;
}

bool CaesarCipher::validateInput(std::string data, int mode) {
    std::regex validationRegex("[A-Za-z]+");
    if (std::regex_match(data, validationRegex)) {
        return true;
    } else {
        return false;
    }
}
