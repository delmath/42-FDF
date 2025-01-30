.PHONY: all clean fclean re

NAME = fdf

SRCS = main.c render/color.c render/render_img.c utils/exit_handler.c utils/math_utils.c \
        utils/parsing_utils.c mlx/mlx_handler.c mlx/mlx_manager.c math/img_calc.c \
        math/camera_calc.c math/matrix_calc.c math/transform_calc.c init/init_map.c \
        init/init_scene.c utils/movement_utils.c utils/hud_utils.c utils/mlx_handler_utils.c \
        render/render_hud.c mlx/mlx_handler_movement.c utils/preset_utils.c init/init_preset.c
SRCS_DIR = src/
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))

OBJ_DIR = obj/
OBJ = $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)%.o)
DEPS = $(OBJ:%.o=%.d)

CC = cc
CCFLAGS = -Wextra -Wall -Werror -g3
CPPFLAGS = -MMD -MP

INCLUDES = include/
HEADERS  = -I $(INCLUDES) -I $(MLX_DIR) -I $(LIBFT_DIR)

MLX_DIR  = minilibx-linux/
MLX      = $(MLX_DIR)libmlx_Linux.a
MLX_FLAG = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX)

LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)libft.a
LIBFT_FLAG  = -L $(LIBFT_DIR) $(LIBFT)
MAKE = make --no-print-directory
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
WHITE  = \033[0;37m
NC     = \033[0;0m
ERASE  = \033[2K\r
ERASE2 = $(ERASE)\033[F$(ERASE)

TOTAL_FILES    = $(words $(SRCS))
COMPILED_FILES = 0
BAR_WIDTH      = 41
REPEAT_CHAR    = $(shell seq 1 $2 | xargs -I@ printf "$1")

all: mlx lft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) $(MLX_FLAG) $(LIBFT_FLAG) -o $(NAME)
	@$(MAKE) end_message

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAGS) $(CPPFLAGS) $(HEADERS) -c $< -o $@
	@$(eval COMPILED_FILES := $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PERCENT := $(shell echo $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))))
	@$(eval PROGRESS := $(shell echo $$(( $(PERCENT) * $(BAR_WIDTH) / 100 ))))
	@$(eval EMPTY := $(shell echo $$(( $(BAR_WIDTH) - $(PROGRESS) ))))
	@printf "$(ERASE)"
	@printf "$(YELLOW)["
	@printf "$(call REPEAT_CHAR,=,$(PROGRESS))"
	@printf "$(call REPEAT_CHAR,.,$(EMPTY))"
	@printf "]$(NC) "
	@printf "$(BLUE)[Compiling $(COMPILED_FILES)/$(TOTAL_FILES)] $(NC)"

-include $(DEPS)

mlx:
	@$(MAKE) -C $(MLX_DIR)

lft:
	@$(MAKE) -C $(LIBFT_DIR)

end_message:
	@printf "\n\n"
	@echo "╔════════════════════════════════╗"
	@echo "║ $(WHITE)       FDF - Compiled          ║"
	@echo "╚════════════════════════════════╝"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[FDF] Cleaned object files.$(NC)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME).$(NC)"

re: fclean all
