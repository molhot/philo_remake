/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:38:57 by satushi           #+#    #+#             */
/*   Updated: 2023/03/19 00:34:13 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_deathistrue(size_t philo_num, t_allinfo *info)
{
	long long	appnedtime;

	pthread_mutex_lock(&(info->timecheck_same[philo_num]));
	appnedtime = info->philoinfo[philo_num].philo_livedstart;
	pthread_mutex_unlock(&(info->timecheck_same[philo_num]));
	if ((getnowtime() - appnedtime) > info->time_to_die)
	{
		if (print_action(&(info->philoinfo[philo_num]), "died") == false)
			return ;
		pthread_mutex_lock(&(info->diecheck));
		info->philo_die_ornot = true;
		pthread_mutex_unlock(&(info->diecheck));
	}
}

bool	check_eatsatisfied(t_allinfo *info, int philonum)
{
	int	eatcount;

	pthread_mutex_lock(&(info->status[philonum]));
	eatcount = (int)info->philoinfo[philonum].how_eated;
	pthread_mutex_unlock(&(info->status[philonum]));
	if (info->eat_limit == eatcount)
		return (true);
	return (false);
}

static	bool	countup_f(t_allinfo *info, size_t philo_num, size_t *countup)
{
	if ((info->philoinfo)[philo_num].correctend == false \
	&& check_eatsatisfied(info, philo_num) == true)
	{
		*countup = *countup + 1;
		(info->philoinfo)[philo_num].correctend = true;
	}
	if ((int)*countup == info->philo_num)
		return (true);
	return (false);
}

void	*philo_checker(void *info_i)
{
	size_t		philo_num;
	size_t		countup;
	t_allinfo	*info;

	philo_num = 0;
	countup = 0;
	info = (t_allinfo *)info_i;
	while (1)
	{
		if (die_check(info) == true)
			return (NULL);
		if (info->eat_limit != -1)
			if (true == countup_f(info, philo_num, &countup))
				break ;
		if ((info->philoinfo)[philo_num].correctend == false)
			philo_deathistrue(philo_num, info);
		philo_num++;
		if ((int)philo_num == info->philo_num)
			philo_num = 0;
		usleep(300);
	}
	return (NULL);
}
