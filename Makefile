ASM_FILE=ft_strlen.s

OBJ_FILE=ft_strlen.o

all: $(NAME)
	nasm -fmacho64 $(ASM_FILE)
	
