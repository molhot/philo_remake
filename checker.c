/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/21 00:34:12 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_deathistrue(size_t philo_num, t_allinfo *info)
{
	long long	appnedtime;

	pthread_mutex_lock(&(info->timecheck_same[philo_num]));
	appnedtime = info->philoinfo[philo_num].philo_livedstart;
	if ((getnowtime() - appnedtime) > info->time_to_die)
	{
		if (print_action(&(info->philoinfo[philo_num]), "died") == false)
		{
			pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
			return (false);
		}
		pthread_mutex_lock(&(info->diecheck));
		info->philo_die_ornot = true;
		pthread_mutex_unlock(&(info->diecheck));
		pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
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
		usleep(300);
	}
	return (NULL);
}
