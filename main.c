#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool isDivisible(long, int);

bool isPrime(int);

int main() {
    // Start a clock
    clock_t begin = clock();

    int result;

//    long remainder = 600851475143;
    long starting_number = 244389;
    long remainder = starting_number;
    int highest_factor;

    int x = 2;

    // Loop while remainder is higher than 1
    while (remainder > 1) {
        // Make sure we have a prime number
        if (!isPrime(x)) {
            x++;
            continue;
        }

        // If remainder is divisible by x, set new highest factor
        if (isDivisible(remainder, x)) {
            highest_factor = x;
            // Set new remainder
            remainder = remainder / x;
            x = 2;
        }
        x++;
    }
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Found result '%d' for number %ld in %f seconds.\n", highest_factor, starting_number, time_spent);
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
