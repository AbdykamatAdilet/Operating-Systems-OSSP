#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SECTOR_SIZE 512

int readSector(int fd, int sector_number, unsigned char *buf) {
    off_t offset = sector_number * SECTOR_SIZE;

    if (lseek(fd, offset, SEEK_SET) == -1)
        return -1;

    if (read(fd, buf, SECTOR_SIZE) != SECTOR_SIZE)
        return -1;

    return 0;
}

int main() {
    unsigned char buf[SECTOR_SIZE];

    int fd = open("disk.img", O_RDONLY);

    if (readSector(fd, 0, buf) == 0) {
        printf("First bytes: %02X %02X %02X %02X\n",
               buf[0], buf[1], buf[2], buf[3]);
    }

    close(fd);
    return 0;
}
