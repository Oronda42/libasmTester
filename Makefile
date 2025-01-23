GREEN = \033[0;32m
RED = \033[0;31m
PURPLE = \033[0;35m
NC = \033[0m # No Color

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 


NAME = main

SRC =   testing/utils.c  \
		testing/test_ft_strlen.c  \
		testing/test_ft_strcpy.c  \
		testing/test_ft_strcmp.c \
		testing/test_ft_write.c \
		testing/test_ft_read.c \
		testing/test_ft_strdup.c \
		testing/main.c
OBJ = $(SRC:.c=.o)
LIB = libasm/libasm.a

all: $(LIB) $(NAME)

$(LIB):
	@echo "$(GREEN)Building libasm.a$(NC)"
	$(MAKE) -C libasm

%.o: %.c
	@echo "$(GREEN)Assembling $< to $@$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME):  $(OBJ)
	@echo  "$(PURPLE)Compiling and linking $(NAME)$(NC)"
	$(CC) $(CFLAGS)  -o $@ $(OBJ) $(LIB)

clean:
	@echo "$(RED)Cleaning up...$(NC)"
	$(MAKE) clean -C libasm
	rm -f $(NAME) $(OBJ)

fclean: clean
	@echo "Force cleaning up..."
	$(MAKE) fclean -C libasm
	rm -f $(NAME)

re: fclean all 

rerun: fclean all
	./main
	

.PHONY: all clean fclean re