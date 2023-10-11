#include <bits/types/FILE.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

#include "functions_file_keyboard.h"
using namespace std;

int main(int argc, char* argv[]) {

    while(true) {
        if (readGamePulse() == 0) {
            system("clear");
            cout << "Waiting for game to start...\n";
        }
        else {
            runKeyboard("../wordle/keyboard.txt");
        }

        std::chrono::seconds duration(1);
        std::this_thread::sleep_for(duration);
    }

    return 0;
}