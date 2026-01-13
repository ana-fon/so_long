# URLs dos módulos externos
LIBFT_URL 	= https://github.com/ana-fon/libft_updated.git
MLX_URL 	= https://github.com/42paris/minilibx-linux.git

# Caminhos das libs
LIBS_PATH = libs
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCH = $(LIBFT_PATH)/libft.a

MLX_PATH = $(LIBS_PATH)/mlx
MLX_ARCH = $(MLX_PATH)/libmlx_Linux.a

# Executável
NAME = so_long

# Sources
FILES = main.c game.c free.c player.c movements/check_movements.c \
		movements/movements.c check_map/check_map.c check_map/check_path.c \
		check_map/create_map.c check_map/ft_init_map.c check_map/ft_init_map_utils.c
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, $(FILES))
OBJS = $(SRC:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RFLAGS = -L ./libs/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -g3

# MAIN RULE
all: deps $(NAME)

# EXTERNAL DEPS
deps:
	@if [ ! -d "$(LIBFT_PATH)" ]; then $(MAKE) get_libft; else echo "libft folder found"; fi
	@if [ ! -d "$(MLX_PATH)" ]; then $(MAKE) get_mlx; else echo "mlx folder found"; fi

# COMPILE OBJS
%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

# COMPILE EXE
$(NAME): $(OBJS) $(LIBFT_ARCH) $(MLX_ARCH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCH) $(MLX_ARCH) $(RFLAGS) -o $(NAME)

# CLONE LIBFT VIA GITHUB
get_libft:
	@mkdir -p $(LIBS_PATH)
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		git clone $(LIBFT_URL) $(LIBFT_PATH); \
		echo "Libft module cloned"; \
	else \
		echo "Libft submodule already exists!"; \
	fi

# CLONE MLX VIA GITHUB
get_mlx:
	@mkdir -p $(LIBS_PATH)
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone $(MLX_URL) $(MLX_PATH); \
		echo "MLX module cloned"; \
	else \
		echo "MLX submodule already exists!"; \
	fi

# Compilar bibliotecas
$(LIBFT_ARCH):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_ARCH):
	$(MAKE) -C $(MLX_PATH)

# Limpeza de objetos
clean:
	rm -f $(OBJS)
	make clean -C libs/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libs/libft

# Recompilar do zero
re: fclean all
