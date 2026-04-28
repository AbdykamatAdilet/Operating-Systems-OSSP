#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*) malloc(3 * sizeof(int));

    if (!arr) return 1;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    printf("Before realloc: %d %d %d\n", arr[0], arr[1], arr[2]);

    int *tmp = (int*) realloc(arr, 6 * sizeof(int));

    if (!tmp) {
        free(arr);
        return 1;
    }

    arr = tmp;

    arr[3] = 40;
    arr[4] = 50;
    arr[5] = 60;

    for (int i = 0; i < 6; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
