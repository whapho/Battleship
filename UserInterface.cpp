#include "Battleship.h"

int menuInput;

void mainMenu() {
    clear();
    cout << "Battleship by whapho" << endl;
    cout << DIVIDER << endl;
    cout << "[1] New Game" << endl;
    cout << "[2] Instructions" << endl;
    cout << "[3] Game Logs" << endl;
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
            showGamelogMenu();
            break;
        default:
            break;
    }
}

void newGame() {
    clear();
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
    clear();
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
    clear();
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
    clear();
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
void showGamelogMenu() {
    clear();
    cout << "Statistics" << endl;
    cout << DIVIDER << endl;
    cout << "[1]";
    cout << "[0] Go back" << endl;
    cout << DIVIDER << endl;
    cin >> menuInput;
    switch (menuInput) {
        case 0:
            mainMenu();
            break;
        default:
            break;
    }
}

int main() {
    srand(time(0));
    ofstream fout;
    fout.open ("gamelog.txt",ios::app);
    mainMenu();
    fout.close();
}