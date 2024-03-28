# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 22:45:21 by hmoon             #+#    #+#              #
#    Updated: 2022/03/23 22:48:00 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
HEADER		:= libft.h
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

SRCS_DIR	:= ./
SRCS_NAME	:= ft_atoi.c ft_bzero.c ft_calloc.c \
			  ft_isalnum.c ft_isalpha.c \
			  ft_isascii.c ft_isdigit.c ft_isprint.c \
			  ft_memccpy.c ft_memchr.c \
			  ft_memcmp.c ft_memchr.c ft_memcpy.c \
			  ft_memmove.c ft_memset.c \
			  ft_strchr.c ft_strdup.c ft_strlcat.c \
			  ft_strlcpy.c ft_strlen.c \
			  ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			  ft_tolower.c ft_toupper.c \
			  ft_substr.c ft_strjoin.c \
			  ft_strtrim.c ft_split.c \
			  ft_itoa.c ft_strmapi.c \
			  ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_lstnew.c ft_lstadd_front.c \
			  ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c \
			  ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c ft_strcmp.c \
			  ft_freearr.c get_next_line.c
SRCS		:= $(addprefix $(SRCS_DIR),$(SRCS_NAME))
OBJS		:= ${SRCS:.c=.o}

.PHONY		: all
all			: $(NAME)

$(NAME)		: $(OBJS)
			@ar rcs $@ $^

*.o			: *.c
			$(CC) $(CFLAGS) -c -g $< -o $@

.PHONY		: clean
clean:
			@rm -f $(OBJS)

.PHONY		: fclean
fclean		: clean
			@rm -f $(NAME)

.PHONY		: re
re			: fclean all
