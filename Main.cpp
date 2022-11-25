#include <iostream>
#include"AppBook.cpp"
#include "User.cpp"
#include "UserManager.cpp"
//ADMID account "dara" password "123"
//Normal account "lina" password "123"
int main()
{
    RunApp app;
    UserManager userManager;
    string username;
    string password;
    do {
        cout << "\t\t\t===========================Login==========================" << endl;
        cout << "\t\t\tEnter username: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;
        User* user = userManager.authenticateUser(username, password);
        if (user != nullptr)
        {
            if (user->getType() == "ADMIN") {
                app.user();
            }
            else if (user->getType() == "NORMAL") {
                app.app();
            }
        }
        else {
            cout << "Invalid user" << endl;
        }
    } while (true);

}