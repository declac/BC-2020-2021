void init(int n, int matrix[n][n]) {
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}