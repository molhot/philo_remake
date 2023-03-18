/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/03/18 06:22:30 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philolife_life(void *info_t)
{
	t_philo		*info;
	int			eatcount;

	info = (t_philo *)info_t;
	pthread_mutex_lock(&(info->all_info-> \
	timecheck_same[info->number_of_philo - 1]));
	info->philo_livedstart = getnowtime();
	pthread_mutex_unlock(&(info->all_info-> \
	timecheck_same[info->number_of_philo - 1]));
	while (1)
	{
		if (eat_drop(info, info->fork_info.l_fork, \
		info->fork_info.r_fork) == false)
			return (NULL);
		pthread_mutex_lock(&(info->all_info->status[info->number_of_philo - 1]));
		eatcount = (int)info->how_eated;
		if (info->eat_limit <= eatcount)
		{
			pthread_mutex_unlock(&(info->all_info->status[info->number_of_philo - 1]));
			break ;
		}
		pthread_mutex_unlock(&(info->all_info->status[info->number_of_philo - 1]));
		if (sleeping(info) == false)
			return (NULL);
		if (think(info) == false)
			return (NULL);
	}
	return (NULL);
}

void	*philolife_life_ult(void *info_t)
{
	t_philo	*info;

	info = (t_philo *)info_t;
	pthread_mutex_lock(&(info->all_info-> \
	timecheck_same[info->number_of_philo - 1]));
	info->philo_livedstart = getnowtime();
	pthread_mutex_unlock(&(info->all_info-> \
	timecheck_same[info->number_of_philo - 1]));
	while (1)
	{
		if (eat_drop(info, info->fork_info.l_fork, \
		info->fork_info.r_fork) == false)
			return (NULL);
		if (sleeping(info) == false)
			return (NULL);
		if (think(info) == false)
			return (NULL);
	}
	return (NULL);
}
