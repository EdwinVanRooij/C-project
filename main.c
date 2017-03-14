#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

int startProgramForAnswer();

bool isDivisible(long, int);

int main(int argc, char *argv[]) {
    // Start a clock
    clock_t begin = clock();

    int answer = startProgramForAnswer();

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Found answer '%d' in %f seconds.\n", answer, time_spent);
}

/**
 * Used to solve the euler problem.
 * @return the answer
 */
int startProgramForAnswer() {
    int maxNumber = 10;

    // Keep track of a number until we've found the smallest answer
    int currentNumber = maxNumber;
    int answer = 0;

    // Loop until answer was found
    while (answer == 0) {
        bool allGoodSoFar = true;
        // Check for every number from 1 to 20 if the current number is evenly divisible
        for (int i = 1; i < maxNumber + 1; ++i) {
            // If number is not evenly divisible, go to the next number
            if (!isDivisible(currentNumber, i)) {
                printf("Number %d is not evenly divisible by %d, moving on.\n", currentNumber, i);
                allGoodSoFar = false;
                currentNumber++;
                continue;
            } else {
                // Number is evenly divisible, check if we're at the last one and all's good so far
                if (i == maxNumber && allGoodSoFar) {
                    // All numbers are evenly divisible, answer found
                    answer = currentNumber;
                }
            }
        }
    }
    return answer;
}

bool isDivisible(long numberToDivide, int numberToDivideWith) {
    float x = numberToDivide;
    float y = numberToDivideWith;
    float z = x / y;

    if (floor(z) == z) {
        return true;
    }
    return false;
}
