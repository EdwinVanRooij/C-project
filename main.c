#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

long long int startProgramForAnswer();

bool isPythagoreanTriplet(int, int);

bool isDivisible(long, int);

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

    for (float a = 1; a < 1000; ++a) {
        for (float b = 1; b < 1000; ++b) {
            float prodAB = a * a + b * b;
//            printf("%f^ + %f^ = %f\n", a, b, prodAB);
            float c = (float) sqrt(prodAB);
            if (floor(c) == c) {
//                printf("Square root of prodAB is %f and whole\n", sqrt(prodAB));
                printf("Calculating sum: %f + %f + %f = %f\n", a, b, c, a + b + c);
                // We have a pythagorean triplet
                if (floor(a + b + c) == 1000) {
                    result = (long long int) (a * b * c);
                }
            } else {
//                printf("Square root of prodAB is %f and NOT whole\n", sqrt(prodAB));
            }
        }
    }

    return result;
}

/**
 * Checks if a number returns a whole number when divided by specified parameter.
 * @param numberToDivide (large) number to divide
 * @param numberToDivideWith number to divide (large) number with
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
