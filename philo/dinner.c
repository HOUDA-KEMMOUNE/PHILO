/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:20:28 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/17 08:20:34 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime());
	increase_long(&philo->table->table_mutex, &philo->table->threads_running_nbr);
	write_status(TAKEN_A_FORK, philo);
	while (!sim_finished(philo->table))
		precise_usleep(philo->table->time_to_sleep, philo->table);
	return (NULL);	
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->num_philo == 1)
		pthread_create(&table->philos[0].thread_id,
			NULL, one_philo, &table->philos[0]);
}
