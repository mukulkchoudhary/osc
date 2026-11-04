#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    int d = atoi(argv[1]);
    int p = fork();
    if (p == 0) {
        sleep(d + 3);
        printf("Child done\n");
    } else {
        sleep(d);
        if (waitpid(p, NULL, WNOHANG) == 0) {
            printf("Child not done, killing it\n");
            kill(p, SIGKILL);
        } else {
            printf("Child finished within time\n");
        }
    }
    return 0;
}
