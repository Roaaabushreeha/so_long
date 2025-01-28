/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:42:45 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 17:32:56 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nullfunction(t_game *game)
{
	game->map = NULL;
	game->player = NULL;
	game->image = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

t_game	*inti_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	nullfunction(game);
	game->map = initmap(game);
	storemap(game, argv);
	game->player = init_player();
	get_player_postion(game);
	if (is_valid(game->map, game) || is_square(game) || valid_path(game))
	{
		perror("Error: Invalid map.");
		exit_game(game);
	}
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "so_long");
	game->image = delcarimages(game);
	load(game);
	game->player->count = 0;
	game->map->count_collectible = check_collectible(game);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		i;

	if (argc != 2)
		return (1);
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '.' && argv[1][i + 1] != 'b')
			return (1);
		i++;
	}
	game = inti_game(argv);
	redraw_player(game, game->mlx, game->win);
	if (!game)
		return (1);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, free_game, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}
