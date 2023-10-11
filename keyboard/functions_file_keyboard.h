#ifndef FUNCTIONS_FILE_KEYBOARD_H
#define FUNCTIONS_FILE_KEYBOARD_H

#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>
#include <chrono>
#include <thread>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"

int readGamePulse();
void runKeyboard();
void printKeyboard(std::map<char, char> guessedWords);
std::vector<std::string> readKeyboardFile(std::string);
std::vector<char> splitGuesses(std::vector<std::string> keyboardFileContent);
std::vector<char> splitColors(std::vector<std::string> keyboardFileContent);

int readGamePulse() {
    int gamePulse;
    std::ifstream file;
    file.open("../wordle/gamePulse.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            gamePulse++;
        }
    }
    file.close();
    return gamePulse;
}


void runKeyboard(std::string filename) {
    std::map<char, char> guessedWords { { 'A', 'w'}, { 'B', 'w' }, { 'C', 'w' }, { 'D', 'w' }, { 'E', 'w' }, { 'F', 'w' }, { 'G', 'w' }, { 'H', 'w' }, { 'I', 'w' }, { 'J', 'w' }, { 'K', 'w' }, { 'L', 'w' }, { 'M', 'w' }, { 'N', 'w' }, { 'O', 'w' }, { 'P', 'w' }, { 'Q', 'w' }, { 'R', 'w' }, { 'S', 'w' }, { 'T', 'w' }, { 'U', 'w' }, { 'V', 'w' }, { 'W', 'w' }, { 'X', 'w' }, { 'Y', 'w' }, { 'Z', 'w' }};

    std::vector<std::string> keyboardFileContent;
    keyboardFileContent = readKeyboardFile(filename);

    std::vector<char> guesses;
    guesses = splitGuesses(keyboardFileContent);
    std::vector<char> colors;
    colors = splitColors(keyboardFileContent);

    for (int i = 0; i < guesses.size(); i++) {
        guessedWords[guesses[i]] = colors[i];
    }

    printKeyboard(guessedWords);
}

