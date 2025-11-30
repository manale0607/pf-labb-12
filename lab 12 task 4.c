#include <stdio.h>
#include <stdlib.h>
int main() {
    int N, extraDays, i;
    float total = 0;
    printf("Enter number of days for sales data: ");
    scanf("%d", &N);
    float *sales = (float *)malloc(N * sizeof(float));

    if (sales == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter sales data for %d days:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%f", &sales[i]);
    }

    for (i = 0; i < N; i++) {
        total += sales[i];
    }

    printf("\nTotal sales for %d days = %.2f\n", N, total);

    total = 0; 
    printf("\nEnter number of additional days: ");
    scanf("%d", &extraDays);

    sales = (float *)realloc(sales, (N + extraDays) * sizeof(float));

    if (sales == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("Enter sales for additional %d days:\n", extraDays);
    for (i = N; i < N + extraDays; i++) {
        scanf("%f", &sales[i]);
    }

    for (i = 0; i < N + extraDays; i++) {
        total += sales[i];
    }

    printf("\nUpdated total sales for %d days = %.2f\n", N + extraDays, total);

    free(sales);

    return 0;
}
