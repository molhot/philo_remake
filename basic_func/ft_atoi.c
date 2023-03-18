/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:08:46 by satushi           #+#    #+#             */
/*   Updated: 2023/03/17 15:27:23 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	sub_num(const char *first, int counter, int p_m)
{
	long	digit;
	long	sum;

	digit = 1;
	sum = 0;
	if ((counter > 10) & (p_m % 2 == 0))
		return (-1);
	if ((counter > 10) & (p_m % 2 == 1))
		return (0);
	while (counter-- != 0)
		digit = digit * 10;
	while (digit != 0)
	{
		sum = sum + (*first - 48) * digit;
		digit = digit / 10;
		first = first + 1;
	}
	if ((sum > 2147483647) && (p_m % 2 == 0))
		return (-1);
	else if ((sum > 2147483648) && (p_m % 2 == 1))
		return (0);
	if (p_m % 2 == 1)
		sum = sum * (-1);
	return (sum);
}

int	ft_atoi(const char *str)
{
	int		plus_or_minus;
	int		counter;

	counter = 0;
	plus_or_minus = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str = str + 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			plus_or_minus = 1;
		str = str + 1;
	}
	while (*str == '0')
		str = str + 1;
	while ('0' <= *str && *str <= '9')
	{
		counter = counter + 1;
		str = str + 1;
	}
	if (counter == 0)
		return (0);
	return (sub_num(str - counter, counter - 1, plus_or_minus));
}
