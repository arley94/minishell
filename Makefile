NAME=minishell
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=./libft/libft.a

SRC=	main.c \
		aux_cmds.c \
		aux_path.c \
		aux_lst.c \
		ft_echo.c \
		ft_pwd.c \
		ft_export.c \
		ft_cd.c \
		ft_env.c \
		ft_unset.c \
		ft_exit.c \
		aux_init.c \
		aux_envp.c \
		execute_builtin.c

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	@make all -C ./libft
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re