/**
 * @file move.cpp
 * @author DECSAI
 * @note To be implemented by students
 */
#include <string>
#include "move.h"

using namespace std;

Move::Move() {
    row = 0;
    column = 0;
    score = 0;
    letters = "";
    ishorizontal = true;
}

void Move::set(int r, int c, char h, const std::string l) {
    setRow(r);
    setCol(c);
    setLetters(l);
    setHorizontal(h);
}

void Move::setRow(int r) {
    if (r >= 0)
        row = r;
}

void Move::setCol(int c) {
    if (c >= 0)
        column = c;
}

void Move::setHorizontal(char h) {
    if (h == 'H' || h == 'h')
        ishorizontal = true;
    else if (h == 'V' || h == 'v')
        ishorizontal = false;
}

void Move::setLetters(const std::string l) {
    letters = normalizeWord(l);
}

void Move::setScore(int s) {
    score = s;
}

int Move::getScore() const {
    return score;
}

int Move::getRow() const {
    return row;
}

int Move::getCol() const {
    return column;
}

bool Move::isHorizontal() const {
    return ishorizontal;
}

std::string Move::getLetters() const {
    return letters;
}

int Move::findScore(const Language &l) {
    setScore(0);
    if (l.query(getLetters()))
        for (int i = 0; i < getLetters().length(); i++)
            score += l.getScore(getLetters()[i]);
    else
        setScore(-1);
    return score;
}

void Move::print(std::ostream &os) const {

    if (isHorizontal() == 1)
        os << 'H' << " ";
    else
        os << 'V' << " ";
    os << getRow() << " ";
    os << getCol() << " ";
    os << getLetters();
}

void Move::read(std::istream &is) {
    char h;
    int c, r;
    string l;

    is >> h;
    is >> r;
    is >> c;
    is >> l;
    set(r, c, h, l);
}

std::istream& operator>>(std::istream& is, Move & m){
    m.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Move &m){
    m.print(os);
    return os;
}