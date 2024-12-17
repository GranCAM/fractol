NAME = fractol

SRCS = fractol.c

LIBMLX = ./MLX42

CC = cc

CFLAGS = -Wall -Werror -Wextra

INC = -I ./include -I ./libft -I $(LIBMLX)/include

RM = rm -rf

LIBMLX42 = ./MLX42/include/libmlx42.a -ldl -lglfw -pthread -lm

#libmlx:
#	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

LIBFT = ./libft/libft.a

OBJ = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C $(LIBMLX)/include
	@$(CC) $(CFLAGS) $(LIBMLX42) $(LIBFT) $(INC) $^ -o $@

clean:
	@make -C $(LIBMLX)/include clean
	@make -C ./libft clean
	@$(RM) $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re