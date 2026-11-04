#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    for (int i = 0; i < 2; i++) {
        if (fork() == 0) {
            for (int j = 1; j <= 10; j++)
                printf("Child %d: %d (PID=%d, PPID=%d)\n", i+1, j, getpid(), getppid());
            return 0;
        }
    }
    wait(NULL); wait(NULL);
    printf("Good Bye\n");
    return 0;
}
