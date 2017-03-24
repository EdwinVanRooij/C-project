#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

long long int startProgramForAnswer();

int amountOfDivisibleNumbersFor(long long int);

bool isDivisible(long long int, int);

int main(int argc, char *argv[]) {
    // Start a clock
    clock_t begin = clock();

    long long int answer = startProgramForAnswer();

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\n\nFound answer '%lli' in %f seconds.\n", answer, time_spent);
}

/**
 * Used to solve the euler problem.
 * @return the answer
 */
long long int startProgramForAnswer() {
    long long int result = 0;
    int amountOfDivisibleNumbers = 0;

    long long int currentNumber = 0;
    int index = 0;

    while (amountOfDivisibleNumbers <= 500) {
        currentNumber += index;

        amountOfDivisibleNumbers = amountOfDivisibleNumbersFor(currentNumber);

        index++;
    }

    return currentNumber;
}

int amountOfDivisibleNumbersFor(long long int number) {
    int amount = 0;

    for (int i = 0; i < number; ++i) {
        if (isDivisible(number, i)) {
            amount++;
        }
    }

    return amount;
}

bool isDivisible(long long int numberToDivide, int numberToDivideWith) {
    float x = numberToDivide;
    float y = numberToDivideWith;
    float z = x / y;

    if (floor(z) == z) {
        return true;
    }
    return false;
}
