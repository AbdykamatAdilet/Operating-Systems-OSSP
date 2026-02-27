#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 5
int nums[SIZE] = {0,1,2,3,4};

int main()
{
    int i;
    pid_t pid; // <- исправлено

    pid = fork();

    if (pid == 0) { // child
        for (i = 0; i < SIZE; i++) {
            nums[i] *= -i;
            printf("CHILD: %d ", nums[i]); /* LINE X */
        }
        printf("\n");
    }
    else if (pid > 0) { // parent
        wait(NULL); // ждем ребёнка
        for (i = 0; i < SIZE; i++)
            printf("PARENT: %d ", nums[i]); /* LINE Y */
        printf("\n");
    }

    return 0;
}
