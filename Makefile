NAME = fdf

SRCS = main.c render/color.c render/render_img.c utils/exit_handler.c utils/math_utils.c \
		utils/parsing_utils.c mlx/mlx_handler.c mlx/mlx_manager.c math/img_calc.c \
		math/camera_calc.c math/matrix_calc.c math/transform_calc.c init/init_map.c \
		init/init_scene.c utils/movement_utils.c utils/hud_utils.c utils/mlx_handler_utils.c \
		render/render_hud.c mlx/mlx_handler_movement.c
SRCS := $(addprefix src/, $(SRCS))
OBJ_DIR = obj/
OBJ = $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)%.o)
DEPS = $(OBJ:%.o=%.d)

CC = cc
CCFLAGS = -Wextra -Wall -Werror -g3
CPPFLAGS = -MMD -MP
SRCS_DIR = src/
INCLUDES = include/

MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx_Linux.a
MLX_FLAG = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX)
HEADERS = -I $(INCLUDES) -I $(MLX_DIR) -I $(LIBFT_DIR)

LIBFT_DIR  = Libft/
LIBFT  = $(LIBFT_DIR)libft.a
LIBFT_FLAG  = -L $(LIBFT_DIR) $(LIBFT)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CCFLAGS) $(OBJ) $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(CPPFLAGS)  $(HEADERS) -o $@ -c $<

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re