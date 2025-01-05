NAME = minishell

OBJ_DIR = obj

SRC = minishell.c \
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
	  ./utils/lib/ft_atoi_a.c \
	  ./utils/lib/ft_isdigit_a.c \
	  ./utils/lib/ft_random_int.c \
	  ./utils/lib/ft_gen_env.c \
	  ./utils/lib/ft_bzero.c \
	  ./utils/lib/ft_calloc.c \
	  ./utils/lib/ft_isalpha.c \
	  ./utils/lib/ft_strtrim.c \
	  ./utils/lib/ft_strchr.c \
	  ./utils/modules/add.c \
	  ./utils/modules/ft_execve.c \
	  ./utils/modules/ft_free.c \
	  ./utils/modules/ft_print_pipe_a.c \
	  ./utils/modules/gen.c \
	  ./utils/modules/extras.c \
	  ./utils/modules/exit_code.c \
	  ./utils/modules/ft_perror/ft_perror.c \
	  ./utils/modules/ft_perror/gen_fd.c \
	  ./utils/modules/close_all_fds.c \
	  ./utils/modules/ft_perror/custom_error/custom_error.c \
	  ./utils/modules/ft_perror/custom_error/custom_extras.c \
	  ./shell_init/shell_init.c \
	  ./shell_init/exec_big_param/exec_big_param.c \
	  ./get_next_line/get_next_line.c \
	  ./get_next_line/get_next_line_utils.c \
	  ./interpret/interpret.c \
	  ./interpret/unclosed_quote.c \
	  ./interpret/unclosed_pipe.c \
	  ./interpret/extended_interpret.c \
	  ./interpret/error_redir.c \
	  ./forge_of_commands/convert_t_pipe_a.c \
	  ./forge_of_commands/init_stderr.c \
	  ./forge_of_commands/custom_prompt.c \
	  ./forge_of_commands/terminus.c \
	  ./forge_of_commands/reboot_prompt.c \
	  ./forge_of_commands/heredoc_supremacy/heredoc_supremacy.c \
	  ./forge_of_commands/heredoc_supremacy/get_eof.c \
	  ./forge_of_commands/heredoc_supremacy/have_heredoc.c \
	  ./forge_of_commands/heredoc_supremacy/init_heredoc.c \
	  ./forge_of_commands/heredoc_supremacy/purify_from_heredoc.c \
	  ./forge_of_commands/heredoc_supremacy/print_heredoc.c \
	  ./forge_of_commands/exec_t_pipe_a/exec_t_pipe_a.c \
	  ./forge_of_commands/exec_t_pipe_a/handle_redir.c \
	  ./forge_of_commands/exec_t_pipe_a/ambiguous_redirect.c \
	  ./forge_of_commands/exec_t_pipe_a/path_no_pipe.c \
	  ./forge_of_commands/exec_t_pipe_a/gen_pid_a/gen_pid_a.c \
	  ./forge_of_commands/exec_t_pipe_a/gen_pid_a/path_w_pipe.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/built_ins_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_echo_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_cd_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_pwd_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_unset_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_env_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_export_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/ft_exit_n.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_n/custom_perror.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/built_ins_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_echo_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_cd_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_env_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_export_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_pwd_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_unset_w.c \
	  ./forge_of_commands/exec_t_pipe_a/built_ins_w/ft_exit_w.c \
	  ./minishell_dlc/check.c\
	  ./minishell_dlc/ft_strjoin_p.c\
	  ./minishell_dlc/ft_strjoin_space.c\
	  ./minishell_dlc/formating.c\
	  ./minishell_dlc/simple_split.c\
	  ./minishell_dlc/join_with_space.c\
	  ./minishell_dlc/join_no_space.c\
	  ./minishell_dlc/ft_free.c\
	  ./minishell_dlc/redirection.c\
	  ./minishell_dlc/cmd.c\
	  ./minishell_dlc/libft/ft_putstr_p.c\
	  ./minishell_dlc/libft/ft_putchar_p.c\
	  ./minishell_dlc/libft/ft_strcmp_p.c\
	  ./minishell_dlc/libft/ft_strlen_p.c\
	  ./minishell_dlc/libft/ft_split_p.c\
	  ./minishell_dlc/libft/ft_strdup_p.c\
	  ./minishell_dlc/ft_split_p.c\
	  ./minishell_dlc/libft/ft_substr_p.c\
	  ./minishell_dlc/builting/env/env.c\
	  ./minishell_dlc/builting/unset/unset.c\
	  ./minishell_dlc/builting/export/check_export.c\
	  ./minishell_dlc/builting/export/simple_export.c\
	  ./minishell_dlc/builting/export/display_export.c\
	  ./minishell_dlc/builting/export/export_with_arg.c\
	  ./minishell_dlc/list/display_list.c\
	  ./minishell_dlc/list/ordered_list.c\
	  ./minishell_dlc/list/creat_bloc_of_list.c\
	  ./minishell_dlc/list/creat_chain_of_list.c\
	  ./minishell_dlc/list/creat_bloc_redir.c\
	  ./minishell_dlc/list/creat_bloc_cmd.c\
	  ./minishell_dlc/list/creat_bloc_pipe.c\
	  ./minishell_dlc/display/display_list.c\
	  ./minishell_dlc/display/sort_list.c\
	  ./minishell_dlc/expend/expend.c\
	  ./minishell_dlc/expend/fake_expend.c \
	  ./minishell_dlc/expend/get_the_thing.c \
	  ./minishell_dlc/expend/dep/dep.c\
	  ./minishell_dlc/expend/dep/ft_split_a.c\
	  ./minishell_dlc/expend/dep/extras_expend.c \
	  ./minishell_dlc/expend/simple_expend.c\
	  ./minishell_dlc/expend/ex_quote.c\
	  ./minishell_dlc/split_pipe.c \
	  ./minishell_dlc/rm_quote.c\
	  ./minishell_dlc/ft_free/free_pipe.c\
	  ./minishell_dlc/split_quote.c\
	  ./minishell_dlc/ft_free/free_list.c\
	  ./minishell_dlc/ft_getenv.c\
	  ./minishell_dlc/expend/check.c\
	  ./minishell_dlc/split_take_quote.c\
	  ./minishell_dlc/ft_expend.c\
	  ./minishell_dlc/ft_expend_ex.c\

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
