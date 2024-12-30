/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:42:45 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/30 17:00:25 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
t_game *inti_game(char **argv)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        perror("Error allocating game structure");
        return (NULL);
    }
    game->map = initmap(game);
    storemap(game, argv);
    if (is_valid(game->map)||is_square(game))
    {
        perror("Error: Invalid map.");
        exit_game(game);
    }
    game->player = init_player();
    get_player_postion(game);
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

	if (argc != 2)
		return (1);
	game = inti_game(argv);
	redraw_player(game, game->mlx, game->win);
	if (!game)
		return (1);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_window, NULL);
	mlx_loop(game->mlx);
	exit_game(game);
	return (0);
}
