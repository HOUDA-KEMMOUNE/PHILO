/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:01:54 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/12 17:01:56 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_each_philo_must_eat;
}				t_info;

int		ft_atoi(const char *str);
void	info_init(char **av);
t_info	**ultimate_info(void);

//-----------parsing------------------
int		check_numbers(int ac ,char **av);
int		check_args(int ac, char **av);

# endif

