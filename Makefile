# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 18:29:24 by angsanch          #+#    #+#              #
#    Updated: 2024/10/04 00:06:41 by angsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: build

outer_clean:

outer_fclean:

include vars.mk

O_FILES = $(C_FILES:.c=.o)

$(NAME): $(LIBS) $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) $(LIBS) $(LINKS)

build: $(NAME)

clean: outer_clean
	rm -f $(O_FILES)

fclean: clean outer_fclean
	rm -f $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re outer_clean outer_fclean
