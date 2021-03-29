#include <stdio.h>
#include <stdlib.h>

void multiply_standard(int  n, int a[n][n], int b[n][n], int c[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[i][j];
            }
        }
    }
}

void transpose(int n, int a[n][n], int b[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            b[i][j] = a[j][i];
}

void init(int n, int matrix[n][n]) {
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}


void multiply_transpose(int  n, int a[n][n], int b[n][n], int c[n][n]) {
    transpose(n, b, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[i][j];
            }
        }
    }
    transpose(n, b, b);
}
/*

void print(int n, int matrix[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", matrix[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    int n = 4;
    int a[n][n];
    int b[n][n];
    int d[n][n];
    int c[n][n];
    int e[n][n];
    init(n, a);
    init(n, b);
    //transpose(n, b, d);
    multiply_standard(n, a, b, c);
    multiply_transpose(n, a, b, e);
    //transpose(n, e, e);
    print(n, a);
    putchar('\n');
    print(n, b);
    putchar('\n');
    print(n, c);
    putchar('\n');
    print(n, e);
    return 0;
}
