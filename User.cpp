#pragma once
#include <iostream>
using namespace std;

class User {
private:
    string username;
    string password;
    string type;
public:
    User() :username("Unknown"), password("Unknown"), type("Unknown") {}
    User(string username, string password, string type) :username(username), password(password), type(type) {}
    ~User() {

    }
    void setUsername(string username) {
        this->username = username;
    }
    string getUsername() {
        return username;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getPassword() {
        return password;
    }
    void setType(string type) {
        this->type = type;
    }
    string getType() {
        return type;
    }
    void inputUser() {
        cout << "\t\t\tEnter username : ";
        cin >> username;
        cout << "\t\t\tEnter password : ";
        cin >> password;
        cout << "\t\t\tEnter type : ";
        cin >> type;
    }
    void outputUser() {
        cout << "\nusername: \t" << username<< "\n";
        for (int i = 80; i > 0; i--)

            cout << '-';

        cout << "\nPassword: \t" << password << "\t\t Type :" << type;
        cout << endl<<endl;

        for (int i = 80; i > 0; i--)

        {
            cout << '-';
        }
    }
};