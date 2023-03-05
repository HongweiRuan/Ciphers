/*
 * tests.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yutong Liu, Hongwei Ruan
 * merrila, hwruan
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Description: test cases for utility, caesar, vigenere, polybius
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;


// void testShiftAlphaCharacter();
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
//    testShiftAlphaCharacter();
    // Repeat for all other functions to be tested
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    
    return;
}



void testToUpperCase() {
    cout << "Now testing function toUpperCase()" << endl;
    cout << "Expected: 'DIAG @ 11 p.m.' Actual: "
         << toUpperCase("Diag @ 11 p.m") << endl;
    return;
}

void testRemoveNonAlphas() {
    cout << "Now testing function removeNonAlphas()" << endl;
    cout << "Expected: 'Diagpm' Actual: "
         << removeNonAlphas("DIAG @ 11 p.m.") << endl;
    cout << "Expected: 'SEEUAT' Actual: "
         << removeNonAlphas("SEE U AT 7.") << endl;
    return;
}

void testRemoveDuplicate() {
    cout << "Now testing function removeDuplicate()" << endl;
    cout << "Expected: 'HELOWRD', Actual: '"
         << removeDuplicate("HELLOWORD") << "'" << endl;
    cout << "Expected: 'NICE', Actual: '"
         << removeDuplicate("NICE") << "'" << endl;
    cout << "Expected: 'YOUREH', Actual: '"
         << removeDuplicate("YOUREHEREEEE")  << "'" << endl;
    return;
}

void testCharToInt() {
    cout << "Now testing function charToInt()" << endl;
    cout << "Expected: 1, Actual: '" << charToInt('1') << "'" << endl;
    cout << "Expected: 2, Actual: '" << charToInt('2') << "'" << endl;
    cout << "Expected: 3, Actual: '" << charToInt('3')  << "'" << endl;
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '"
         << shiftAlphaCharacter('a',0) << "'" << endl;
    cout << "Expected: 'd', Actual: '"
         << shiftAlphaCharacter('b',2) << "'" << endl;
    cout << "Expected: 'C', Actual: '"
         << shiftAlphaCharacter('X',5) << "'" << endl;
    cout << "Expected: 'V', Actual: '"
         << shiftAlphaCharacter('X',50) << "'" << endl;
    cout << "Expected: 'r', Actual: '"
         << shiftAlphaCharacter('z',70) << "'" << endl;
    cout << "Expected: 'c', Actual: '"
         << shiftAlphaCharacter('d',-27) << "'" << endl;
    cout << "Expected: 'd', Actual: '"
         << shiftAlphaCharacter('d',-26) << "'" << endl;
    cout << "Expected: 'E', Actual: '"
         << shiftAlphaCharacter('D',-25) << "'" << endl;
    cout << "Expected: 'J', Actual: '"
         << shiftAlphaCharacter('X',-300) << "'" << endl;
    cout << "Expected: 'o', Actual: '"
         << shiftAlphaCharacter('s',-30) << "'" << endl;
    return;
}

void testCaesarCipher() {
    cout << "Now testing function caesarCipher()" << endl;
    cout << "Expected: 'Cuuj cu qj jxu Tyqw qj 11 f.c.', Actual: '"
         << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '"
         << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    return;
}


void testVigenereCipher() {
    cout << "Now testing function vigenereCipher()" << endl;
    cout << "Expected: Euyb dv ee lxy Lzrk ll 11 f.g, Actual: "
         << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel", true) << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m. , Actual: "
         << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel", false) << endl;
    
    return;
}

void testFillGrid() {
    char grid1[SIZE][SIZE];
    
    fillGrid(grid1, mixKey("POLYBIUS"));
    cout << "Now testing function fillGrid()" << endl;
    cout << "Expected: " << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "| P | O | L | Y | B | I |" << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "| U | S | A | C | D | E |" << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "| F | G | H | J | K | M |" << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "| N | Q | R | T | V | W |" << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "| X | Z | 0 | 1 | 2 | 3 |" << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "| 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
    cout << " --- --- --- --- --- ---" << endl;
    cout << "Actual: " << endl;
    
    printGrid(grid1);
    
    cout << endl;
}

void testMixKey() {
    cout << "Now testing function mixKey()" << endl;
    cout << "Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789 "
         << "Actual: " << mixKey("POLYBIUS") << endl;
    cout << "Expected: 183ABCDEFGHIJKLMNOPQRSTUVWXYZ0245679 "
         << "Actual: " << mixKey("183") << endl;
}

void testFindInGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Now testing function findInGrid()" << endl;
    cout << "Expected: 00 " << "Actual: " << findInGrid('A', grid) << endl;
    cout << "Expected: 01 " << "Actual: " << findInGrid('B', grid) << endl;
    cout << "Expected: 55 " << "Actual: " << findInGrid('9', grid) << endl;
}

void testPolybiusSquare() {
    char grid[SIZE][SIZE];
    cout << "Now testing function polybiusSquare()" << endl;
    cout << "Expected: 11110533 000102 1533 341411 04113334, Actual: "
         << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true)
         << endl;
    cout << "Expected: 15151311 435445 0511 332215 04151133, Actual: "
         << polybiusSquare(grid, "POLYBIUS", "EECS 183 IS THE BEST", true)
         << endl;
    cout << "Expected: EECS 183 IS THE BEST, Actual: "
         << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false)
         << endl;
    cout << "Expected: EECS 183 IS THE BEST, Actual: "
         << polybiusSquare(grid, "POLYBIUS", "15151311 435445 0511 332215 04151133", false)
         << endl;
    
}

