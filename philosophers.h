/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:45 by satushi           #+#    #+#             */
/*   Updated: 2023/03/18 13:32:29 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ERROR_ARGUMENT 1
# define ERROR_MALLOC 2
# define ERROR_PHILOINFO 3
# define T_L_F "TAKE LEFT FORK"
# define T_R_F "TAKE RIGHT FORK"
# define D_L_F "DROP LEFT FORK"
# define D_R_F "DROP RIGHT FORK"
# define EAT "eating now, mogumogu okayu~~~"
# define THINK "thinking now ...mmm"
# define SLEEP "sleeping now ...zzZZ"

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork {
	int	l_fork;
	int	r_fork;
}	t_fork;

typedef struct philo_info	t_philo;

typedef struct all_info {
	pthread_mutex_t	*forks;
	pthread_mutex_t	*status;
	pthread_mutex_t	*timecheck_same;
	pthread_mutex_t	write;
	pthread_mutex_t	diecheck;
	pthread_mutex_t	correctend;
	t_philo			*philoinfo;
	pthread_t		checkthread;
	int				philo_num;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				time_to_die;
	int				eat_limit;
	bool			philo_die_ornot;
}	t_allinfo;

typedef struct philo_info{
	size_t			number_of_philo;
	size_t			how_eated;
	pthread_t		philo_thread;
	t_fork			fork_info;
	long long		time_to_die;
	long long		philo_livedstart;
	bool			correctend;
	int				eat_limit;
	t_allinfo		*all_info;
}t_philo;

/************************basicfunc**************************/
int				main(int argc, char *argv[]);
/*---------------------------------------------------------*/

/***********************philo'slife*************************/
void			*philolife_life(void *info_t);
void			*philolife_life_ult(void *info_t);
/*---------------------------------------------------------*/

/*************************actions*******************************/
bool			think(t_philo *info);
bool			sleeping(t_philo *info);
bool			eat_drop(t_philo *info, int l_f, int r_f);
/*-------------------------------------------------------------*/

/************************handlefork*****************************/
void			unlock_rightfork(t_philo *info, int r_f);
bool			error_unlockrightfork(t_philo *info, int r_f);
void			unlock_leftfork(t_philo *info, int l_f);
bool			error_unlockleftfork(t_philo *info, int l_f);
void			unlock_allfork(t_philo *info, int l_f, int r_f);
bool			error_unlokallfork(t_philo *info, int l_f, int r_f);
/*-------------------------------------------------------------*/

/************************basicfunc**************************/
int				ft_atoi(const char *str);
long long		getnowtime(void);
bool			print_action(t_philo *info, char *action);
/*---------------------------------------------------------*/

/************************errorcheck*************************/
bool			arg_check(int argnum, char **arg);
/*---------------------------------------------------------*/

/************************showerror**************************/
int				print_errormessage(int errornum);
/*---------------------------------------------------------*/

/***********************handlemutex*************************/
bool			mutexinit(t_allinfo *allinfo);
bool			create_forks(t_allinfo *info);
/*---------------------------------------------------------*/

/**********************handlethreads************************/
int				destroy_threads(t_allinfo *main);
bool			create_forks(t_allinfo *info);
bool			create_threads(t_allinfo *info);
bool			create_threads_ult(t_allinfo *info);
bool			start_philolife(t_philo *subject);
bool			even_pn_startlife(t_allinfo *info, size_t *philo_num);
bool			even_pn_startultlife(t_allinfo *info, size_t *philo_num);
bool			start_philolifeult(t_philo *subject);
bool			add_pn_startlife(t_allinfo *info, size_t *philo_num);
bool			add_pn_startultlife(t_allinfo *info, size_t *philo_num);
/*---------------------------------------------------------*/

/**********************readyphiloinfo***********************/
bool			create_samephilo(t_allinfo *info);
/*---------------------------------------------------------*/

/***********************destroymutex************************/
void			mutex_destroy(t_allinfo *info);
/*---------------------------------------------------------*/

/***********************free************************/
void			free_mutex(t_allinfo *info);
/*-------------------------------------------------*/

void			*philo_func(void *info);
void			*philo_checker(void *info_i);
void			*limited_philolife_even(void *info_t);
void			*limited_philolife_add(void *info_t);

#endif