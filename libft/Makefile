.PHONY: all clean fclean re

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_striteri.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_lstnew.c ft_lstclear.c ft_count_word.c ft_free_char_matrix.c \
       ft_strnjoin.c ft_strlen_s.c ft_free_null.c get_next_line.c

INC = libft.h
OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m
ERASE = \033[2K\r
ERASE2 = $(ERASE)\033[F$(ERASE)
TOTAL_FILES = $(words $(SRCS))
COMPILED_FILES = 0
PERCENT = 0
BAR_WIDTH = 30
REPEAT_CHAR = $(shell seq 1 $2 | xargs -I@ printf "$1")

all: start_message $(NAME) end_message

$(NAME): $(OBJS)
	@$(AR) $@ $^

$(OBJDIR)/%.o: %.c $(INC)
	@mkdir -p $(OBJDIR)
	@$(eval COMPILED_FILES := $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PERCENT := $(shell echo $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))))
	@$(eval PROGRESS := $(shell echo $$(( $(PERCENT) * $(BAR_WIDTH) / 100 ))))
	@$(eval EMPTY := $(shell echo $$(( $(BAR_WIDTH) - $(PROGRESS) ))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(ERASE)"
	@printf "$(YELLOW)["
	@printf "$(call REPEAT_CHAR,=,$(PROGRESS))"
	@printf "$(call REPEAT_CHAR,.,$(EMPTY))"
	@printf "]"
	@printf "$(BLUE)[Compiling $(COMPILED_FILES)/$(TOTAL_FILES)]$(NC) "
	@printf "$(PERCENT)%%$(NC)"


start_message:
	@echo "$(YELLOW)========================================$(NC)"
	@echo "$(YELLOW)Starting compilation of $(NAME)...$(NC)"
	@echo "$(YELLOW)========================================$(NC)"
	@echo ""

end_message:
	@printf "\n\n"
	@echo "$(GREEN)========================================$(NC)"
	@echo "$(GREEN)Finished compilation of $(NAME).$(NC)"
	@echo "$(GREEN)========================================$(NC)"
	@echo ""

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "$(RED)[LIBFT] Cleaned object files.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME).$(NC)"

re: fclean all
