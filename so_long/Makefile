CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11
SRCS_DIR = src

SLSRCS = so_long.c map.c init_map.c imagesdec.c player_move.c collectible.c free.c valid.c valid_path.c flood_fill.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SLSRCS))
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $@ -L $(LIBFT_DIR) -lft

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
