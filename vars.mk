CC		=gcc
LIBS	=libft/libft.a
CFLAGS	=-Wall -Werror -Wextra -Iinclude
NAME	=minishell
C_FILES	= src/main.c \
			src/node/print/nop.c \
			src/node/print/and.c \
			src/node/print/or.c \
			src/node/print/semicolon.c \
			src/node/print/block.c \
			src/node/print/proc.c \
			src/node/print/line.c \
			src/node/print/print.c \
			src/node/create/nop.c \
			src/node/create/and.c \
			src/node/create/or.c \
			src/node/create/semicolon.c \
			src/node/create/block.c \
			src/node/create/proc.c \
			src/node/create/line.c \
			src/node/create/create.c \

libft/libft.a:
	make -C libft

outer_clean:
	make -C libft clean

outer_fclean:
	make -C libft fclean
