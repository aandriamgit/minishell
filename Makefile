NAME = minishell
CFLAGS = -Werror -Wall -Wextra -g
RM = rm -rf
OBJ_DIR = .obj
SRCS = minishell.c \
	   	./lib/ft_putstr_fd.c \
	   	./lib/ft_strncmp.c \
	   	./lib/ft_putnbr_fd.c \
	   	./lib/ft_putchar_fd.c \
		./lib/ft_strlen.c \
		./lib/ft_substr.c \
		./lib/ft_strjoin.c \
		./lib/ft_strdup.c \
		./lib/ft_split.c \
		./lib/ft_strrchr.c \
		./interpret/ft_add_history/ft_add_history.c \
		./interpret/interpret.c \
		./shell_init/add_prev_history.c \
		./shell_init/big_param_init.c \
		./shell_init/creat_env_dir.c \
		./shell_init/fork_mkdir.c \
		./shell_init/terminate_shell_init.c \
		./shell_init/vars_init.c \
		./simple_execution/simple_execution.c \
		./simple_execution/no_pipe_exec/test.c \
		./simple_execution/no_pipe_exec/is_special_cmd.c \
		./simple_execution/no_pipe_exec/fork_exec_nopipe.c \
		./simple_execution/no_pipe_exec/exec_special_cmd/exec_special_cmd.c \
		./simple_execution/pipe_exec/pipe_exec.c \
		./simple_execution/p_test/p_test.c \
		./simple_execution/p_test/parsing_test.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

YELLOW = \033[38;2;249;226;175m
BLUE = \033[38;2;180;190;254m
GREEN = \033[38;2;166;227;161m
RESET = \033[0m
COMPILING = "\r${YELLOW}[ ]${RESET} compiling ${BLUE}"
COMPILED = "\r${GREEN}[✔]${RESET} compiled successfully! ${BLUE}.  ★                                                                \n"
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
