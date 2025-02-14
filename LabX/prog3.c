#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void signal_communication() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child waiting for signal... (PID: %d)\n", getpid());
        pause();
    } else {
        sleep(1);
        kill(pid, SIGTERM);
        printf("Parent sent SIGTERM to child\n");
        wait(NULL);
    }
}

