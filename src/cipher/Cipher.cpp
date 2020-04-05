#include "Cipher.h"

Cipher::Cipher() {
	
}

Cipher::Cipher(std::string text) {
	this->setText(text);
}

void Cipher::setText(std::string text) {
	//add validation
	this->text = text;
}

std::string Cipher::getText() {
	return text;
}