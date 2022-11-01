#include "Battleship.h"
#include <iostream>

using namespace std;

void fire(int x, int y, int *board) {
    if (*(board + (x-1) * COLS + (y-1)) == 0)
        *(board + (x-1) * COLS + (y-1)) = 2;
    else
        *(board + (x-1) * COLS + (y-1)) = 3;
}

bool gameOver(int *board) {
    int hits;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*board == 3)
                hits++;
        }
    }
    if (hits == 17)
        return true;
}

void aimbot(int *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (*(board + i * COLS + j) == 1)
                *(board + i * COLS + j) = 3;
        }
    }
}