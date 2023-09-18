/* Project 1: Program to read a regular automata from a file and
              determine if a word is in the language of the automaton.
   Author: Pablo Olivares
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to split the input into tokens
vector<string> split(string line) {
    vector<string> tokens;
    string token;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            tokens.push_back(token);
            token = "";
        } else {
            token += line[i];
        }
    }
    tokens.push_back(token);
    return tokens;
}

class state {
public:
    bool isFinal;
    vector<int> transitions;

    state(bool isFinal, vector<int> transitions) {
        this->isFinal = isFinal;
        this->transitions = transitions;
    }

    int next(vector<string> inputs, char input) {
        int st = -1;
        for (int i = 0; i < inputs.size(); i++) {
            if (inputs[i][0] == input) {
                st = transitions[i];
                break;
            }
        }

        return st;
    }
};

int main(int argc, char *argv[]) {
  // Open the file and read the document line by line
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    string line;
    vector<state> q;
    int row = 0;

    // Get the inputs of the automata & the final states
    getline(file, line);
    vector<string> inputs = split(line);
    getline(file, line);
    vector<string> areFinal = split(line);
    
    // Get the states of the automata
    while (getline(file, line)) {
        bool isFinal = false;
        vector<string> trans = split(line);

        // Check if the state is final
        for (int i = 0; i < areFinal.size(); i++) {
            if (row == stoi(areFinal[i])) {
                isFinal = true;
                break;
            }
        }
        
        // Convert the string transitions to integers
        vector<int> t;
        for(int i = 0; i < trans.size(); ++i) {
            t.push_back(stoi(trans[i]));
        }
        
        // Create the state
        state st(isFinal, t);
        q.push_back(st);
        ++row;
    }

    // Close the file
    file.close();

    // Print the automata table
    for (int i = 0; i < q.size(); i++) {
        cout << "State " << i << ": ";
        for (int j = 0; j < inputs.size(); j++) {
            cout << inputs[j] << " -> " << q[i].transitions[j] << ", ";
        }
        cout << endl;
    }

    // Introduce a word to check if it is accepted
    string word;
    cout << "Introduce a word: ";
    cin >> word;

    // Check if the word is accepted
    int currentState = 0;
    int i = 0;
    while (i < word.length() && currentState != -1) {
        char input = word[i];
        currentState = q[currentState].next(inputs, input);
        ++i;
    }

        if (currentState != -1 && q[currentState].isFinal) {
            cout << "The word is accepted" << endl;
        } else {
            cout << "The word is not accepted" << endl;
        }

    return 0;
}