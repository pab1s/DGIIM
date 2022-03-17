/**
 * @file movelist.cpp
 * @author DECSAI
 * @note To be implemented by students
 * @warning Complete the code
 *  */

#include <iostream>
#include <cassert>
#include "movelist.h"
#include "move.h"
#include "language.h"

using namespace std;

Movelist::Movelist() {
    moves = nullptr;
    nMove = 0;
}

Movelist::Movelist(int nmov) {
    moves = nullptr;
    allocate(nmov);
    nMove = nmov;
}

Movelist::Movelist(const Movelist& orig) {
    moves = nullptr;
    nMove = 0;
    copy(orig);
}

Movelist::~Movelist() {
    deallocate();
}

Move Movelist::get(int p) const {
    assert(p >= 0 && p < size());
    return moves[p];
}

void Movelist::set(int p, const Move& m) {
    assert(p >= 0 && p < size());
    moves[p] = m;
}

int Movelist::find(const Move& mov) const {
    for (int i = 0; i < size(); i++)
        if (get(i).getCol() == mov.getCol() && get(i).getRow() == mov.getRow() &&
            get(i).getLetters() == mov.getLetters() && get(i).isHorizontal() == mov.isHorizontal())
            return i;   
    
    return -1;
}

void Movelist::add(const Move& mov) {
    nMove++;
    Move *aux = new Move[nMove];
    for (int i = 0; i < size() - 1; i++)
        aux[i] = get(i);
    aux[nMove - 1] = mov;
    
    deallocate();
    moves = aux;
}

void Movelist::remove(int p) {
    assert(p >= 0 && p < size());
    nMove--;
    Move *aux = new Move[nMove];
    
    for (int i = p; i < size(); i++)
        moves[i] = moves[i + 1];
    for (int i = 0; i < nMove; i++)
        aux[i] = moves[i];
    
    deallocate();
    moves = aux;
}

void Movelist::remove(const Move& mov) {
    int pos = find(mov);
    if (pos != -1)
        remove(pos);
}

void Movelist::zip(const Language& l) {
    int i = 0;
    while (i < size()) {
        if (get(i).getLetters().length() < 2 || !(l.query(get(i).getLetters()))) {
            remove(i);
        } else {
            i++;
        }
    }
}

int Movelist::getScore() const {
    int suma = 0;
    int score = 0;
    for (int i = 0; i < size(); i++) {
        score = get(i).getScore();
        if (score < 0)
            return -1;
        else
            suma += score;
    }
    return suma;
}

void Movelist::clear() {
    deallocate();
    moves = nullptr;
    nMove = 0;
}

Movelist Movelist::operator=(const Movelist& orig) {
    if (this != &orig)
        copy(orig);
    return *this;
}

bool Movelist::read(std::istream& is) {
    Move mov;
    string l = "";
    char h = 'H';
    int col = 0, row = 0;
    
    do {
        if (is.eof() || !is)
            return false;
        else {
            is >> h;
            is >> row;
            is >> col;
            is >> l;
            
            if (l != "@") {
                mov.set(row, col, h, l);
                add(mov);
            }
        }
    } while (l != "@");
    
    return true;
}

bool Movelist::print(std::ostream &os, bool scores) const {
    bool res = true;
    for (int i = 0; i < size() && res; i++) {
        get(i).print(os);
        if (scores)
            os << " (" << get(i).getScore() << ") - ";
        else
            os << " - ";
        if (os.bad())
            res = false;
    }
    return res;
}

void Movelist::allocate(int n) {
    if (moves != nullptr)
        deallocate();
    moves = new Move[n];
}

void Movelist::deallocate() {
    if (moves != nullptr) {
        delete[] moves;
    }
    moves = nullptr;
}

void Movelist::copy(const Movelist& ml) {
    if (moves != nullptr)
        deallocate();
    nMove = ml.size();
    allocate(nMove);
    for (int i = 0; i < nMove; i++)
        set(i, ml.get(i));
}

std::ostream & operator<<(std::ostream & os, const Movelist & i){
    i.print(os);
    return os;
}


std::istream & operator>>(std::istream & is, Movelist & i){
    i.read(is);
    return is;
}