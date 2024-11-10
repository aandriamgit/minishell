NAME = minishell

OBJ_DIR = obj

SRC = minishell.c\
	  ./builting/env/env.c\
	  ./libft/ft_strlen.c\
	  ./utils/list/creat_bloc_of_list.c\
	  ./utils/list/creat_chain_of_list.c\
	  ./utils/list/display_list.c\
	  ./libft/ft_strcmp.c\
	  ./utils/list/ordered_list.c\
	  ./builting/export/simple_export.c\
	  ./builting/export/export_with_arg.c\
	  ./builting/export/display_export.c\
	  ./libft/ft_split.c\
	  ./libft/ft_execve.c \
	  ./libft/ft_strjoin.c \
	  ./libft/ft_strdup.c \
	  ./libft/ft_substr.c \
	  ./libft/ft_free_all.c \
	  ./libft/ft_putstr_fd.c \
	  ./libft/ft_strncmp.c \
	  ./shell_init/shell_init.c \
	  ./shell_init/exec_big_param/exec_big_param.c \
	  ./builting/export/check_export.c\
	  ./builting/unset/unset.c\
	  ./get_next_line/get_next_line.c \
	  ./get_next_line/get_next_line_utils.c \
	  ./interpret/interpret.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)/$(dir $<)
	cc $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ)
		cc $(FLAGS) $(OBJ) -lreadline -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
