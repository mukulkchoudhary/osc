#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *ignore_fn(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    while (1) { printf("Ignore thread running\n"); sleep(1); }
    return NULL;
}
void *obey_fn(void *arg) {
    while (1) { printf("Obey thread running\n"); sleep(1); }
    return NULL;
}
int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, ignore_fn, NULL);
    pthread_create(&t2, NULL, obey_fn, NULL);
    sleep(2);
    pthread_cancel(t1);
    pthread_cancel(t2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main done\n");
    return 0;
}
