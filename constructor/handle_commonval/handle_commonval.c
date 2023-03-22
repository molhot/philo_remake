/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commonval.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:24:20 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/18 23:24:20 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

bool	die_check(t_allinfo *info)
{
	bool	val;

	pthread_mutex_lock(&(info->diecheck));
	val = info->philo_die_ornot;
	pthread_mutex_unlock(&(info->diecheck));
	return (val);
}

void	livestart_ch(t_philo *info)
{
	pthread_mutex_lock(&(info->all_info-> \
	timecheck_same[info->number_of_philo - 1]));
	info->philo_livedstart = getnowtime_ms();
	pthread_mutex_unlock(&(info->all_info-> \
	timecheck_same[info->number_of_philo - 1]));
}
