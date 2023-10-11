#ifndef FUNCTIONS_FILE_H
#define FUNCTIONS_FILE_H

#include <cctype>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <iomanip>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"

void mainMenu(int count, std::string wordListBig, std::string allowedWordsBig);
void howToPlay(int count, std::string wordListBig, std::string allowedWordsBig);
void statisticsSummary(int count, std::string wordListBig, std::string allowedWordsBig);
void resetStatistics(int count, std::string wordListBig, std::string allowedWordsBig);
void game(int count, std::string wordListBig, std::string allowedWordsBig);
std::string randomWord(std::string wordListBig);
std::string lowerCase(std::string word);
std::string upperCase(std::string word);
bool isAllowed(std::string wordListBig, std::string allowedWordsBig, std::string guess);
std::string checkGuess(int count, std::string guess, std::string answer);
void printGuess(int count, std::string guess, std::string colors);
std::vector<int> readStats();
void writeStats(std::vector<int> stats);
void appendWordRecord(std::string answer, int attempts, std::string win);
std::vector<std::string> readWordRecord();
void printWordRecord();
void writeKeyboard(std::string guess, std::string colors);
void emptyKeyboard();
void gameStartPulse();
void gameEndPulse();

void mainMenu(int count, std::string wordListBig, std::string allowedWordsBig) {
    system("clear");
    int option;
    std::cout << "=========================\n" << "    WELCOME TO WORDLE\n" << "=========================\n" << std::endl << std::endl << "1. Play Wordle\n" << "2. How to Play\n" << "3. Statistics Summary\n" << "4. Reset Statistics\n" << "5. Exit\n" << std::endl << std::endl << "Select an option: ";
    std::cin >> option;

    if (option == 1) {
        game(count, wordListBig, allowedWordsBig);
    }

    else if (option == 2) {
        howToPlay(count, wordListBig, allowedWordsBig);
    }
    
    else if (option == 3) {
        statisticsSummary(count, wordListBig, allowedWordsBig);
    }

    else if (option == 4) {
        resetStatistics(count, wordListBig, allowedWordsBig);
    }

    else {
        exit(0);
    }
}

void howToPlay(int count, std::string wordListBig, std::string allowedWordsBig) {
    system("clear");
    std::cin.ignore();
    std::string input;
    std::cout << "=============================================\n" << "                 HOW TO PLAY\n" << "=============================================\n" << "Guess the Wordle in 6 tries.\n" << std::endl << std::endl << "HOW TO PLAY:\n" << "- Each guess must be a valid 5 letter word.\n" << "- The color of the tiles will change to show\n  you how close your guess was to the word." << std::endl << std::endl << GREEN << " ---" << RESET << " ---  ---  ---  ---\n" << GREEN << "| W |" << RESET << "| E || A || R || Y |\n" << GREEN << " ---" << RESET << "  ---  ---  ---  ---\n" << BOLD << "W" << RESET << " is in the word and in the correct spot.\n" << std::endl << " ---  " << YELLOW << "---" << RESET << "  ---  ---  ---\n" << "| P |" << YELLOW << "| I |" << RESET << "| L || L || S |\n" << " ---  " << YELLOW << "---" << RESET << "  ---  ---  ---\n" <<  BOLD << "I" << RESET << " is in the word but in the wrong spot.\n" << std::endl << " ---  ---  ---  " << GRAY << "---" << RESET << "  ---\n" << "| V || A || G |" << GRAY << "| U |" << RESET << "| E |\n" << " ---  ---  ---  " << GRAY << "---" << RESET << "  ---\n" << BOLD << "U" << RESET << " is not in the word in any spot.\n" << std::endl << std::endl << "Press [enter] to continue\n";
    std::getline(std::cin, input);
    mainMenu(count, wordListBig, allowedWordsBig);
}

std::vector<int> readStats() {
    std::ifstream file;
    std::vector<int> stats;
    
    file.open("stats.txt", std::ios::in);
    if (file.is_open()) {
        int number;
        while (file >> number) {
            stats.push_back(number);
        }
    }
    file.close();

    return stats;
}

void statisticsSummary(int count, std::string wordListBig, std::string allowedWordsBig) {
    system("clear");
    std::cin.ignore();
    std::string input;
    std::vector<int> stats;
    float winPercent;
    stats = readStats();
    if (stats[0] == 0) {
        std::cout << "==========================\n    STATISTICS SUMMARY\n==========================\n" << "Times Played:" << std::setw(13) << std::right <<  0 << std::endl << "Average Attempts:" << std::setw(9) << std::right << 0 << std::endl << "Win Percentage:" << std::setw(10) << std::right << 0 << "%" << std::endl << "Current Streak:" << std::setw(11) << std::right << 0 << std::endl << "Longest Streak:" << std::setw(11) << std::right << 0 << std::endl << std::endl << std::endl;
    }
    else {
        winPercent = ((float)stats[2] / (float)stats[0]) * 100;
        std::cout << std::setprecision(3);
        std::cout << "==========================\n    STATISTICS SUMMARY\n==========================\n" << "Times Played:" << std::setw(13) << std::right <<  stats[0] << std::endl << "Average Attempts:" << std::setw(9) << std::right << stats[1] / stats[0] << std::endl << "Win Percentage:" << std::setw(10) << std::right << winPercent << "%" << std::endl << "Current Streak:" << std::setw(11) << std::right << stats[3] << std::endl << "Longest Streak:" << std::setw(11) << std::right << stats[4] << std::endl << std::endl << std::endl;
    }

    printWordRecord();

    std::getline(std::cin, input);
    mainMenu(count, wordListBig, allowedWordsBig);
}

