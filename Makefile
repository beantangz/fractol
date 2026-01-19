NAME = fractol

SRC = fractol.c \
		utils.c \
		mandelbrot.c \
		view.c \
		args.c \
		julia.c

# Répertoire de MiniLibX et libft
MLX_DIR = minilib
LIBFT_DIR = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

# Includes et librairies
MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_FLAGS = -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft

# Règle par défaut
all: $(NAME)

$(NAME): $(SRC)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all