/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:41 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 14:35:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	print_errormessage(int errornum)
{
	if (errornum == ERROR_ARGUMENT)
		ft_putchar_fd("argnum is difficult\n you must write four argnum\n");
	if (errornum == ERROR_MALLOC)
		ft_putchar_fd("malloc is missed\n");
	return (false);
}
