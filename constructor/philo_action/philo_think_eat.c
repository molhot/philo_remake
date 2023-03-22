/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 14:59:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void	wait_func(long long time)
{
	long long endtime;

	endtime = getnowtime_ms();
	while (getnowtime_ms() - endtime < time * 1000)
		usleep(1000);
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
	if (info->all_info->time_to_eat > info->all_info->time_to_die)
		return (error_unlockallfork(&info->all_info->forks[l_f], &info->all_info->forks[r_f]));
	livestart_ch(info);
	wait_func(info->all_info->time_to_eat);
	unlock_allfork(&info->all_info->forks[l_f], &info->all_info->forks[r_f]);
	info->how_eated = info->how_eated + 1;
	return (true);
}

bool	sleeping(t_philo *info)
{
	if (print_action(info->all_info, info->number_of_philo, "is sleeping") == false)
		return (false);
	if (info->all_info->time_to_sleep > info->all_info->time_to_die)
		return (false);
	wait_func(info->all_info->time_to_sleep);
	if (print_action(info->all_info, info->number_of_philo, "is thinking") == false)
		return (false);
	return (true);
}
