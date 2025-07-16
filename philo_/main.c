/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:33:29 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/12 16:33:31 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info **ultimate_info(void)
{
	static t_info	*info;
	return (&info);
}

void	info_init(char **av)
{
	t_info	*args = malloc(sizeof(t_info));

	args->num_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		args->num_each_philo_must_eat = ft_atoi(av[5]);
	*ultimate_info() = args;
}

// void	philo_routine(void *data)
// {

// }

int	main(int ac, char **av)
{
	// int			i;
	// pthread_t	tid;

	if (check_numbers(ac, av) == 1)
		return (1);
	info_init(av);
	create_list(5);
	return(0);
}
