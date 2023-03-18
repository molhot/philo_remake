/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showerror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:41 by satushi           #+#    #+#             */
/*   Updated: 2023/03/17 15:27:43 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	print_errormessage(int errornum)
{
	if (errornum == ERROR_ARGUMENT)
		ft_putchar_fd("argnum is difficult\n you must write four argnum\n");
	if (errornum == ERROR_MALLOC)
		ft_putchar_fd("malloc is missed\n");
	return (1);
}
