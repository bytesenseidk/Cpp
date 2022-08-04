#ifndef ENHANCEDUSERSYSTEM_PROFILEDATA_H
#define ENHANCEDUSERSYSTEM_PROFILEDATA_H
#include "Encryption.h"
#include <utility>
#include <cmath>

class ProfileData {
private:
    string Username;
    string Password;
    string Email;

public:
    void setUsername(string username);
    void setPassword(string password);
    void setEmail(string email);

    static bool validateUniqueUsername(const string &Username);
    static bool validateUsername(const string &Username);
    static bool validateUniqueEmail(const string &Email);
    static bool validateEmail(const string &Email);
    static bool validatePassword(const string &Password);

    bool loginUser();
    void signupUser();

    ~ProfileData();
};


#endif //ENHANCEDUSERSYSTEM_PROFILEDATA_H
