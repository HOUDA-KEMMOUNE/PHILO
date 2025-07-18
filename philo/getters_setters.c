/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:56:25 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/07/18 18:56:27 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(t_mtx *mutex, bool value)
{
	bool	res;

	pthread_mutex_lock(mutex);
	res = value;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(t_mtx *mutex, long value)
{
	long	res;

	pthread_mutex_lock(mutex);
	res = value;
	pthread_mutex_unlock(mutex);
	return (res);
}
