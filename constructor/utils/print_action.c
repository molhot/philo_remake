/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:51 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 22:22:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

bool	print_action(t_allinfo *info, size_t pn, char *action)
{
	pthread_mutex_lock(&(info->diecheck));
	if (info->philo_die_ornot == true)
	{
		pthread_mutex_unlock(&(info->diecheck));
		return (false);
	}
	pthread_mutex_lock(&info->write);
	printf("%lld %ld %s\n", getnowtime(), pn, action);
	pthread_mutex_unlock(&info->write);
	pthread_mutex_unlock(&(info->diecheck));
	return (true);
}

bool	print_die(t_allinfo *info, size_t pn, char *action)
{
	pthread_mutex_lock(&info->write);
	printf("%lld %ld %s\n", getnowtime(), pn, action);
	pthread_mutex_unlock(&info->write);
	return (true);
}
