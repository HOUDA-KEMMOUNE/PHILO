/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:11:33 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/16 10:11:35 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 600 200 800 [5]

int	main(int ac, char **av)
{
	t_table	table;

	if (check_numbers(ac, av) == 1)
		return (1);
	if (parse_input(&table, av) == 1)
		return (1);
	// data_init(&table); //TODO
}
