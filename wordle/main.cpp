#include <iostream>
#include <ostream>
#include <cstring>

#include "functions_file.h"
using namespace std;

int main(int argc, char* argv[]) {
    int count;
    string wordList;
    string allowedWords;

    if (argc == 4) {
        count = stoi(argv[1]);
        wordList = argv[2];
        allowedWords = argv[3];

        mainMenu(count, wordList, allowedWords); 
    }

    else {
        cerr << "Invalid number of arguments" << endl;
        exit(0);
    }

    return 0;
}