void resetStatistics(int count, std::string wordListBig, std::string allowedWordsBig) {
    std::ofstream file;

    file.open("stats.txt", std::ios::out);
    if (file.is_open()) {
        file << 0 << std::endl << 0 << std::endl << 0 << std::endl << 0 << std::endl << 0 << std::endl << 0;
    }
    file.close();

    file.open("wordRecord.txt", std::ios::out);
    file.close();

    statisticsSummary(count, wordListBig, allowedWordsBig);
}

void gameStartPulse() {
    std::ofstream file;
    file.open("gamePulse.txt", std::ios::out);
    if (file.is_open()) {
        file << "1";
    }
    file.close();
}

void gameEndPulse() {
    std::ofstream file;
    file.open("gamePulse.txt", std::ios::out);
    file.close();
}

void game(int count, std::string wordListBig, std::string allowedWordsBig) {
    gameStartPulse();
    system("clear");
    std::string answer = randomWord(wordListBig);
    std::string exitFunction;
    std::vector<int> stats;
    std::vector<std::string> guessVector;
    std::vector<std::string> colorVector;

    for (int n = 1; n < 7; n++) {
        std::string guess;
        std::string guessDisplay;
        std::cout << "Enter a guess: ";
        std::cin >> guess;
        std::cin.ignore();
        guess = lowerCase(guess);

        if (isAllowed(wordListBig, allowedWordsBig, guess) == false) {
            std::cout << "Invalid guess" << std::endl;
            n--;
        }
        
        else {
            std::string colors = checkGuess(count, guess, answer);
            guessVector.push_back(guess);
            
            writeKeyboard(guess, colors);

            colorVector.push_back(colors);
            system("clear");

            for (int i = 0; i < n; i++) {
                printGuess(count, guessVector[i], colorVector[i]);
            }
            if (guess == answer) {
                stats = readStats();
                stats[0] += 1;
                stats[1] += n;
                stats[2] += 1;
                stats[3] += 1;
                if (stats[3] > stats[4]) {
                    stats[4] = stats[3];
                }
                stats[5];
                writeStats(stats);
                appendWordRecord(answer, n, "yes");

                std::cout << "Splendid!\n" << std::endl << "Press [enter] to continue";
                std::getline(std::cin, exitFunction);
                emptyKeyboard();
                gameEndPulse();
                mainMenu(count, wordListBig, allowedWordsBig);
            }
        }
    }

    stats = readStats();
    stats[0] += 1;
    stats[1] += 6;
    stats[2];
    stats[3] = 0;
    if (stats[3] > stats[4]) {
        stats[4] = stats[3];
    }
    stats[5] += 1;
    
    writeStats(stats);

    appendWordRecord(answer, 6, "no");

    std::cout << "The word was: " << answer << std::endl << "Better luck next time!\n" << std::endl << "Press [enter] to continue";
    std::getline(std::cin, exitFunction);
    emptyKeyboard();
    gameEndPulse();
    mainMenu(count, wordListBig, allowedWordsBig);
}

void emptyKeyboard() {
    std::ofstream file;
    file.open("keyboard.txt", std::ios::out);
    file.close();
}

void writeKeyboard(std::string guess, std::string colors) {
    std::ofstream file;
    file.open("keyboard.txt", std::ios::app);
    if (file.is_open()) {
        file << colors[0] << colors[1] << colors[2] << colors[3] << colors[4] << std::endl << upperCase(guess) << std::endl;
    }
    file.close();
}

std::vector<std::string> readWordRecord() {
    std::ifstream file;
    std::vector<std::string> wordRecord;

    file.open("wordRecord.txt", std::ios::in);
    if(file.is_open()) {
        std::string line;
        while(getline(file, line)) {
            wordRecord.push_back(line);
        }
    }
    file.close();

    return wordRecord;
}

void printWordRecord() {
    std::vector<std::string> wordRecord = readWordRecord();

    std::vector<std::string> word;
    std::vector<std::string> attempts;
    std::vector<std::string> win;

    for (int i = 0; i < wordRecord.size(); i++) {
        if ((i + 1) % 3 == 1) {
            word.push_back(wordRecord[i]);
        }
        if ((i + 1) % 3 == 2) {
            attempts.push_back(wordRecord[i]);
        }
        if ((i + 1) % 3 == 0) {
            win.push_back(wordRecord[i]);
        }
    }

    std::cout << "--------------------------\nWORD     ATTEMPTS      WIN\n--------------------------\n";
    for (int i = 0; i < word.size(); i++) {
        std::cout << word[i] << std::setw(12) << std::right << attempts[i] << std::setw(9) << std::right << win[i] << std::endl;
    }

    std::cout << std::endl << std::endl << "Press [enter] to continue" << std::endl;

}

