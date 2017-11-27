# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/27 16:29:55 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2017/11/27 16:29:59 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

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
		 ft_strmap.c\
		 ft_strlowcase.c\
		 ft_strupcase.c\
		 ft_strcapitalize.c\
		 ft_strrev.c

OBJS = $(RAW_SRCS:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) -c $(CFLAGS) -I libft.h $(RAW_SRCS)
	@ar rc $(NAME) $(OBJS) $(NAME)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
