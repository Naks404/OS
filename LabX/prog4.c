#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void write_pid_to_file() {
    int fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    pid_t pid = fork();
    if (pid == 0) {
        dprintf(fd, "Child PID: %d\n", getpid());
    } else {
        dprintf(fd, "Parent PID: %d\n", getpid());
        wait(NULL);
    }
    close(fd);
}
