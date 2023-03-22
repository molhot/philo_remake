/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 19:53:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	philo_deathistrue(size_t philo_num, t_allinfo *info)
{
	long	long	now;

	pthread_mutex_lock(&(info->timecheck_same[philo_num]));
	now = getnowtime_ms();
	if (now - info->philoinfo[philo_num].philo_livedstart > info->time_to_die * 1000)
	{
		pthread_mutex_lock(&(info->diecheck));
		if (info->philo_die_ornot == true)
		{
			pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
			pthread_mutex_unlock(&(info->diecheck));
			return (false);
		}
		if (print_die(info, philo_num + 1, "died") == false)
		{
			pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
			pthread_mutex_unlock(&(info->diecheck));
			return (false);
		}
		info->philo_die_ornot = true;
		pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
		pthread_mutex_unlock(&(info->diecheck));
		return (false);
	}
	pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
	return (true);
}

void	*philo_checker(void *info_i)
{
	size_t		philo_num;
	t_allinfo	*info;
	size_t		countup;

	philo_num = 0;
	countup = 0;
	info = (t_allinfo *)info_i;
	while (1)
	{
		while ((info->philoinfo)[countup].correctend == true)
		{
			countup++;
			if (countup == info->philo_num)
				return (NULL);
		}
		countup = 0;
		if ((info->philoinfo)[philo_num].correctend == false)
			if (philo_deathistrue(philo_num, info) == false)
				return (NULL);
		philo_num++;
		if (philo_num == info->philo_num)
			philo_num = 0;
		usleep(1000);
	}
	return (NULL);
}
