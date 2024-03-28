# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 22:37:29 by hmoon             #+#    #+#              #
#    Updated: 2022/06/14 07:01:53 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	philo
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -pthread
RM				:=	rm -rf

HEADER			:=	$(addprefix ./include/, philo.h)
SRC_DIR			:=	./src/
OBJ_DIR			:=	./.obj/

SRC_FILES		:=	$(addsuffix .c, philo \
						philo_utils philo_cafeteria \
						philo_kitchen)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
SRC				:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

.PHONY	:	all
all		:	$(OBJ_DIR) $(NAME)

.PHONY	:	clean
clean	:
	@$(RM) $(OBJ_DIR)
	@echo "\033[91m      REMOVE OBJECT      \033[0m"


.PHONY	:	fclean
fclean	:	clean
	@$(RM) $(NAME)
	@echo "\033[91m      FCLEAN DONE      \033[0m"

.PHONY	:	re
re		:	fclean all

$(OBJ_DIR)	:
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi

$(OBJ)	:	$(HEADER) | $(OBJ_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	:	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[01;32m        SUCCESS!      \033[0m"
