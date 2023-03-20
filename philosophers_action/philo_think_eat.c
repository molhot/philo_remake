/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:59:29 by satushi           #+#    #+#             */
/*   Updated: 2023/03/21 00:36:34 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	eat_countup(t_philo *info)
{
	info->how_eated = info->how_eated + 1;
	livestart_ch(info);
	return (true);
}

bool	eat_drop(t_philo *info, int l_f, int r_f)
{
	if (pthread_mutex_lock(&info->all_info->forks[l_f]) != 0)
		return (false);
	if (print_action(info, "has taken a fork") == false)
		return (error_unlockleftfork(info, l_f));
	if (l_f == r_f)
		return (error_unlockleftfork(info, l_f));
	if (pthread_mutex_lock(&info->all_info->forks[r_f]) != 0)
		return (error_unlockleftfork(info, l_f));
	if (print_action(info, "has taken a fork") == false)
		return (error_unlokallfork(info, l_f, r_f));
	if (print_action(info, "is eating") == false)
		return (error_unlokallfork(info, l_f, r_f));
	if (info->all_info->time_to_eat > info->all_info->time_to_die)
	{
		unlock_allfork(info, l_f, r_f);
		return (false);
	}
	usleep(1000 * (long long)info->all_info->time_to_eat);
	unlock_allfork(info, l_f, r_f);
	if (eat_countup(info) == false)
		return (false);
	return (true);
}

bool	think(t_philo *info)
{
	bool	diecheck;

	pthread_mutex_lock(&(info->all_info->diecheck));
	diecheck = info->all_info->philo_die_ornot;
	pthread_mutex_unlock(&(info->all_info->diecheck));
	if (diecheck == true)
		return (false);
	if (print_action(info, "is thinking") == false)
		return (false);
	if (info->all_info->time_to_think > info->all_info->time_to_die)
		return (false);
	usleep(1000 * info->all_info->time_to_think);
	return (true);
}

bool	sleeping(t_philo *info)
{
	bool	diecheck;

	pthread_mutex_lock(&(info->all_info->diecheck));
	diecheck = info->all_info->philo_die_ornot;
	pthread_mutex_unlock(&(info->all_info->diecheck));
	if (diecheck == true)
		return (false);
	if (print_action(info, "is sleeping") == false)
		return (false);
	if (info->all_info->time_to_sleep > info->all_info->time_to_die)
		return (false);
	usleep(1000 * info->all_info->time_to_sleep);
	if (info->number_of_philo == 2 && info->all_info->philo_num % 2 == 1)
		usleep(200);
	return (true);
}

//1 ~~~~~~XXXXXXXXXXXXXX~~~~~~~~
//2 XXXXXXXXXXXXX~~~~~~~XXXXXXXX
//3 XXXXXX~~~~~~~XXXXXXXXXXXXXXX