void printKeyboard(std::map<char, char> guessedWords) {
    system("clear");

    if (guessedWords['Q'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['Q'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['Q'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['Q'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['W'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['W'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['W'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['W'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['E'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['E'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['E'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['E'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['R'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['R'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['R'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['R'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['T'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['T'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['T'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['T'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['Y'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['Y'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['Y'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['Y'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['U'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['U'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['U'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['U'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['I'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['I'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['I'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['I'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['O'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['O'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['O'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['O'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['P'] == 'w') {
        std::cout << " --- " << std::endl;
    }
    if (guessedWords['P'] == 'g') {
        std::cout << GREEN << " --- " << RESET << std::endl;
    }
    if (guessedWords['P'] == 'y') {
        std::cout << YELLOW << " --- " << RESET << std::endl;
    }
    if (guessedWords['P'] == 'b') {
        std::cout << GRAY << " --- " << RESET << std::endl;
    }

    if (guessedWords['Q'] == 'w') {
        std::cout << "| Q |";
    }
    if (guessedWords['Q'] == 'g') {
        std::cout << GREEN << "| Q |" << RESET;
    }
    if (guessedWords['Q'] == 'y') {
        std::cout << YELLOW << "| Q |" << RESET;
    }
    if (guessedWords['Q'] == 'b') {
        std::cout << GRAY << "| Q |" << RESET;
    }
    if (guessedWords['W'] == 'w') {
        std::cout << "| W |";
    }
    if (guessedWords['W'] == 'g') {
        std::cout << GREEN << "| W |" << RESET;
    }
    if (guessedWords['W'] == 'y') {
        std::cout << YELLOW << "| W |" << RESET;
    }
    if (guessedWords['W'] == 'b') {
        std::cout << GRAY << "| W |" << RESET;
    }
    if (guessedWords['E'] == 'w') {
        std::cout << "| E |";
    }
    if (guessedWords['E'] == 'g') {
        std::cout << GREEN << "| E |" << RESET;
    }
    if (guessedWords['E'] == 'y') {
        std::cout << YELLOW << "| E |" << RESET;
    }
    if (guessedWords['E'] == 'b') {
        std::cout << GRAY << "| E |" << RESET;
    }
    if (guessedWords['R'] == 'w') {
        std::cout << "| R |";
    }
    if (guessedWords['R'] == 'g') {
        std::cout << GREEN << "| R |" << RESET;
    }
    if (guessedWords['R'] == 'y') {
        std::cout << YELLOW << "| R |" << RESET;
    }
    if (guessedWords['R'] == 'b') {
        std::cout << GRAY << "| R |" << RESET;
    }
    if (guessedWords['T'] == 'w') {
        std::cout << "| T |";
    }
    if (guessedWords['T'] == 'g') {
        std::cout << GREEN << "| T |" << RESET;
    }
    if (guessedWords['T'] == 'y') {
        std::cout << YELLOW << "| T |" << RESET;
    }
    if (guessedWords['T'] == 'b') {
        std::cout << GRAY << "| T |" << RESET;
    }
    if (guessedWords['Y'] == 'w') {
        std::cout << "| Y |";
    }
    if (guessedWords['Y'] == 'g') {
        std::cout << GREEN << "| Y |" << RESET;
    }
    if (guessedWords['Y'] == 'y') {
        std::cout << YELLOW << "| Y |" << RESET;
    }
    if (guessedWords['Y'] == 'b') {
        std::cout << GRAY << "| Y |" << RESET;
    }
    if (guessedWords['U'] == 'w') {
        std::cout << "| U |";
    }
    if (guessedWords['U'] == 'g') {
        std::cout << GREEN << "| U |" << RESET;
    }
    if (guessedWords['U'] == 'y') {
        std::cout << YELLOW << "| U |" << RESET;
    }
    if (guessedWords['U'] == 'b') {
        std::cout << GRAY << "| U |" << RESET;
    }
    if (guessedWords['I'] == 'w') {
        std::cout << "| I |";
    }
    if (guessedWords['I'] == 'g') {
        std::cout << GREEN << "| I |" << RESET;
    }
    if (guessedWords['I'] == 'y') {
        std::cout << YELLOW << "| I |" << RESET;
    }
    if (guessedWords['I'] == 'b') {
        std::cout << GRAY << "| I |" << RESET;
    }
    if (guessedWords['O'] == 'w') {
        std::cout << "| O |";
    }
    if (guessedWords['O'] == 'g') {
        std::cout << GREEN << "| O |" << RESET;
    }
    if (guessedWords['O'] == 'y') {
        std::cout << YELLOW << "| O |" << RESET;
    }
    if (guessedWords['O'] == 'b') {
        std::cout << GRAY << "| O |" << RESET;
    }
    if (guessedWords['P'] == 'w') {
        std::cout << "| P |" << std::endl;
    }
    if (guessedWords['P'] == 'g') {
        std::cout << GREEN << "| P |" << RESET << std::endl;
    }
    if (guessedWords['P'] == 'y') {
        std::cout << YELLOW << "| P |" << RESET << std::endl;
    }
    if (guessedWords['P'] == 'b') {
        std::cout << GRAY << "| P |" << RESET << std::endl;
    }

    if (guessedWords['Q'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['Q'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['Q'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['Q'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['W'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['W'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['W'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['W'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['E'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['E'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['E'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['E'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['R'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['R'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['R'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['R'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['T'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['T'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['T'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['T'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['Y'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['Y'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['Y'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['Y'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['U'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['U'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['U'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['U'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['I'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['I'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['I'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['I'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['O'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['O'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['O'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['O'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['P'] == 'w') {
        std::cout << " --- " << std::endl;
    }
    if (guessedWords['P'] == 'g') {
        std::cout << GREEN << " --- " << RESET << std::endl;
    }
    if (guessedWords['P'] == 'y') {
        std::cout << YELLOW << " --- " << RESET << std::endl;
    }
    if (guessedWords['P'] == 'b') {
        std::cout << GRAY << " --- " << RESET << std::endl;
    }



    if (guessedWords['A'] == 'w') {
        std::cout << "   --- ";
    }
    if (guessedWords['A'] == 'g') {
        std::cout << GREEN << "   --- " << RESET;
    }
    if (guessedWords['A'] == 'y') {
        std::cout << YELLOW << "   --- " << RESET;
    }
    if (guessedWords['A'] == 'b') {
        std::cout << GRAY << "   --- " << RESET;
    }
    if (guessedWords['S'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['S'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['S'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['S'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['D'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['D'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['D'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['D'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['F'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['F'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['F'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['F'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['G'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['G'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['G'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['G'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['H'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['H'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['H'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['H'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['J'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['J'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['J'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['J'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['K'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['K'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['K'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['K'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['L'] == 'w') {
        std::cout << " --- " << std::endl;
    }
    if (guessedWords['L'] == 'g') {
        std::cout << GREEN << " --- " << RESET << std::endl;
    }
    if (guessedWords['L'] == 'y') {
        std::cout << YELLOW << " --- " << RESET << std::endl;
    }
    if (guessedWords['L'] == 'b') {
        std::cout << GRAY << " --- " << RESET << std::endl;
    }

    if (guessedWords['A'] == 'w') {
        std::cout << "  | A |";
    }
    if (guessedWords['A'] == 'g') {
        std::cout << GREEN << "  | A |" << RESET;
    }
    if (guessedWords['A'] == 'y') {
        std::cout << YELLOW << "  | A |" << RESET;
    }
    if (guessedWords['A'] == 'b') {
        std::cout << GRAY << "  | A |" << RESET;
    }
    if (guessedWords['S'] == 'w') {
        std::cout << "| S |";
    }
    if (guessedWords['S'] == 'g') {
        std::cout << GREEN << "| S |" << RESET;
    }
    if (guessedWords['S'] == 'y') {
        std::cout << YELLOW << "| S |" << RESET;
    }
    if (guessedWords['S'] == 'b') {
        std::cout << GRAY << "| S |" << RESET;
    }
    if (guessedWords['D'] == 'w') {
        std::cout << "| D |";
    }
    if (guessedWords['D'] == 'g') {
        std::cout << GREEN << "| D |" << RESET;
    }
    if (guessedWords['D'] == 'y') {
        std::cout << YELLOW << "| D |" << RESET;
    }
    if (guessedWords['D'] == 'b') {
        std::cout << GRAY << "| D |" << RESET;
    }
    if (guessedWords['F'] == 'w') {
        std::cout << "| F |";
    }
    if (guessedWords['F'] == 'g') {
        std::cout << GREEN << "| F |" << RESET;
    }
    if (guessedWords['F'] == 'y') {
        std::cout << YELLOW << "| F |" << RESET;
    }
    if (guessedWords['F'] == 'b') {
        std::cout << GRAY << "| F |" << RESET;
    }
    if (guessedWords['G'] == 'w') {
        std::cout << "| G |";
    }
    if (guessedWords['G'] == 'g') {
        std::cout << GREEN << "| G |" << RESET;
    }
    if (guessedWords['G'] == 'y') {
        std::cout << YELLOW << "| G |" << RESET;
    }
    if (guessedWords['G'] == 'b') {
        std::cout << GRAY << "| G |" << RESET;
    }
    if (guessedWords['H'] == 'w') {
        std::cout << "| H |";
    }
    if (guessedWords['H'] == 'g') {
        std::cout << GREEN << "| H |" << RESET;
    }
    if (guessedWords['H'] == 'y') {
        std::cout << YELLOW << "| H |" << RESET;
    }
    if (guessedWords['H'] == 'b') {
        std::cout << GRAY << "| H |" << RESET;
    }
    if (guessedWords['J'] == 'w') {
        std::cout << "| J |";
    }
    if (guessedWords['J'] == 'g') {
        std::cout << GREEN << "| J |" << RESET;
    }
    if (guessedWords['J'] == 'y') {
        std::cout << YELLOW << "| J |" << RESET;
    }
    if (guessedWords['J'] == 'b') {
        std::cout << GRAY << "| J |" << RESET;
    }
    if (guessedWords['K'] == 'w') {
        std::cout << "| K |";
    }
    if (guessedWords['K'] == 'g') {
        std::cout << GREEN << "| K |" << RESET;
    }
    if (guessedWords['K'] == 'y') {
        std::cout << YELLOW << "| K |" << RESET;
    }
    if (guessedWords['K'] == 'b') {
        std::cout << GRAY << "| K |" << RESET;
    }
    if (guessedWords['L'] == 'w') {
        std::cout << "| L |" << std::endl;
    }
    if (guessedWords['L'] == 'g') {
        std::cout << GREEN << "| L |" << RESET << std::endl;
    }
    if (guessedWords['L'] == 'y') {
        std::cout << YELLOW << "| L |" << RESET << std::endl;
    }
    if (guessedWords['L'] == 'b') {
        std::cout << GRAY << "| L |" << RESET << std::endl;
    }

    if (guessedWords['A'] == 'w') {
        std::cout << "   --- ";
    }
    if (guessedWords['A'] == 'g') {
        std::cout << GREEN << "   --- " << RESET;
    }
    if (guessedWords['A'] == 'y') {
        std::cout << YELLOW << "   --- " << RESET;
    }
    if (guessedWords['A'] == 'b') {
        std::cout << GRAY << "   --- " << RESET;
    }
    if (guessedWords['S'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['S'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['S'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['S'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['D'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['D'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['D'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['D'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['F'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['F'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['F'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['F'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['G'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['G'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['G'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['G'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['H'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['H'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['H'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['H'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['J'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['J'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['J'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['J'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['K'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['K'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['K'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['K'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['L'] == 'w') {
        std::cout << " --- " << std::endl;
    }
    if (guessedWords['L'] == 'g') {
        std::cout << GREEN << " --- " << RESET << std::endl;
    }
    if (guessedWords['L'] == 'y') {
        std::cout << YELLOW << " --- " << RESET << std::endl;
    }
    if (guessedWords['L'] == 'b') {
        std::cout << GRAY << " --- " << RESET << std::endl;
    }



    if (guessedWords['Z'] == 'w') {
        std::cout << "     --- ";
    }
    if (guessedWords['Z'] == 'g') {
        std::cout << GREEN << "     --- " << RESET;
    }
    if (guessedWords['Z'] == 'y') {
        std::cout << YELLOW << "     --- " << RESET;
    }
    if (guessedWords['Z'] == 'b') {
        std::cout << GRAY << "     --- " << RESET;
    }
    if (guessedWords['X'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['X'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['X'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['X'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['C'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['C'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['C'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['C'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['V'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['V'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['V'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['V'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['B'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['B'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['B'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['B'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['N'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['N'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['N'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['N'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['M'] == 'w') {
        std::cout << " --- " << std::endl;
    }
    if (guessedWords['M'] == 'g') {
        std::cout << GREEN << " --- " << RESET << std::endl;
    }
    if (guessedWords['M'] == 'y') {
        std::cout << YELLOW << " --- " << RESET << std::endl;
    }
    if (guessedWords['M'] == 'b') {
        std::cout << GRAY << " --- " << RESET << std::endl;
    }

    if (guessedWords['Z'] == 'w') {
        std::cout << "    | Z |";
    }
    if (guessedWords['Z'] == 'g') {
        std::cout << GREEN << "    | Z |" << RESET;
    }
    if (guessedWords['Z'] == 'y') {
        std::cout << YELLOW << "    | Z |" << RESET;
    }
    if (guessedWords['Z'] == 'b') {
        std::cout << GRAY << "    | Z |" << RESET;
    }
    if (guessedWords['X'] == 'w') {
        std::cout << "| X |";
    }
    if (guessedWords['X'] == 'g') {
        std::cout << GREEN << "| X |" << RESET;
    }
    if (guessedWords['X'] == 'y') {
        std::cout << YELLOW << "| X |" << RESET;
    }
    if (guessedWords['X'] == 'b') {
        std::cout << GRAY << "| X |" << RESET;
    }
    if (guessedWords['C'] == 'w') {
        std::cout << "| C |";
    }
    if (guessedWords['C'] == 'g') {
        std::cout << GREEN << "| C |" << RESET;
    }
    if (guessedWords['C'] == 'y') {
        std::cout << YELLOW << "| C |" << RESET;
    }
    if (guessedWords['C'] == 'b') {
        std::cout << GRAY << "| C |" << RESET;
    }
    if (guessedWords['V'] == 'w') {
        std::cout << "| V |";
    }
    if (guessedWords['V'] == 'g') {
        std::cout << GREEN << "| V |" << RESET;
    }
    if (guessedWords['V'] == 'y') {
        std::cout << YELLOW << "| V |" << RESET;
    }
    if (guessedWords['V'] == 'b') {
        std::cout << GRAY << "| V |" << RESET;
    }
    if (guessedWords['B'] == 'w') {
        std::cout << "| B |";
    }
    if (guessedWords['B'] == 'g') {
        std::cout << GREEN << "| B |" << RESET;
    }
    if (guessedWords['B'] == 'y') {
        std::cout << YELLOW << "| B |" << RESET;
    }
    if (guessedWords['B'] == 'b') {
        std::cout << GRAY << "| B |" << RESET;
    }
    if (guessedWords['N'] == 'w') {
        std::cout << "| N |";
    }
    if (guessedWords['N'] == 'g') {
        std::cout << GREEN << "| N |" << RESET;
    }
    if (guessedWords['N'] == 'y') {
        std::cout << YELLOW << "| N |" << RESET;
    }
    if (guessedWords['N'] == 'b') {
        std::cout << GRAY << "| N |" << RESET;
    }
    if (guessedWords['M'] == 'w') {
        std::cout << "| M |" << std::endl;
    }
    if (guessedWords['M'] == 'g') {
        std::cout << GREEN << "| M |" << RESET << std::endl;
    }
    if (guessedWords['M'] == 'y') {
        std::cout << YELLOW << "| M |" << RESET << std::endl;
    }
    if (guessedWords['M'] == 'b') {
        std::cout << GRAY << "| M |" << RESET << std::endl;
    }

    if (guessedWords['Z'] == 'w') {
        std::cout << "     --- ";
    }
    if (guessedWords['Z'] == 'g') {
        std::cout << GREEN << "     --- " << RESET;
    }
    if (guessedWords['Z'] == 'y') {
        std::cout << YELLOW << "     --- " << RESET;
    }
    if (guessedWords['Z'] == 'b') {
        std::cout << GRAY << "     --- " << RESET;
    }
    if (guessedWords['X'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['X'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['X'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['X'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['C'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['C'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['C'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['C'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['V'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['V'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['V'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['V'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['B'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['B'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['B'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['B'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['N'] == 'w') {
        std::cout << " --- ";
    }
    if (guessedWords['N'] == 'g') {
        std::cout << GREEN << " --- " << RESET;
    }
    if (guessedWords['N'] == 'y') {
        std::cout << YELLOW << " --- " << RESET;
    }
    if (guessedWords['N'] == 'b') {
        std::cout << GRAY << " --- " << RESET;
    }
    if (guessedWords['M'] == 'w') {
        std::cout << " --- " << std::endl;
    }
    if (guessedWords['M'] == 'g') {
        std::cout << GREEN << " --- " << RESET << std::endl;
    }
    if (guessedWords['M'] == 'y') {
        std::cout << YELLOW << " --- " << RESET << std::endl;
    }
    if (guessedWords['M'] == 'b') {
        std::cout << GRAY << " --- " << RESET << std::endl;
    }
}

std::vector<char> splitColors(std::vector<std::string> keyboardFileContent) {
    std::vector<char> colors;
    for (int i = 0; i < keyboardFileContent.size(); i++) {
        if ((i + 1) % 2 == 1) {
            for (int j = 0; j < keyboardFileContent[i].size(); j++) {
                colors.push_back(keyboardFileContent[i][j]);
            }
        }
    }
    return colors;
}

std::vector<char> splitGuesses(std::vector<std::string> keyboardFileContent) {
    std::vector<char> guesses;
    for (int i = 0; i < keyboardFileContent.size(); i++) {
        if ((i + 1) % 2 == 0) {
            for (int j = 0; j < keyboardFileContent[i].size(); j++) {
                guesses.push_back(keyboardFileContent[i][j]);
            }
        }
    }
    return guesses;
}

std::vector<std::string> readKeyboardFile(std::string filename) {
    std::ifstream file;
    file.open(filename, std::ios::in);
    std::vector<std::string> keyboardFileContent;
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            keyboardFileContent.push_back(line);
        }
    }
    file.close();
    return keyboardFileContent;
}

#endif