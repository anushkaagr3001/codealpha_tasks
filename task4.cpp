#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Class
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void display() {
        cout << type << " : Rs." << amount << endl;
    }
};

// Account Class
class Account {
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int accNo) {
        accountNumber = accNo;
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal Successful.\n";
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        history.push_back(Transaction("Transfer Sent", amount));
        receiver.history.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successful.\n";
    }

    void showTransactions() {
        cout << "\nTransaction History\n";
        cout << "----------------------\n";

        if (history.empty()) {
            cout << "No Transactions Found.\n";
            return;
        }

        for (Transaction t : history) {
            t.display();
        }
    }

    void showAccount() {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Balance : Rs." << balance << endl;
    }
};

// Customer Class
class Customer {
public:
    int customerID;
    string name;
    Account account;

    Customer(int id, string n, int accNo)
        : account(accNo) {
        customerID = id;
        name = n;
    }

    void displayCustomer() {
        cout << "\nCustomer ID : " << customerID << endl;
        cout << "Customer Name : " << name << endl;
        account.showAccount();
    }
};

int main() {

    vector<Customer> customers;

    int choice;

    do {

        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Transactions\n";
        cout << "6. Account Details\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            int id, accNo;
            string name;

            cout << "Customer ID: ";
            cin >> id;

            cin.ignore();

            cout << "Customer Name: ";
            getline(cin, name);

            cout << "Account Number: ";
            cin >> accNo;

            customers.push_back(Customer(id, name, accNo));

            cout << "Customer Created Successfully.\n";
            break;
        }

        case 2: {
            int id;
            double amount;

            cout << "Customer ID: ";
            cin >> id;

            cout << "Amount: ";
            cin >> amount;

            for (auto &c : customers) {
                if (c.customerID == id) {
                    c.account.deposit(amount);
                }
            }

            break;
        }

        case 3: {
            int id;
            double amount;

            cout << "Customer ID: ";
            cin >> id;

            cout << "Amount: ";
            cin >> amount;

            for (auto &c : customers) {
                if (c.customerID == id) {
                    c.account.withdraw(amount);
                }
            }

            break;
        }

        case 4: {
            int senderID, receiverID;
            double amount;

            cout << "Sender Customer ID: ";
            cin >> senderID;

            cout << "Receiver Customer ID: ";
            cin >> receiverID;

            cout << "Amount: ";
            cin >> amount;

            Customer *sender = nullptr;
            Customer *receiver = nullptr;

            for (auto &c : customers) {
                if (c.customerID == senderID)
                    sender = &c;

                if (c.customerID == receiverID)
                    receiver = &c;
            }

            if (sender && receiver)
                sender->account.transfer(receiver->account, amount);
            else
                cout << "Customer Not Found.\n";

            break;
        }

        case 5: {
            int id;

            cout << "Customer ID: ";
            cin >> id;

            for (auto &c : customers) {
                if (c.customerID == id) {
                    c.account.showTransactions();
                }
            }

            break;
        }

        case 6: {
            int id;

            cout << "Customer ID: ";
            cin >> id;

            for (auto &c : customers) {
                if (c.customerID == id) {
                    c.displayCustomer();
                }
            }

            break;
        }

        case 7:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
