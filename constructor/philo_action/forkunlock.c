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

#include "../../philosophers.h"

bool	error_unlockonefork(pthread_mutex_t *f)
{
	pthread_mutex_unlock(f);
	return (false);
}

void	unlock_allfork(pthread_mutex_t *lf, pthread_mutex_t *rf)
{
	pthread_mutex_unlock(rf);
	pthread_mutex_unlock(lf);
}

bool	error_unlockallfork(pthread_mutex_t *lf, pthread_mutex_t *rf)
{
	unlock_allfork(lf, rf);
	return (false);
}
