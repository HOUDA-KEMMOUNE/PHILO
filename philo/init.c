/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:19:43 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/17 01:19:45 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, pthread_mutex_t *forks, int i)
{
	int	philo_nbr;

	philo_nbr = philo->table->num_philo;
	if (philo->philo_id % 2 == 0)
	{
		philo->first_fork = &forks[i];
		if (philo->philo_id == philo_nbr)
			philo->second_fork = &forks[0];
		else
			philo->second_fork = &forks[philo->philo_id];
	}
	else
	{
		philo->second_fork = &forks[i];
		if (philo->philo_id == philo_nbr)
			philo->first_fork = &forks[0];
		else
			philo->first_fork = &forks[philo->philo_id];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->num_philo)
	{
		philo = table->philos + i;
		philo->philo_id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->last_meal_time = 0;
		philo->table = table;
		pthread_mutex_init(&philo->philo_mutex, NULL);
		assign_forks(philo, table->forks, i);
	}
}

void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end_simulation = false;
	table->philos_full = 0;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;
	table->philos = malloc(sizeof(t_philo) * table->num_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	pthread_mutex_init(&table->table_mutex, NULL);
	pthread_mutex_init(&table->write_mutex, NULL);
	while (++i < table->num_philo)
		pthread_mutex_init(&table->forks[i], NULL);
	philo_init(table);
}
