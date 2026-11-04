#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void h(int s) {
    printf("Handler called! Signal = %d\n", s);
}
int main() {
    signal(SIGUSR1, h);
    printf("Raising SIGUSR1 to myself\n");
    raise(SIGUSR1);
    printf("Done\n");
    return 0;
}
