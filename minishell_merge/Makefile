NAME = minishell

OBJ_DIR = obj

SRC = minishell.c \
	  ./builting/env/env.c \
	  ./libft/ft_strlen.c \
	  ./utils/list/creat_bloc_of_list.c \
	  ./utils/list/creat_chain_of_list.c \
	  ./utils/list/display_list.c \
	  ./utils/list/ordered_list.c \
	  ./utils/lib/ft_itoa_a.c \
	  ./utils/lib/ft_strdup_a.c \
	  ./utils/lib/ft_strncmp_a.c \
	  ./utils/lib/ft_putstr_fd_a.c \
	  ./utils/lib/ft_strjoin_a.c \
	  ./utils/lib/ft_strrchr_a.c \
	  ./utils/lib/ft_split_a.c \
	  ./utils/lib/ft_strlen_a.c \
	  ./utils/lib/ft_substr_a.c \
	  ./utils/lib/ft_putnbr_fd_a.c \
	  ./utils/lib/ft_putchar_fd_a.c \
	  ./utils/modules/add.c \
	  ./utils/modules/ft_execve.c \
	  ./utils/modules/ft_free.c \
	  ./utils/modules/ft_perror.c \
	  ./utils/modules/ft_print_pipe_a.c \
	  ./utils/modules/gen.c \
	  ./builting/export/simple_export.c \
	  ./builting/export/export_with_arg.c \
	  ./builting/export/display_export.c \
	  ./libft/ft_split.c \
	  ./libft/ft_execve.c \
	  ./libft/ft_strjoin.c \
	  ./libft/ft_strdup.c \
	  ./libft/ft_substr.c \
	  ./libft/ft_free_all.c \
	  ./libft/ft_putstr_fd.c \
	  ./libft/ft_strncmp.c \
	  ./libft/ft_strcmp.c \
	  ./shell_init/shell_init.c \
	  ./shell_init/exec_big_param/exec_big_param.c \
	  ./builting/export/check_export.c\
	  ./builting/unset/unset.c \
	  ./get_next_line/get_next_line.c \
	  ./get_next_line/get_next_line_utils.c \
	  ./interpret/interpret.c \
	  ./interpret/unclosed_quote.c \
	  ./interpret/formating/formating.c \
	  ./interpret/formating/check_input.c \
	  ./forge_of_commands/convert_t_pipe_a.c \
	  ./forge_of_commands/init_stderr.c \
	  ./forge_of_commands/custom_prompt.c \
	  ./forge_of_commands/terminus.c \
	  ./forge_of_commands/heredoc_supremacy/heredoc_supremacy.c \
	  ./forge_of_commands/heredoc_supremacy/get_eof.c \
	  ./forge_of_commands/heredoc_supremacy/have_heredoc.c \
	  ./forge_of_commands/heredoc_supremacy/init_heredoc.c \
	  ./forge_of_commands/heredoc_supremacy/purify_from_heredoc.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_t_pipe_a.c \
	  ./forge_of_commands/exec_t_pipe_a/utilities.c \
	  ./forge_of_commands/exec_t_pipe_a/handle_cmd.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_built_ins_n/ft_cd_n.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_built_ins_n/ft_echo_n.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_built_ins_n/ft_pwd_n.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_built_ins_w/ft_cd_w.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_built_ins_w/ft_echo_w.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_built_ins_w/ft_pwd_w.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	cc $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ)
		cc $(FLAGS) $(OBJ) -lreadline -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
