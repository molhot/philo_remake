/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_philosinfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:51:36 by user              #+#    #+#             */
/*   Updated: 2023/03/22 20:04:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static	bool	philosmutex_init(t_allinfo *allinfo)
{
	if (pthread_mutex_init(&(allinfo->write), NULL) != 0)
	{
		mutex_error();
		return (false);
	}
	if (pthread_mutex_init(&(allinfo->diecheck), NULL) != 0)
	{
		pthread_mutex_destroy(&allinfo->write);
		mutex_error();
		return (false);
	}
	return (true);
}

static	bool	freereturn(t_allinfo *info)
{
	malloc_error();
	free_mutex(info);
	return (false);
}

static	bool	create_forks(t_allinfo *info)
{
	size_t	fork_num;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	info->timecheck_same = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (info->forks == NULL || info->timecheck_same == NULL)
		return (freereturn(info));
	fork_num = 0;
	while (fork_num != info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[fork_num], NULL) != 0)
			return (freereturn(info));
		if (pthread_mutex_init(&info->timecheck_same[fork_num], NULL) != 0)
			return (freereturn(info));
		fork_num++;
	}
	return (true);
}

bool	ready_philosinfo(t_allinfo *info, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->philo_die_ornot = false;
    if (philosmutex_init(info) == false)
        return (false);
    if (create_forks(info) == false)
        return (false);
	return (true);
}
