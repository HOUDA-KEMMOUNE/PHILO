/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:17:57 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/16 10:17:59 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check(const char *str, int i)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 10)
	{
		printf("The number is too long. The max is: INT_MAX\n");
		return (-1);
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	i = check(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (check_len(&str[i]) == -1)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((long)result * sign);
}
// ./philo 		5 			600 			200 			800 					[5]
//			num_philo	time_to_die		time_to_eat		time_to_sleep	[num_each_philo_must_eat]

int	parse_input(t_table *table, char **av)
{
	table->num_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	// printf("table->time_to_die === %ld\n", table->time_to_die);
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
	{
		printf("The times should be greater than 60ms !\n");
		return (1);
	}
	if (av[5])
		table->num_each_philo_must_eat = ft_atol(av[1]);
	else
		table->num_each_philo_must_eat = -1;
	return (0);
}
