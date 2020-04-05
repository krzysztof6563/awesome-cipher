# awesome-cipher

Zadaniem programu jest zaszyfrowanie lub odszyfrowanie tekstu podanego przez użytkownika. Na starcie programu użytkownik wybiera główny tryb działania programu - szyfrowanie lub odszyfrowanie. Kolejnym krokiem jest wybranie przez użytkownika algorytmu szyfrującego. Ostatnim krokiem jest podanie ciągu znaków do przetworzenia.

**Dane wejściowe**
1. Tryb działania programu
2. Wybrany algorytm
3. Ciąg znaków

**Dane wyjściowe**

Zaszyfrowany lub odszyfrowany tekst

**Tryby działania programu:**

zaszyfrowanie tekstu
odszyfrowanie tekstu

**Dostępne algorytmy:**

1. szyfr cezara (ROT_13)
2. szyfrowanie char -> int, int -> char (z przesunięciem)
3. szyfr podstawieniowy [tablica podstawień określona w pliku źródłowym]

**Przykład danych wejściowych:**

1  
2  
KOPYTKO

**Przykład danych wyjściowych:**

XBCLGXB

## Jak skompilować?
Należy użyc cmake, a następnie narzędzi jakie cmake zbudował. Na Linuxie wygląda to następująco:

```
cmake .
make 
```
Na Windowsie da się otworzyć w Visual Studio. 
[https://docs.microsoft.com/pl-pl/cpp/build/cmake-projects-in-visual-studio?view=vs-2019](https://docs.microsoft.com/pl-pl/cpp/build/cmake-projects-in-visual-studio?view=vs-2019)

Skompilowane pliki znajdują się w folderze ./bin

Pliki *.o znajdują się w katalogu ./src/CMakeFiles/awesome-cipher.dir 

## Co z dokumentacją?
Dokumntacja jest generowana za pomocą aplikacji Doxygen. Plik konfiguracyjny znajduje się w ./docs/Doxyfile. Aby wygenerować nową wersję wystarczy uruchomić następujące polecenia.

```
cd docs
doxygen Doxyfile
```