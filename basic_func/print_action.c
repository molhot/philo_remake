/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:21:51 by satushi           #+#    #+#             */
/*   Updated: 2023/03/18 13:41:52 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	print_action(t_philo *info, char *action)
{
	bool		diecheck;

	pthread_mutex_lock(&(info->all_info->diecheck));
	diecheck = info->all_info->philo_die_ornot;
	pthread_mutex_unlock(&(info->all_info->diecheck));
	if (diecheck == true)
		return (false);
	pthread_mutex_lock(&info->all_info->write);
	printf("%lld %ld %s\n", getnowtime(), info->number_of_philo, action);
	pthread_mutex_unlock(&info->all_info->write);
	return (true);
}
