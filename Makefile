NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = operations/swap.c \
       operations/push.c \
       operations/rotate.c \
       operations/reverse.c \
       utils/utils.c \
       utils/stack_utils.c \
       sorts/sort_small.c \
       sorts/sort_big.c \
       main.c

OBJS = $(SRCS:.c=.o)

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
