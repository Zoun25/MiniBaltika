CC		=gcc
LIBS	=libft/libft.a
CFLAGS	=-Wall -Werror -Wextra -Iinclude
NAME	=minishell
C_FILES	= src/main.c

libft/libft.a:
	make -C libft

outer_clean:
	make -C libft clean

outer_fclean:
	make -C libft fclean
