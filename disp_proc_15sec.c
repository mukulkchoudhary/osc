#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    for (int i = 1; i <= 5; i++) {
        printf("\n=== Display %d ===\n", i);
        system("ps -af");
        if (i < 5) sleep(30);
    }
    return 0;
}
