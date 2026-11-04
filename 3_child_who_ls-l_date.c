#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    if (fork() == 0) { execlp("who", "who", NULL); }
    if (fork() == 0) { execlp("ls", "ls", "-l", NULL); }
    if (fork() == 0) { execlp("date", "date", NULL); }
    wait(NULL); wait(NULL); wait(NULL);
    printf("All children finished\n");
    return 0;
}
