/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:43:20 by user              #+#    #+#             */
/*   Updated: 2023/03/22 19:53:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	start_philolife(t_philo *subject)
{
	if (pthread_create(&(subject->philo_thread), NULL, \
	&philolife_life, (void *)(subject)) != 0)
		return (false);
	return (true);
}

static bool	startlife(t_allinfo *info, size_t *philo_num)
{
	if (start_philolife(&((info->philoinfo)[*philo_num])) == false)
		return (false);
	*philo_num = *philo_num + 2;
	return (true);
}

static	bool	checker_start(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	if (pthread_create(&info->checkthread, NULL, \
	&philo_checker, (void *)info) != 0)
		return (false);
	usleep(100);
	while (philo_num != info->philo_num)
	{
		pthread_join((info->philoinfo[philo_num]).philo_thread, NULL);
		philo_num++;
	}
	if (pthread_join(info->checkthread, NULL) != 0)
		return (false);
	return (true);
}

bool    constructer(t_allinfo *info)
{
    size_t	philo_num;

	philo_num = 0;
	while (philo_num < info->philo_num)
		startlife(info, &philo_num);
	usleep(200);
	philo_num = 1;
	while (philo_num < info->philo_num)
		startlife(info, &philo_num);
	usleep(200);
	if (checker_start(info) == false)
		return (false);
	return (true);
}
