/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:37:36 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 14:50:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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

static bool	zero_check(char *arg)
{
	if (arg[0] == '0' && arg[1] == '\0')
		return (true);
	return (false);
}

bool	arg_check(int argnum, char **arg)
{
	size_t	arg_position;

	if (argnum != 5 && argnum != 6)
	{
		argnum_error();
		return (false);
	}
	arg_position = 1;
	while (arg[arg_position] != NULL)
	{
		if (arg_position == 1 && zero_check(arg[arg_position]))
		{
			argminus_error();
			return (false);
		}
		if (argment_check(arg[arg_position]) == false)
		{
			argminus_error();
			return (false);
		}
		arg_position++;
	}
	return (true);
}
