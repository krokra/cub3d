NAME		= cub3d

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -Iincludes -Iminilibx-linux

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src/
SRC			=	main.c \
				parsing_utils.c \
				my_mlx_pixel_put.c \
				map_checker.c \
				initialize.c
OBJ_DIR		= obj
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP			= $(OBJ:.o=.d)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(OBJ) -Llibft -lft $(MLX_FLAGS) -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -Ilibft -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

bonus : all

clean:
	@make clean -C libft
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all

libft:
	make -C libft

-include $(DEP)

.PHONY: all clean fclean re