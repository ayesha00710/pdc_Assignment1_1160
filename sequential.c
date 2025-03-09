#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500 // Matrix size

void multiplyMatrices(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    static int A[N][N], B[N][N], C[N][N]; // Use static to avoid stack overflow
    clock_t start, end;

    // Initialize matrices A and B with 1s
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }

    // Measure execution time
    start = clock();
    multiplyMatrices(A, B, C);
    end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC; // Convert to seconds
    printf("Execution Time: %.6f seconds\n", timeTaken);

    return 0;
}
