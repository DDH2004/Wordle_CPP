#include <igloo/igloo.h>
#include <string>
#include "functions_file.h"
using namespace igloo;

Context(TestImportantWordleFunctions){
    Spec(aboutIsAllowedForFiveWords) {
        Assert::That(isAllowed("5-words.txt", "5-allowed.txt", "about"), IsTrue());
    }
    Spec(alsoIsAllowedForFourWords) {
        Assert::That(isAllowed("4-words.txt", "4-allowed.txt", "also"), IsTrue());
    }
    Spec(abroadIsAllowedForSixWords) {
        Assert::That(isAllowed("6-words.txt", "6-allowed.txt", "abroad"), IsTrue());
    }
    Spec(abilityIsAllowedForSevenWords) {
        Assert::That(isAllowed("7-words.txt", "7-allowed.txt", "ability"), IsTrue());
    }
    Spec(absoluteIsAllowedForEightWords) {
        Assert::That(isAllowed("8-words.txt", "8-allowed.txt", "absolute"), IsTrue());
    }
    Spec(aboutIsNotAllowedForSixWords) {
        Assert::That(isAllowed("6-words.txt", "6-allowed.txt", "about"), IsFalse());
    }
    Spec(aboutIsNotAllowedForSevenWords) {
        Assert::That(isAllowed("7-words.txt", "7-allowed.txt", "about"), IsFalse());
    }
        Spec(aboutIsNotAllowedForEightWords) {
        Assert::That(isAllowed("8-words.txt", "8-allowed.txt", "about"), IsFalse());
    }
        Spec(aboutIsNotAllowedForFourWords) {
        Assert::That(isAllowed("4-words.txt", "4-allowed.txt", "about"), IsFalse());
    }
    Spec(aaaaaIsNotAllowedForFiveWords) {
        Assert::That(isAllowed("5-words.txt", "5-allowed.txt", "aaaaa"), IsFalse());
    }
    Spec(aaaaIsNotAllowedForFiveWords) {
        Assert::That(isAllowed("5-words.txt", "5-allowed.txt", "aaaa"), IsFalse());
    }
    Spec(aaaaaaIsNotAllowedForFiveWords) {
        Assert::That(isAllowed("5-words.txt", "5-allowed.txt", "aaaaaa"), IsFalse());
    }
    Spec(colorsOfAnkerInHorse) {
        Assert::That(checkGuess(5, "anker", "horse"), Contains("bbbyy"));
    }
    Spec(colorsofLocalinLocal) {
        Assert::That(checkGuess(5, "local", "local"), Contains("ggggg"));        
    }
};

int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}