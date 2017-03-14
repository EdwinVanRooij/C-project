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
    int maxNumber = 20;

    // Keep track of a number until we've found the smallest answer.
    long currentNumber = maxNumber;

    // Loop until answer was found
    while (1) {
        // Check for every number from 1 to 20 if the current number is evenly divisible.
        for (int i = 1; i < maxNumber + 1; ++i) {
            // If current number isn't divisible by i, there's no point in checking for the others, so break this loop.
            if (!isDivisible(currentNumber, i)) {
//                printf("%d is not divisible by %d, breaking loop.\n", currentNumber, i);
                break;
            } else {
//                printf("%d is divisible by %d, continuing...\n", currentNumber, i);
                // Number is divisible, now check if we're at the last number and we'll have a winner!
                if (i == maxNumber) {
                    return currentNumber;
                }
            }
        }
        currentNumber++;
    }
}

bool isDivisible(long numberToDivide, int numberToDivideWith) {
    long double z = (long double) numberToDivide / numberToDivideWith;

    if (floor((double) z) == z) {
        return true;
    }
    return false;
}
