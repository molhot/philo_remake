/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:06:43 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/18 03:06:43 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	mutex_destroy_component(t_allinfo *info)
{
	pthread_mutex_destroy(&info->write);
	pthread_mutex_destroy(&info->diecheck);
}

void	mutex_destroy(t_allinfo *info)
{
	size_t	num;

	num = 0;
	pthread_mutex_destroy(&info->write);
	pthread_mutex_destroy(&info->diecheck);
	while (num != info->philo_num)
	{
		pthread_mutex_destroy(&info->forks[num]);
		pthread_mutex_destroy(&info->timecheck_same[num]);
		num++;
	}
}
