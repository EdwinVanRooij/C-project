#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

bool isDivisible(long, int);

bool isPrime(int);

bool isPalindrome(long);

long findHighestPalindromeForDigits();


int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Incorrect amount of parameters given
        printf("Usage: %s <number>", argv[0]);
        return 0;
    }

    // Start a clock
    clock_t begin = clock();

    long amountOfDigits = atoll(argv[1]);

    long highestPalindrome = findHighestPalindromeForDigits();

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Found result '%ld' in %f seconds.\n", highestPalindrome, time_spent);
}

/**
 * Finds highest palindrome for x amount of digits.
 * @param amountOfDigits amount of digits
 * @return highest palindrome
 */
long findHighestPalindromeForDigits() {
    long highestPalindrome = 0;
    long product;

    for (int i = 0; i < 999; ++i) {
        for (int j = 0; j < 999; ++j) {
            product = i * j;
            // If product is a palindrome, check if it's higher than previous one
            if (isPalindrome(product)) {
                if (product > highestPalindrome) {
                    // Product is new highest palindrome
                    highestPalindrome = product;
                    printf("Highest palindrome is: %ld\n", highestPalindrome);
                }
            }
        }
    }

    return highestPalindrome;
}

void tostring(char str[], int num) {
    int i, rem, len = 0, n;

    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

int toint(char str[]) {
    int len = strlen(str);
    int i, num = 0;

    for (i = 0; i < len; i++) {
        num = num + ((str[len - (i + 1)] - '0') * pow(10, i));
    }

    return num;
}

/**
 * Checks if the given number is a (mathematical) palindrome or not.
 * @param number to check for
 * @return boolean
 */
bool isPalindrome(long number) {
    printf("Number: %ld\n", number);

    char numberInString[16];

    int iLastNumber = (int) (number % 10);
    tostring(numberInString, (int) number);

    int first = numberInString[0];
    if (first )
    printf("Last number: %d\n\n", iLastNumber);

    return true;
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
