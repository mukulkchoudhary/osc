#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
void h(int s) { printf("\nGot SIGCLD no=%d\n", s); wait(NULL); }
int main() {
    signal(SIGCLD, h);
    if (fork() == 0) {
        printf("Child running...\n");
        sleep(2);
        printf("Child exiting\n");
        exit(0);
    } else {
        while (1) { printf("Parent...\n"); sleep(1); }
    }
    return 0;
}
