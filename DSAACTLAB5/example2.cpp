#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }
    double getBalance() {
        return balance;
    }
    BankAccount() {
        balance = 0;
    }
};

int main() {
    BankAccount acc;
    acc.deposit(5000);
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
