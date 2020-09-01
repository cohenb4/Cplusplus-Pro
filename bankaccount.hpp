#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <string>

class BankAccount{
    protected:
        std::string name;
        int ID;
        double balance;
        static int naccount;
        BankAccount(std::string n, int id, double startBal): name(n), ID(id), balance(startBal) {} //constructor
    public:
        std::string getName(){return name;} //gets name
        size_t getID(){return ID;} //gets ID
        double getBalance(){return balance;} //gets balance
};

int BankAccount::naccount = 0;

#endif // BANKACCOUNT_H
