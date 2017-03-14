#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

long startProgramForAnswer();

bool isPrime(int);

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

    int currentNumber = 0;
    int amountOfPrimes = 0;

    while (1) {
        currentNumber++;
        if (isPrime(currentNumber)) {
            amountOfPrimes++;
            if (amountOfPrimes == 10001) {
                result = currentNumber;
                break;
            }
        }
    }

    return result;
}

bool isPrime(int number) {
    // Must be greater than 1
    if (number <= 1) {
        return false;
    }

    // Start at 1, because everything is divisible by 1
    int x = 2;

    // While x is lower than the number to check for
    while (x < number) {
        // If the number to check for is equally divisible, the number is not a prime number
        if (number % x == 0) {
            return false;
        }
        x++;
    };

    // No divisor found, number is prime
    return true;
}
