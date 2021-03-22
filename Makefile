ASM_FILE=ft_strlen.s
OBJ_FILE=ft_strlen.o
TEST_FILE=main.c

NAME=libasm.a

all: $(NAME)

$(NAME): $(OBJ_FILE)
	nasm -fmacho64 $(ASM_FILE)
	ar rcs $(NAME) $(OBJ_FILE)

clean:
	rm -rf $(OBJ_FILE)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	gcc $(TEST_FILE) $(NAME)
	./a.out

.PHONY: all clean fclean re test
