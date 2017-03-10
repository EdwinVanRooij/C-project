#include <stdio.h>

int main() {

    // Initialize final variable
    int total;

    // Start with 1 and 2
    int number1 = 1;
    int number2 = 2;

    // Since 2 is an even number, add it in advance
    total += number2;

    // Temp number to be used in every calculation
    int tmp;

    do {
        // Calculate the new number
        tmp = number1 + number2;

        // If number exceeds 4 million, end calculations
        if (tmp > 4000000) {
            break;
        }

        // If the new number is even, add it to the total
        if (tmp % 2 == 0) {
            total += tmp;
        }

        // Number 1 will be the previous new number
        number1 = number2;
        number2 = tmp;
    } while (number2 < 4000000);

    printf("Answer: %d", total);
}

