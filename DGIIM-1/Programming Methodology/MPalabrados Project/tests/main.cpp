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
ostream & operator<<(ostream & os, const Game & game);
istream & operator>>(istream & is, Game &game);

/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    Move move;
    Game game;
    int w = -1, h = -1, wait = 0;
    string lang = "", ifilematch = "", ofilematch = "", word;
    ifstream ifile;
    ofstream ofile;
    bool end = false;
    char c;

    // Auxiliares
    string auxi1, auxi2, param = "";
    bool l_param = false, w_param = false, h_param = false, p_param = false, r_param = false,
            save_param = false, open_param = false, ContinuarPartida = false;
    int height = 0, weight = 0, score = 0;
    bool scorepositivo = game.crosswords.getScore() > 0;
    bool haycruces = game.crosswords.size() >= 1;
    bool primermovimiento = game.acceptedmovements.size() == 0;
    int j = 0;
    

    /// Check arguments

    auxi1 = args[1];
    if (nargs < 5)
        auxi2 = "";
    else
        auxi2 = args[3];

    if (auxi1 == "-open" || auxi2 == "-open") {
        open_param = true;
        ContinuarPartida = true;
        if (nargs > 5)
            errorBreak(ERROR_ARGUMENTS, "");
    }

    // Process arguments

    for (int i = 0; i < nargs; i++) {
        param = args[i];

        if (param == "-l") {
            l_param = true;
            lang = args[i + 1];
        }

        if (param == "-w") {
            w_param = true;
            weight = atoi(args[i + 1]);
        }

        if (param == "-h") {
            h_param = true;
            height = atoi(args[i + 1]);
        }

        if (param == "-r") {
            r_param = true;
            game.random = atoi(args[i + 1]);
        }

        if (param == "-save") {
            save_param = true;
            ofilematch = args[i + 1];
            ofile.open(ofilematch);
            if (ofile.fail())
                errorBreak(ERROR_OPEN, args[i + 1]);
        }

        if (param == "-open") {
            ifilematch = args[i + 1];
            ifile.open(ifilematch);
            if (ifile.fail())
                errorBreak(ERROR_OPEN, args[i + 1]);
        }
    }

    if (ContinuarPartida && (l_param || h_param || r_param))
        errorBreak(ERROR_ARGUMENTS, "");
    if (!ContinuarPartida && ((!l_param) || (!h_param) || (!w_param)))
        errorBreak(ERROR_ARGUMENTS, "");

    /// load data from file, if asked to in arguments

    if (ContinuarPartida) {
        ifile >> game;
        if (ifile.eof())
            errorBreak(ERROR_DATA, ifilematch);
        ifile.close();
    } else {
        game.language.setLanguage(lang);
        if(r_param)
            game.bag.setRandom(game.random);
        game.bag.define(game.language);
        game.player.add(toISO(game.bag.extract(MAXPLAYER)));
        game.tiles.setSize(height, weight);
        game.score = 0;
    }

    // Game's main loop 
    // 1) First set the size of the window according to the size (rows & columns) of
    // the new Tiles

    game.setWindowSize(); //  Set terminal size
    game.doPaint(); //  Display basic information
    game.wait = wait;

    while (!end) {
        // 2) Given the inner data members, it pretty-prints the screen
        game.doPaint();
        setCursorOn(); //    Activamos cursor

        // 3) Reads the movement from cin
        cin >> move;
        setCursorOff(); //  Desactivamos el cursor
        word = move.getLetters();
        if (word == "_") {
            end = true;
        }

        // Checks whether the movement is valid accoring to the letters in player    
        // Finds all the crosswords produced by move and inform about the reasons of rejection
        if (game.player.isValid(word)) {

            if (game.acceptedmovements.size() == 0 && game.score == 0){
                move.setScore(move.findScore(game.language));
                game.crosswords.add(move);
            }
            else
                game.crosswords = game.tiles.findCrosswords(move, game.language);
            //Checks that the crosswords are valid, that is either has a positive score
            //      or produces at least a cross with other existin letters

            if (((game.crosswords.size() == 1 && game.crosswords.getScore() > 0) || (game.crosswords.size() > 1 && game.crosswords.getScore() > 0)) && game.crosswords.get(game.crosswords.size()-1).getScore() > 0) {
                // Once a valid move is detected, the user is asked to confirm

                // call doConfirmCrosswords()

                //     the movement. If he/she does (by pressing Y o y) then the movement
                if (game.doConfirmCrosswords("Accept movement? [Y/N]")) {
                    //     is inserted in tiles and its score is calculated,
                    game.player.extract(word);
                    game.player.add(toISO(game.bag.extract(word.size())));
                    //     otherwise, the move is just ignored
                    // If valid and accepted, computes the score and adds it
                    move.setScore(game.crosswords.getScore());
                    game.acceptedmovements.add(move);
                    //  Para no modificar la función add
                    if (move.isHorizontal()) {
                        j = move.getCol() - 1;
                        for (int i = 0; i < move.getLetters().size(); i++) {
                            while (game.tiles.get(move.getRow() - 1, j) != EMPTY)
                                j++;
                            game.tiles.set(move.getRow() - 1, j, move.getLetters()[i]);
                            j++;
                        }
                    }else{
                        j = move.getRow()-1;
                        for(int i = 0; i < move.getLetters().size(); i++){
                            while(game.tiles.get(j,move.getCol()-1) != EMPTY)
                                j++;
                            game.tiles.set(j,move.getCol()-1,move.getLetters()[i]);
                            j++;
                        }
                    }
                    game.score += move.getScore();
                    // Show crosswords found
                }
            } else {
                // If it is a bad crosswords
                // call doBadCrosswords()

                if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == BOARD_OVERFLOW) { //  Si devuelve el cruce vacío, entonces se ha dado BOARD_OVERFLOW
                    game.doBadCrosswords("Board overflow");
                    move.setScore(BOARD_OVERFLOW);
                    game.rejectedmovements.add(move);
                } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == NOT_FREE) {
                    game.doBadCrosswords("Non existent word");
                    move.setScore(NOT_FREE);
                    game.rejectedmovements.add(move);
                } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == NONEXISTENT_WORD) {
                    game.doBadCrosswords("Non existent word");
                    move.setScore(NONEXISTENT_WORD);
                    game.rejectedmovements.add(move);
                } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == MISSING_CROSSWORDS) {
                    game.doBadCrosswords("Missing crossword");
                    move.setScore(MISSING_CROSSWORDS);
                    game.rejectedmovements.add(move);
                } else {
                    game.doBadCrosswords("Bad crosswords found");
                    game.rejectedmovements.add(move);
                }
            }
        } else if(word != "_") {
            // If not valid w.r.t. player
            // call doBadCrosswords()     
            game.doBadCrosswords("Infeasible word");
            move.setScore(INFEASIBLE_WORD);
            game.rejectedmovements.add(move);
        }
        
        game.crosswords.clear();
        j = 0;

    }
    // End of game
    // Save file or print screen

    if (save_param) {
        ofile << PASSWORD << endl;
        ofile << game;
        if (ofile.eof())
            errorBreak(ERROR_DATA, "");
        ofile.close();
    } else {
        cout << endl << "%%%OUTPUT" << endl;
        cout << game;
    }

    return 0;
}

ostream & operator<<(ostream & os, const Game & game) {
    os << game.score << endl << game.language.getLanguage() << endl;
    game.tiles.print(os);
    os << game.player.size() << " " << toUTF(game.player.to_string()) << endl;
    os << game.bag.size() << " " << toUTF(game.bag.to_string()) << endl;

    return os;
}

istream & operator>>(istream & is, Game &game) {
    string auxiliar = "", lang = "";
    int relleno;
    is >> auxiliar;

    if (auxiliar != PASSWORD)
        errorBreak(ERROR_DATA, "");
    is >> game.score >> lang;
    if (is.eof())
        return is;

    game.language.setLanguage(lang);
    is >> game.tiles;
    is >> relleno;
    is >> auxiliar;
    if (is.eof())
        return is;

    game.player.add(toISO(auxiliar));
    is >> relleno >> auxiliar;
    if (is.eof())
        return is;
    game.bag.set(toISO(auxiliar));

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

