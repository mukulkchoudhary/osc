#include <stdio.h>
#include <pthread.h>
int a, b;
void *sum_fn(void *arg) {
    int s = 0;
    for (int i = a; i <= b; i++) s += i;
    printf("Sum = %d\n", s);
    return (void*)(long)s;
}
void *prime_fn(void *arg) {
    printf("Primes: ");
    for (int i = a; i <= b; i++) {
        int p = 1;
        for (int j = 2; j < i; j++)
            if (i % j == 0) { p = 0; break; }
        if (i > 1 && p) printf("%d ", i);
    }
    printf("\n");
    return (void*)1L;
}
int main() {
    printf("Enter range: ");
    scanf("%d %d", &a, &b);
    pthread_t t1, t2;
    void *r1, *r2;
    pthread_create(&t1, NULL, sum_fn, NULL);
    pthread_create(&t2, NULL, prime_fn, NULL);
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);
    printf("Return values: %ld, %ld\n", (long)r1, (long)r2);
    return 0;
}
