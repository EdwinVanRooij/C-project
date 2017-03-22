#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long int startProgramForAnswer();

long long int getHighestHorizontalProduct(char[]);

long long int getHighestVerticalProduct(char[]);

long long int getHighestDiagonalLeftRight(char[]);

long long int getHighestDiagonalRightLeft(char[]);

int main(int argc, char *argv[]) {
    // Start a clock
    clock_t begin = clock();

    long long int answer = startProgramForAnswer();

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\n\nFound answer '%lli' in %f seconds.\n", answer, time_spent);
}

/**
 * Used to solve the euler problem.
 * @return the answer
 */
long long int startProgramForAnswer() {
    long long int result = 0;

    // Save complete grid as string
    char completeGrid[] = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 \n"
            "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 \n"
            "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 \n"
            "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 \n"
            "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 \n"
            "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 \n"
            "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 \n"
            "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 \n"
            "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 \n"
            "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 \n"
            "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 \n"
            "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 \n"
            "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 \n"
            "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 \n"
            "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 \n"
            "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 \n"
            "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 \n"
            "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 \n"
            "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 \n"
            "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 \n";

    long long int longestHorizontalProduct = getHighestHorizontalProduct(completeGrid);
    printf("\nHighest horizontal product: %lli\n\n", longestHorizontalProduct);

    long long int longestVerticalProduct = getHighestVerticalProduct(completeGrid);
    printf("\nHighest vertical product: %lli\n\n", longestVerticalProduct);

    long long int longestDiagonalLeftRight = getHighestDiagonalLeftRight(completeGrid);
    printf("\nHighest diagonal left right product: %lli\n\n", longestDiagonalLeftRight);

    long long int longestDiagonalRightLeft = getHighestDiagonalRightLeft(completeGrid);
    printf("\nHighest diagonal right left product: %lli\n\n", longestDiagonalRightLeft);

    result = longestHorizontalProduct;
    if (longestVerticalProduct > result) {
        result = longestVerticalProduct;
    }
    if (longestDiagonalLeftRight > result) {
        result = longestDiagonalLeftRight;
    }
    if (longestDiagonalRightLeft > result) {
        result = longestDiagonalRightLeft;
    }

    return result;
}

/**
 * Returns the highest product of numbers in a grid, horizontally.
 */
long long int getHighestHorizontalProduct(char grid[]) {
    // Declare highest number
    long long int highestNumber = 0;

    // Declare variables
    int rows = 20;
    int pairsForEachRow = 20;
    int unusedAroundRow = 1;
    int unusedAroundPair = 1;
    int pairSize = 2;
    int pairsToMultiply = 4;

    // A row consists of pairs times their pair size with whitespaces for each
    int rowSize = (pairsForEachRow * (pairSize + unusedAroundPair)) + unusedAroundRow;

    // Go over each row
    for (int j = 0; j < rows; ++j) {

        // Go over the contents
        int startingPointLocation = j * rowSize;

        // Calculate endpoint location
        int endPointLocation =
                startingPointLocation // Start at location of startingPoint
                + rowSize // Add the complete size of a row
                - unusedAroundPair // Subtract unused chars around the last pair
                - unusedAroundRow // Subtract the unused chars around the row
                - 1; // -1 because index starts at 0

        for (int i = startingPointLocation; // Start at calculated location
             i < endPointLocation -
                 (pairSize + unusedAroundPair) *
                 (pairsToMultiply - 1); // Leave amount of pairs to multiply minus one, we'll get them manually
             i += pairSize + unusedAroundPair) { // Move to the next pair each time

            // Collect all pairs
            int startOfPairOne = i;
            char pair1[3] = {grid[i], grid[startOfPairOne + 1], '\0'};
            int pairOne = atoi(pair1);

            int startOfPairTwo = startOfPairOne + pairSize + unusedAroundPair;
            char pair2[3] = {grid[startOfPairTwo], grid[startOfPairTwo + 1], '\0'};
            int pairTwo = atoi(pair2);

            int startOfPairThree = startOfPairTwo + pairSize + unusedAroundPair;
            char pair3[3] = {grid[startOfPairThree], grid[startOfPairThree + 1], '\0'};
            int pairThree = atoi(pair3);

            int startOfPairFour = startOfPairThree + pairSize + unusedAroundPair;
            char pair4[3] = {grid[startOfPairFour], grid[startOfPairFour + 1], '\0'};
            int pairFour = atoi(pair4);

            long long int product = pairOne * pairTwo * pairThree * pairFour;

            if (product > highestNumber) {
                highestNumber = product;
            }
        }
    }
    return highestNumber;
}

