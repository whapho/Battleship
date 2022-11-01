#include "Battleship.h"
#include <iostream>

using namespace std;

int menuInput;

void mainMenu() {
    system("cls");
    cout << "Battleship Game" << endl;
    cout << "-----------------------" << endl;
    cout << "[1] New Game" << endl;
    cout << "[2] Instructions" << endl;
    cout << "[0] Close Game" << endl;
    cout << "-----------------------" << endl;
    cin >> menuInput;

    switch (menuInput) {
        case 0:
            break;
        case 1:
            newGame();
            break;
        case 2:
            showInstructions();
            break;
        default:
            break;
    }
}

void newGame() {
    system("cls");
    cout << "Choose mode" << endl;
    cout << "-----------------------" << endl;
    cout << "[1] Singleplayer" << endl;
    cout << "[2] Multiplayer" << endl;
    cout << "[0] Go back" << endl;
    cout << "-----------------------" << endl;

    cin >> menuInput;
    switch (menuInput) {
        case 0:
            mainMenu();
            break;
        case 1:
            startSingleplayerGame();
            break;
        case 2:
            startMultiplayerGame();
            break;
        default:
            break;
    }
}

void showInstructions() {
    system("cls");
    cout << "Instructions" << endl;
    cout << "-----------------------" << endl;
    cout << "[1] PvE instructions" << endl;
    cout << "[2] PvP instructions" << endl;
    cout << "[0] Go back" << endl;
    cout << "-----------------------" << endl;
    cin >> menuInput;
    switch (menuInput) {
        case 0:
            mainMenu();
            break;
        case 1:
            showSingleplayerInstructions();
            break;
        case 2:
            showMultiplayerInstructions();
            break;
        default:
            break;
    }
}

void showSingleplayerInstructions() {
    system("cls");
    while (menuInput != 0) {
        cout << "Singleplayer Instructions" << endl;
        cout << "-----------------------" << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "[0] Go back" << endl;
        cout << "-----------------------" << endl;
        cin >> menuInput;
    }
    showInstructions();
}

void showMultiplayerInstructions() {
    system("cls");
    while (menuInput != 0) {
        cout << "Multiplayer Instructions" << endl;
        cout << "-----------------------" << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "..." << endl;
        cout << "[0] Go back" << endl;
        cout << "-----------------------" << endl;
        cin >> menuInput;
    }
    showInstructions();
}

int main() {
    srand(time(0));
    mainMenu();
}