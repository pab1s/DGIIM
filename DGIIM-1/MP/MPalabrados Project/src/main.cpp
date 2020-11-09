/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <string>
#include <cassert>
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include "language.h"
#include "bag.h"
#include "player.h"
#include "move.h"
#include "movelist.h"
#include "tiles.h"
#include "window.h"
#include "AnsiTerminal.h"
using namespace std;


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
#define GENERAL_ERROR 4
#define PASSWORD "MPALABRADOS-V1"


/**
 * @brief Reports an important error and exits the program
 * @param errorcode An integer representing the error detected, which is represented
 * by several symbolic constants: ERROR_ARGUMENTS, ERROR_OPEN y ERROR_DATA
 * @param errorinfo Additional information regarding the error: "" (empty string) for 
 * errors parsing the arguments to main() and, for the case of errors opening or 
 * reading/writing data, the name of the file thas has failed.
 */
void errorBreak(int errorcode, const string & errorinfo);

/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    Move move;
    Game game;
    int w = -1, h = -1, wait = 0;
    bool idparam = false, langparam = false, widthparam = false, 
         heightparam = false, savedata = false,newmatch = true;
    string word = "", lang = "", imatchname = "", omatchname = "", param = "";
    ifstream imatch;
    ofstream omatch;
    istream *input = &cin;
    ostream *output = &cout;
    bool end = false;

    /// Check arguments
    for (int i = 1; i < nargs; i += 2) {
        param = args[i];
        if (param == "-l") {
            langparam = true;
            lang = args[i + 1];
        }
        if (param == "-w") {
            widthparam = true;
            w = atoi(args[i + 1]);
        }
        if (param == "-h") {
            heightparam = true;
            h = atoi(args[i + 1]);
        }
        if (param == "-r") {
            idparam = true;
            game.random = atoi(args[i + 1]);
        }
        if (param == "-save") {
            savedata = true;
            omatchname = args[i + 1];
            omatch.open(omatchname);
            if (omatch.fail())
                errorBreak(ERROR_OPEN, omatchname);
        }
        if (param == "-open") {
            newmatch = false;
            imatchname = args[i + 1];
            imatch.open(imatchname);
            if (imatch.fail())
                errorBreak(ERROR_OPEN, imatchname);
        }
    }

    // Process arguments
    if (!newmatch && nargs > 7)
        errorBreak(ERROR_ARGUMENTS, "");
    if (!newmatch && (langparam || widthparam || heightparam || idparam))
        errorBreak(ERROR_ARGUMENTS, "");
    if (newmatch && (!langparam || !widthparam || !heightparam))
        errorBreak(ERROR_ARGUMENTS, "");

    // load data from file, if asked to in arguments
    if (!newmatch) {
        input = &imatch;
        *input >> game;
        if(imatch.eof())
            errorBreak(ERROR_DATA,imatchname);
        imatch.close();

    } else if (newmatch) {
        game.language.setLanguage(lang);
        assert(game.random >= 0);
        game.bag.setRandom(game.random);
        game.bag.define(game.language);

        game.player.clear();
        game.player.add(game.bag.extract(MAXPLAYER));

        game.tiles.setSize(h, w);
        game.score = 0;
    }

    // Game's main loop

    // 1) First set the size of the window according to the size (rows & columns) of
    // the new Tiles
    game.setWindowSize();
    game.doPaint();
    game.wait = wait;

    while (!end) {
        // 2) Given the inner data members, it pretty-prints the screen
        game.doPaint();
        setCursorOn();

        // 3) Reads the movement from cin
        cin >> move;
        setCursorOff();
        word = move.getLetters();
        
        if (word == "_") {
            end = true;
        }

        // Checks whether the movement is valid accoring to the letters in player    
        // Finds all the crosswords produced by move and inform about the reasons of rejection
        else if (game.player.isValid(word)) {
            game.crosswords.clear();

            if (game.acceptedmovements.size() == 0 && game.score == 0){
                if ((move.getCol() > 0 && move.getRow() > 0 && move.getCol() < game.tiles.getHeight() && move.getRow() < game.tiles.getWidth()) &&
                   ((move.isHorizontal() && (move.getLetters().length()+move.getRow() < game.tiles.getWidth())) ||
                   (!move.isHorizontal() && (move.getLetters().length()+move.getCol() < game.tiles.getHeight())))
                    ) {
                    move.setScore(move.findScore(game.language));
                    game.crosswords.add(move);
                } else {
                    move.setScore(BOARD_OVERFLOW);
                    game.crosswords.add(move);
                }
            }
            else {
                game.crosswords = game.tiles.findCrosswords(move, game.language);
                for (int k=0; k<game.crosswords.size(); k++) {
                    bool existent = game.language.query(game.crosswords.get(k).getLetters());
                    if (!existent) {
                        move.setScore(NONEXISTENT_WORD);
                    }
                }
            }
            //Checks that the crosswords are valid, that is either has a positive score
            //      or produces at least a cross with other existin letters

            if (((game.crosswords.size() == 1 && game.crosswords.getScore() > 0) || (game.crosswords.size() > 1 && game.crosswords.getScore() > 0)) && game.crosswords.get(game.crosswords.size()-1).getScore() > 0) {
                // Once a valid move is detected, the user is asked to confirm
                // call doConfirmCrosswords()
                //     the movement. If he/she does (by pressing Y o y) then the movement
                //     is inserted in tiles and its score is calculated,
                //     otherwise, the move is just ignored
                // If valid and accepted, computes the score and adds it
                //     otherwise, the move is just ignored
                // If valid and accepted, computes the score and adds it
                //  Para no modificar la función add
                // Show crosswords found
                if (game.doConfirmCrosswords("Accept movement? [Y/N]")) {
                    game.player.extract(word);
                    game.player.add(toISO(game.bag.extract(word.size())));
                    move.setScore(game.crosswords.getScore());
                    move.setScore(game.crosswords.getScore());
                    game.acceptedmovements.add(move); 
                    game.tiles.add(game.crosswords.get(game.crosswords.size()-1));
                    game.score += move.getScore();
                    
                }
            } else {
            // If it is a bad crosswords
            // call doBadCrosswords()
                switch (game.crosswords.getScore()) {
                    
                    case UNKNOWN:
                        game.doBadCrosswords("Bad crosswords found");
                        game.rejectedmovements.add(move);
                        break;
                        
                    case BOARD_OVERFLOW:
                        game.doBadCrosswords("Board overflow");
                        move.setScore(BOARD_OVERFLOW);
                        game.rejectedmovements.add(move);
                        break;
                        
                    case NONEXISTENT_WORD:
                        game.doBadCrosswords("Non existent word");
                        move.setScore(NONEXISTENT_WORD);
                        game.rejectedmovements.add(move);
                        break;
                        
                    case NOT_FREE:
                        game.doBadCrosswords("Not free");
                        move.setScore(NOT_FREE);
                        game.rejectedmovements.add(move);
                        break;
                        
                    case MISSING_CROSSWORDS:
                        game.doBadCrosswords("Missing crosswords");
                        move.setScore(MISSING_CROSSWORDS);
                        game.rejectedmovements.add(move);
                        break;
                }
            }
        // If not valid w.r.t. player
        // call doBadCrosswords()
        } else {
            move.setScore(INFEASIBLE_WORD);
            game.crosswords.add(move);
            game.doBadCrosswords("Infeasible word");
            game.rejectedmovements.add(move);
        }
    }
    // End of game
    // Save file or print screen
    if (savedata) {
        output = &omatch;
        *output << PASSWORD << endl << game;
        omatch.close();
    } else {
        output = &cout;
        *output << endl << "%%%OUTPUT" << endl << game;
    }
    input = nullptr;
    output = nullptr;

    return 0;
}

