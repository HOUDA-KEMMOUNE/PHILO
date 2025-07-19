#include "philo.h"

void    write_status(t_philo_status status, t_philo *philo)
{
    long    current_time;

    if (philo->full)
        return ;
    current_time = gettime() - philo->table->start_simulation;
    pthread_mutex_lock(&philo->table->write_mutex);
    if (status == TAKEN_A_FORK && !sim_finished(philo->table))
		printf("%-6ld %d has taken a fork\n", current_time, philo->philo_id);
	else if (status == EATING && !sim_finished(philo->table))
		printf("%-6ld %d is eating\n", current_time, philo->philo_id);
	else if (status == SLEEPING && !sim_finished(philo->table))
		printf("%-6ld %d is sleeping\n", current_time, philo->philo_id);
	else if (status == THINKING && !sim_finished(philo->table))
		printf("%-6ld %d is thinking\n", current_time, philo->philo_id);
	else if (status == DIED)
		printf("%-6ld %d died", current_time, philo->philo_id);
	pthread_mutex_unlock(&philo->table->write_mutex);
}
