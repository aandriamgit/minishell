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
		./interpret/ft_readline/ft_readline.c \
		./interpret/ft_add_history/ft_add_history.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

YELLOW = \033[38;2;249;226;175m
BLUE = \033[38;2;180;190;254m
GREEN = \033[38;2;166;227;161m
RESET = \033[0m
COMPILING = "\r${YELLOW}[ ]${RESET} compiling ${BLUE}"
COMPILED = "\r${GREEN}[✔]${RESET} compiled successfully! ${BLUE}.  ★                                       \n"
RM_NAME = "\r${GREEN}[✔]${RESET} rm name successfully! ${BLUE}✧̣̇ ˳\n"
RM_OBJS = "\r${GREEN}[✔]${RESET} rm objs successfully! ${BLUE}.˚ ✦\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@cc $(CFLAGS) -c $< -o $@
	@printf $(COMPILING)$<

$(NAME) : $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)
	@printf $(COMPILED)

all: $(NAME)

fclean: clean
	@$(RM) $(NAME)
	@printf $(RM_NAME)

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@printf $(RM_OBJS)

re: fclean all
