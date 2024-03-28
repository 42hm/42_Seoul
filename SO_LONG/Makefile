# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 12:10:57 by hmoon             #+#    #+#              #
#    Updated: 2022/05/25 17:31:06 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= so_long
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror
RM				:= rm -rf

LIBFT			:= ./libft/libft.a
LIBFT_DIR		:= ./libft/
LIBFT_HEADER	:= ./libft/include/

MLX_DIR			:= ./mlx
MLX_OPENGL		:= -L ./mlx -lmlx
MLX_FLAGS		:= -framework OpenGL -framework Appkit

HEADER			:= ./include/
SRC_DIR			:= ./src/
OBJ_DIR			:= ./.obj/

HEADER_BONUS	:= ./bonus/include/
SRC_DIR_B		:= ./bonus/src/
OBJ_DIR_B		:= ./bonus/.obj/

SRC_FILES		:= $(addsuffix .c, so_long \
					validate_file so_long_utils \
					validate_map init_mlx \
					set_image so_long_move)
OBJ_FILES		:= $(SRC_FILES:.c=.o)
SRC				:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ				:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_FILES_B		:= $(addsuffix .c, so_long_bonus \
					validate_file_bonus so_long_utils_bonus \
					validate_map_bonus init_mlx_bonus \
					set_image_bonus so_long_move_bonus)
OBJ_FILES_B		:= $(SRC_FILES_B:.c=.o)
SRC_BONUS		:= $(addprefix $(SRC_DIR_B), $(SRC_FILES_B))
OBJ_BONUS		:= $(addprefix $(OBJ_DIR_B), $(OBJ_FILES_B))

ifdef BONUS
		INCLUDE			= $(HEADER_BONUS)
		SRC_FOLDER		= $(SRC_DIR_B)
		OBJ_FOLDER		= $(OBJ_DIR_B)
		OBJS			= $(OBJ_BONUS)
else
		INCLUDE			= $(HEADER)
		SRC_FOLDER		= $(SRC_DIR)
		OBJ_FOLDER		= $(OBJ_DIR)
		OBJS			= $(OBJ)
endif

.PHONY		: all
all			: mlx $(LIBFT) $(OBJ_FOLDER) $(NAME)

$(NAME)		: $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_OPENGL) $(MLX_FLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "\033[01;32m       SUCCESS!      \033[0m"

$(OBJ_FOLDER)	:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir -p $(OBJ_FOLDER); \
	fi

$(OBJ_FOLDER)%.o	:	$(SRC_FOLDER)%.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_HEADER) -I$(INCLUDE) -o $@ -c $<

$(LIBFT)	:
	@make -C $(LIBFT_DIR) all

.PHONY		: bonus
bonus		:
	@make BONUS=1 all

.PHONY		: mlx
mlx			:
	@make -sC $(MLX_DIR) all

.PHONY		: clean
clean		:
	@make -sC $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_DIR_B) $(MLX_LIB)

.PHONY		: fclean
fclean		: clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

.PHONY		: re
re			: fclean all
