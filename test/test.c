#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <limits.h>

#define THREAD_COUNT 4000
#define MAGENTA "\033[35m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define NC "\e[0m"

typedef struct s_count
{
	pthread_mutex_t	key;
	unsigned int	count;

}				t_count;

void    *pthread_handler(void *arg)
{
	unsigned int    *count;
	unsigned int    i;
	pthread_t       tid1;

	count = (unsigned int  *)arg;
	i = 0;
	tid1 = pthread_self();
	// printf("%sThread[%ld]: THREAD_COUNT (start) ===> %u%s\n", MAGENTA, tid1, *count, NC);
	printf("\033[35mThread[%ld]: THREAD_COUNT (start) ===> %u\e[0m\n", tid1, *count);
	while (i < THREAD_COUNT)
	{
		(*count)++;
		i++;
	}
	printf("%sThread[%ld]: %s", CYAN, tid1, NC);
	printf("THREAD_COUNT ===> %u\n", *count);
	return (NULL);
}

int main()
{
	pthread_t       tid1;
	pthread_t       tid2;
	pthread_t       tid3;
	t_count			counter;
	// unsigned int    count;

	// count = 0;
	counter.count = 0;
	pthread_mutex_init(&counter.key, NULL);
	//creating the threads
	pthread_create(&tid1, NULL, pthread_handler, &counter.count);
	// sleep(1);
	pthread_create(&tid2, NULL, pthread_handler, &counter.count);
	// sleep(1);
	pthread_create(&tid3, NULL, pthread_handler, &counter.count);
	// sleep(1);

	//waiting for threads
	pthread_join(tid1, NULL);
	printf("Waiting the first thread ....\n");
	pthread_join(tid2, NULL);
	printf("Waiting the second thread ....\n");
	pthread_join(tid3, NULL);
	printf("Waiting the third thread ....\n");
	if (counter.count != (THREAD_COUNT * 3))
	{
		printf("%sERROR: Total threads are: %u%s\n", RED, counter.count, NC);
		return (1);
	}
	else
	{
		printf("%sTotal threads are: %u%s\n", GREEN, counter.count, NC);
		return (0);
	}
}
