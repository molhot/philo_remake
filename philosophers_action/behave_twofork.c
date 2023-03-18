/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_twofork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:35:06 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/17 15:35:06 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	unlock_allfork(t_philo *info, int l_f, int r_f)
{
	pthread_mutex_unlock(&info->all_info->forks[r_f]);
	pthread_mutex_unlock(&info->all_info->forks[l_f]);
}

bool	error_unlokallfork(t_philo *info, int l_f, int r_f)
{
	unlock_allfork(info, l_f, r_f);
	return (false);
}
