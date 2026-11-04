#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    signal(SIGINT, SIG_DFL);
    printf("User: %s\n", getenv("USER"));
    printf("Press Ctrl+C to see default action\n");
    while (1) sleep(1);
    return 0;
}
