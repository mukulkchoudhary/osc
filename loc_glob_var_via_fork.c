#include <stdio.h>
#include <unistd.h>
int g = 10;
int main() {
    int l = 20;
    if (fork() == 0) {
        g++; l++;
        printf("Child: g=%d l=%d\n", g, l);
    } else {
        sleep(1);
        printf("Parent: g=%d l=%d\n", g, l);
    }
    return 0;
}
