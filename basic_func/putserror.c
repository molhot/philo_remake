/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putserror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:01:55 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/19 01:01:55 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	argnum_error(void)
{
	printf("%s\n", ERROR_ARGUMENTNUM);
}

void	argminus_error(void)
{
	printf("%s\n", ERROR_ARGUMENTMINUS);
}

void	mutex_error(void)
{
	printf("%s\n", ERROR_MUTEX);
}

void	malloc_error(void)
{
	printf("%s\n", ERROR_MALLOC);
}
