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
	if (constructer(&allinfo) == false)
		return (1);
	//destracter();
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