void appendWordRecord(std::string answer, int attempts, std::string win) {
    std::ofstream file;

    file.open("wordRecord.txt", std::ios::app);
    if(file.is_open()) {
        file << answer << std::endl;
        file << attempts << std::endl;
        file << win << std::endl;
    }
    file.close();
}

void writeStats(std::vector<int> stats) {
    std::ofstream file;
    file.open("stats.txt", std::ios::out);
    if (file.is_open()) {
        file << stats[0] << std::endl << stats[1] << std::endl << stats[2] << std::endl << stats[3] << std::endl << stats[4] << std::endl << stats [5];
    }
    file.close();
}

void printGuess(int count, std::string guess, std::string colors) {
    std::string guessDisplay = upperCase(guess);
    std::vector<std::string> bound;
    for (int i = 0; i < count; i++) {
        bound.push_back(" --- ");
    }

    for (int i = 0; i < guess.size(); i++) {
        if (colors[i] == 'g') {
            std::cout << GREEN << bound[i] << RESET;
        }
        else if (colors[i] == 'y') {
            std::cout << YELLOW << bound[i] << RESET;
        }
        else if (colors[i] == 'b') {
            std::cout << GRAY << bound[i] << RESET;
        }
        if (i == guess.size() - 1) {
            std::cout << std::endl;
        }
        }             
    for (int i = 0; i < guess.size(); i++) {
        if (colors[i] == 'g') {
            std::cout << GREEN << "| " << guessDisplay[i] << " |" << RESET;
        }
        else if (colors[i] == 'y') {
            std::cout << YELLOW << "| " << guessDisplay[i] << " |" << RESET;
        }
        else if (colors[i] == 'b') {
            std::cout << GRAY << "| " << guessDisplay[i] << " |" << RESET;
        }
        if (i == guess.size() - 1) {
            std::cout << std::endl;
        }                    
    }
    for (int i = 0; i < guess.size(); i++) {
        if (colors[i] == 'g') {
            std::cout << GREEN << bound[i] << RESET;
        }
        else if (colors[i] == 'y') {
            std::cout << YELLOW << bound[i] << RESET;
        }
        else if (colors[i] == 'b') {
            std::cout << GRAY << bound[i] << RESET;
        }
        if (i == guess.size() - 1) {
            std::cout << std::endl << std::endl;
        }
    }
}

std::string checkGuess(int count, std::string guess, std::string answer) {
    char answerLetters[count];
    char guessLetters[count];
    char colorLetters[count];

    for (int i = 0; i < count; i++) {
        answerLetters[i] = answer[i];
        guessLetters[i] = guess[i];
    }

    for (int i = 0; i < count; i++) {
        if (answerLetters[i] == guessLetters[i]) {
            colorLetters[i] = 'g';
        }
        else {
            colorLetters[i] = 'b';
        }
    }

    for (int i = 0; i < count; i++) {
        if (colorLetters[i] != 'g') {
            for (int j = 0; j < count; j++) {
                if (colorLetters[j] == 'b' && answerLetters[i] == guessLetters[j]) {
                    colorLetters[j] = 'y';
                }
            }
        }
    }

    return colorLetters;
}

std::string randomWord(std::string wordListBig) {
    std::fstream file;
    std::vector<std::string> wordsList;
    int place;
    int total;
    std::string answer;

    file.open(wordListBig, std::ios::in);

    if (file.is_open()) {
        std::string word;
        while(getline(file, word)) {
            wordsList.push_back((word));
            total++;
        }
    }

    file.close();

    srand(time(NULL));
    place = rand() % total;

    answer = wordsList[place];

    return answer;
}

std::string lowerCase(std::string word) {
    std::string lowerWord;
    std::string temp;
    for(int i = 0; i < word.size(); i++) {
        temp = tolower(word[i]);
        lowerWord.append(temp);
    }
    return lowerWord;
}

std::string upperCase(std::string word) {
    std::string upperWord;
    std::string temp;
    for(int i = 0; i < word.size(); i++) {
        temp = toupper(word[i]);
        upperWord.append(temp);
    }
    return upperWord;
}

bool isAllowed(std::string wordListBig, std::string allowedWordsBig, std::string guess) {
    std::fstream file;
    std::vector<std::string> wordList;

    file.open(allowedWordsBig, std::ios::in);

    if (file.is_open()) {
        std::string word;

        while(getline(file, word)) {
            wordList.push_back(word);
        }
    }

    file.close();

    file.open(wordListBig, std::ios::in);

    if (file.is_open()) {
        std::string word;

        while(getline(file, word)) {
            wordList.push_back(word);
        }
    }

    file.close();

    for (std::string w : wordList) {
        if (w == guess) {
            return true;
        }
    }
    for (std::string w : wordList) {
        if (w == guess) {
            return true;
        }
    }

    return false;
}

#endif