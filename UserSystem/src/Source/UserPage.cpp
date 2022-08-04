#include "../Header/UserPage.h"

UserPage::UserPage(string username) {
    Username = move(username);
    personalDetails();
}

void UserPage::userMenu() {
    cout << "\nWelcome " << Username << '!' << endl;
    cout << "[0] Exit" << endl;
    cout << "[1] Display Data" << endl;
    cout << "[2] Change Data\n" << endl;
    try {
        signed int choice;
        cout << "Selection:" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 0:
                break;
            case 1:
                displayData();
                break;
            case 2:
                changeData();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

void UserPage::changeData() {
    string newUsername;
    string newPass;
    string newMail;
    cout << "\n[ CHANGE DATA ]" << endl;
    cout << "[1] Username" << endl;
    cout << "[2] Password" << endl;
    cout << "[3] Email\n" << endl;
    try {
        signed int choice;
        cout << "Selection: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                while (true) {
                    cout << "\n[ CHANGE USERNAME ]" << endl;
                    cout << "Enter new username: ";
                    cin >> newUsername;
                    cin.ignore();
                    if (!ProfileData::validateUniqueUsername(newUsername)) {
                        cout << "Username is already in use.\n" << endl;
                        continue;
                    }
                    else if (!ProfileData::validateUsername(newUsername)) {
                        cout << "Username must be at least 6 characters long.\n" << endl;
                        continue;
                    }
                    changeUserData("Username", newUsername);
                    break;
                }
                break;
            case 2:
                while (true) {
                    cout << "\n[ CHANGE PASSWORD ]" << endl;
                    cout << "Enter new password: ";
                    cin >> newPass;
                    cin.ignore();
                    if (!ProfileData::validatePassword(newPass)) {
                        cout << "Username must be at least 6 characters long.\n" << endl;
                        continue;
                    }
                    changeUserData("Password", newPass);
                    break;
                }
                break;
            case 3:
                while (true) {
                    cout << "\n[ CHANGE EMAIL ]" << endl;
                    cout << "Enter new email: ";
                    cin >> newMail;
                    cin.ignore();
                    if (!ProfileData::validateUniqueEmail(newMail)) {
                        cout << "Email is already in use.\n" << endl;
                        continue;
                    }
                    else if (!ProfileData::validateEmail(newMail)) {
                        cout << "Email is not a valid email.\n" << endl;
                        continue;
                    }
                    changeUserData("Email", newMail);
                    break;
                }
                break;
            default:
                cout << "Invalid choice.." << endl;
                break;
        }
    }
    catch (exception& e) {
        cout << e.what();
    }
}

void UserPage::displayData() {
    cout << "\n[ PROFILE DATA ]" << endl;
    cout << "Username: " << Username << endl;
    cout << "Password: " << Password << endl;
    cout << "Email: " << Email << endl;
}

void UserPage::personalDetails() {
    string username;
    Encryption crypt{};
    crypt.decrypt();
    ifstream userList("temp.csv");

    while (getline(userList, users)) {
        username = users.substr(0, users.find(','));
        if (Username == username) {
            users.erase(0, users.find(',') + 1);
            Password = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Email = users.substr(0, users.find(','));
        }
    }
    userList.close();
    crypt.encrypt();
}

void UserPage::changeUserData(const string& flag, const string& newData) {
    Encryption crypt{};
    string newRepl;
    if (flag == "Username") {
        newRepl = newData + ',' + Password + ',' + Email;
    }
    else if (flag == "Password") {
        newRepl = Username + ',' + newData + ',' + Email;
    }
    else if (flag == "Email") {
        newRepl = Username + ',' + Password + ',' + newData;
    }

    crypt.decrypt();
    fstream userFile("temp.csv", ios::in);
    if (userFile.is_open()) {
        string user;
        vector<string> users_details;
        while(getline(userFile, user)) {
            string::size_type pos = 0;
            while ((pos = user.find(Username, pos)) != string::npos) {
                user.replace(pos, user.size(), newRepl);
                pos += newRepl.size();
            }
            users_details.push_back(user);
        }
        userFile.close();
        userFile.open("newList.csv", ios::out | ios::trunc);
        for (const auto& i : users_details) {
            userFile << i << endl;
        }
    }
    userFile.close();
    try {
        if (filesystem::remove("temp.csv")) {
            rename("newList.csv", "temp.csv");
            cout << flag << " successfully changed." << endl;
        }
        else {
            cout << flag << " couldn't be changed." << endl;
        }
    }
    catch (const filesystem::filesystem_error& e) {
        cout << e.what() << endl;
    }
    crypt.encrypt();
}

UserPage::~UserPage() = default;