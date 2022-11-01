#include "Battleship.h"

using namespace std;

void fire(int x, int y, int *board) {
    if (*(board + (x-1) * COLS + (y-1)) == 0)
        *(board + (x-1) * COLS + (y-1)) = 2;
    else
        *(board + (x-1) * COLS + (y-1)) = 3;
}

bool checkForShips(int *board) {
    int tileCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(board + i * COLS + j) != 0)
                tileCount++;
        }
    }
    if (tileCount == 17)
        return true;
    return false;
}

bool gameOver(int *board, int mode) {
    int count, hit;
    if (mode == 0)
        hit = 3;
    else
        hit = 7;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(board + i * COLS + j) == hit)
                count++;
        }
    }
    if (count == 17)
        return true;
    else
        return false;
}

void aimbot(int *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (*(board + i * COLS + j) == 1)
                *(board + i * COLS + j) = 7;
        }
    }
}