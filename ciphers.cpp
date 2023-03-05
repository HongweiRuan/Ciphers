/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yutong Liu, Hongwei Ruan
 * merrila, hwruan
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Description: A cipher allows player to choose to encrypt and decrypt among three different methods
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void ciphers() {
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " ;
    string cipherMethod;
    cin >> cipherMethod;
    cipherMethod = toUpperCase(cipherMethod);
    if (cipherMethod == "CAESAR" || cipherMethod == "C") {
        string original = "";
        string key = "";
        string mode = "";
        int digitKey = 0;
        bool crypt = true;
        bool digit = true;
        cout << "Encrypt or decrypt: ";
        cin >> mode;
        mode = toUpperCase(mode);
        if (mode == "ENCRYPT" || mode == "E") {
            crypt = true;
            cout << "Enter a message: ";
            getline(cin, original);
            getline(cin, original);
            cout << "What is your key: ";
            cin >> key;
            for (int i = 0; i < key.length(); i++) {
                if (!isdigit(key.at(i))) {
                    digit = false;
                    cout << "Invalid key!" << endl;
                    break;
                }
            }
            if (digit) {
                digitKey = stoi(key);
                cout << "The encrypted message is: "
                     << caesarCipher(original, digitKey, crypt) << endl;
            }
        } else if (mode == "DECRYPT" || mode == "D") {
            crypt = false;
            cout << "Enter a message: ";
            getline(cin, original);
            getline(cin, original);
            cout << "What is your key: ";
            cin >> key;
            for (int i = 0; i < key.length(); i++) {
                if (!isdigit(key.at(i))) {
                    digit = false;
                    cout << "Invalid key!" << endl;
                    break;
                }
            }
            if (digit) {
                digitKey = stoi(key);
                cout << "The decrypted message is: "
                     << caesarCipher(original, digitKey, crypt) << endl;
            }
        } else {
            cout << "Invalid mode!" << endl;
        }
    } else if (cipherMethod == "VIGENERE" || cipherMethod == "V") {
        string original = "";
        string keyword = "";
        string mode = "";
        bool crypt = true;
        bool digit = false;
        cout << "Encrypt or decrypt: ";
        cin >> mode;
        mode = toUpperCase(mode);
        if (mode == "ENCRYPT" || mode == "E") {
            crypt = true;
            cout << "Enter a message: ";
            getline(cin, original);
            getline(cin, original);
            cout << "What is your key: ";
            getline (cin, keyword);
            for (int i = 0; i < keyword.length(); i++) {
                if (isdigit(keyword.at(i))) {
                    digit = true;
                    cout << "Invalid key!" << endl;
                    break;
                }
            }
            if (!digit) {
                cout << "The encrypted message is: "
                     << vigenereCipher(original, keyword, crypt) << endl;
            }
        } else if (mode == "DECRYPT" || mode == "D") {
            cout << "Enter a message: ";
            getline(cin, original);
            getline(cin, original);
            cout << "What is your key: ";
            getline (cin, keyword);
            crypt = false;
            for (int i = 0; i < keyword.length(); i++) {
                if (isdigit(keyword.at(i))) {
                    digit = true;
                    cout << "Invalid key!" << endl;
                    break;
                }
            }
            if (!digit) {
                cout << "The decrypted message is: "
                     << vigenereCipher(original, keyword, crypt) << endl;
            }
        } else {
            cout << "Invalid mode!" << endl;
        }
    } else if (cipherMethod == "POLYBIUS" || cipherMethod == "P") {
        string original = "";
        string keyword = "";
        string mode = "";
        bool crypt = true;
        bool isAlnum = true;
        char grid[SIZE][SIZE];
        cout << "Encrypt or decrypt: ";
        cin >> mode;
        mode = toUpperCase(mode);
        if (mode == "ENCRYPT" || mode == "E") {
            crypt = true;
            cout << "Enter a message: ";
            getline(cin, original);
            getline(cin, original);
            original = toUpperCase(original);
            for (int i = 0; i < original.size(); i++) {
                if ((!isalpha(original[i])) && (!isdigit(original[i]))
                     && (!isspace(original[i]))) {
                    isAlnum = false;
                    cout << "Invalid message!" << endl;
                    break;
                }
            }
            if (isAlnum) {
                cout << "What is your key: ";
                getline (cin, keyword);
                keyword = toUpperCase(keyword);
                crypt = true;
                for (int i = 0; i < keyword.length(); i++) {
                    if ((!isalpha(keyword[i])) && (!isdigit(keyword[i]))) {
                        isAlnum = false;
                        cout << "Invalid key!" << endl;
                        break;
                    }
                }
                if (isAlnum) {
                    cout << "The encrypted message is: "
                    << polybiusSquare(grid, keyword, original, true) << endl;
                }
            }
        } else if (mode == "DECRYPT" || mode == "D") {
            cout << "Enter a message: ";
            getline(cin, original);
            getline(cin, original);
            original = toUpperCase(original);
            for (int i = 0; i < original.size(); i++) {
                if ((!isalpha(original[i])) && (!isdigit(original[i]))
                     && (!isspace(original[i]))) {
                    isAlnum = false;
                    cout << "Invalid message!" << endl;
                    break;
                }
            }
            if (isAlnum) {
                cout << "What is your key: ";
                getline (cin, keyword);
                keyword = toUpperCase(keyword);
                crypt = false;
                for (int i = 0; i < keyword.length(); i++) {
                    if ((!isalpha(keyword[i])) && (!isdigit(keyword[i]))) {
                        isAlnum = false;
                        cout << "Invalid key!" << endl;
                        break;
                    }
                }
                if (isAlnum) {
                    cout << "The decrypted message is: "
                         << polybiusSquare(grid, keyword, original, crypt) << endl;
                }
            }
        } else {
            cout << "Invalid mode!" << endl;
        }
    } else {
        cout << "Invalid cipher!" << endl;
    }
}

