#include "philo.h"

long    gettime(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

void    precise_usleep(long sleep_time, t_table *table)
{
    long    start;

    start = gettime();
    while (gettime() - start < sleep_time)
    {
        if (sim_finished(table))
            break ;
        usleep(10);
    }
}
