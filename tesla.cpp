#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int roomx = 15;
const int roomy = 15;
const int TURNS_TO_WAKE = 5;

struct player {
    int x;
    int y;
    bool caughtOnce = false; //whether the player has been caught previously

    void place(char room[roomx][roomy]){ //place player at x, y position in room
        room[x][y] = 'o';
    }

    void move(char room[roomx][roomy], char dir){ //moves player based on input
        bool correct = true;
        room[x][y] = '-'; //removes player from previous position

        do{ //moves character
            if(!correct) cin >> dir;
            correct = true;
            switch(dir){
                case 'w': --y; break;
                case 'a': --x; break;
                case 's': ++y; break;
                case 'd': ++x; break;
                default: correct = false; cout << "Invalid direction, try again\n"; break;
            }
            if(x > roomx - 1 || x < 0 || y > roomy - 1 || y < 0){ //moves player back to previous position if out of bounds, prompts for new input
                switch(dir){
                    case 'w': ++y; break;
                    case 'a': ++x; break;
                    case 's': --y; break;
                    case 'd': --x; break;
                    default: correct = false; break;
                }
                correct = false;
                cout << "Out of bounds, choose another direction\n";
            }
            if(room[x][y] != '-'){ //moves player back to previous position if intersecting with elon or a car, prompts for new input
                switch(dir){
                    case 'w': ++y; break;
                    case 'a': ++x; break;
                    case 's': --y; break;
                    case 'd': --x; break;
                    default: correct = false; break;
                }
                correct = false;
                cout << "Object in way, choose another direction\n";
            }
        }while(!correct);
        room[x][y] = 'o'; //places player in new position
    }
};

struct elon { //elon musk
    int x;
    int y;
    bool awake = false;

    void place(char room[roomx][roomy]){ //place elon at x, y position in room
        room[x][y] = 'e';
    }

    void move(char room[roomx][roomy]){//moves elon in a random direction
        int dir;
        bool valid;

        room[x][y] = '-'; //removes elon from previous position

        do {
            valid = true;
            dir = rand() % 4;
            switch(dir){ //moves elon
                case 0: --y; break;
                case 1: --x; break;
                case 2: ++y; break;
                case 3: ++x; break;
                default: valid = false; break;
            }
            if(x > roomx - 1 || x < 0 || y > roomy - 1 || y < 0 || room[x][y] != '-'){
                switch(dir){ //moves elon back to previous position if position is not valid (out of bounds or intersecting with a car or the player)
                    case 'w': ++y; break;
                    case 'a': ++x; break;
                    case 's': --y; break;
                    case 'd': --x; break;
                    default: valid = false; break;
                }
                valid = false;
            }
        } while (!valid);

        room[x][y] = 'e'; //places elon in new position
    }
};

void drawRoom(char room[roomx][roomy], player player1){ //draws the room with a border
    cout << "*="; //draws top left corner

    for(int i = 0; i < roomx; ++i){ //draws top border
        cout << "==";
    }

    cout << "=*" << endl; //draws top right corner

    for(int i = 0; i < roomy; ++i){ //draws room with side borders - all but a 3x3 area around player are left blank
        cout << "||";
        for(int j = 0; j < roomx; ++j){
            if(fabs(player1.x - j) <= 1 && fabs(player1.y - i) <= 1){
                cout << " " << room[j][i];
            }else{
                cout << "  ";
            }
        }
        cout << "||" << endl;
    }

    cout << "*="; //draws bottom left corner

    for(int i = 0; i < roomx; ++i){ //draws bottom border
        cout << "==";
    }

    cout << "=*" << endl; //draws bottom right corner
}

void addObjs(char room[roomx][roomy], player& player1, elon& elon1, int carPos[]){ //adds cars, player, and elon
    int xtemp, ytemp;
    bool valid = true;

    do{ //randomly places yugo in an unoccupied space
        valid = true;
        xtemp = rand() % roomx;
        ytemp = rand() % roomy;
        if(room[xtemp][ytemp] == '-'){
            room[xtemp][ytemp] = 'y';
        }else{
            valid = false;
        }
    }while(!valid);

    carPos[0] = xtemp;
    carPos[1] = ytemp;

    do{ //randomly places pinto in an unoccupied space
        valid = true;
        xtemp = rand() % roomx;
        ytemp = rand() % roomy;
        if(room[xtemp][ytemp] == '-'){
            room[xtemp][ytemp] = 'p';
        }else{
            valid = false;
        }
    }while(!valid);

    carPos[2] = xtemp;
    carPos[3] = ytemp;

    do{ //randomly places roadster in an unoccupied space
        valid = true;
        xtemp = rand() % roomx;
        ytemp = rand() % roomy;
        if(room[xtemp][ytemp] == '-'){
            room[xtemp][ytemp] = 'r';
        }else{
            valid = false;
        }
    }while(!valid);

    carPos[4] = xtemp;
    carPos[5] = ytemp;

    do{ //sets player's location to a random location
        valid = true;
        xtemp = rand() % roomx;
        ytemp = rand() % roomy;
        if(room[xtemp][ytemp] == '-'){
            player1.x = xtemp;
            player1.y = ytemp;
        }else{
            valid = false;
        }
    }while(!valid);

    do{ //sets elon's location to a random location
        valid = true;
        xtemp = rand() % roomx;
        ytemp = rand() % roomy;
        if(room[xtemp][ytemp] == '-'){
            elon1.x = xtemp;
            elon1.y = ytemp;
        }else{
            valid = false;
        }
    }while(!valid);

    player1.place(room); //places player
    elon1.place(room); //places elon

}

