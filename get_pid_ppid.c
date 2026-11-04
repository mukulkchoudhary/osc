#include <stdio.h>
#include <unistd.h>
int main() {
    int p = fork();
    if (p == 0)
        printf("Child: PID=%d, Parent=%d\n", getpid(), getppid());
    else
        printf("Parent: PID=%d, Child=%d\n", getpid(), p);
    return 0;
}
