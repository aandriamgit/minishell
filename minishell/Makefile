NAME = minishell

SRC = minishell.c\
		./libft/ft_strncmp.c\
		./formating/formating.c\
		./formating/check_quote.c\
		./libft/ft_strlen.c\
		./libft/ft_split.c\
		./libft/ft_substr.c\
		./libft/ft_strdup.c\

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME):$(OBJ)
		cc $(FLAGS) $(OBJ) -lreadline -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
