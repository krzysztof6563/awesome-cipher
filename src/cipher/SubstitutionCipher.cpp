#include "SubstitutionCipher.h"

std::string alphabet = "abcdefghijklmnopqrstuvwxyz ";
std::string alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
std::string cipher_alphabet = "tifozrsbncgmdpaehvjkqyluxw ";
std::string cipher_alphabet_upper = "TIFOZRSBNCGMDPAEHVJKQYLUXW ";

void SubstitutionCipher::cipher(std::string text) {
    //std::string processedData = "";
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
    
    }
    
    //this->text = processedData;
}

void SubstitutionCipher::decipher(std::string text) {
    //std::string processedData = "";
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

    }
    //this->text = processedData;
}

bool SubstitutionCipher::validateInput(std::string data, int mode) {

    return true;
}
