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

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int			philo_id;
	long		meal_counter;
	int			full; //A flag or boolean
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	long	num_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_each_philo_must_eat;
	long	start_simulation;
	long	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}				t_table;

//----------parsing.c--------------
int		check_args(int ac, char **av);
int		check_numbers(int ac, char **av);

//---------utils.c-----------------
long	ft_atol(const char *str);

#endif