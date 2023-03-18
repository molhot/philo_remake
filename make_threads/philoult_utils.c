/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoult_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:59:47 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/18 04:59:47 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	start_philolifeult(t_philo *subject)
{
	if (pthread_create(&(subject->philo_thread), NULL, \
	&philolife_life_ult, (void *)(subject)) != 0)
		return (false);
	//pthread_detach(subject->philo_thread);
	return (true);
}

bool	even_pn_startultlife(t_allinfo *info, size_t *philo_num)
{
	if (start_philolifeult(&((info->philoinfo)[*philo_num])) == false)
		return (false);
	*philo_num = *philo_num + 2;
	return (true);
}

bool	add_pn_startultlife(t_allinfo *info, size_t *philo_num)
{
	if ((*philo_num) % 2 == 1 && *philo_num == 1)
		usleep(100);
	if (start_philolifeult(&((info->philoinfo)[*philo_num])) == false)
		return (false);
	*philo_num = *philo_num + 2;
	return (true);
}
