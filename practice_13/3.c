#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char buffer[100];

    fptr = fopen("demo.txt", "w");
    if (fptr == NULL) {
        perror("Error creating file");
        return 1;
    }

    fprintf(fptr, "Hello, C File Handling!");
    fclose(fptr);

    fptr = fopen("demo.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fgets(buffer, 100, fptr) != NULL) {
        printf("Content of file: %s\n", buffer);
    }

    fclose(fptr);
    return 0;
}
