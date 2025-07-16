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

int	check_args(int ac, char **av)
{
	if (av[1] == NULL || ac < 5 || ac > 6)
	{
		if (ac < 5)
			printf("Few arguments\n");
		else if (ac > 6)
			printf("Many arguments\n");
		return (1);
	}
	return (0);
}

int	check_numbers(int ac, char **av)
{
	int		i;
	int		j;

	if (check_args(ac, av) == 1)
		return (1);
	i = 1;
	j = 0;
	while (av[i] && i < ac - 1)
	{
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9')
				|| (av[i][j] == '+'))
				j++;
			else
			{
				printf("Invalid character: %c\n", av[i][j]);
				return (1);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
