#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Transaction {
public:
    string date;
    double amount;
    string type;

    Transaction(string d, double a, string t) : date(d), amount(a), type(t) {}
};

class Loan {
public:
    string loanDate;
    double loanAmount;

    Loan(string d, double a) : loanDate(d), loanAmount(a) {}
};

class Account {
protected:
    string accountNumber;
    string holderName;
    string address;
    string accountType;
    double funds;
    vector<Transaction> transactionHistory;
    vector<Loan> loanHistory;

public:
    Account(string accNo, string name, string addr, string type, double fund) :
        accountNumber(accNo), holderName(name), address(addr), accountType(type), funds(fund) {}

    virtual void deposit(double amount) {
        funds += amount;
        transactionHistory.emplace_back("2024-05-27", amount, "Deposit");
    }

    virtual bool withdraw(double amount) {
        if (funds >= amount) {
            funds -= amount;
            transactionHistory.emplace_back("2024-05-27", amount, "Withdrawal");
            return true;
        }
        return false;
    }

    void updateAddress(string newAddress) {
        address = newAddress;
    }

    void applyLoan(double amount) {
        loanHistory.emplace_back("2024-05-27", amount);
        funds += amount;
    }

    void transferFunds(Account &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
        }
    }

    void viewPassbook() const {
        cout << "Passbook for Account Number: " << accountNumber << endl;
        for (const auto& transaction : transactionHistory) {
            cout << "Date: " << transaction.date << ", Amount: " << transaction.amount << ", Type: " << transaction.type << endl;
        }
    }

    void searchTransaction(string date, double amount) const {
        cout << "Searching transactions for Date: " << date << " and Amount: " << amount << endl;
        for (const auto& transaction : transactionHistory) {
            if (transaction.date == date && transaction.amount == amount) {
                cout << "Found Transaction - Date: " << transaction.date << ", Amount: " << transaction.amount << ", Type: " << transaction.type << endl;
            }
        }
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string accNo, string name, string addr, double fund) :
        Account(accNo, name, addr, "Savings", fund) {}
};

class CurrentAccount : public Account {
public:
    CurrentAccount(string accNo, string name, string addr, double fund) :
        Account(accNo, name, addr, "Current", fund) {}
};

class JointAccount : public Account {
private:
    string secondHolderName;

public:
    JointAccount(string accNo, string name1, string name2, string addr, double fund) :
        Account(accNo, name1, addr, "Joint", fund), secondHolderName(name2) {}

    void updateSecondHolderName(string newName) {
        secondHolderName = newName;
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Primary Holder: " << holderName << endl;
        cout << "Second Holder: " << secondHolderName << endl;
        cout << "Address: " << address << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Funds: " << funds << endl;
    }
};

int main() {
    SavingsAccount sa("123456", "John Doe", "123 Elm St", 1000.0);
    CurrentAccount ca("654321", "Jane Doe", "456 Oak St", 2000.0);
    JointAccount ja("789012", "John Smith", "Jane Smith", "789 Pine St", 1500.0);

    // Perform some operations
    sa.deposit(500);
    sa.withdraw(200);
    sa.viewPassbook();
    sa.searchTransaction("2024-05-27", 500);

    ca.deposit(1000);
    ca.transferFunds(sa, 500);
    ca.viewPassbook();
    sa.viewPassbook();

    ja.updateSecondHolderName("Jane Doe");
    ja.displayAccountInfo();

    return 0;
}
