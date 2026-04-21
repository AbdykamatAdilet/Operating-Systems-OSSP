#include <stdio.h>
#include <stdlib.h>

struct threeNum {
    int n1, n2, n3;
};

int main() {
    int n;
    struct threeNum num;
    FILE *fptr;

    if ((fptr = fopen("program.bin", "wb")) == NULL) {
        printf("Error! Opening file");
        exit(1);
    }

    printf("Reading numbers from file:\n");

    for (n = 1; n < 5; ++n) {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
    }

    fclose(fptr);

    return 0;
}
