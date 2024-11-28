#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID=%d, Parent PID=%d\n", getpid(), getppid());
        sleep(2);  // Simulate child task
        printf("Child process finished.\n");
    } else {
        // Parent process
        printf("Parent Process: PID=%d, waiting for child...\n", getpid());
        wait(NULL);  // Wait for child to finish
        printf("Child process completed. Parent resuming.\n");
    }

    return 0;
}
