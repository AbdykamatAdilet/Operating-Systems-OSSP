#include <stdio.h>
#include <unistd.h>
int main () {
    fork();
    printf("moooooo\n");
    fork();
    printf("beeeeeee\n");
    fork();
    printf("woooooov\n");
    return 0;
}
