/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yutong Liu, Hongwei Ruan
 * merrila, hwruan
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Description: functions for encrypting and decrypting using caesar method
 */

#include "caesar.h"
#include <iostream>
char shiftAlphaCharacter(char c, int n) {
    
    char initial = 'a';
    if (!isalpha(c)) {
        return c;
    } else {
        if (islower(c)) {
            initial = 'a';
        } else {
            initial = 'A';
        }
        if (n < 0) {
            c = (c - initial + 26 + n % 26) % 26 + initial;
        } else if (n > 0) {
            c = (c - initial + n % 26) % 26 + initial;
        }
        return c;
    }
}

string caesarCipher(string original, int key, bool encrypt) {
    
    string caesarResult = "";
    
    if (encrypt) {
        for (int i = 0; i < original.size(); i++) {
            caesarResult += shiftAlphaCharacter(original.at(i), key);
        }
    } else {
        key = 26 - (key % 26);
        for (int i = 0; i < original.size(); i++) {
            caesarResult += shiftAlphaCharacter(original.at(i), key);
        }
    }
    return caesarResult;
}
