#include "Battleship.h"

int menuInput;

void mainMenu() {
    clear();
    cout << "Battleship by Max Gerew" << endl;
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
        cout << "Upon starting a multiplayer game, player 1 will be prompted" << endl;
        cout << "to place their ships. Once they are finished, it will be player 2's turn" << endl;
        cout << "to place their ships. After that, the game will start, and both players will" << endl;
        cout << "take turns shooting at each other. Once the game concludes, you can see" << endl;
        cout << "the final board in the game logs menu." << endl;
        cout << "[0] Go back" << endl;
        cout << DIVIDER << endl;
        cin >> menuInput;
    }
    showInstructions();
}
void showGamelogMenu() {
    clear();
    int choice;
    cout << "Game Logs" << endl;
    cout << DIVIDER << endl;
    getGamesPlayed();
    cout << "[0] Go back" << endl;
    cout << DIVIDER << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice != 0) {
        getGameBoards(choice);
    } else {
        mainMenu();
    }
}

int main() {
    srand(time(0));
    mainMenu();
}