#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    FILE *t1 = fopen("foo.txt","w"); fprintf(t1,"foo\n"); fclose(t1);
    FILE *t2 = fopen("bar.txt","w"); fprintf(t2,"bar\n"); fclose(t2);

    int fd1 = open("foo.txt", O_RDONLY, 0);
    printf("fd1 = %d\n", fd1);
    close(fd1);

    int fd2 = open("bar.txt", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);
    exit(0);
}
