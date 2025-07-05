#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_b_func(void *arg) {
    int *thread_a_stack_var = (int *)arg;
    printf("Thread B: Value of Thread A's stack var = %d\n", *thread_a_stack_var);

    // Modify Thread A's stack variable
    *thread_a_stack_var = 12345;
    printf("Thread B: Changed value of Thread A's stack var!\n");

    return NULL;
}

void *thread_a_func(void *arg) {
    int stack_var = 42; // This lives on Thread A's stack
    unsigned long thread_b;

    // Pass pointer to stack_var to Thread B
    pthread_create(&thread_b, NULL, thread_b_func, &stack_var);

    // Sleep a bit to give Thread B time to access the variable
    usleep(200);

    printf("Thread A: Value of stack_var after Thread B = %d\n", stack_var);

    pthread_join(thread_b, NULL);
    return NULL;
}

int main() {
    unsigned long thread_a;
    pthread_create(&thread_a, NULL, thread_a_func, NULL);
    pthread_join(thread_a, NULL);
    return 0;
}