ostream & operator<<(ostream & os, const Game & game) {
    os << game.score << endl;
    os << toUTF(game.language.getLanguage()) << endl;
    game.tiles.print(os);
    os << game.player.size() << " " << toUTF(game.player.to_string()) << endl;
    os << game.bag.size() << " " << toUTF(game.bag.to_string()) << endl;
    return os;
}

istream & operator>>(istream & is, Game &game) {
    int *trash = new int;
    string str_aux = "";

    is >> str_aux;
    if (str_aux != PASSWORD)
        errorBreak(ERROR_DATA, "");
    is >> game.score;
    is >> str_aux;
    game.language.setLanguage(str_aux);
    if (is.eof())
      return is;

    game.tiles.read(is);

    is >> *trash >> str_aux;
    if ((is).eof())
        return is;
    game.player.add(toISO(str_aux));

    is >> *trash >> str_aux;
    if ((is).eof())
        return is;
    game.bag.set(toISO(str_aux));

    delete trash;

    return is;
}

void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch (errorcode) {
        case ERROR_ARGUMENTS:
            cerr << "Error in call. Please use either:" << endl;
            cerr << "-l <language> -w <width> -h <height> [-r <randomnumber> -save <matchfile>]" << endl;
            cerr << "-open <matchfile> [-save <matchfile>]" << endl;
            break;
        case ERROR_OPEN:
            cerr << "Error opening file " << errordata << endl;
            break;
        case ERROR_DATA:
            cerr << "Data error in file " << errordata << endl;
            break;
        case GENERAL_ERROR:
            cerr << "Error: " << errordata << endl;
            break;
    }
    std::exit(1);
}

