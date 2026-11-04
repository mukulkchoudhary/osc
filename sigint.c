#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void h(int s) { printf("\nSIGINT no=%d\n", s); }
int main() {
    signal(SIGINT, h);
    while (1) { printf("Running...\n"); sleep(1); }
}
