#include <stdio.h>
#include <unistd.h>
int main() {
    int p = fork();
    if (p == 0) {
        sleep(2);
        printf("Child: Parent PID = %d\n", getppid());
    } else {
        printf("Parent exiting...\n");
    }
    return 0;
}
