#include "philo.h"

void    wait_all_threads(t_table *table)
{
    while (!get_bool(&table->table_mutex, table->all_threads_ready))
        ;
}

void    increase_long(t_mtx *mutex, long *value)
{
    pthread_mutex_lock(mutex);
    (*value)++;
    pthread_mutex_unlock(mutex);
}
