/**
 * @file tiles.h
 * @author Pablo Olivares
 * @note Implemented by student
 */

#include <iostream>
#include <cassert>
#include "language.h"
#include "movelist.h"
#include "move.h"
#include "tiles.h"

using namespace std;

Tiles::Tiles() {
    cell = nullptr;
    rows = 0;
    columns = 0;
}

Tiles::Tiles(int r, int c) {
    cell = nullptr;
    allocate(r, c);
}

Tiles::Tiles(const Tiles & orig) {
    cell = nullptr;
    copy(orig);
}

Tiles::~Tiles() {
    deallocate();
}

// Basic methods

void Tiles::setSize(int r, int c) {
    if (cell != nullptr)
        deallocate();
    allocate(r, c);
}

Tiles& Tiles::operator=(const Tiles& orig) {
    if (this != &orig)
        copy(orig);
    return *this;
}

int Tiles::getWidth() const {
    return columns;
}

int Tiles::getHeight() const {
    return rows;
}

char Tiles::get(int r, int c) const {
    assert(r >= 0 && r < getHeight());
    assert(c >= 0 && c < getWidth());

    return cell[r][c];
}

void Tiles::set(int r, int c, char l) {
    if (r >= 0 && r < getHeight() &&
            c >= 0 && c < getWidth())
        cell[r][c] = l;
}

void Tiles::add(const Move& m) {
    int r = m.getRow() - 1, c = m.getCol() - 1,
            size = m.getLetters().size();
    char l[size];
    bool horizontal = m.isHorizontal();

    for (int n = 0; n < size; n++)
        l[n] = m.getLetters()[n];

    if (horizontal)
        for (int j = 0; j < size; j++)
            set(r, j + c, l[j]);

    else if (!horizontal)
        for (int i = 0; i < size; i++)
            set(i + r, c, l[i]);
}

void Tiles::print(std::ostream &os) const {
    os << getHeight() << " " << getWidth() << std::endl;
    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++)
            os << toUTF(get(i, j)) << " ";
        os << std::endl;
    }
    os << std::endl;
}

bool Tiles::read(std::istream &is) {
    char letter = EMPTY;
    int r = 0, c = 0;

    is >> r >> c;
    allocate(r, c);

    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            is >> letter;
            set(i, j, letter);
            if (is.eof())
                return false;
        }
    }
    return true;
}

Move Tiles::findMaxWord(int r, int c, bool hrz) const {
    Move m, orig;
    string word = "";
    int j = 0;
    orig.setRow(r);
    orig.setCol(c);
    
    //Horizontal
    if (hrz) {
        m.setHorizontal('H');
        m.setRow(r + 1);

        while (c - 1 >= 0 && get(r, c - 1) != EMPTY)
            c--;

        m.setCol(c + 1);

        while (c + 1 <= getWidth() && (orig.getCol() == c || get(r, c) != EMPTY)) {
            if (get(r, c) != EMPTY)
                word += get(r, c);
            else if (orig.getCol() == c)
                word += '_';
            c++;
            j++;
        }
        
    //Vertical
    } else if (!hrz) {

        m.setHorizontal('V');
        m.setCol(c + 1);

        while (r - 1 >= 0 && get(r - 1, c) != EMPTY)
            r--;

        m.setRow(r + 1);

        while (r + 1 <= getHeight() && (orig.getRow() == r || get(r, c) != EMPTY)) {
            if (get(r, c) != EMPTY)
                word += get(r, c);
            else if (orig.getRow() == r)
                word += '_';
            r++;
            j++;
        }
    }

    m.setLetters(word);

    return m;
}

