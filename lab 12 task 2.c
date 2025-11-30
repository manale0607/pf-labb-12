#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter initial size of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    arr = (int *)realloc(arr, 2 * n * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("Enter %d more elements:\n", n);
    for (i = n; i < 2 * n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUpdated array elements:\n");
    for (i = 0; i < 2 * n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}

