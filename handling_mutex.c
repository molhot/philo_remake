/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:27:12 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 18:27:12 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	mutexinit(t_allinfo *allinfo)
{
	if (pthread_mutex_init(&(allinfo->write), NULL) != 0)
		return (false);
	if (pthread_mutex_init(&(allinfo->correctend), NULL) != 0)
		return (false);
	if (pthread_mutex_init(&(allinfo->diecheck), NULL) != 0)
		return (false);
	return (true);
}

static	bool	freereturn(t_allinfo *info)
{
	free_mutex(info);
	return (false);
}

bool	create_forks(t_allinfo *info)
{
	int	fork_num;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->status = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->timecheck_same = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (info->forks == NULL || info->status == NULL \
	|| info->timecheck_same == NULL)
		return (freereturn(info));
	fork_num = 0;
	while (fork_num != info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[fork_num], NULL) != 0)
			return (freereturn(info));
		if (pthread_mutex_init(&info->status[fork_num], NULL) != 0)
			return (freereturn(info));
		if (pthread_mutex_init(&info->timecheck_same[fork_num], NULL) != 0)
			return (freereturn(info));
		fork_num++;
	}
	return (true);
}
