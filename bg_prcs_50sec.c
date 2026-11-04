#include <stdio.h>
#include <unistd.h>
int main() {
    if (fork() == 0) {
        sleep(50);
        printf("System info printed after 50s\n");
        system("uname -a");
    } else {
        printf("Parent exiting, child runs in background\n");
    }
    return 0;
}
