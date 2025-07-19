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

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKEN_A_FORK,
	DIED,
}	t_philo_status;

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
	long		nbr_limit_meals;
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
void	parse_input(t_table *table, char **av);

//---------utils.c-----------------
long	ft_atol(char *str);

//---------init.c-----------------
void	data_init(t_table *table);

//---------getters_setters.c-----------------
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	sim_finished(t_table *table);

//---------write.c-----------------
void	write_status(t_philo_status status, t_philo *philo);

//---------dinner.c-----------------
void	dinner_start(t_table *table);
void	*lone_philo(void *data);
void	*dinner_simulation(void *data);

//---------synchro_utils.c-----------------
void	increase_long(t_mtx *mutex, long *value);
void	wait_all_threads(t_table *table);
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);

//---------utils2.c-----------------
void	precise_usleep(long sleep_time, t_table *table);
long	gettime(void);
void	error_exit(char *error);
void	clean(t_table *table);

//---------monitor.c-----------------
void	*monitor_dinner(void *data);

#endif
