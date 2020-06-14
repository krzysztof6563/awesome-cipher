#include "NumberCipher.h"

void NumberCipher::cipher(std::string text) {
    std::string processedData = "";
    for (int i = 0; i < text.length(); i++) {
        processedData += std::to_string(text[i]+offset);
        if (i < text.length() - 1) {
            processedData += ',';
        }
    }
    for (int c : text) {
    }
    this->text = processedData;
}

void NumberCipher::decipher(std::string text) {
    std::string processedData = "";

    while (true) {
        std::size_t found = text.find(',');
        if (found != std::string::npos) {
            std::string number = text.substr(0, found);
            loadedNumbers.push_back(std::stoi(number));
            text = text.substr(found+1, text.length()-2);
        } else {
            loadedNumbers.push_back(std::stoi(text));
            break;
        }
    }

    for (auto number : loadedNumbers) {
        processedData += (char)(number-offset);
    }
    this->text = processedData;
}

bool NumberCipher::validateInput(std::string data, int mode) {
    bool match = false;
    if (mode == 1) {
        //szyfrowanie
        std::regex validationRegex("[A-Za-z ]+");
        match = std::regex_match(data, validationRegex);
    } else if (mode == 2) {
        //odszyfrowanie
        std::regex validationRegex("[0-9,]+");
        match = std::regex_match(data, validationRegex);
    }
    if (match) {
        return true;
    } else {
        std::cout << "Nieprawidlowy format danych." << std::endl;
        if (mode == 1) {
            std::cout << "Wpisz jedynie litery alfabetu (bez polskich znakow) i spacje" << std::endl;
        } else if (mode == 2) {
            std::cout << "Wpisz jedynie cyfry i przecinki. Przyklad prawidlowych danych: \"192,321,431,134,100\"" << std::endl;
        }

        return false;
    }
}
