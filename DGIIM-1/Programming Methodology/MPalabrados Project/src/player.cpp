/**
 * @file player.cpp
 * @author DECSAI
 * @note To be implemented by students
 */

#include <assert.h>
#include <cstring>
#include "player.h"

/// See http://www.cplusplus.com/reference/cstring/ for details about cstrings
using namespace std;

/**
 * @brief Removes a position from a cstring
 * @param cstr The cstring
 * @param pos The position
 * @return The cstring is modified
 */
void removeCString(char *cstr, int pos);

/**
 * @brief Sort a cstring from A to Z
 * @param cstr The cstring
 * @return The cstring is modified
 */
void sortCString(char *cstr);

//Main methods

Player::Player() {
    clear();
}

int Player::size() const {
    int n = strlen(letters);
    return n;
}

std::string Player::to_string() const {
    string s = "";
    for (int i = 0; i < strlen(letters); i++)
        s += letters[i];
    return s;
}

void Player::clear() {
    letters[0] = '\0';
}

bool Player::isValid(const string s) const {
    char letras[MAXPLAYER + 1];
    
    for (int i=0; i<size(); i++)
        letras[i] = letters[i];
    
    for (int i = 0; i < s.size(); i++) {
        bool buscando = true;
        
        for (int j = 0; letras[j] != '\0'; j++) {
            if (letras[j] == s[i] && buscando) {
                buscando = false;
                removeCString(letras, j);
            }
        }
        if (buscando)
            return false;
    }
    return true;
}

bool Player::extract(const std::string s) {
    int nletras = s.size();
    bool found = false,
            done = false;

    if (!isValid(s)) {
        done = false;
    } else {
        for (int i = 0; i < nletras; i++) {
            for (int j = 0; j < size(); j++) {
                if (s[i] == letters[j] && !found) {
                    removeCString(letters, j);
                    found = true;
                }
            }
            found = false;
        }
        done = true;
    }

    return done;
}

void Player::add(string frombag) {
    assert((strlen(letters) + frombag.size()) <= MAXPLAYER);
    int tamanio = size();
    for (int i = size(); i < MAXPLAYER + 1; i++)
        letters[i] = frombag[i - tamanio];
    sortCString(letters);
}

//Auxiliary functions

void removeCString(char *cstr, int pos) {
    for (int i = pos; i < strlen(cstr); i++)
        cstr[i] = cstr[i + 1];

}

void sortCString(char *cstr) {

    int n = strlen(cstr);

    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (cstr[j] > cstr[j + 1]) {
                int aux = cstr[j];
                cstr[j] = cstr[j + 1];
                cstr[j + 1] = aux;
            }
}
