/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_philoinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:23:28 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 19:23:28 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	insert_info_tophilo(int philonum, t_allinfo *info)
{
	((info->philoinfo)[philonum - 1]).fork_info.r_fork = philonum - 2;
	((info->philoinfo)[philonum - 1]).fork_info.l_fork = philonum - 1;
	((info->philoinfo)[philonum - 1]).how_eated = 0;
	((info->philoinfo)[philonum - 1]).number_of_philo = philonum;
	((info->philoinfo)[philonum - 1]).correctend = false;
	((info->philoinfo)[philonum - 1]).eat_limit = info->eat_limit;
	((info->philoinfo)[philonum - 1]).all_info = info;
}

bool	create_samephilo(t_allinfo *info)
{
	int	l_f_n;

	l_f_n = 2;
	info->philoinfo = (t_philo *)malloc(sizeof(t_allinfo) * info->philo_num);
	if (info->philoinfo == NULL)
		return (false);
	while (l_f_n != info->philo_num + 1)
	{
		insert_info_tophilo(l_f_n, info);
		l_f_n++;
	}
	((info->philoinfo)[0]).fork_info.r_fork = 0;
	((info->philoinfo)[0]).fork_info.l_fork = info->philo_num - 1;
	((info->philoinfo)[0]).how_eated = 0;
	((info->philoinfo)[0]).number_of_philo = 1;
	((info->philoinfo)[0]).time_to_die = 0;
	((info->philoinfo)[0]).correctend = false;
	((info->philoinfo)[0]).eat_limit = info->eat_limit;
	((info->philoinfo)[0]).all_info = info;
	return (true);
}
