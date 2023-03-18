NAME = philo

SRCS = main.c\
		arg_checker.c\
		ready_samephiloinfo.c\
		handling_mutex.c\
		make_threads/handling_threads.c make_threads/philo_utils.c make_threads/philoult_utils.c\
		philosophers_action/philo_behavior.c philosophers_action/philo_think_eat.c\
		philosophers_action/behave_onefork.c philosophers_action/behave_twofork.c\
		basic_func/ft_atoi.c basic_func/print_action.c basic_func/ft_getnowtime.c\
		checker.c\
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