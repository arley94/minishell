NAME=minishell
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=./libft/libft.a

SRC=	main.c \
		aux_cmds.c \
		aux_path.c \
		aux.c \
		ft_echo.c \
		ft_pwc.c \
		ft_export \
		ft_cd.c \
		aux_init.c \
		aux_export.c \
		aux_envp.c

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