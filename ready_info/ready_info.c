/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:39:52 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/22 10:39:52 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	ready_info(t_allinfo *allinfo, int argc, char **argv)
{
    if (arg_check(argc, argv) == false)
        return (false);
    if (ready_philosinfo(allinfo, argv) == false)
        return (false);
    if (create_samephilo(allinfo, argv, argc) == false)
        return (false);
    return (true);
}
