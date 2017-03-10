#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int getLargestPrimeFactor(long);

int main() {
    long number = 600851475143;

    int result = getLargestPrimeFactor(number);

}

int getLargestPrimeFactor(long sum) {
    int result;
    int allFactors[20];

    // Get all prime factors
    //todo

    // Get highest prime factor
    //todo

    // Return highest prime factor
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
