/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yutong Liu, Hongwei Ruan
 * merrila, hwruan
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Description: functions for encrypting and decrypting using polybius method
 */


#include "polybius.h"
#include <string>
using namespace std;


void fillGrid (char grid[SIZE][SIZE], string content) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = content[SIZE*i+j];
        }
    }
}


string mixKey(string key) {
    string keyALNUM;
    keyALNUM = key + ALNUM;
    string removeKeyALNUM = removeDuplicate(keyALNUM);
    
    return removeKeyALNUM;
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == c) {
                return to_string(row) + to_string(col);
            }
        }
    }
    return "";
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    
    fillGrid(grid, mixKey(key));
    string result = "";
    
    if (encrypt) {
        for (int i = 0; i < original.size(); i++) {
            if (original[i] == ' ') {
                result += " ";
            } else {
                result += findInGrid(original[i], grid);
            }
        }
    } else {
        for (int i = 0; i < original.size(); i++) {
            if(original[i] == ' ') {
                result += " ";
            } else {
                result.push_back(grid[charToInt(original[i])][charToInt(original[i+1])]);
                i++;
            }
        }
    }
    return result;
}
