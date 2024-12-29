CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11

SLSRCS = so_long.c init_map.c window.c imagesdec.c player_move.c collectible.c hooks.c

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SOOBJ = $(SLSRCS:.c=.o)

NAME = so_long


all: $(NAME)

$(NAME): $(SOOBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(SOOBJ) $(MLXFLAGS) -o $@ -L $(LIBFT_DIR) -lft

$(SOOBJ): %.o : %.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(SOOBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
