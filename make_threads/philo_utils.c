/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:39:32 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/18 04:39:32 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	start_philolife(t_philo *subject)
{
	if (pthread_create(&(subject->philo_thread), NULL, \
	&philolife_life, (void *)(subject)) != 0)
		return (false);
	//pthread_detach(subject->philo_thread);
	return (true);
}

bool	even_pn_startlife(t_allinfo *info, size_t *philo_num)
{
	if (start_philolife(&((info->philoinfo)[*philo_num])) == false)
		return (false);
	*philo_num = *philo_num + 2;
	return (true);
}

bool	add_pn_startlife(t_allinfo *info, size_t *philo_num)
{
	if ((*philo_num) % 2 == 1 && *philo_num == 1)
		usleep(100);
	if (start_philolife(&((info->philoinfo)[*philo_num])) == false)
		return (false);
	*philo_num = *philo_num + 2;
	return (true);
}
