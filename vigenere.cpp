/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yutong Liu, Hongwei Ruan
 * merrila, hwruan
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Description: functions for encrypting and decrypting using vigenere method
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>


string vigenereCipher(string original, string keyword, bool encrypt) {
    
    string vigenereResult = "";
    char newChar = 'A';
    string noAlphaKeyword = removeNonAlphas(keyword);
    string newKeyword = toUpperCase(noAlphaKeyword);
 
    if (encrypt) {
        int j = 0;
        for (int i = 0; i < original.size(); i++) {
            if (isalpha(original.at(i))) {
                int keywordValue = newKeyword.at(j % noAlphaKeyword.size()) - 'A';
                newChar = shiftAlphaCharacter(original.at(i), keywordValue);
                j++;
            } else {
                newChar = original.at(i);
            }
            vigenereResult += newChar;
        }
    } else {
        int j = 0;
        for (int i = 0; i < original.size(); i++) {
            if (isalpha(original.at(i))) {
                int keywordValue = newKeyword.at(j % noAlphaKeyword.size()) - 'A';
                int decryptValue = 26 - keywordValue;
                newChar = shiftAlphaCharacter(original.at(i), decryptValue);
                j++;
            } else {
                newChar = original.at(i);
            }
            vigenereResult += newChar;
        }
    }
    return vigenereResult;
}
