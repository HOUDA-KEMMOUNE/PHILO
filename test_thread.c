#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void *thread_function(void *arg)
{
    (void)arg;
    pthread_t tid;

    tid = pthread_self();
    printf("the ID of this thread is ==> [%ld]\n", tid);
    return (NULL); //ghaymout
}

int main()
{
    pthread_t   thread_id;
    
    printf("------------Hello, Threads!------------\n");
    pthread_create(&thread_id, NULL, thread_function, NULL);
    printf("the ID of this thread is ==> [%ld]  (in the main function)\n", thread_id);
    pthread_join(thread_id, NULL); // Wait for the thread to finish
    return (0);
}
// thread => fucntion
// main thread => main()