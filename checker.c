/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/21 23:06:28 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_deathistrue(size_t philo_num, t_allinfo *info)
{
	long	long	now;

	pthread_mutex_lock(&(info->timecheck_same[philo_num]));
	now = getnowtime_ms();
	if (now - info->philoinfo[philo_num].philo_livedstart > info->time_to_die * 1000)
	{
		pthread_mutex_lock(&(info->diecheck));
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

	philo_num = 0;
	info = (t_allinfo *)info_i;
	sleep(1);
	return (NULL);
	while (1)
	{
		if (info->eatend_count == info->philo_num)
			return (NULL);
		if ((info->philoinfo)[philo_num].correctend == false)
			if (philo_deathistrue(philo_num, info) == false)
				return (NULL);
		philo_num++;
		if ((int)philo_num == info->philo_num)
			philo_num = 0;
		usleep(1000);
	}
	return (NULL);
}
