# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:27:12 by xamartin          #+#    #+#              #
#    Updated: 2017/11/14 23:05:02 by xamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRCS_DIR = ./srcs
INC_DIR = ./includes

RAW_SRCS=\
		 ft_atoi.c\
		 ft_memccpy.c\
		 ft_strchr.c\
		 ft_strncmp.c\
		 ft_bzero.c\
		 ft_memchr.c\
		 ft_strclr.c\
		 ft_strncpy.c\
		 ft_count_words.c\
		 ft_memcmp.c\
		 ft_strcmp.c\
		 ft_strnequ.c\
		 ft_isalnum.c\
		 ft_memcpy.c\
		 ft_strcpy.c\
		 ft_strnew.c\
		 ft_isalpha.c\
		 ft_memdel.c\
		 ft_strdel.c\
		 ft_strnstr.c\
		 ft_isascii.c\
		 ft_memmove.c\
		 ft_strdup.c\
		 ft_strrchr.c\
		 ft_isdigit.c\
		 ft_memset.c\
		 ft_strdupi.c\
		 ft_strsplit.c\
		 ft_isprint.c\
		 ft_putchar.c\
		 ft_strequ.c\
		 ft_strstr.c\
		 ft_itoa.c\
		 ft_putchar_fd.c\
		 ft_striter.c\
		 ft_strsub.c\
		 ft_lstadd.c\
		 ft_putendl.c\
		 ft_striteri.c\
		 ft_strtrim.c\
		 ft_lstdel.c\
		 ft_putendl_fd.c\
		 ft_strjoin.c\
		 ft_tolower.c\
		 ft_lstdelone.c\
		 ft_putnbr.c\
		 ft_strlcat.c\
		 ft_toupper.c\
		 ft_lstiter.c\
		 ft_lstnew.c\
		 ft_putstr_fd.c\
		 ft_strmapi.c\
		 ft_memalloc.c\
		 ft_strcat.c\
		 ft_strncat.c\
		 ft_putnbr_fd.c\
		 ft_strlen.c\
		 ft_lstmap.c\
		 ft_putstr.c\
		 ft_strmap.c

OBJS = $(RAW_SRCS:.c=.o)

SRCS = $(addprefix $(SRCS_DIR)/,$(RAW_SRCS))

CC = gcc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -c $(CFLAGS) -I $(INC_DIR) $(SRCS)
	@ar rc $(NAME) $(OBJS) $(NAME)
	@ranlib $(NAME)
	@rm -f *.o

$(OBJS):
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $(SRCS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
