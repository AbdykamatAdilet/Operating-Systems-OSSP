#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*) calloc(10, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    int *tmp = (int*) realloc(arr, 5 * sizeof(int));

    if (tmp == NULL) {
        printf("Realloc failed!\n");
        free(arr);
        return 1;
    }

    arr = tmp;

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}
