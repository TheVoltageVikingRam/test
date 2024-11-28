#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    // Both parent and child execute this code
    printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
    return 0;
}
