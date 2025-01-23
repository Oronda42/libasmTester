NASM = nasm
NASMFLAGS = -f elf64
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRC:.s=.o)
NAME = libasm.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) 

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re