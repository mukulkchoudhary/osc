#include <stdio.h>
#include <unistd.h>
int main() {
    int p = fork();
    if (p == 0)
        printf("Child exiting...\n");
    else {
        sleep(5);
        printf("Parent: child is zombie now\n");
    }
    return 0;
}
