#include "Battleship.h"
#include <iostream>

using namespace std;

const string DISPLAY[10] = {
        " 1 ", " 2 ", " 3 ", " 4 ", " 5 ",
        " 6 ", " 7 ", " 8 ", " 9 ", "10 "
};

int* playerOneBoard = new int[ROWS * COLS];
int* playerTwoBoard = new int[ROWS * COLS];

void createPlayerOneBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(playerOneBoard + i * COLS + j) = 0;
        }
    }
}

void createPlayerTwoBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(playerTwoBoard + i * COLS + j) = 0;
        }
    }
}

void displayPlayerOneBoard() {
    system("cls");
    int num;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(playerOneBoard + i * COLS + j);
            switch (num) {
                case 0:
                    cout << "* ";
                    break;
                case 1:
                    cout << "1 ";
                    break;
                case 2:
                    cout << "2 ";
                    break;
                case 3:
                    cout << "3 ";
                    break;
                case 4:
                    cout << "4 ";
                    break;
                case 5:
                    cout << "5 ";
                    break;
                case 6:
                    cout << "M ";
                    break;
                case 7:
                    cout << "H ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}


void displayPlayerOneBoardHidden() {
    system("cls");
    int num;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(playerOneBoard + i * COLS + j);
            switch (num) {
                case 0:
                    cout << "* ";
                    break;
                case 1:
                    cout << "* ";
                    break;
                case 2:
                    cout << "* ";
                    break;
                case 3:
                    cout << "* ";
                    break;
                case 4:
                    cout << "* ";
                    break;
                case 5:
                    cout << "* ";
                    break;
                case 6:
                    cout << "M ";
                    break;
                case 7:
                    cout << "H ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}

void placePlayerOneShips() {
    system("cls");
    displayPlayerOneBoard();
    int input = 1;
    for (int i = 0; i < sizeof(SHIP_LENGTHS)/sizeof(SHIP_LENGTHS[0]); i++) {
        string orientation;
        int x, y, shipLength = SHIP_LENGTHS[i];
        cout << "Enter orientation: ";
        cin >> orientation;
        cout << "Enter starting coordinates for ship: ";
        cin >> x >> y;
        for (int j = 0; j < shipLength; j++) {
            *(playerOneBoard + (x-1) * COLS + (y-1)) = i + 1;
            if (orientation == "h")
                y++;
            else if (orientation == "v")
                x++;
        }
        system("cls");
        displayPlayerOneBoard();
    }
    while (input != 0) {
        cout << "[0] Done" << endl;
        cin >> input;
    } input = 1;
    if (!checkPlayerOneBoard()) {
        while (input != 0) {
            cout << "Ships out of bounds." << endl;
            cout << "[0] Try again" << endl;
            cin >> input;
        } input = 1;
        createPlayerOneBoard();
        placePlayerOneShips();
    }
}

bool checkPlayerOneBoard() {
    int tileCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(playerOneBoard + i * COLS + j) != 0)
                tileCount++;
        }
    }
    if (tileCount == 17)
        return true;
    return false;
}

void displayPlayerTwoBoard() {
    system("cls");
    int num;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(playerTwoBoard + i * COLS + j);
            switch (num) {
                case 0:
                    cout << "* ";
                    break;
                case 1:
                    cout << "1 ";
                    break;
                case 2:
                    cout << "2 ";
                    break;
                case 3:
                    cout << "3 ";
                    break;
                case 4:
                    cout << "4 ";
                    break;
                case 5:
                    cout << "5 ";
                    break;
                case 6:
                    cout << "M ";
                    break;
                case 7:
                    cout << "H ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}

void displayPlayerTwoBoardHidden() {
    system("cls");
    int num;
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(playerTwoBoard + i * COLS + j);
            switch (num) {
                case 0:
                    cout << "* ";
                    break;
                case 1:
                    cout << "* ";
                    break;
                case 2:
                    cout << "* ";
                    break;
                case 3:
                    cout << "* ";
                    break;
                case 4:
                    cout << "* ";
                    break;
                case 5:
                    cout << "* ";
                    break;
                case 6:
                    cout << "M ";
                    break;
                case 7:
                    cout << "H ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}

void placePlayerTwoShips() {
    system("cls");
    displayPlayerTwoBoard();
    int input = 1;
    for (int i = 0; i < sizeof(SHIP_LENGTHS)/sizeof(SHIP_LENGTHS[0]); i++) {
        string orientation;
        int x, y, shipLength = SHIP_LENGTHS[i];
        cout << "Enter orientation: ";
        cin >> orientation;
        cout << "Enter starting coordinates for ship: ";
        cin >> x >> y;
        for (int j = 0; j < shipLength; j++) {
            *(playerTwoBoard + (x-1) * COLS + (y-1)) = i + 1;
            if (orientation == "h")
                y++;
            else if (orientation == "v")
                x++;
        }
        system("cls");
        displayPlayerTwoBoard();
    }
    while (input != 0) {
        cout << "[0] Done" << endl;
        cin >> input;
    } input = 1;
    if (!checkPlayerTwoBoard()) {
        while (input != 0) {
            cout << "Ships out of bounds." << endl;
            cout << "[0] Try again" << endl;
            cin >> input;
        } input = 1;
        createPlayerTwoBoard();
        placePlayerTwoShips();
    }
}

bool checkPlayerTwoBoard() {
    int tileCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(playerTwoBoard + i * COLS + j) != 0)
                tileCount++;
        }
    }
    if (tileCount == 17)
        return true;
    return false;
}

void playerOneFire() {
    int x, y;
    displayPlayerTwoBoardHidden();
    cout << "Enter coordinates: ";
    cin >> x >> y;
    if (*(playerTwoBoard + (x-1) * COLS + (y-1)) == 0) {
        *(playerTwoBoard + (x-1) * COLS + (y-1)) = 6;
    } else {
        *(playerTwoBoard + (x-1) * COLS + (y-1)) = 7;
        playerOneFire();
    }
    if (gameOver(playerTwoBoard)) {
        int input = 1;
        while (input != 0) {
            cout << "Player 1 wins!" << endl;
            cout << "[0] Done" << endl;
            cin >> input;
        } input = 1;
    }
}

void playerTwoFire() {
    int x, y;
    displayPlayerOneBoardHidden();
    cout << "Enter coordinates: ";
    cin >> x >> y;
    if (*(playerOneBoard + (x-1) * COLS + (y-1)) == 0) {
        *(playerOneBoard + (x-1) * COLS + (y-1)) = 6;
    } else {
        *(playerOneBoard + (x-1) * COLS + (y-1)) = 7;
        playerTwoFire();
    }
    if (gameOver(playerOneBoard)) {
        int input = 1;
        while (input != 0) {
            cout << "Player 2 wins!" << endl;
            cout << "[0] Done" << endl;
            cin >> input;
        } input = 1;
    }
}

void startMultiplayerGame() {
    int input = 1;
    createPlayerOneBoard();
    createPlayerTwoBoard();
    system("cls");
    while (input != 0) {
        cout << "Player 1's turn to place ships! Player 2 look away!!" << endl;
        cout << "[0] Ready" << endl;
        cin >> input;
    } input = 1;
    placePlayerOneShips();
    system("cls");
    while (input != 0) {
        cout << "Player 2's turn to place ships! Player 1 look away!!" << endl;
        cout << "[0] Ready" << endl;
        cin >> input;
    } input = 1;
    placePlayerTwoShips();
    system("cls");
    while (input != 0) {
        cout << "Boards are set! Ready to play?" << endl;
        cout << "[0] Ready" << endl;
        cin >> input;
    } input = 1;
    int count = 0;
//    while (!gameOver()) {
        if (count % 2 == 0) {
            displayPlayerOneBoard();
            while (input != 0) {
                cout << "This is your board." << endl;
                cout << "[0] Take shot" << endl;
                cin >> input;
            } input = 1;
            playerOneFire();
            displayPlayerTwoBoardHidden();
            cout << "You missed." << endl;
            system("cls");
            while (input != 0) {
                cout << "Player 2's turn! Player 1 look away!!" << endl;
                cout << "[0] Ready" << endl;
                cin >> input;
            } input = 1;
        }
        if (count % 2 == 0) {
            displayPlayerTwoBoard();
            while (input != 0) {
                cout << "This is your board." << endl;
                cout << "[0] Take shot" << endl;
                cin >> input;
            } input = 1;
            playerTwoFire();
            displayPlayerOneBoardHidden();
            cout << "You missed." << endl;
            system("cls");
            while (input != 0) {
                cout << "Player 1's turn! Player 2 look away!!" << endl;
                cout << "[0] Ready" << endl;
                cin >> input;
            } input = 1;
        }
        count++;
//    }
}