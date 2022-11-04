#include "Battleship.h"

using namespace std;

int menuInput;
const string DIVIDER = "----------------------------------------";

void mainMenu() {
    system("cls");
    cout << "Battleship by whapho" << endl;
    cout << DIVIDER << endl;
    cout << "[1] New Game" << endl;
    cout << "[2] Instructions" << endl;
    cout << "[3] Statistics" << endl;
    cout << "[0] Close Game" << endl;
    cout << DIVIDER << endl;
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
        case 3:
            showStatMenu();
            break;
        default:
            break;
    }
}

void newGame() {
    system("cls");
    cout << "Choose game mode" << endl;
    cout << DIVIDER << endl;
    cout << "[1] Singleplayer" << endl;
    cout << "[2] Multiplayer" << endl;
    cout << "[0] Go back" << endl;
    cout << DIVIDER << endl;

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
    cout << DIVIDER << endl;
    cout << "[1] PvE instructions" << endl;
    cout << "[2] PvP instructions" << endl;
    cout << "[0] Go back" << endl;
    cout << DIVIDER << endl;
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
        cout << DIVIDER << endl;
        cout << "Upon starting a singleplayer game, the computer" << endl;
        cout << "will place ships randomly on the game board." << endl;
        cout << "Your goal is to sink these ships in" << endl;
        cout << "as little shots as possible, or as" << endl;
        cout << "quick as possible, depending on the mode." << endl;
        cout << "[0] Go back" << endl;
        cout << DIVIDER << endl;
        cin >> menuInput;
    }
    showInstructions();
}

void showMultiplayerInstructions() {
    system("cls");
    while (menuInput != 0) {
        cout << "Multiplayer Instructions" << endl;
        cout << DIVIDER << endl;
        cout << "Under construction" << endl;
        cout << "[0] Go back" << endl;
        cout << DIVIDER << endl;
        cin >> menuInput;
    }
    showInstructions();
}
void showStatMenu() {
    system("cls");
    cout << "Statistics" << endl;
    cout << DIVIDER << endl;
    cout << "[1] Singleplayer Statistics" << endl;
    cout << "[2] Multiplayer Statistics" << endl;
    cout << "[0] Go back" << endl;
    cout << DIVIDER << endl;
    cin >> menuInput;
    switch (menuInput) {
        case 0:
            mainMenu();
            break;
        case 1:
            showSingleplayerStats();
            break;
        case 2:
            showMultiplayerStats();
            break;
        default:
            break;
    }
}

void showSingleplayerStats() {
    system("cls");
    while (menuInput != 0) {
        cout << "Singleplayer Statistics" << endl;
        cout << DIVIDER << endl;
        cout << "Under Construction" << endl;
        cout << "[0] Go back" << endl;
        cout << DIVIDER << endl;
        cin >> menuInput;
    }
    showStatMenu();
}

void showMultiplayerStats() {
    system("cls");
    while (menuInput != 0) {
        cout << "Multiplayer Statistics" << endl;
        cout << DIVIDER << endl;
        cout << "Under Construction" << endl;
        cout << "[0] Go back" << endl;
        cout << DIVIDER << endl;
        cin >> menuInput;
    }
    showStatMenu();
}

int main() {
    srand(time(0));
    mainMenu();
}