CC		= gcc -g
NAME	= push_swap
FLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard src/*.c Libft/*.c)
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJS)

fclean:	clean		
	rm -rf $(NAME)

norm:
	@norminette $(wildcard Libft/*.c)
	@norminette $(wildcard src/*.c)
	@norminette $(wildcard inc/*.h)

.PHONY: all re clean fclean norm