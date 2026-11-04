#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void h(int s) { printf("\nSIGHUP no=%d\n", s); exit(0); }
int main() {
    signal(SIGHUP, h);
    while (1) { printf("Waiting...\n"); sleep(2); }
}
