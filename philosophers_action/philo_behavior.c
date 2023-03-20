/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:34:43 by satushi           #+#    #+#             */
/*   Updated: 2023/03/21 00:35:36 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philolife_life(void *info_t)
{
	t_philo		*info;

	info = (t_philo *)info_t;
	livestart_ch(info);
	while (1)
	{
		if (eat_drop(info, info->fork_info.l_fork, \
		info->fork_info.r_fork) == false)
			return (NULL);
		if (info->eat_limit <= (int)info->how_eated)
			break ;
		if (sleeping(info) == false)
			return (NULL);
		if (think(info) == false)
			return (NULL);
	}
	info->all_info->eatend_count = info->all_info->eatend_count + 1;
	info->correctend = true;
	return (NULL);
}

void	*philolife_life_ult(void *info_t)
{
	t_philo	*info;

	info = (t_philo *)info_t;
	livestart_ch(info);
	while (1)
	{
		if (eat_drop(info, info->fork_info.l_fork, \
		info->fork_info.r_fork) == false)
			return (NULL);
		if (sleeping(info) == false)
			return (NULL);
		if (think(info) == false)
			return (NULL);
	}
	return (NULL);
}
