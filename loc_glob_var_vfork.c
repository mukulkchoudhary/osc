#include <stdio.h>
#include <unistd.h>
int g = 10;
int main() {
    int l = 20;
    if (vfork() == 0) {
        g++; l++;
        printf("Child: g=%d l=%d\n", g, l);
        _exit(0);
    } else {
        printf("Parent: g=%d l=%d\n", g, l);
    }
    return 0;
}
