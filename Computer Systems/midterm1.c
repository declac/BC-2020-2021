#include <stdio.h>
#include <stdlib.h>
int square(int base);
void squares_sequence(int * buffer, int num) {
    for (int i = 0; i < num; ++i) {
        buffer[i] = square(i + 1);
    }
}

int square(int base) {
    return base * base;
}
void print_sequence(int * squares, int num) {
    for (int i = 0; i < num; ++i) {
        printf("%d ", squares[i]);
    }
    printf("\n");
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Please enter an integer for the number of squares desired.\n");
        exit(EXIT_FAILURE);
    }
    int num = atoi(argv[1]);
    int * buffer = (int *)malloc(num * sizeof(int));
    squares_sequence(buffer, num);
    print_sequence(buffer, num);
    free(buffer);
    return EXIT_SUCCESS;
}