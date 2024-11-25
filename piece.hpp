// piece.hpp

#include <iostream>
#include <algorithm>
#include <cmath>

#include "rotMatricies.hpp"

#ifndef PIECE
#define PIECE

class piece {
public:
    int pos[3]; // Position array, (0,0,0) = center piece
    char col[3]; // Color array (x,y,z) => ('O','W','B')... ('B','NULL','G')
    // White = 'W'
    // Red = 'R'
    // Blue = 'B'
    // Green = 'G'
    // Orange = 'O'
    // Yellow = 'Y'

    piece(int x = 0, int y = 0, int z = 0) {
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        col[0] = 'A';
        col[1] = 'A';
        col[2] = 'A';
    }

    void rotate(int rotMatrix[3][3]) {
        int newPos[3];
        for (int column = 0; column < 3; column++) {
            newPos[column] = 0;
            for (int row = 0; row < 3; row++) {
                newPos[column] += pos[row] * rotMatrix[row][column];
            }
        }
        for (int i = 0; i < 3; i++) {
            pos[i] = newPos[i];
        }

        int nonEffect;
        for (int i = 0; i < 3; i++) {
            if (rotMatrix[i][i] != 0) {
                nonEffect = i;
                break;
            }
        }

        switch (nonEffect)
        {
        case 0:
            std::swap(col[1],col[2]);
            break;
        case 1:
            std::swap(col[0],col[2]);
            break;
        case 2:
            std::swap(col[0],col[1]);
            break;
        }
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            std::cout << "Pos: " << pos[i] << ", Color: " << col[i] << std::endl;
        }
    }
};

#endif