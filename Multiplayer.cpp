#include "Battleship.h"

int* playerOneBoard = new int[ROWS * COLS];
int* playerTwoBoard = new int[ROWS * COLS];

void createPlayerBoard(int *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(board + i * COLS + j) = 0;
        }
    }
}

void displayFinalBoards() {
    int num;
    cout << BOARD_HEADER << " | " << BOARD_HEADER << endl;
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
                    cout << num << " ";
                    break;
            }
        }
        cout << "| ";
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
                    cout << num << " ";
                    break;
            }
        }
        cout << endl;
    }
    cout << DIVIDER << endl;
}

void writeFinalBoards() {
    ofstream fout;
    fout.open("gamelog.txt", ios::app);
    fout << "Multiplayer game played at: " << getCurrentDateAndTime() << endl;
    fout << DIVIDER << endl;
    int num;
    fout << BOARD_HEADER << " | " << BOARD_HEADER << endl;
    for (int i = 0; i < 10; i++) {
        fout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(playerOneBoard + i * COLS + j);
            switch (num) {
                case 0:
                    fout << "* ";
                    break;
                case 1:
                    fout << "1 ";
                    break;
                case 2:
                    fout << "2 ";
                    break;
                case 3:
                    fout << "3 ";
                    break;
                case 4:
                    fout << "4 ";
                    break;
                case 5:
                    fout << "5 ";
                    break;
                case 6:
                    fout << "M ";
                    break;
                case 7:
                    fout << "H ";
                    break;
                default:
                    fout << num << " ";
                    break;
            }
        }
        fout << "| ";
        fout << DISPLAY[i];
        for (int j = 0; j < 10; j++) {
            num = *(playerTwoBoard + i * COLS + j);
            switch (num) {
                case 0:
                    fout << "* ";
                    break;
                case 1:
                    fout << "1 ";
                    break;
                case 2:
                    fout << "2 ";
                    break;
                case 3:
                    fout << "3 ";
                    break;
                case 4:
                    fout << "4 ";
                    break;
                case 5:
                    fout << "5 ";
                    break;
                case 6:
                    fout << "M ";
                    break;
                case 7:
                    fout << "H ";
                    break;
                default:
                    fout << num << " ";
                    break;
            }
        }
        fout << endl;
    }
    fout << DIVIDER << endl;
    fout.close();
}

void displayPlayerBoard(int *board, bool hidden) {
    clear();
    int num;
    cout << BOARD_HEADER << endl;
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
    clear();
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
        clear();
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
        clear();
        cout << "Player 1's turn to place ships. Player 2 look away!" << endl;
        cout << "[0] Ready?" << endl;
        input = 1;
        cin >> input;
    } while (input != 0);
    placePlayerShips(playerOneBoard);
    do {
        clear();
        cout << "Player 2's turn to place ships. Player 1 look away!" << endl;
        cout << "[0] Ready?" << endl;
        input = 1;
        cin >> input;
    } while (input != 0);
    placePlayerShips(playerTwoBoard);
    for (int i = 0; i < 200; i++) {
        do {
            clear();
            cout << "Player 1's turn to fire." << endl;
            cout << "[0] Ready" << endl;
            input = 1;
            cin >> input;
        } while (input != 0);
        clear();
        do {
            displayPlayerBoard(playerTwoBoard, true);
            cout << "Enter coordinates: ";
            cin >> coords;
            fire(coords, playerTwoBoard, 1);
            cout << fire(coords, playerTwoBoard, 1) << endl;
            if (gameOver(playerTwoBoard, 1))
                goto endloop;
        } while (fire(coords, playerTwoBoard, 1));

        do {
            clear();
            cout << "Player 2's turn to fire." << endl;
            cout << "[0] Ready" << endl;
            input = 1;
            cin >> input;
        } while (input != 0);
        clear();
        do {
            displayPlayerBoard(playerOneBoard, true);
            cout << "Enter coordinates: ";
            cin >> coords;
            fire(coords, playerOneBoard, 1);
            cout << fire(coords, playerOneBoard, 1) << endl;
            if (gameOver(playerOneBoard, 1))
                goto endloop;
        } while (fire(coords, playerOneBoard, 1));
    }
    endloop:
    clear();
    displayFinalBoards();
    do {
        if (gameOver(playerOneBoard, 1))
            cout << "Player 2 wins!!!" << endl;
        else if (gameOver(playerTwoBoard, 1))
            cout << "Player 1 wins!!!" << endl;
        else
            cout << "Draw";
        cout << "[0] Continue to main menu" << endl;
        input = 1;
        cin >> input;
    } while (input != 0);
    writeFinalBoards();
    mainMenu();
}
//A1 A2 B1 B2 B3 C1 C2 C3 D1 D2 D3 D4 E1 E2 E3 E4 E5
//1 2 0 V A1 V B1 V C1 V D1 V E1 0 0 V A1 V B1 V C1 V D1 V E1 0 0 A1 A2 B1 B2 B3 C1 C2 C3 D1 D2 D3 D4 E1 E2 E3 E4 E5
