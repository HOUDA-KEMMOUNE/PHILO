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

// int	main(int ac, char **av)
// {
// 	t_table	table;

// 	if (check_numbers(ac, av) == 1)
// 		return (1);
// 	if (parse_input(&table, av) == 1)
// 		return (1);
// 	data_init(&table);
// 	dinner_start(&table);
// 	clean(&table);
// }

int	main(int ac, char **av)
{
	t_table	table;

	if (5 == ac || 6 == ac)
	{
		parse_input(&table, av);
		data_init(&table);
		dinner_start(&table);
		clean(&table);
	}
	else
	{
		error_exit("Wrong input:\n"
			"Correct is ./philo 5 800 200 200 [5]");
	}
	return (0);
}
