/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:07:02 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/14 18:07:02 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static	void	ready_philoinfo(t_allinfo *info, int argc, char **argv)
// {
// 	info->philo_num = ft_atoi(argv[1]);
// 	info->time_to_die = ft_atoi(argv[2]);
// 	info->time_to_eat = ft_atoi(argv[3]);
// 	info->time_to_sleep = ft_atoi(argv[4]);
// 	info->time_to_think = 0;
// 	info->philo_die_ornot = false;
// 	info->eatend_count = 0;
// 	if (argc == 6)
// 		info->eat_limit = ft_atoi(argv[5]);
// 	else
// 		info->eat_limit = -1;
// }

static void	all_free(t_allinfo *allinfo)
{
	mutex_destroy(allinfo);
	free(allinfo->philoinfo);
	free_mutex(allinfo);
}

int	main(int argc, char *argv[])
{
	t_allinfo	allinfo;

	if (ready_info(&allinfo, argc, argv) == false)
		return (1);
	printf("check\n");
	if (constructer(&allinfo) == false)
		return (1);
	//destracter();
	// if (makingthread(&allinfo) == false)
	// {
	// 	all_free(&allinfo);
	// 	return (1);
	// }
	all_free(&allinfo);
}

//ready philo
//	構造体のマロック
//	mutexの初期化
//	作った構造体へ代入

//constructer
//	threadの作成
//	threadへの関数の紐づけ

//destracter
//	threadの削除
//	mutexのdestroy
//	mallocのfree