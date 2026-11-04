#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <ctype.h>
int main() {
    DIR *d = opendir("/proc");
    struct dirent *e;
    while ((e = readdir(d))) {
        if (!isdigit(e->d_name[0])) continue;
        int pid = atoi(e->d_name);
        if (pid % 2 == 0 && pid != getpid()) {
            printf("Killing %d\n", pid);
            kill(pid, SIGKILL);
        }
    }
    closedir(d);
    return 0;
}
