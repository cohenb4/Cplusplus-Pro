#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include "bankaccount.hpp"
#include "checkingaccount.hpp"
#include "savingsaccount.hpp"

using namespace std;

int main(){

    int ID;
    string acc_code;
    double amt;

    ifstream infile;
    //infile.open("Transactions.txt", ios::in); //opens text file, only works if full file path given
    infile.open("C:\\Users\\Gus\\Documents\\qt\\labwk10\\Transactions.txt", ios::in);

    srand(time(NULL)); //seeds random number
    ID = (rand()%900000) + 100000; //generates random ID

    SavingsAccount *psa = new SavingsAccount("John", ID, 100.); //creates new savings account
    ID = (rand()%900000) + 100000; //generates random ID
    CheckingAccount *pca = new CheckingAccount("Mary", ID, 100.); //creates new checking account

    while(1){
        infile >> acc_code >> amt;
        //cout << acc_code << amt << endl; //for testing- prints what is read from file
        if((acc_code[0] == 's') && (acc_code[1] == 'w')){ //if savings withdrawal- calls makeWithdrawal
            psa->makeWithdrawal(amt);
            //cout << "Savings Balance " << psa->getBalance() << endl; //for testing- print savings and checking balances
            //cout << "Checking balance: " << pca->getBalance() << endl;
        }else if((acc_code[0] == 's') && (acc_code[1] == 'd')){ //if savings deposit- calls makeDeposit
            psa->makeDeposit(amt);
            //cout << "Savings Balance " << psa->getBalance() << endl; //for testing- print savings and checking balances
            //cout << "Checking balance: " << pca->getBalance() << endl;
        }else if((acc_code[0] == 'c') && (acc_code[1] == 'w')){ //if checking withdrawal- calls makeWithdrawal
            pca->makeWithdrawal(amt);
            //cout << "Savings Balance " << psa->getBalance() << endl; //for testing- print savings and checking balances
            //cout << "Checking balance: " << pca->getBalance() << endl;
        }else if((acc_code[0] == 'c') && (acc_code[1] == 'd')){ //if checking deposit- calls makeDeposit
            pca->makeDeposit(amt);
            //cout << "Savings Balance " << psa->getBalance() << endl; //for testing- print savings and checking balances
            //cout << "Checking balance: " << pca->getBalance() << endl;
        }else if(acc_code == "EOF"){
            break;
        }
    }

    cout << endl << "Closing Balance of Savings Account #" << psa->getID() << ": $" << psa->getBalance() << endl << "   Number of savings deposits: " << psa->getNdep() << endl; //prints savings account statistics
    cout << "   Number of savings withdrawals: " << psa->getNwd() << endl << endl;

    cout << "Closing Balance of Checking Account #" << pca->getID() << ": $" << pca->getBalance() << endl << "   Number of checking deposits: " << pca->getNdep() << endl; //prints checking account statistics
    cout << "   Number of checking withdrawals: " << pca->getNwd() << endl << endl;

    closeAccount(psa); //closes savings account
    closeAccount(pca); //closes checking account
    infile.close(); //closes text file

    return 0;
}
