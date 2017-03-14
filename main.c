#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

long startProgramForAnswer();

bool isDivisible(long, int);

int main(int argc, char *argv[]) {
    // Start a clock
    clock_t begin = clock();

    long answer = startProgramForAnswer();

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Found answer '%ld' in %f seconds.\n", answer, time_spent);
}

/**
 * Used to solve the euler problem.
 * @return the answer
 */
long startProgramForAnswer() {
    long result = 0;

    long sumOfSquareOfNumbers = 0;
    long squareOfSumOfNumbers = 0;

    int amountOfNumbers = 100;

    // Add squares of all numbers until max
    for (int i = 1; i < amountOfNumbers + 1; ++i) {
        sumOfSquareOfNumbers += i * i;
    }

    // First add all numbers
    for (int j = 0; j < amountOfNumbers + 1; ++j) {
        squareOfSumOfNumbers += j;
    }
    // Then take the square of that number
    squareOfSumOfNumbers *= squareOfSumOfNumbers;

    result = squareOfSumOfNumbers - sumOfSquareOfNumbers;
    return result;
}

bool isDivisible(long numberToDivide, int numberToDivideWith) {
    long double z = (long double) numberToDivide / numberToDivideWith;

    if (floor((double) z) == z) {
        return true;
    }
    return false;
}
