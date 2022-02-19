SRC = 		client.c \
			utils.c \
			server.c

SRCS =	$(addprefix srcs/, $(SRC))

OBJ =	$(SRC:.c=.o)

OBJS =	$(addprefix objs/, $(OBJ))

NAME1 =	server

NAME2 =	client

CC = gcc

FLAGS = -Werror -Wall -Wextra

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all : tmp $(NAME1) $(NAME2)

$(NAME2) : $(OBJS)
		@$(CC) $(FLAGS) objs/utils.o objs/client.o -o $@
		@echo "$(GREEN)client.c successfully compiled"


$(NAME1) : $(OBJS)
		@$(CC) $(FLAGS) objs/server.o objs/utils.o -o $@
		@echo "$(GREEN)server.c successfully compiled"

objs/%.o: srcs/%.c include/minitalk.h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

tmp :
	@mkdir -p objs

clean :
	@rm -rf $(OBJS)
	@rm -rf objs

fclean : clean
	@rm -rf $(NAME1) $(NAME2)
	@rm -f client_bonus server_bonus
	@make -C bonus fclean

bonus :
	@make -C bonus
	
re : fclean all

.PHONY : all re fclean clean tmp bonus