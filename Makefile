NAME = philo

SRCS = main.c\
		ready_info/ready_info.c\
			ready_info/arg_checker.c\
			ready_info/philos_info/ready_philosinfo.c\
			ready_info/philo_info/ready_samephiloinfo.c\
		constructor/start_threads.c\
			constructor/lifecycle.c\
				constructor/philo_think_eat.c\
				constructor/philo_action/forkunlock.c\
			constructor/checker.c\
		commonvariable/handle_commonval.c\
		basic_func/ft_atoi.c basic_func/print_action.c basic_func/ft_getnowtime.c basic_func/putserror.c\
		free/destroy_mutex.c free/free.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror -I includes -pthread

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	rm -f all

re: fclean all

.PHONY:			all clean fclean re bonus