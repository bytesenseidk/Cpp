#include "../Header/UserPage.h"

using namespace std;

void showUsers() {
    string users;
    Encryption crypt{};

    crypt.decrypt();
    ifstream userList("temp.csv");
    while (getline(userList, users)) {
        cout << users << endl;
    }
    userList.close();
    crypt.encrypt();
}

int main() {
    string username;
    string password;
    string email;

    ProfileData User;

    signed int choice;
    while (true) {
        cout << "\n[ LOGIN SYSTEM ]\n" << endl;
        cout << "[0] Exit" << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Sign Up" << endl;
        cout << "[3] Display Users\n" << endl;
        try {
            cout << "Selection: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 0:
                    return 0;

                case 1:
                    cout << "\n[ SING IN ]" << endl;
                    cout << "Enter username: ";
                    cin >> username;
                    User.setUsername(username);
                    cout << "Enter password: ";
                    cin >> password;
                    User.setPassword(password);
                    if (User.loginUser()) {
                        UserPage(username).userMenu();
                        return 0;
                    }
                    else {
                        cout << "Not logged in." << endl;
                    }
                    break;

                case 2:
                    cout << "\n[ SING UP ]" << endl;
                    while (true) {
                        try {
                            cout << "Enter Username: ";
                            cin >> username;
                            if (!ProfileData::validateUniqueUsername(username)) {
                                cout << "Username is already in use.\n" << endl;
                                continue;
                            }
                            else if (!ProfileData::validateUsername(username)) {
                                cout << "Username must be at least 6 characters long.\n" << endl;
                                continue;
                            }
                            User.setUsername(username);

                            cout << "Enter Email: ";
                            cin >> email;
                            if (!ProfileData::validateUniqueEmail(email)) {
                                cout << "Email already in use.\n" << endl;
                                continue;
                            }
                            if (!ProfileData::validateEmail(email)) {
                                cout << "Email is not a valid email.\n" << endl;
                                continue;
                            }
                            User.setEmail(email);

                            cout << "Enter Password: ";
                            cin >> password;
                            if (!ProfileData::validatePassword(password)) {
                                cout << "Password must be at least 6 characters long.\n" << endl;
                                continue;
                            }
                            User.setPassword(password);
                            break;
                        }
                        catch (exception & e) {
                            cout << "Please enter a valid data type!" << endl;
                            cout << e.what() << endl;
                            continue;
                        }
                    }
                    User.signupUser();
                    break;

                case 3:
                    showUsers();
                    break;

                default:
                    cout << "Choice out of scope.." << endl;
                    break;
            }
            continue;
        }
        catch (exception &e) {
            cout << e.what() << endl;
            cout << "You must enter an integer as displayed above.\n" << endl;
        }
    }
}
