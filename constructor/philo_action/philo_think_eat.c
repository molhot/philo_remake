/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 18:47:38 by user             ###   ########.fr       */
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

bool	eat_drop(t_philo *info, int l_f, int r_f)
{
	pthread_mutex_lock(&info->all_info->forks[l_f]);
	if (l_f == r_f || print_action(info->all_info, info->number_of_philo, "has taken a fork") == false)
		return (error_unlockonefork(&info->all_info->forks[l_f]));
	pthread_mutex_lock(&info->all_info->forks[r_f]);
	if (print_action(info->all_info, info->number_of_philo, "has taken a fork") == false)
		return (error_unlockallfork(&info->all_info->forks[l_f], &info->all_info->forks[r_f]));
	if (print_action(info->all_info, info->number_of_philo, "is eating") == false)
		return (error_unlockallfork(&info->all_info->forks[l_f], &info->all_info->forks[r_f]));
	livestart_ch(info);
	if (wait_func(info->time_to_eat, info) == false)
		return (error_unlockallfork(&info->all_info->forks[l_f], &info->all_info->forks[r_f]));
	unlock_allfork(&info->all_info->forks[l_f], &info->all_info->forks[r_f]);
	info->how_eated = info->how_eated + 1;
	return (true);
}

bool	sleeping(t_philo *info)
{
	if (print_action(info->all_info, info->number_of_philo, "is sleeping") == false)
		return (false);
	if (info->time_to_sleep > info->all_info->time_to_die)
		return (false);
	if (wait_func(info->time_to_sleep, info) == false)
		return (false);
	if (print_action(info->all_info, info->number_of_philo, "is thinking") == false)
		return (false);
	return (true);
}
