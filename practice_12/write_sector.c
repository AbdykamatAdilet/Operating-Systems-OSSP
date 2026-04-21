#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SECTOR_SIZE 512

int writeSector(int fd, int sector_number, const unsigned char *buf) {
    off_t offset = sector_number * SECTOR_SIZE;

    if (lseek(fd, offset, SEEK_SET) == -1)
        return -1;

    if (write(fd, buf, SECTOR_SIZE) != SECTOR_SIZE)
        return -1;

    return 0;
}

int main() {
    unsigned char buf[SECTOR_SIZE];
    memset(buf, 0xAB, SECTOR_SIZE);

    int fd = open("disk.img", O_RDWR);

    if (writeSector(fd, 5, buf) == 0)
        printf("Sector written\n");

    close(fd);
    return 0;
}
