NAME = ./philo

CC = /bin/cc

CFLAGS = -Wextra -Werror -Wall -g


GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

SRC = src/main.c src/utils.c src/routine.c src/thread_utils.c \
		src/prints_no_norme.c src/states_actions.c src/print_data.c

OBJ_DIR = ./obj
OBJ = $(SRC:./src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT_LIBRARY):
	/bin/make --quiet -C $(LIBFT)

$(NAME): $(OBJ)
	@echo
	@echo "$(YELLOW)Compiling source files...$(NC)"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation is complete. Generated executable: $(NAME).$(NC)"
	@echo

$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling file $<...$(NC)"
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo

$(OBJ_DIR):
	@/bin/mkdir -p $(OBJ_DIR)

clean:
	@echo
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Cleaning complete.$(NC)"
	@echo

fclean: clean
	@echo
	@echo "$(YELLOW)Removing executable $(NAME)...$(NC)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Removal complete.$(NC)"
	@echo

re: fclean all

.PHONY: all clean fclean re