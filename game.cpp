#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int START_ACCOUNT = 100;

int rollDie();
bool playOneGame();
void winLoss(int wins, int losses);
double percWon(int wins, int losses);
double avgWon(int wins, int losses, int acct);

int main()
{
    srand(time(NULL));
    bool win;
    int winCount = 0;
    int lossCount = 0;
    int acct = START_ACCOUNT; //amount in account
    int wag; //wager
    double avg;

    cout << "Account balance $" << acct << endl;
    cout << "Enter wager (0 to exit): "; //take wager
    cin >> wag;
    while(!(wag >= 0 && wag <= acct)){ //make sure wager is valid
        cout << "Error: You must wager between $1 and $" << acct << " (type 0 to exit): ";
        cin >> wag;
    }

    while(wag != 0 && acct > 0){
        win = playOneGame(); //play game

        if(win){ //depending on win or loss, print an appropriate statement, then add or remove the wager from account and
                 //increment the appropriate counter
            cout << " ** You win! **" << endl;
            acct += wag;
            ++winCount;
        } else {
            cout << " ** You lose **" << endl;
            acct -= wag;
            ++lossCount;
        }

        if(acct > 0){
            cout << "Account balance $" << acct << endl;
            cout << "Enter wager (0 to exit): "; //take wager
            cin >> wag;
            while(!(wag >= 0 && wag <= acct)){ //make sure wager is valid
                cout << "Error: You must wager between $1 and $" << acct << " (type 0 to exit): ";
                cin >> wag;
            }
        }
    }

    if(acct <= 0) cout << "Game over, you are out of money!\n";
    cout << "Your final account balance is $" << acct << endl;

    winLoss(winCount, lossCount);
    avg = avgWon(winCount, lossCount, acct);

    if(avg < 0){ //outputs average amount lost or gained
        cout << "You lost $" << avg * -1 << " per round on average.\n";
    }else{
        cout << "You gained $" << avg << " per round on average.\n";
    }

    return 0;
}

int rollDie(){ //gets a random number between 1 and 6
    int dieRoll = rand() % 6 + 1;
    return dieRoll;
}

bool playOneGame(){
    int point = -1;
    bool match = false;

    cout << "Enter your point value (1-6): "; //take point value
    cin >> point;

    while(point < 0 || point > 6){ //ensures point value between 1 and 6
        cout << "Error: Enter your point value, must be between 1 and 6: ";
        cin >> point;
    }

    for(int i = 1; i <= 3 && !match; ++i){ //rolls dice up to 3 times, checks if roll matches point after each, exits loop if matches
        int temp = rollDie();
        cout << "Roll #" << i << " is " << temp << endl;
        if(temp == point) match = true;
    }

    return match;
}

double percWon(int wins, int losses){ //calculates the percentage of wins
    double perc = static_cast<double>(wins)/static_cast<double>(losses + wins);
    return perc;
}

void winLoss(int wins, int losses){ //outputs number of wins and percentage
    cout << "You won " << wins << " times out of " << wins + losses << " for a winning percentage of " << percWon(wins, losses) << "%" << endl;
}

double avgWon(int wins, int losses, int acct){ //computes average amount won
    double avg = (acct - START_ACCOUNT) / (wins + losses);
    return avg;
}
