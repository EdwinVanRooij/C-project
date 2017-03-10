#include <stdio.h>

int main() {
    int initial_list[1000];

    int total;
    for (int i = 0; i < sizeof(initial_list) / sizeof(initial_list[0]); ++i) {
        if (i <= 0) {
            continue;
        }
        if (i % 5 == 0 || i % 3 == 0) {
            total += i;
        }
    }
    printf("Total is: %d", total);
}

