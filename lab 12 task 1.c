#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p;
    int i, j, k;

    printf("Enter rows and columns for Matrix A (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter columns for Matrix B (p): ");
    scanf("%d", &p);
    int *A = (int *)malloc(m * n * sizeof(int));
    int *B = (int *)malloc(n * p * sizeof(int));
    int *C = (int *)malloc(m * p * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter values for Matrix A (%dx%d):\n", m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i*n + j]); 

    printf("\nEnter values for Matrix B (%dx%d):\n", n, p);
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            scanf("%d", &B[i*p + j]);

    // Matrix Multiplication
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            C[i*p + j] = 0;
            for (k = 0; k < n; k++) {
                C[i*p + j] += A[i*n + k] * B[k*p + j];
            }
        }
    }

    printf("\nResultant Matrix C (%dx%d):\n", m, p);
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%d ", C[i*p + j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}

