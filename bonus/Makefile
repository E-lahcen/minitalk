SRC = 		client_bonus.c \
			utils_bonus.c \
			server_bonus.c

SRCS =	$(addprefix srcs_bonus/, $(SRC))

OBJ =	$(SRC:.c=.o)

OBJS =	$(addprefix objs_bonus/, $(OBJ))

NAME1 =	server_bonus

NAME2 =	client_bonus

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
	@mv client_bonus server_bonus ../

$(NAME1) : $(OBJS)
		@$(CC) $(FLAGS) objs_bonus/utils_bonus.o objs_bonus/server_bonus.o -o $@
		@echo "$(GREEN)server_bonus.c successfully compiled"

$(NAME2) : $(OBJS)
		@$(CC) $(FLAGS) objs_bonus/utils_bonus.o objs_bonus/client_bonus.o -o $@
		@echo "$(GREEN)client_bonus.c successfully compiled"

objs_bonus/%.o: srcs_bonus/%.c include_bonus/minitalk_bonus.h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating bonus object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

tmp :
	@mkdir -p objs_bonus

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME1) $(NAME2)
	@rm -rf objs_bonus

re : fclean all

.PHONY : all re fclean clean tmp bonus