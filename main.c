#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int getLargestPrimeFactor(long);

int main() {
    long number = 600851475143;

    int result = getLargestPrimeFactor(number);

    printf("Result: %d", result);
}

int getLargestPrimeFactor(long sum) {
    long highestFactor = 0;
    int x = 0;
    float tmp = 0;
    while (x < sum) {
        tmp = sum / x;
        if (isPrime(x) && tmp % 1.0 == 0) {
            highestFactor = tmp;
        }
        x++;
    }
    return (int) highestFactor;
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
