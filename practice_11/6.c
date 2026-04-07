#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int sz;
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) { perror("r1"); exit(1); }

    sz = write(fd, "hello OS&SP\n", strlen("hello OS&SP\n"));

    printf("called write(%d, \"hello OS&SP\\n\", %lu). It returned %d\n",
           fd, strlen("hello OS&SP\n"), sz);

    close(fd);
    return 0;
}
