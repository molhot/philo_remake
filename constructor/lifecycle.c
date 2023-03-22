/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:54:22 by user              #+#    #+#             */
/*   Updated: 2023/03/22 22:45:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philolife_life(void *info_t)
{
	t_philo		*info;

	info = (t_philo *)info_t;
	if (info->number_of_philo == info->all_info->philo_num && info->all_info->philo_num % 2 == 1)
		usleep(200);
	livestart_ch(info);
	while (1)
	{
		if (eat_drop(info, info->fork_info.l_fork, \
		info->fork_info.r_fork, info->number_of_philo) == false)
			return (NULL);
		if (info->eat_limit != -1 && info->eat_limit <= (int)info->how_eated)
			break ;
		if (sleeping(info) == false)
			return (NULL);
	}
	info->correctend = true;
	return (NULL);
}
