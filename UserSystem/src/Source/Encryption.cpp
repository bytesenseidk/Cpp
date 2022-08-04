#include "../Header/Encryption.h"

void Encryption::encrypt() {
    fstream fileIn, fileOut;

    fileIn.open("temp.csv", fstream::in);
    fileOut.open("Users.csv", fstream::out);

    while (fileIn >> noskipws >> fileSymbol) {
        signed int temp = fileSymbol + 7;
        fileOut << (char)temp;
    }
    fileIn.close();
    fileOut.close();
    try {
        filesystem::remove("temp.csv");
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}

void Encryption::decrypt() {
    fstream fileIn, fileOut;

    if (!filesystem::exists("Users.csv")) {
        ofstream usersList;
        usersList.open("Users.csv");
        usersList.close();
    }
    fileIn.open("Users.csv", fstream::in);
    fileOut.open("temp.csv", fstream::out);

    while (fileIn >> noskipws >> fileSymbol) {
        signed int temp = fileSymbol - 7;
        fileOut << (char)temp;
    }
    fileIn.close();
    fileOut.close();
}

Encryption::~Encryption() = default;