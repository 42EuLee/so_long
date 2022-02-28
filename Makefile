NAME 		= so_long

CC 			= gcc
CFLAGS 		=  -g -fsanitize=address -Wall -Wextra -Werror 
MACMLX 		= -framework OpenGl -framework Appkit
RM 			= rm -f
LIB 		= -lmlx -Llibft -lft

SL_SRC 		= ./
GNL_SRC		= ./get_next_line/

GNL_FILES 	= $(wildcard $(GNL_SRC)*.c)
SL_FILES 	= $(wildcard $(SL_SRC)*.c)

OBJS		= $(SL_FILES:.c=.o)

INCLUDES 	= -Iincludes -Imlx -Iget_next_line -Ilibft

all: $(NAME)

$(NAME):
	make re -C libft
	@$(CC) $(LIB) $(CFLAGS) $(INCLUDES) $(SL_FILES) $(GNL_FILES) $(MACMLX) -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft

re:	fclean all

.PHONY:	all run clean
