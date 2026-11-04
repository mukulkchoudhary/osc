#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main() {
    signal(SIGINT, SIG_IGN);
    printf("Ctrl+C ignored for 5 seconds...\n");
    sleep(5);
    signal(SIGINT, SIG_DFL);
    printf("Default restored. Press Ctrl+C to kill.\n");
    while (1) sleep(1);
    return 0;
}
