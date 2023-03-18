/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:37:36 by satushi           #+#    #+#             */
/*   Updated: 2023/03/17 15:16:40 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	bool	argment_check(char *argline)
{
	size_t	argline_position;

	argline_position = 0;
	while (argline[argline_position] != '\0')
	{
		if (!('0' <= argline[argline_position] && \
		argline[argline_position] <= '9'))
			return (false);
		argline_position++;
	}
	return (true);
}

bool	arg_check(int argnum, char **arg)
{
	size_t	arg_position;

	if (argnum != 5 && argnum != 6)
		return (false);
	arg_position = 1;
	while (arg[arg_position] != NULL)
	{
		if (argment_check(arg[arg_position]) == false)
			return (false);
		arg_position++;
	}
	return (true);
}
