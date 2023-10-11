#include "functions_file_keyboard.h"
#include <igloo/core/defaultregistrationaliases.h>
#include <igloo/igloo.h>

using namespace igloo;

Context(TestImportantKeyboardFunctions){
    Spec(gameNotOn) {
        Assert::That(readGamePulse(), Equals(0));
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
