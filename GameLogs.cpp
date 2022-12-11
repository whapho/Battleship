#include "Battleship.h"

void getGamesPlayed() {
    ifstream fin;
    fin.open("gamelog.txt", ios::app);
    int index = 1;
    string str;
    while (!fin.eof()) {
        getline(fin, str);
        if (str[0] == 'M') {
            cout << "[" << index << "]" << str << endl;
            index++;
        }
    }
}

void getGameBoards(int index) {
    clear();
    ifstream fin;
    fin.open("gamelog.txt", ios::app);
    string str;
    int input = 1;
    int pos = (index - 1) * 696;
    fin.seekg(pos, ios::beg);
    for (int i = 0; i < 14; i++) {
        getline(fin, str);
        cout << str << endl;
    }
    while (input != 0) {
        cout << "[0] Go back" << endl;
        cin >> input;
    }
    showGamelogMenu();
}
