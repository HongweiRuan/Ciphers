/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yutong Liu, Hongwei Ruan
 * merrila, hwruan
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Functions in this file will be used for fulfilling other functions,
 * use as helper functions.
 */

#include "utility.h"
#include <iostream>
#include <string>
#include <cctype>

string toUpperCase(string original) {
    for (int i = 0; i < original.length(); i++) {
            original[i] = toupper(original[i]);
        }
        return original;
}

string removeNonAlphas(string original) {
    string result = "";
        for (int i = 0; i < original.length(); i++) {
            if (isalpha(original[i])) {
                result += original[i];
            }
        }
        return result;
}

string removeDuplicate(string original) {
    string finalString = "";
    for (int i = 0; i < original.size(); i++) {
        if (!(finalString.find(original[i]) < finalString.length())) {
            finalString += original[i];
        }
    }
    return finalString;
}

int charToInt(char original) {
    int integerForm = 0;
    integerForm = int(original) - 48;
    return integerForm;
}


////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}


