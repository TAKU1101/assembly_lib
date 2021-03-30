SRCS=ft_strlen.s \
	 ft_strcpy.s \
	 ft_strcmp.s \
	 ft_write.s \
	 ft_read.s \
	 ft_strdup.s

OBJS = $(SRCS:.s=.o)

TEST_FILE=main.c

NAME=libasm.a

.s.o:
	nasm -fmacho64 $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) main.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re
	gcc $(TEST_FILE) $(NAME)
	./a.out

.PHONY: all clean fclean re test
