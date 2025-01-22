NAME = fdf

SRCS = main.c listener.c mlx_manager.c init_map.c exit_handler.c parsing/parsing_utils.c
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