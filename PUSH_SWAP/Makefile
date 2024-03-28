# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 22:37:29 by hmoon             #+#    #+#              #
#    Updated: 2022/03/23 22:47:55 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= push_swap
BONUS			:= checker
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -f

LIBFT_DIR		:= ./libft
LIBFT_LIB		:= ./libft/libft.a

INCLUDE			:= ./include/
INCLUDE_FILE	:= $(addprefix $(INCLUDE), push_swap.h)

SRCS			:= $(addprefix ./srcs/, \
					push_swap.c parse_argv.c \
					print_error.c \
					make_stack.c order_stack.c \
					util_stack.c solve.c \
					solve_small.c)
OBJS_FILE		:= $(SRCS:.c=.o)

SRCS_BONUS			:= $(addprefix ./srcs/, \
					checker.c \
					parse_argv.c \
					print_error.c \
					make_stack.c order_stack.c \
					util_stack.c)
OBJS_FILE_BONUS		:= $(SRCS_BONUS:.c=.o)

ifdef CHECKER
		OBJ_FILE		= $(OBJS_FILE_BONUS)
		NAMES			= $(BONUS)
else
		OBJ_FILE		= $(OBJS_FILE)
		NAMES			= $(NAME)
endif

.PHONY	: all
all		: libft $(NAMES)

$(NAMES)	: $(OBJ_FILE) $(INCLUDE_FILE)
		$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJ_FILE) -g -o $(NAMES)

%.o		: %.c
		$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_DIR) -g -c $< -o $@

.PHONY	: bonus
bonus	:
		@make CHECKER=1 all

.PHONY	: libft
libft	:
		@make -C ./libft all

.PHONY	: clean
clean	:
		@make -C ./libft clean
		@$(RM) $(OBJS_FILE) $(OBJS_FILE_BONUS)

.PHONY	: fclean
fclean	: clean
		@make -C ./libft fclean
		@$(RM) $(NAME) $(BONUS)

.PHONY	: re
re		: fclean all
