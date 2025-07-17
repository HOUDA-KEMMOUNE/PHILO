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

static void	assign_forks(t_philo *philo, t_fork *forks,
			int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->num_philo;
	philo->first_fork = &forks[philo_position];
	if (philo_nbr % 2)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->num_philo)
	{
		philo = table->philos + i;
		philo->philo_id = i + 1;
		philo->full = false;
		philo->meal_counter = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}

void	data_init(t_table *table)
{
	int		i;

	i = -1;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philos = malloc(sizeof(t_philo) * table->num_philo);
	table->forks = malloc(sizeof(t_fork) * table->num_philo);
	pthread_mutex_init(&table->table_mutex, NULL);
	while (++i < table->num_philo)
	{
    	pthread_mutex_init(&table->forks[i].fork, NULL);
    	table->forks[i].fork_id = i;
	}
	philo_init(table);
}