/**
 * Returns the highest product of numbers in a grid, vertically.
 */
long long int getHighestVerticalProduct(char grid[]) {
    // Declare highest number
    long long int highestNumber = 0;

    // Create an array[20] of int[20] items
    int intRows[20][20];

    // Declare variables
    int rows = 20;
    int pairsForEachRow = 20;
    int unusedAroundRow = 1;
    int unusedAroundPair = 1;
    int pairSize = 2;
    int pairsToMultiply = 4;

    // A row consists of pairs times their pair size with whitespaces for each
    int rowSize = (pairsForEachRow * (pairSize + unusedAroundPair)) + unusedAroundRow;

    for (int j = 0; j < rows; ++j) {
        int startingPointLocation = j * rowSize;
        int endPointLocation = startingPointLocation + rowSize - unusedAroundPair - unusedAroundRow - 1;

        int pairNumberInRow = 0;
        for (int i = startingPointLocation;
             i < endPointLocation - (pairSize + unusedAroundPair) * (pairsToMultiply - 1);
             i += (pairSize + unusedAroundPair) * 4) {

            int startOfPairOne = i;
            char pair1[3] = {grid[i], grid[startOfPairOne + 1], '\0'};

            int startOfPairTwo = startOfPairOne + pairSize + unusedAroundPair;
            char pair2[3] = {grid[startOfPairTwo], grid[startOfPairTwo + 1], '\0'};

            int startOfPairThree = startOfPairTwo + pairSize + unusedAroundPair;
            char pair3[3] = {grid[startOfPairThree], grid[startOfPairThree + 1], '\0'};

            int startOfPairFour = startOfPairThree + pairSize + unusedAroundPair;
            char pair4[3] = {grid[startOfPairFour], grid[startOfPairFour + 1], '\0'};

            int rowNumber = i / rowSize;

            intRows[rowNumber][pairNumberInRow] = atoi(pair1);
            intRows[rowNumber][pairNumberInRow + 1] = atoi(pair2);
            intRows[rowNumber][pairNumberInRow + 2] = atoi(pair3);
            intRows[rowNumber][pairNumberInRow + 3] = atoi(pair4);

            pairNumberInRow += 4;
        }
    }

    long long int product = 0;
    for (int k = 0; k < 20; ++k) {
        for (int i = 0; i < 17; i += 1) {
            product = intRows[i][k]
                      * intRows[i + 1][k]
                      * intRows[i + 2][k]
                      * intRows[i + 3][k];
            if (product > highestNumber) {
                highestNumber = product;
            }
        }
    }

    return highestNumber;
}

/**
 * Returns the highest product of numbers in a grid, diagonally starting left top, going right bottom.
 */
long long int getHighestDiagonalLeftRight(char grid[]) {
    //region Variable declaration
    // Declare highest number
    long long int highestNumber = 0;

    // Create an array[20] of int[20] items
    int intRows[20][20];

    // Declare variables
    int rows = 20;
    int pairsForEachRow = 20;
    int unusedAroundRow = 1;
    int unusedAroundPair = 1;
    int pairSize = 2;
    int pairsToMultiply = 4;
    //endregion

    //region 2D Array creation
    // A row consists of pairs times their pair size with whitespaces for each
    int rowSize = (pairsForEachRow * (pairSize + unusedAroundPair)) + unusedAroundRow;

    for (int j = 0; j < rows; ++j) {
        int startingPointLocation = j * rowSize;
        int endPointLocation = startingPointLocation + rowSize - unusedAroundPair - unusedAroundRow - 1;

        int pairNumberInRow = 0;
        for (int i = startingPointLocation;
             i < endPointLocation - (pairSize + unusedAroundPair) * (pairsToMultiply - 1);
             i += (pairSize + unusedAroundPair) * 4) {

            int startOfPairOne = i;
            char pair1[3] = {grid[i], grid[startOfPairOne + 1], '\0'};

            int startOfPairTwo = startOfPairOne + pairSize + unusedAroundPair;
            char pair2[3] = {grid[startOfPairTwo], grid[startOfPairTwo + 1], '\0'};

            int startOfPairThree = startOfPairTwo + pairSize + unusedAroundPair;
            char pair3[3] = {grid[startOfPairThree], grid[startOfPairThree + 1], '\0'};

            int startOfPairFour = startOfPairThree + pairSize + unusedAroundPair;
            char pair4[3] = {grid[startOfPairFour], grid[startOfPairFour + 1], '\0'};

            int rowNumber = i / rowSize;

            intRows[rowNumber][pairNumberInRow] = atoi(pair1);
            intRows[rowNumber][pairNumberInRow + 1] = atoi(pair2);
            intRows[rowNumber][pairNumberInRow + 2] = atoi(pair3);
            intRows[rowNumber][pairNumberInRow + 3] = atoi(pair4);

            pairNumberInRow += 4;
        }
    }
    //endregion

    long long int product = 0;
    for (int k = 0; k < 20 - 3; ++k) {
        for (int i = 0; i < 20 - 3; i += 1) {
            int pair1 = intRows[k][i];
            int pair2 = intRows[k + 1][i + 1];
            int pair3 = intRows[k + 2][i + 2];
            int pair4 = intRows[k + 3][i + 3];
            product = pair1 * pair2 * pair3 * pair4;
//            printf("%i * %i * %i * %i = %lli\n", pair1, pair2, pair3, pair4, product);

            if (product > highestNumber) {
                highestNumber = product;
            }
        }
    }

    return highestNumber;
}

