NAME = json

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc libft/libft.a main.c srcs/*.c -o $(NAME)

clean:
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/

re: fclean all

.PHONY: all, clean, fclean, re