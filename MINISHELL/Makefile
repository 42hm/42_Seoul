# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoon <hmoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 15:57:32 by hmoon             #+#    #+#              #
#    Updated: 2022/07/11 17:56:47 by hmoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	minishell

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror -g -D READLINE_LIBRARY

READLINE_DIR		:=	readline
READLINE_INCLUDE	:=	$(READLINE_DIR)
READLINE_LIB		:=	$(READLINE_DIR)
READLINE			:=	$(READLINE_DIR)/libreadline.a

INCLUDE				:=	include
INCLUDE_FILES		:=	minishell.h parse.h utils.h redirect.h list.h \
						main_logic.h built_in.h pipe_signal.h
INCLUDE_FILES		:=	$(addprefix $(INCLUDE)/, $(INCLUDE_FILES))

SRC_DIR				:=	./src
ROOT_SRCS			:=	$(addprefix $(SRC_DIR)/, \
							main.c \
						)

BUILTIN_DIR			:=	$(SRC_DIR)/builtin
BUILTIN_SRCS		:=	$(addprefix $(BUILTIN_DIR)/, \
							ft_cd_tilde.c \
							ft_cd_util2.c \
							ft_cd_util.c \
							ft_cd_home.c \
							ft_cd.c \
							ft_echo.c \
							ft_exit_util.c \
							ft_exit.c \
							ft_env.c \
							ft_export_util2.c \
							ft_export_util.c \
							ft_export.c \
							ft_pwd.c \
							ft_unset.c \
							ft_unlink.c \
							set_exit_status.c \
						)

PIPE_SIGNAL_DIR		:=	$(SRC_DIR)/pipe_signal
PIPE_SIGNAL_SRCS	:=	$(addprefix $(PIPE_SIGNAL_DIR)/, \
							signal_cmd.c \
							signal_here.c \
						)

PIPES_DIR			:=	$(SRC_DIR)/pipes
PIPES_SRCS			:=	$(addprefix $(PIPES_DIR)/, \
							alone_cmd.c \
							main_logic.c \
							pipe.c \
						)

REDIRECTION_DIR		:=	$(SRC_DIR)/redirection
REDIRECTION_SRCS	:=	$(addprefix $(REDIRECTION_DIR)/, \
							heredoc_input.c \
							heredoc.c \
							input.c \
							output.c \
						)

PARSE_DIR			:=	$(SRC_DIR)/parse
PARSE_SRCS			:=	$(addprefix $(PARSE_DIR)/, \
							cmd.c \
							envp.c \
							error.c \
							exec.c \
							free.c \
							heredoc.c \
							interpret.c \
							parse.c \
							remover.c \
							tokenize.c \
						)

PROMPT_DIR			:=	$(SRC_DIR)/prompt
PROMPT_SRCS			:=	$(addprefix $(PROMPT_DIR)/, \
							echoctl.c \
							prompt.c \
						)

UTIL_DIR			:=	$(SRC_DIR)/util
UTIL_SRCS			:=	$(addprefix $(UTIL_DIR)/, \
							ast.c \
							calloc.c \
							free.c \
							isalnum.c \
							itoa.c \
							list.c \
							split.c \
							strchr.c \
							strdup.c \
							strjoin_free.c \
							strlcat.c \
							strlen.c \
							strncmp.c \
							strndup.c \
							strskip.c \
							strcmp.c \
							putstr_fd.c \
							putendl_fd.c \
						)

SRCS				:=	$(ROOT_SRCS) \
						$(BUILTIN_SRCS) \
						$(PIPE_SIGNAL_SRCS) \
						$(PIPES_SRCS) \
						$(REDIRECTION_SRCS) \
						$(PARSE_SRCS) \
						$(PROMPT_SRCS) \
						$(UTIL_SRCS)
OBJS				:=	$(SRCS:.c=.o)

.PHONY				:	all
all					:	$(READLINE) $(NAME)

$(READLINE)			:
	cd $(READLINE_DIR); ./configure
	make -C $(READLINE_DIR) all

$(NAME)				:	$(OBJS) $(INCLUDE_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJS) \
	-L$(READLINE_LIB) -lreadline -lhistory -lncurses

.PHONY				:	.c.o
.c.o				:
	@$(CC) $(CFLAGS) -I$(READLINE_INCLUDE) -I$(INCLUDE) -c $< -o $@

.PHONY				:	clean
clean				:
	@rm -rf $(OBJS)

.PHONY				:	fclean
fclean				:	clean
	@rm -rf $(NAME)
	@make -C $(READLINE_DIR) clean

.PHONY				:	re
re					:	fclean all
