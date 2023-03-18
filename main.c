/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:02 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 18:07:02 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	ready_philoinfo(t_allinfo *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->time_to_think = 0;
	info->philo_die_ornot = false;
	if (argc == 6)
		info->eat_limit = ft_atoi(argv[5]);
	else
		info->eat_limit = -1;
}

static	bool	makingthread(t_allinfo *allinfo)
{
	if (allinfo->eat_limit != -1)
	{
		if (create_threads(allinfo) == false)
		{
			free(allinfo->philoinfo);
			return (false);
		}
	}
	else
	{
		if (create_threads_ult(allinfo) == false)
		{
			free(allinfo->philoinfo);
			return (false);
		}
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_allinfo	allinfo;

	if (arg_check(argc, argv) == false)
		return (1);
	ready_philoinfo(&allinfo, argc, argv);
	if (mutexinit(&allinfo) == false)
		return (1);
	if (create_forks(&allinfo) == false)
		return (1);
	if (create_samephilo(&allinfo) == false)
		return (1);
	if (makingthread(&allinfo) == false)
	{
		mutex_destroy(&allinfo);
		return (1);
	}
	mutex_destroy(&allinfo);
	free(allinfo.philoinfo);
	free_mutex(&allinfo);
}
