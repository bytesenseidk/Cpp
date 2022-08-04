#ifndef ENHANCEDUSERSYSTEM_USERPAGE_H
#define ENHANCEDUSERSYSTEM_USERPAGE_H
#include "Encryption.h"
#include "ProfileData.h"
#include <filesystem>

class UserPage {
private:
    string Username;
    string Password;
    string Email;

    string users;

    void personalDetails();
    void displayData();

public:
    explicit UserPage(string username);
    void userMenu();
    void changeData();
    void changeUserData(const string& flag, const string& newUsername);

    void changePassword(const string& newPass);
    void changeEmail();

    ~UserPage();
};


#endif //ENHANCEDUSERSYSTEM_USERPAGE_H
