NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)
SRC = decals_parse.c \
	draft_map.c\
	draft_ray.c\
	free.c \
	get_next_line_utils.c \
	get_next_line.c\
	hook.c \
	init.c \
	main.c \
	map_parse.c\
	parse.c\
	rotations.c \
	struct.c\
	wasd.c \

OBJ_DIR = objs
LIBFT_DIR = includes/libft
MLX_DIR = includes/mlx

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)
	@echo "Compilation terminée."

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Fichiers objets supprimés."

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Exécutable supprimé."

norm :
	norminette

re: fclean all

.PHONY: all clean fclean re
