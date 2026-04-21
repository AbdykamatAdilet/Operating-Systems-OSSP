#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char wbuf[] = "Hello from pipe!";
    char rbuf[64] = {0};

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], rbuf, 64);
        printf("Child received: %s\n", rbuf);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], wbuf, strlen(wbuf));
        close(pipefd[1]);
    }

    return 0;
}
