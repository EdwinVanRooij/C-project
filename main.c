#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int);

long long int startProgramForAnswer();

int main(int argc, char *argv[]) {
    // Start a clock
    clock_t begin = clock();

    long long int answer = startProgramForAnswer();

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Found answer '%lli' in %f seconds.\n", answer, time_spent);
}

/**
 * Used to solve the euler problem.
 * @return the answer
 */
long long int startProgramForAnswer() {
    long long int result = 0;

    for (int i = 0; i < 2000000; ++i) {
        printf("Checking %i for prime...\n", i);
        if (isPrime(i)) {
            result += i;
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
