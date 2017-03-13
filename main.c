#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

bool isDivisible(long, int);

bool isPrime(int);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Incorrect amount of parameters given
        printf("Usage: %s <number>", argv[0]);
        return 0;
    }

    // Start a clock
    clock_t begin = clock();

    long starting_number = atoll(argv[1]);
    long remainder = starting_number;
    int highest_factor;

    int x = 1;

    // Loop while remainder is higher than 1
    while (remainder > 1) {
        // Make sure we have a prime number
        if (isPrime(x)) {
            // If remainder is divisible by x, set new highest factor
            if (isDivisible(remainder, x)) {
                highest_factor = x;
                printf("Found a new highest: %d, remaining number: %ld\n", highest_factor, remainder);
                // Set new remainder
                remainder = remainder / x;
                x = 1;
            }
        }
        x++;
    }
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Found result '%d' for number %ld in %f seconds.\n", highest_factor, starting_number, time_spent);
}

/**
 * Checks if a number returns a whole number when divided by specified parameter.
 * @param numberToDivide (large) number to divide
 * @param numberToDivideWith number to devide (large) number with
 * @return boolean
 */
bool isDivisible(long numberToDivide, int numberToDivideWith) {
    double x = numberToDivide;
    double y = numberToDivideWith;
    double z = x / y;

    if (floor(z) == z) {
        return true;
    }
    return false;
}

/**
 * Checks whether a number is a prime number or not.
 * @param number number to check for
 * @return boolean
 */
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
