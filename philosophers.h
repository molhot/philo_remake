/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:57:45 by satushi           #+#    #+#             */
/*   Updated: 2023/03/22 22:17:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ERROR_ARGUMENTNUM "ARGMENT is not correct amount"
# define ERROR_ARGUMENTMINUS "ARGMENT contains minus value"
# define ERROR_MUTEX "MUTEX is not corrective started"
# define ERROR_MALLOC "MALLOC error"
# define ERROR_PHILOINFO 3

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
	pthread_mutex_t	*timecheck_same;
	pthread_mutex_t	write;
	pthread_mutex_t	diecheck;
	t_philo			*philoinfo;
	pthread_t		checkthread;
	size_t			philo_num;
	int				time_to_die;
	bool			philo_die_ornot;
}	t_allinfo;

typedef struct philo_info{
	size_t			number_of_philo;
	size_t			how_eated;
	pthread_t		philo_thread;
	t_fork			fork_info;
	long long		time_to_die;
	long long		philo_livedstart;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	bool			correctend;
	int				eat_limit;
	t_allinfo		*all_info;
}t_philo;

//main
int				main(int argc, char *argv[]);

//check, ready
bool			ready_info(t_allinfo *allinfo, int argc, char **argv);
bool			arg_check(int argnum, char **arg);
bool			ready_philosinfo(t_allinfo *info, char **argv);
bool			create_samephilo(t_allinfo *info, char **argv, int argc);

//construct
bool    		constructer(t_allinfo *info);
void			*philolife_life(void *info_t);
bool			print_action(t_allinfo *info, size_t pn, char *action);
bool			eat_drop(t_philo *info, int l_f, int r_f, size_t pn);
bool			error_unlockonefork(pthread_mutex_t *f);
void			unlock_allfork(pthread_mutex_t *lf, pthread_mutex_t *rf);
bool			error_unlockallfork(pthread_mutex_t *lf, pthread_mutex_t *rf);
bool			sleeping(t_philo *info);
void			*philo_checker(void *info_i);
bool			print_die(t_allinfo *info, size_t pn, char *action);

bool			die_check(t_allinfo *info);
void			livestart_ch(t_philo *info);

//destruct



/************************basicfunc**************************/
int				ft_atoi(const char *str);
long long		getnowtime(void);
long long		getnowtime_ms(void);
void			argnum_error(void);
void			argminus_error(void);
void			mutex_error(void);
void			malloc_error(void);
/*---------------------------------------------------------*/

/***********************handlemutex*************************/
void			mutex_destroy_component(t_allinfo *info);
/*---------------------------------------------------------*/

/**********************handlethreads************************/
int				destroy_threads(t_allinfo *main);
/*---------------------------------------------------------*/

/***********************destroymutex************************/
void			mutex_destroy(t_allinfo *info);
/*---------------------------------------------------------*/

/***********************free************************/
void			free_mutex(t_allinfo *info);
/*-------------------------------------------------*/

#endif