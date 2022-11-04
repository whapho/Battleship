#include "Battleship.h"

using namespace std;

int* gameBoard = new int[ROWS * COLS];

void createGameBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(gameBoard + i * COLS + j) = 0;
        }
    }
}

void displayGameBoard() {
    system("cls");
    int num;
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < COLS; j++) {
            num = *(gameBoard + i * COLS + j);
            switch (num) {
                case 0:
                    cout << "* ";
                    break;
                case 1:
                    cout << "* ";
                    break;
                case 2:
                    cout << "M ";
                    break;
                case 3:
                    cout << "H ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}

void placeRandomShips() {
    for (int i = 0; i < sizeof(SHIP_LENGTHS)/sizeof(SHIP_LENGTHS[0]); i++) {
        int orientation = rand() % 2;
        int x, y, shipLength = SHIP_LENGTHS[i];

        if (orientation == 0) {
            x = rand() % 10;
            y = rand() % (10-SHIP_LENGTHS[i]);
        } else {
            x = rand() % (10-SHIP_LENGTHS[i]);
            y = rand() % 10;
        }
        for (int j = 0; j < shipLength; j++) {
            *(gameBoard + x * COLS + y) = 1;
            if (orientation == 0)
                y++;
            else if (orientation == 1)
                x++;
        }
    }
    if (!checkForShips(gameBoard)) {
        createGameBoard();
        placeRandomShips();
    }
}

void startSingleplayerGame() {
    int input = 1;
    string coord;
    createGameBoard();
    placeRandomShips();
    while (!gameOver(gameBoard, 0)) {
        system("cls");
        displayGameBoard();
        cout << "Enter coordinates: ";
        cin >> coord;
        fire(coord, gameBoard, 0);
        cout << gameOver(gameBoard, 0);
    }
    do {
        system("cls");
        displayGameBoard();
        cout << "You win!" << endl;
        cout << "[0] Done" << endl;
        cin >> input;
    } while (input != 0);
    mainMenu();
}