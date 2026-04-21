#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("sample.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, "Hello OS&SP!", 12);

    off_t pos = lseek(fd, 0, SEEK_SET);
    printf("Position = %ld\n", pos);

    char buf[13] = {0};
    read(fd, buf, 12);
    printf("Read: %s\n", buf);

    off_t size = lseek(fd, 0, SEEK_END);
    printf("File size = %ld bytes\n", size);

    close(fd);
    return 0;
}
