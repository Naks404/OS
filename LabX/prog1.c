#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void fork_three_times() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
            exit(0);
        }
        wait(NULL);
    }
}

