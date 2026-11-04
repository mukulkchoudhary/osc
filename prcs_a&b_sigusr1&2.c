#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
void a_handler(int s) { printf("A: I am awake (signal %d)\n", s); }
void b_handler(int s) { printf("B: I am awake (signal %d)\n", s); }

int main() {
    int p = fork();
    if (p == 0) {
        signal(SIGUSR2, b_handler);
        printf("B (PID %d) sleeping...\n", getpid());
        while (1) pause();
    } else {
        signal(SIGUSR1, a_handler);
        printf("A (PID %d) sleeping...\n", getpid());
        sleep(1);
        kill(p, SIGUSR2);       // wake B
        sleep(1);
        kill(getpid(), SIGUSR1); // wake A
        sleep(1);
        kill(p, SIGKILL);
        wait(NULL);
    }
    return 0;
}
