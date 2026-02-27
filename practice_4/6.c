#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { // child
        execlp("gedit", "gedit", NULL);
        perror("execlp failed");
        return 1;
    } else if (pid > 0) { // parent
        wait(NULL);
        printf("Child complete\n");
    } else {
        perror("fork failed");
    }

    return 0;
}
