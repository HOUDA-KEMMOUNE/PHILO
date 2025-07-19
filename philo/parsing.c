/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:15:16 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/16 10:15:18 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_table *table, char **av)
{
	table->num_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}

// int	check_args(int ac, char **av)
// {
// 	if (av[1] == NULL || ac < 5 || ac > 6)
// 	{
// 		if (ac < 5)
// 			printf("Few arguments\n");
// 		else if (ac > 6)
// 			printf("Many arguments\n");
// 		return (1);
// 	}
// 	return (0);
// }

// int	check_numbers(int ac, char **av)
// {
// 	int		i;
// 	int		j;

// 	if (check_args(ac, av) == 1)
// 		return (1);
// 	i = 1;
// 	j = 0;
// 	while (av[i] && i < ac)
// 	{
// 		while (av[i][j])
// 		{
// 			if ((av[i][j] >= '0' && av[i][j] <= '9')
// 				|| (av[i][j] == '+'))
// 				j++;
// 			else
// 			{
// 				printf("Invalid character: %c\n", av[i][j]);
// 				return (1);
// 			}
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	return (0);
// }
