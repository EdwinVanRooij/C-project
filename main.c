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

    // Store the 1000 digit number in an array, since there's no data type big enough to contain it otherwise
    char thousandDigitNumber[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

    // Keep track of small integers at all times, use to create the product
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;

    // Multiply all products to create the product
    long long int product = 0;

    // Start at amount of numbers -1 (index starts at 0) to initially fill all small integers
    short int index = 4 - 1;

    // Loop while index is under the max amount of digits
    while (index < 1000) {
        // Set numbers from 1000 digit number based on current index
        n1 = thousandDigitNumber[index - 3] - '0';
        n2 = thousandDigitNumber[index - 2] - '0';
        n3 = thousandDigitNumber[index - 1] - '0';
        n4 = thousandDigitNumber[index] - '0';

        // Calculate product
        product = n1 * n2 * n3 * n4;

        // Show product to user
        printf("Product of %i, %i, %i, and %i: %lli\n", n1, n2, n3, n4, product);

        // If the current product exceeds the current highest, set new highest
        if (product > result) {
            result = product;
        }

        index++;
    }

    return result;
}
