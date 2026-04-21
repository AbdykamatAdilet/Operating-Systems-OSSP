#include <stdio.h>
#include <string.h>

int main() {
    FILE *filePointer;

    char dataToBeWritten[50] = "KBTU 2026 01 - OS & SP class";

    filePointer = fopen("Demo.c", "w");

    if (filePointer == NULL) {
        printf("Demo.c file failed to open.");
    } else {
        printf("The file is now opened.\n");

        if (strlen(dataToBeWritten) > 0) {
            fputs(dataToBeWritten, filePointer);
            fputs("\n", filePointer);
        }

        fclose(filePointer);

        printf("Data successfully written in file Demo.c\n");
        printf("The file is now closed.\n");
    }

    return 0;
}
