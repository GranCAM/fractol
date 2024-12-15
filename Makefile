NAME = fractol

SRCS = fractal.c event.c event2.c main.c tools.c 

CC = cc

CFLAGS = -Wall -Werror -Wextra

INC = -I ./include -I ./libft

RM = rm -rf

LIBMLX42 = ./include/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT = ./libft/libft.a

OBJ = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./include
	@$(CC) $(CFLAGS) $(LIBMLX42) $(LIBFT) $(INC) $^ -o $@

clean:
	@make -C ./include clean
	@make -C ./libft clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@make -C ./include clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
