/**
 * @file bag.cpp
 * @author DECSAI
 * @note To be implemented by students except function shuffle()
 */
#include <fstream>
#include <cassert>
#include <random>
#include <algorithm>
#include <language.h>
#include "bag.h"

using namespace std;

/**
 * @brief Randomly reorders a vector of char
 * @param s Vector of char
 * @param n Number of char in the vector
 * @author DECSAI
 */
void shuffleVector(char *s, int n, int id);

/**
 * @brief Removes a position from a vector and compacts the remaining positions, 
 * thus reducing its size
 * @param s Vector of char
 * @param n Number of chars
 * @param p Position to remove
 */
void removeVector(char *s, int &n, int p);


// Main methods

Bag::Bag() {
    nletters = 0;
    id = time(NULL);
}

char Bag::get(int p)const {
    char letter;
    assert(p <= size() && p >= 0);
    letter = letters[p];
    return letter;
}

void Bag::set(int p, char c) {
    assert(p <= size() && p >= 0);
    letters[p] = c;
}

void Bag::setRandom(int id_) {
    id = id_;
}

/*void Bag::define(Language &l) {
    char letter;
    int f = 0, counter = 0;
    string s = l.getLetterSet();
    
    for (int i=0; i<s.length(); i++) {
        letter = s[i];
        f = l.getFrequency(letter);
        
        for (int j=0; j<f; j++) {
            letters[counter] = letter;
        counter++;
        }
    }

    nletters = counter;
    shuffleVector(letters, nletters, id);
}*/

int Bag::size() const {
    return nletters;
}

string Bag::to_string() const {
    string s = "";
    for (int i = 0; i < nletters; i++)
        s += letters[i];
    return s;
}

void Bag::set(string s) {
    for (int i = 0; i < s.length(); i++)
        letters[i] = s[i];

    nletters = s.length();
}

string Bag::extract(int n) {
    int nletras = nletters;
    string s = "";
    if (nletras >= n) {
        for (int i = 0; i < n; i++) {
            s += letters[0];
            removeVector(letters, nletters, 0);
        }
    }

    if (nletras < n) {
        for (int i = 0; i < nletras; i++) {
            s += letters[0];
            removeVector(letters, nletters, 0);
        }
    }

    return s;
}

// Auxiliary functions 

void shuffleVector(char *s, int n, int id) {
    vector <char> aux(s, s + n);
    unsigned seed = id;
    std::shuffle(aux.begin(), aux.end(), std::default_random_engine(seed));
    for (int i = 0; i < n; i++)
        s[i] = aux[i];
}

void removeVector(char *s, int &n, int p) {
    for (int i = p; i < n; i++)
        s[i] = s[i + 1];
    n--;
}

void Bag::define(Language &l) {
    ifstream ifile("build/bags.data");
    string mybag, mylang;
    int myrandom;
    bool found = false;

    if (!ifile) return;
    while (!ifile.eof() && !found) {
        ifile >> mylang >> myrandom >> mybag;
        if (ifile && mylang == l.getLanguage() && myrandom == this->id)
            found = true;
    }
    ifile.close();
    if (found)
        this->set(toISO(mybag));
    else
        this->set("");
}