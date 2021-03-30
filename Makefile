SRCS=ft_strlen.s \
	 ft_strcpy.s \
	 ft_strcmp.s \
	 ft_write.s \
	 ft_read.s \
	 ft_strdup.s

OBJS = $(SRCS:.s=.o)

TEST_FILE=main.c

NAME=libasm.a

ifeq ($(shell uname),Linux)
.s.o:
	nasm -fmacho64 -D OS=LINUX $<
else
.s.o:
	nasm -fmacho64 -D OS=MAC $<
endif

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) main.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	gcc $(TEST_FILE) $(NAME)
	./a.out
	$(RM) a.out

.PHONY: all clean fclean re test
