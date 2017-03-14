#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

int startProgramForAnswer();

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
    return 0;
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
