/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 22:34:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static bool	wait_func(long long time, t_philo *info)
{
	long long endtime;

	endtime = getnowtime_ms();
	while (getnowtime_ms() - endtime < time * 1000)
	{
		if (getnowtime_ms() - endtime > info->all_info->time_to_die * 1000)
		{
			pthread_mutex_lock(&(info->all_info->diecheck));
			if (info->all_info->philo_die_ornot == true)
			{
				pthread_mutex_unlock(&(info->all_info->diecheck));
				return (false);
			}
			print_die(info->all_info, info->number_of_philo, "died");
			info->all_info->philo_die_ornot = true;
			pthread_mutex_unlock(&(info->all_info->diecheck));
			return (false);
		}
		usleep(100);
	}
	return (true);
}

bool	eat_drop(t_philo *info, int l_f, int r_f, size_t pn)
{
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;

	lf = &(info->all_info->forks[l_f]);
	rf = &(info->all_info->forks[r_f]);
	pthread_mutex_lock(lf);
	if (print_action(info->all_info, pn, "has taken a fork") == false)
		return (error_unlockonefork(lf));
	if (l_f == r_f)
		return (error_unlockonefork(lf));
	pthread_mutex_lock(rf);
	if (print_action(info->all_info, pn, "has taken a fork") == false)
		return (error_unlockallfork(lf, rf));
	if (print_action(info->all_info, pn, "is eating") == false)
		return (error_unlockallfork(lf, rf));
	livestart_ch(info);
	if (wait_func(info->time_to_eat, info) == false)
		return (error_unlockallfork(lf, rf));
	unlock_allfork(lf, rf);
	info->how_eated = info->how_eated + 1;
	return (true);
}

bool	sleeping(t_philo *info)
{
	if (print_action(info->all_info, info->number_of_philo, "is sleeping") == false)
		return (false);
	if (wait_func(info->time_to_sleep, info) == false)
		return (false);
	if (print_action(info->all_info, info->number_of_philo, "is thinking") == false)
		return (false);
	return (true);
}
