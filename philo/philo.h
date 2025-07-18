/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:33:36 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/16 09:33:39 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int			philo_id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_mtx		*first_fork;
	t_mtx		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long		num_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nnbr_limit_meals;
	long		start_simulation;
	long		threads_running_nbr;
	long		philos_full;
	bool		end_simulation;
	bool		all_threads_ready;
	t_mtx		*forks;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	pthread_t	monitor;
	t_philo		*philos;
}				t_table;

//----------parsing.c--------------
int		check_args(int ac, char **av);
int		check_numbers(int ac, char **av);

//---------utils.c-----------------
long	ft_atol(char *str);
int		parse_input(t_table *table, char **av);

//---------init.c-----------------
void	data_init(t_table *table);

#endif
