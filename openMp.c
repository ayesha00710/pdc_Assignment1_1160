#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // OpenMP Library

#define N 500 // Matrix size
#define NUM_THREADS 4 // Number of threads

void multiplyMatricesStatic(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for collapse(2) num_threads(NUM_THREADS) schedule(static)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    static int A[N][N], B[N][N], C[N][N]; // Use static to avoid stack overflow
    double start, end;

    // Initialize Matrices with 1s
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
            C[i][j] = 0;
        }
    }

    // **Static Scheduling Execution**
    start = omp_get_wtime();
    multiplyMatricesStatic(A, B, C);
    end = omp_get_wtime();

    printf("Execution Time (Static Scheduling): %.6f seconds\n", end - start);

    return 0;
}
