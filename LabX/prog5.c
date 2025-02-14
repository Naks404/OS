#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    printf("Task 1: Forking 3 times\n");
    fork_three_times();

    printf("\nTask 2: Pipe communication\n");
    pipe_communication();

    printf("\nTask 3: Signal communication\n");
    signal_communication();

    printf("\nTask 4: Writing PID to file\n");
    write_pid_to_file();

    printf("\nTask 5: Adding 3 integers\n");
    int x = 3, y = 4, z = 5, sum;
    add(&x, &y, &z, &sum);
    printf("Sum: %d\n", sum);

    return 0;
}

