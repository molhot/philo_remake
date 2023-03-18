/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:30:09 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/17 15:30:09 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	unlock_rightfork(t_philo *info, int r_f)
{
	pthread_mutex_unlock(&info->all_info->forks[r_f]);
}

bool	error_unlockrightfork(t_philo *info, int r_f)
{
	unlock_rightfork(info, r_f);
	return (false);
}

void	unlock_leftfork(t_philo *info, int l_f)
{
	pthread_mutex_unlock(&info->all_info->forks[l_f]);
}

bool	error_unlockleftfork(t_philo *info, int l_f)
{
	unlock_rightfork(info, l_f);
	return (false);
}
