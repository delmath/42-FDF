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
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m

all: start_message $(NAME) end_message

start_message:
	@echo "$(YELLOW)========================================$(NC)"
	@echo "$(YELLOW)Starting compilation of $(NAME)...$(NC)"
	@echo "$(YELLOW)========================================$(NC)"

end_message:
	@echo "$(GREEN)========================================$(NC)"
	@echo "$(GREEN)Finished compilation of $(NAME).$(NC)"
	@echo "$(GREEN)========================================$(NC)"

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking...$(NC)"
	@$(AR) $(NAME) $^

$(OBJDIR)/%.o: %.c $(INC)
	@mkdir -p $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean
	$(MAKE) all