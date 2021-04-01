ifeq ($(shell uname), Linux)
SRCS += ${shell find ./srcs_linux -type f -name "*.s"}
endif
ifeq ($(shell uname), Darwin)
SRCS += ${shell find ./srcs_mac -type f -name "*.s"}
endif

OBJS = $(SRCS:.s=.o)

TEST_FILE=srcs_test/main.c

NAME=libasm.a

ifeq ($(shell uname), Linux)
.s.o:
	nasm -f elf64 -D LINUX $<
endif
ifeq ($(shell uname), Darwin)
.s.o:
	nasm -f macho64 -D MAC $<
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
	gcc -L. -lasm $(TEST_FILE)
	./a.out
	$(RM) a.out

.PHONY: all clean fclean re test
