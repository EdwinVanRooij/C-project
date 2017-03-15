#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

long long int startProgramForAnswer();

bool isPythagoreanTriplet(int, int);

bool isDivisible(long, int);

int square(int);

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

    for (int a = 0; a < 10000; ++a) {
        for (int b = 0; b < 10000; ++b) {
            int prodAB = square(a) + square(b);
        }
    }

    return result;
}

int square(int num) {
    return num * num;
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
