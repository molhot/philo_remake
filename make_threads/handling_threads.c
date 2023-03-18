/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:14 by satushi           #+#    #+#             */
/*   Updated: 2023/03/18 13:45:55 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static	bool	checker_start(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	if (pthread_create(&info->checkthread, NULL, \
	&philo_checker, (void *)info) != 0)
		return (false);
	usleep(100);
	while ((int)philo_num != info->philo_num)
	{
		pthread_join((info->philoinfo[philo_num]).philo_thread, NULL);
		philo_num++;
	}
	if (pthread_join(info->checkthread, NULL) != 0)
		return (false);
	return (true);
}

bool	create_threads(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	while ((int)philo_num < info->philo_num)
		even_pn_startlife(info, &philo_num);
	usleep(200);
	philo_num = 1;
	while ((int)philo_num < info->philo_num)
		add_pn_startlife(info, &philo_num);
	usleep(200);
	if (checker_start(info) == false)
		return (false);
	return (true);
}

bool	create_threads_ult(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	while ((int)philo_num < info->philo_num)
		even_pn_startultlife(info, &philo_num);
	usleep(200);
	philo_num = 1;
	while ((int)philo_num < info->philo_num)
		add_pn_startultlife(info, &philo_num);
	philo_num = 0;
	while ((int)philo_num != info->philo_num)
	{
		pthread_join((info->philoinfo[philo_num]).philo_thread, NULL);
		philo_num++;
	}
	usleep(200);
	if (checker_start(info) == false)
		return (false);
	return (true);
}