/**
 * Returns the highest product of numbers in a grid, diagonally starting right top, going left bottom.
 */
long long int getHighestDiagonalRightLeft(char grid[]) {
    //region Variable declaration
    // Declare highest number
    long long int highestNumber = 0;

    // Create an array[20] of int[20] items
    int intRows[20][20];

    // Declare variables
    int rows = 20;
    int pairsForEachRow = 20;
    int unusedAroundRow = 1;
    int unusedAroundPair = 1;
    int pairSize = 2;
    int pairsToMultiply = 4;
    //endregion

    //region 2D Array creation
    // A row consists of pairs times their pair size with whitespaces for each
    int rowSize = (pairsForEachRow * (pairSize + unusedAroundPair)) + unusedAroundRow;

    for (int j = 0; j < rows; ++j) {
        int startingPointLocation = j * rowSize;
        int endPointLocation = startingPointLocation + rowSize - unusedAroundPair - unusedAroundRow - 1;

        int pairNumberInRow = 0;
        for (int i = startingPointLocation;
             i < endPointLocation - (pairSize + unusedAroundPair) * (pairsToMultiply - 1);
             i += (pairSize + unusedAroundPair) * 4) {

            int startOfPairOne = i;
            char pair1[3] = {grid[i], grid[startOfPairOne + 1], '\0'};

            int startOfPairTwo = startOfPairOne + pairSize + unusedAroundPair;
            char pair2[3] = {grid[startOfPairTwo], grid[startOfPairTwo + 1], '\0'};

            int startOfPairThree = startOfPairTwo + pairSize + unusedAroundPair;
            char pair3[3] = {grid[startOfPairThree], grid[startOfPairThree + 1], '\0'};

            int startOfPairFour = startOfPairThree + pairSize + unusedAroundPair;
            char pair4[3] = {grid[startOfPairFour], grid[startOfPairFour + 1], '\0'};

            int rowNumber = i / rowSize;

            intRows[rowNumber][pairNumberInRow] = atoi(pair1);
            intRows[rowNumber][pairNumberInRow + 1] = atoi(pair2);
            intRows[rowNumber][pairNumberInRow + 2] = atoi(pair3);
            intRows[rowNumber][pairNumberInRow + 3] = atoi(pair4);

            pairNumberInRow += 4;
        }
    }
    //endregion

    long long int product = 0;
    for (int k = 0; k < 20 - 3; ++k) {
        for (int i = 3; i < 20; i += 1) {
//            printf("k: %i, i: %i\n", k, i);
            int pair1 = intRows[k][i];
            int pair2 = intRows[k + 1][i - 1];
            int pair3 = intRows[k + 2][i - 2];
            int pair4 = intRows[k + 3][i - 3];
            product = pair1 * pair2 * pair3 * pair4;
//            printf("%i * %i * %i * %i = %lli\n", pair1, pair2, pair3, pair4, product);
//
            if (product > highestNumber) {
                highestNumber = product;
            }
        }
    }

    return highestNumber;
}