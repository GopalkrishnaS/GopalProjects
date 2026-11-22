#include <stdio.h>

int main() {
    int size;

    printf("Enter the diamond size: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Please enter a positive number.");
        return 0;
    }

    for (int row = 1; row <= size; ++row) {
        for (int space = 0; space < size - row; ++space)
            printf(" ");
        for (int star = 0; star < 2 * row - 1; ++star)
            printf("*");
        printf("\n");
    }

    for (int row = size - 1; row >= 1; --row) {
        for (int space = 0; space < size - row; ++space)
            printf(" ");
        for (int star = 0; star < 2 * row - 1; ++star)
            printf("*");
        printf("\n");
    }

    return 0;
}