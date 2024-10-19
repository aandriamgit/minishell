# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandriam <aandriam@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 16:14:24 by aandriam          #+#    #+#              #
#    Updated: 2024/10/19 18:28:37 by aandriam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -rf
OBJ_DIR = .obj
SRCS = minishell.c \
	   ./lib/ft_split.c \
	   ./lib/ft_execve.c \
	   ./lib/ft_strdup.c \
	   ./lib/ft_strlen.c \
	   ./lib/ft_substr.c \
	   ./lib/ft_strjoin.c \
	   ./lib/ft_strncmp.c \
	   ./lib/ft_free_all.c \
	   ./lib/ft_putstr_fd.c \
	   ./lib/ft_putnbr_fd.c \
	   ./lib/ft_putchar_fd.c \
	   ./shell_init/shell_init.c \
	   ./shell_init/exec_big_param/exec_big_param.c \
	   ./interpret/interpret.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c \
	   ./simple_execution/simple_execution.c \
	   ./simple_execution/redirection_test/redirection_test.c \
	   ./simple_execution/redirection_test/first_test/exec_t_pipe/exec_t_pipe.c \
	   ./simple_execution/redirection_test/first_test/first_test.c \
	   ./simple_execution/redirection_test/first_test/exec_t_pipe/exec_cmd.c \
	   ./simple_execution/redirection_test/first_test/exec_t_pipe/exec_t_pipe.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

YELLOW = \033[38;2;249;226;175m
BLUE = \033[38;2;180;190;254m
GREEN = \033[38;2;166;227;161m
RESET = \033[0m
COMPILING = "\r${YELLOW}[ ]${RESET} compiling ${BLUE}"
COMPILED = "\r${GREEN}[✔]${RESET} compiled successfully! ${BLUE}.  ★                                                                                 \n"
RM_NAME = "\r${GREEN}[✔]${RESET} rm name successfully! ${BLUE}✧̣̇ ˳\n"
RM_OBJS = "\r${GREEN}[✔]${RESET} rm objs successfully! ${BLUE}.˚ ✦\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@cc $(CFLAGS) -c $< -o $@
	@printf $(COMPILING)$<

$(NAME) : $(OBJS)
	@cc $(CFLAGS) $(OBJS) -lreadline -o $(NAME)
	@printf $(COMPILED)

all: $(NAME)

fclean: clean
	@$(RM) $(NAME)
	@printf $(RM_NAME)

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@printf $(RM_OBJS)

re: fclean all
