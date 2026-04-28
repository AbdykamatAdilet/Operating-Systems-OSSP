#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    int *arr = (int*) calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    arr[2] = 42;
    printf("After update: arr[2] = %d\n", arr[2]);

    free(arr);
    arr = NULL;

    return 0;
}
