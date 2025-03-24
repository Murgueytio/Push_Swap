NAME	= push_swap

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= $(wildcard operations/*.c utils/*.c split/*.c sorting/*.c main.c)
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
