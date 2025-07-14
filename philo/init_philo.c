/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:29:26 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/12 21:29:29 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**philo_list(void)
{
	static t_philo	*philo;
	return (&philo);
}

t_philo	*add_node(t_philo *philosopher)
{
	t_philo	*tmp;
	t_philo	*node;

	tmp = philosopher;
	node = malloc(sizeof(t_philo));
	if (philosopher == NULL)
	{
		philosopher = node;
		node->next = philosopher;
		return (philosopher);
	}
	while (tmp->next != philosopher)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
	node->next = philosopher;
	return (node);
}

void	create_list(int	philo_num)
{
	t_philo	**philosopher;
	int		i;

	philosopher = philo_list();
	i = 0;
	while(i < philo_num)
	{
		*philosopher = add_node(*philosopher);
		(*philosopher)->id = i + 1;
		i++;		
	}
	if(*philo_list() == NULL)
		printf("masd9atch\n");

}
