#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    // Создаём тестовый файл
    FILE *tmp = fopen("sample.txt","w");
    fprintf(tmp, "ABCDEFGH");
    fclose(tmp);

    char c;
    int fd1 = open("sample.txt", O_RDONLY, 0);
    int fd2 = open("sample.txt", O_RDONLY, 0);

    read(fd1, &c, 1);   // fd1 читает 'A'
    read(fd2, &c, 1);   // fd2 тоже читает 'A' (независимая позиция!)

    printf("c = %c\n", c);

    close(fd1); close(fd2);
    exit(0);
}
