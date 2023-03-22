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

#include "../../philosophers.h"

static	void	insert_info_tophilo(int philonum, t_allinfo *info, char **argv, int argc)
{
	((info->philoinfo)[philonum - 1]).fork_info.r_fork = philonum - 2;
	((info->philoinfo)[philonum - 1]).fork_info.l_fork = philonum - 1;
	((info->philoinfo)[philonum - 1]).how_eated = 0;
	((info->philoinfo)[philonum - 1]).number_of_philo = philonum;
	((info->philoinfo)[philonum - 1]).correctend = false;
	if (argc == 6)
		((info->philoinfo)[philonum - 1]).eat_limit = ft_atoi(argv[5]);
	else
		((info->philoinfo)[philonum - 1]).eat_limit = -1;
	((info->philoinfo)[philonum - 1]).all_info = info;
	((info->philoinfo)[philonum - 1]).time_to_eat = ft_atoi(argv[3]);
	((info->philoinfo)[philonum - 1]).time_to_sleep = ft_atoi(argv[4]);
	((info->philoinfo)[philonum - 1]).time_to_think = 0;
}

bool	create_samephilo(t_allinfo *info, char **argv, int argc)
{
	size_t	l_f_n;

	l_f_n = 2;
	info->philoinfo = (t_philo *)malloc(sizeof(t_allinfo) * info->philo_num);
	if (info->philoinfo == NULL)
	{
		malloc_error();
		return (false);
	}
	while (l_f_n != info->philo_num + 1)
	{
		insert_info_tophilo(l_f_n, info, argv, argc);
		l_f_n++;
	}
	((info->philoinfo)[0]).fork_info.r_fork = 0;
	((info->philoinfo)[0]).fork_info.l_fork = info->philo_num - 1;
	((info->philoinfo)[0]).how_eated = 0;
	((info->philoinfo)[0]).number_of_philo = 1;
	((info->philoinfo)[0]).time_to_die = 0;
	((info->philoinfo)[0]).correctend = false;
	if (argc == 6)
		((info->philoinfo)[0]).eat_limit = ft_atoi(argv[5]);
	else
		((info->philoinfo)[0]).eat_limit = -1;
	((info->philoinfo)[0]).all_info = info;
	((info->philoinfo)[0]).time_to_eat = ft_atoi(argv[3]);
	((info->philoinfo)[0]).time_to_sleep = ft_atoi(argv[4]);
	((info->philoinfo)[0]).time_to_think = 0;
	return (true);
}
