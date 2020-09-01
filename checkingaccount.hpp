#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

class CheckingAccount : public BankAccount
{
protected:
    int nwd; //number of withdrawls made
    int ndep; //number of deposits made
public:
    static double overdraftfee;

    CheckingAccount(string n, int id, double startBal) : BankAccount(n, id, startBal)
    {
       name = n; //sets name to n
       ID = id; //sets ID to id
       balance = startBal; //sets balance to startBal
       ++naccount;
    }

    void balanceMessage()
    {
        if (ndep == 0) //if number of deposits is 0 then prints out start message
        {
            cout << "Account " << ID << " starting balance" << balance << endl;
        }
        else if (ndep >= 1) //if number of deposits is greater than or equal to 1 it prints out current balance
        {
            cout << "Account " << ID << " current balance: " << balance << endl;
        }
    }

    void overdraftMessage(const double &a) {
        balance -= overdraftfee; // charge OD fee
        cout << "Account No. " << ID << ", INSUFFICIENT FUNDS TO WITHDRAW AMT: $" << fixed << setprecision(2) << a << ", BALANCE IS: $" << balance << endl;
    }

    void makeWithdrawal(const double &w)
    {
        checkBalance(w); //calls to checkBalance function
        if (checkBalance(w) == true) //checks if sufficient funds
        {
            balance -= w; //removes from balance
            ++nwd; //increments number of withdrawals
        }
        else
        {
            balance -= w; //removes from balance
            ++nwd; //increments number of withdrawals
            overdraftMessage(w); //calls overdraftMessage()
        }
    }

    void makeDeposit(const double &d)
    {
        balance += d; //adds deposit to balance
        ++ndep; //increments the number of deposits
        balanceMessage(); //prints balance message
    }

    bool checkBalance(const double &a)
    {
        if ((balance - a) > 0.01) //checks if balance is greater than number to withdrawal
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend void closeAccount(CheckingAccount *psa)
    {
       --naccount; //decrements total number of accounts
        delete psa; //closes account
    }

    int getNdep()
    {
        return ndep;
    }

    int getNwd()
    {
        return nwd;
    }

    void openAccount(const double &d) //allows for openAccount
    {
        if (balance < 25) //makes sure the balance is less than 25
        {
            closeAccount(this); //if so it voids and closes account
        }
        else
        {
            balance += d; //adds deposit to balance
            ++ndep; //increments number of deposits
            ++naccount; //increments number of accounts
        }

        balanceMessage(); //prints out the balance
    }

};

double CheckingAccount::overdraftfee = 35;



#endif // CHECKINGACCOUNT_H