bool playGame(int& turnCount){
    char room[roomx][roomy]; //room
    char dir = 'w';
    bool starman = false;
    bool won = false;
    int carPos[6]; //0 and 1 are yugo x and y respectively, 2 and 3 are pinto, 4 and 5 are roadster

    for(int i = 0; i < roomy; ++i){
        for(int j = 0; j < roomx; ++j){
            room[j][i] = '-';
        }
    }

    player player1;
    elon elon1;

    addObjs(room, player1, elon1, carPos);

    while(dir != 'q' && !starman && !won){
        drawRoom(room, player1); //draws room
        if(fabs(player1.x - carPos[0]) <= 3 && fabs(player1.y - carPos[1]) <= 3){ //tells the user if a car is nearby
            cout << "A car is nearby!\n";
        }else if(fabs(player1.x - carPos[2]) <= 3 && fabs(player1.y - carPos[3]) <= 3){
            cout << "A car is nearby!\n";
        }else if(fabs(player1.x - carPos[4]) <= 3 && fabs(player1.y - carPos[5]) <= 3){
            cout << "A car is nearby!\n";
        }else{
            cout << "No cars nearby\n";
        }
        cout << "Enter direction to move (wasd, q to quit, e to enter car): "; //prompts for direction
        cin >> dir;
        if(dir != 'q' && dir != 'e') player1.move(room,dir); //moves player if player has not chosen to enter a car or quit
        if(elon1.awake) elon1.move(room); //moves elon if elon is awake
        ++turnCount;
        if(turnCount >= TURNS_TO_WAKE) elon1.awake = true; //wakes up elon after specified number of turns have passed
        if(fabs(player1.x - elon1.x) <= 1 && fabs(player1.y - elon1.y) <= 1 && player1.caughtOnce){ //makes the player the starman if they are caught a second time
            cout << "You have been caught again! ";
            starman = true;
        }
        if(fabs(player1.x - elon1.x) <= 1 && fabs(player1.y - elon1.y) <= 1 && !player1.caughtOnce){ //marks that the player is the starman if they are caught the first time
            cout << "You have been caught! If you are caught again you will become the Starman.\n";
            player1.caughtOnce = true;
        }
        if(dir == 'e' && fabs(player1.x - carPos[0]) <= 1 && fabs(player1.y - carPos[1]) <= 1){ //enters car, wins or loses based on car
            starman = true;
            cout << "You have entered the Yugo! ";
        }else if(dir == 'e' && fabs(player1.x - carPos[2]) <= 1 && fabs(player1.y - carPos[3]) <= 1){
            starman = true;
            cout << "You have entered the Pinto! ";
        }else if(dir == 'e' && fabs(player1.x - carPos[4]) <= 1 && fabs(player1.y - carPos[5]) <= 1){
            won = true;
            cout << "You have entered the Roadster! ";
        }else if(dir == 'e'){
            cout << "No cars nearby\n";
        }
    }

    if(starman) cout << "You are the Starman!\n";
    if(won) cout << "You have escaped!\n";

    return won;
}

int main(){
    srand(time(NULL));

    int turnCount = 0;
    int totalTurns = 0;
    int gamesPlayed = 0;
    int wins = 0;
    int losses = 0;
    bool quit = false;
    bool won;

    while(!quit){ //runs game until user quits
        turnCount = 0;
        won = playGame(turnCount);
        cout << "You took " << turnCount << " turns.\n";
        cout << "Continue? (1 to quit, 0 to continue)" << endl;
        cin >> quit;
        if(won){
            ++wins;
        }else{
            ++losses;
        }

        ++gamesPlayed;
        totalTurns += turnCount;
    }

    cout << "You escaped " << wins << " times and became the Starman " << losses << " times.\n";
    cout << "You took an average of " << static_cast<double>(totalTurns) / gamesPlayed << " turns each game.\n";

    return 0;
}