Movelist Tiles::findCrosswords(const Move &m, const Language &l) const {
    Movelist crosslist;
    Move movement = m, maxword;
    string word = "", letters = movement.getLetters(), aux = "";
    int i = 0, ncross = 0, r = movement.getRow() - 1, c = movement.getCol() - 1;

    //Fuera de los límites (-2)
    if (movement.getCol() > getWidth() || movement.getCol() < 0 ||
            movement.getRow() > getHeight() || movement.getRow() < 0) {
        movement.setScore(BOARD_OVERFLOW);
        crosslist.add(movement);
        return crosslist;
    }

    //Empieza en celda ocupada (-5)
    if (get(r, c) != EMPTY) {
        movement.setScore(NOT_FREE);
        crosslist.add(movement);
        return crosslist;
    }

    //Comprobación palabra existente
    //Horizontal
    
    //Buscamos el origen de la palabra
    if (movement.isHorizontal()) {
        movement.setRow(r + 1);
        while (c - 1 >= 0 && get(r, c - 1) != EMPTY) {
            c--;
        }
        movement.setCol(c + 1);
        
        //Añadimos las letras del player y sus cruces
        while (i < letters.length() && c < getWidth() && c >= 0) {
            if (get(r, c) == EMPTY) {
                word += letters[i];
                if ((r + 1 < getWidth() && get(r + 1, c) != EMPTY) || (r - 1 > 0 && get(r - 1, c) != EMPTY)) {
                    maxword = findMaxWord(r, c, !movement.isHorizontal());
                    aux = maxword.getLetters();
                    for (int k = 0; k < aux.length(); k++)
                        if (aux[k] == '_')
                            aux[k] = letters[i];
                    maxword.setLetters(aux);
                    maxword.setScore(maxword.findScore(l));
                    crosslist.add(maxword);
                    ncross++;
                }
                i++;
            } else {
                word += get(r, c);
                ncross++;
            }
            c++;
        }
        
        //Completamos la palabra hasta el final
        while (c < getWidth() && get(r, c) != EMPTY) {
            word += get(r, c);
            c++;
        }
    }
    
    //Vertical (Analogo al horizontal)
    if (!movement.isHorizontal()) {
        movement.setCol(c + 1);
        while (r - 1 >= 0 && get(r - 1, c) != EMPTY) {
            r--;
        }
        movement.setRow(r + 1);

        while (i < letters.length() && r < getHeight() && r >= 0) {
            if (get(r, c) == EMPTY) {
                word += letters[i];
                if ((c + 1 < getHeight() && get(r, c + 1) != EMPTY) || (c - 1 > 0 && get(r, c - 1) != EMPTY)) {
                    maxword = findMaxWord(r, c, !movement.isHorizontal());
                    aux = maxword.getLetters();
                    for (int k = 0; k < aux.length(); k++)
                        if (aux[k] == '_')
                            aux[k] = letters[i];
                    maxword.setLetters(aux);
                    maxword.setScore(maxword.findScore(l));
                    crosslist.add(maxword);
                    ncross++;
                }
                i++;
            } else {
                word += get(r, c);
                ncross++;
            }
            r++;
        }

        if ((r >= getHeight() || r < 0 || c >= getWidth() || c < 0) && i != letters.length() ) {
            movement.setScore(BOARD_OVERFLOW);
            crosslist.add(movement);
            return crosslist;
        }

        while (r < getHeight() && get(r, c) != EMPTY) {
            word += get(r, c);
            r++;
        }
    }

    if (word != letters)
        ncross++;

    movement.setLetters(word);
    movement.setScore(movement.findScore(l));
    crosslist.add(movement);

    //La palabra no existe (-3)
    if (!l.query(word)) {
        movement.setScore(NONEXISTENT_WORD);
        crosslist.add(movement);
        return crosslist;
    }

    //La palabra no tiene cruces (-6)
    if (ncross == 0) {
        movement.setScore(MISSING_CROSSWORDS);
        crosslist.add(movement);
        return crosslist;
    }

    return crosslist;
}
//Private functions

void Tiles::allocate(int r, int c) {
    if (cell != nullptr)
        deallocate();

    rows = r;
    columns = c;
    cell = new char*[r];
    for (int i = 0; i < r; i++)
        cell[i] = new char[c];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cell [i][j] = EMPTY;
}

void Tiles::deallocate() {
    if (cell != nullptr) {
        for (int i = 0; i < rows; i++)
            delete[] cell[i];
        delete []cell;
    }

    cell = nullptr;
    rows = columns = 0;
}

void Tiles::copy(const Tiles& t) {
    if (cell != nullptr)
        deallocate();

    allocate(t.getHeight(), t.getWidth());

    for (int i = 0; i < t.getHeight(); i++)
        for (int j = 0; j < t.getWidth(); j++)
            set(i, j, t.get(i, j));
}
