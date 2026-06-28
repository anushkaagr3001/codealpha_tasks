#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration Function
void registerUser() {
    string username, password;
    bool exists = false;

    cout << "\n===== Registration =====" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Input Validation
    if (username.empty() || password.empty()) {
        cout << "Username and Password cannot be empty!" << endl;
        return;
    }

    // Check if username already exists
    ifstream infile("users.txt");
    string user, pass;

    while (infile >> user >> pass) {
        if (user == username) {
            exists = true;
            break;
        }
    }
    infile.close();

    if (exists) {
        cout << "Username already exists! Please choose another." << endl;
        return;
    }

    // Save new user
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration Successful!" << endl;
}

// Login Function
void loginUser() {
    string username, password;
    bool found = false;

    cout << "\n===== Login =====" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");
    string user, pass;

    while (infile >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
        cout << "Login Successful! Welcome " << username << "!" << endl;
    else
        cout << "Invalid Username or Password!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n====== Login & Registration System ======" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 3);

    return 0;
}