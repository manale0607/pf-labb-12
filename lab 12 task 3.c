#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char *str = (char *)malloc(n * 100 * sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", (str + i * 100));
   }

    char temp[100];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str + i * 100, str + j * 100) > 0) {
                strcpy(temp, str + i * 100);
                strcpy(str + i * 100, str + j * 100);
                strcpy(str + j * 100, temp);
            }
        }
    }
    printf("\nSorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", (str + i * 100));
    }

    free(str);
    return 0;
}

