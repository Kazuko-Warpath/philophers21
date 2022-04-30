NAME = philo

SRCS = ft_fork.c ft_philo.c ft_utils.c philo.c

HEADER = philo.h

OBJS = $(SRCS:.c=.o)

FLAGS = -Wextra -Werror -Wall -pthread

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME) 

%.o : %.c
	cc $(FLAGS) -c $<

$(OBJS): $(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
