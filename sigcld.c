#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
void h(int s) { printf("\nSIGCLD no=%d\n", s); wait(NULL); }
int main() {
    signal(SIGCLD, h);
    if (fork() == 0) { sleep(2); exit(0); }
    while (1) { printf("Parent...\n"); sleep(1); }
}
