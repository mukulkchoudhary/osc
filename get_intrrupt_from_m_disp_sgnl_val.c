#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void h(int s) {
    printf("\nSignal received: %d\n", s);
}
int main() {
    signal(SIGINT, h);
    signal(SIGTSTP, h);
    signal(SIGQUIT, h);
    printf("Press Ctrl+C, Ctrl+Z, or Ctrl+\\\n");
    while (1) sleep(1);
    return 0;
}
