//semhitinit.c — Initialize semaphore
#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
int main() {
    int key = ftok(".", 'a');
    int sem = semget(key, 1, IPC_CREAT | 0666);
    semctl(sem, 0, SETVAL, 1);
    printf("Semaphore created. key=%d semid=%d\n", key, sem);
    return 0;
}
//semhit1.c — Locks semaphore, does work
#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
struct sembuf op = {0, -1, 0};    // P operation (wait)
int main() {
    int key = ftok(".", 'a');
    int sem = semget(key, 1, 0666);
    semop(sem, &op, 1);
    printf("semhit1: Locked. Working...\n");
    sleep(5);
    struct sembuf v = {0, 1, 0};   // V operation (signal)
    semop(sem, &v, 1);
    printf("semhit1: Done. Released.\n");
    return 0;
}
//semhit2.c — Waits until semhit1 releases
#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
struct sembuf op = {0, -1, 0};
int main() {
    int key = ftok(".", 'a');
    int sem = semget(key, 1, 0666);
    printf("semhit2: Waiting for semhit1...\n");
    semop(sem, &op, 1);
    printf("semhit2: Got it! Running now.\n");
    struct sembuf v = {0, 1, 0};
    semop(sem, &v, 1);
    return 0;
}
