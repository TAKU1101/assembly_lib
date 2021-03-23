ASM_FILE=ft_strlen.s \
		 ft_strcpy.s \
		 ft_strcmp.s \
		 ft_write.s \
		 ft_read.s
OBJ_FILE=ft_strlen.o \
		 ft_strcpy.o \
		 ft_strcmp.o \
		 ft_write.o \
		 ft_read.o
TEST_FILE=main.c

NAME=libasm.a

all:
	nasm -fmacho64 ft_strlen.s
	nasm -fmacho64 ft_strcpy.s
	nasm -fmacho64 ft_strcmp.s
	nasm -fmacho64 ft_write.s
	nasm -fmacho64 ft_read.s
	ar rcs $(NAME) $(OBJ_FILE)

$(NAME):
	nasm -fmacho64 ft_strlen.s
	nasm -fmacho64 ft_strcpy.s
	nasm -fmacho64 ft_strcmp.s
	nasm -fmacho64 ft_write.s
	nasm -fmacho64 ft_read.s
	ar rcs $(NAME) $(OBJ_FILE)

clean:
	rm -rf $(OBJ_FILE) main.o

fclean:
	rm -rf $(OBJ_FILE) main.o
	rm -rf $(NAME)

re:
	rm -rf $(OBJ_FILE) main.o
	rm -rf $(NAME)
	nasm -fmacho64 ft_strlen.s
	nasm -fmacho64 ft_strcpy.s
	nasm -fmacho64 ft_strcmp.s
	nasm -fmacho64 ft_write.s
	nasm -fmacho64 ft_read.s
	ar rcs $(NAME) $(OBJ_FILE)

test:
	rm -rf $(OBJ_FILE) main.o
	rm -rf $(NAME)
	nasm -fmacho64 ft_strlen.s
	nasm -fmacho64 ft_strcpy.s
	nasm -fmacho64 ft_strcmp.s
	nasm -fmacho64 ft_write.s
	nasm -fmacho64 ft_read.s
	ar rcs $(NAME) $(OBJ_FILE)
	gcc $(TEST_FILE) $(NAME)
	./a.out

.PHONY: all clean fclean re test
