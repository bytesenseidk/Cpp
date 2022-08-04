#ifndef ENHANCEDUSERSYSTEM_ENCRYPTION_H
#define ENHANCEDUSERSYSTEM_ENCRYPTION_H
#include <bits/stdc++.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Encryption {
private:
    char fileSymbol;

public:
    void encrypt();
    void decrypt();
    ~Encryption();
};

#endif //ENHANCEDUSERSYSTEM_ENCRYPTION_H
