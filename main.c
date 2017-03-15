#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

long long int startProgramForAnswer();

bool isPythagoreanTriplet(int, int);

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

    int a = 0;
    int b = 0;
    int c = 0;

    // Add 1 to a every time
    while (!result) {
        // Add 1 to b every time
        while (!result) {
            c = (square(a) + square(b)) / (square(a) / square(b));
            if (a + b + c == 1000) {
                result = a * b * c;
            }

            b++;
        }
        a++;
    }

    return result;
}


int square(int num) {
    return num * num;
}
