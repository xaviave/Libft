# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:27:12 by xamartin          #+#    #+#              #
#    Updated: 2017/11/09 13:58:12 by xamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRCS=\
	 *.c

OBJ=\
	*.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@rm -f $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
