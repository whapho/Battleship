#include "Battleship.h"

using namespace std;

int* playerOneBoard = new int[ROWS * COLS];
int* playerTwoBoard = new int[ROWS * COLS];

void createPlayerBoard(int *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(board + i * COLS + j) = 0;
        }
    }
}

void displayPlayerBoard(int *board, bool hidden) {
    system("cls");
    int num;
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < 10; i++) {
        cout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(board + i * COLS + j);
            if (hidden) {
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
                        cout << num << " ";
                        break;
                }
            } else {
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
                        cout << num << " ";
                        break;
                }
            }
        }
        cout << endl;
    }
}

void placePlayerShips(int *board) {
    system("cls");
    displayPlayerBoard(board, false);
    int input = 1;
    for (int i = 0; i < sizeof(SHIP_LENGTHS)/sizeof(SHIP_LENGTHS[0]); i++) {
        string orientation, coord;
        char letter;
        int x, y = 0, shipLength = SHIP_LENGTHS[i];
        cout << "Ship: " << i + 1 << " || Length: " << SHIP_LENGTHS[i] << endl;
        cout << "Enter orientation: ";
        cin >> orientation;
        cout << "Enter starting coordinates: ";
        cin >> coord;
        letter = coord[0];
        coord.erase(0, 1);
        x = stoi(coord);
        switch (letter) {
            case 'A':
                y = 1;
                break;
            case 'B':
                y = 2;
                break;
            case 'C':
                y = 3;
                break;
            case 'D':
                y = 4;
                break;
            case 'E':
                y = 5;
                break;
            case 'F':
                y = 6;
                break;
            case 'G':
                y = 7;
                break;
            case 'H':
                y = 8;
                break;
            case 'I':
                y = 9;
                break;
            case 'J':
                y = 10;
                break;
            default:
                break;
        }
        for (int j = 0; j < shipLength; j++) {
            *(board + (x-1) * COLS + (y-1)) = i + 1;
            if (orientation == "H")
                y++;
            else if (orientation == "V")
                x++;
        }
        system("cls");
        displayPlayerBoard(board, false);
    }
    while (input != 0) {
        cout << "[0] Done" << endl;
        cin >> input;
    } input = 1;
    if (!checkForShips(board)) {
        while (input != 0) {
            cout << "Ships out of bounds." << endl;
            cout << "[0] Try again" << endl;
            cin >> input;
        } input = 1;
        createPlayerBoard(board);
        placePlayerShips(board);
    }
}

void startMultiplayerGame() {
    createPlayerBoard(playerOneBoard);
    createPlayerBoard(playerTwoBoard);
    int input;
    string coords;
    do {
        system("cls");
        cout << "Player 1's turn to place ships. Player 2 look away!" << endl;
        cout << "[0] Ready?" << endl;
        input = 1;
        cin >> input;
    } while (input != 0);
    placePlayerShips(playerOneBoard);
    do {
        system("cls");
        cout << "Player 2's turn to place ships. Player 1 look away!" << endl;
        cout << "[0] Ready?" << endl;
        input = 1;
        cin >> input;
    } while (input != 0);
    placePlayerShips(playerTwoBoard);
    do {
        for (int turn = 0; turn < 200; turn++) {
            if (turn % 2 == 0) {
                do {
                    system("cls");
                    cout << "Player 1's turn to fire." << endl;
                    cout << "[0] Ready" << endl;
                    input = 1;
                    cin >> input;
                } while (input != 0);
                system("cls");
                do {
                    displayPlayerBoard(playerTwoBoard, true);
                    cout << "Enter coordinates: ";
                    cin >> coords;
                    fire(coords, playerTwoBoard, 1);
                    cout << fire(coords, playerTwoBoard, 1);
                } while (fire(coords, playerTwoBoard, 1));
            } else if (turn % 2 == 1) {
                do {
                    system("cls");
                    cout << "Player 2's turn to fire." << endl;
                    cout << "[0] Ready" << endl;
                    input = 1;
                    cin >> input;
                } while (input != 0);
                system("cls");
                do {
                    displayPlayerBoard(playerOneBoard, true);
                    cout << "Enter coordinates: ";
                    cin >> coords;
                    fire(coords, playerOneBoard, 1);
                    cout << fire(coords, playerOneBoard, 1);
                } while (fire(coords, playerOneBoard, 1));
            }
        }
        cout << gameOver(playerOneBoard, 1) << gameOver(playerTwoBoard, 1);
    }while (!gameOver(playerOneBoard, 1) || !gameOver(playerTwoBoard, 1));
}
//A1 A2 B1 B2 B3 C1 C2 C3 D1 D2 D3 D4 E1 E2 E3 E4 E5
//1 2 0 V A1 V B1 V C1 V D1 V E1 0 0 V A1 V B1 V C1 V D1 V E1 0