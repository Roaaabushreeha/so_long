/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:42:45 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/28 18:58:12 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//game init 

 t_game *inti_game(char **argv)
{
	t_game *game;
    char    **arr;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        perror("Error allocating game structure");
        return NULL;
    }
    arr = init_map(argv[1]);
    if (!arr || store_map(game, arr) != 0)
    {
        perror("Error initializing map");
        free(game);
        return NULL;
    }
	game->player=init_player(game);
	get_player_postion(game);
    openwindow(game);
    game->image = delcarimages(game);
	load(game);
	game->count_collectible=check_collectible(game);
    return game;
}
int	main(int argc, char *argv[])
{   
	t_game *game;
    if (argc != 2)
        return (1);
    game = inti_game(argv);
    if (!game)
    return (1);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 2, 1L << 0, close_window, NULL); // pass the game struct so u can call the function free_exit(game) to free everything
    mlx_loop(game->mlx);
    // free(game); 
    return (0);
}
int	init(t_game *game, char **arr)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (arr[rows])
		rows++;
	if (rows == 0)
		return (-1);
	cols = strlen(arr[0]);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (-1);
	game->map->height = rows;
	game->map->width = cols;
	return (0);
}

int	store_map(t_game *game, char **arr)
{
	int	i;

	init(game, arr);
	game->map->array = malloc((game->map->height + 1) * sizeof(char *));
	if (!game->map->array)
		return (-1);
	i = 0;
	while (i < game->map->height)
	{
		game->map->array[i] = ft_strdup(arr[i]);
		if (!game->map->array[i])
		{
			while (--i >= 0)
				free(game->map->array[i]);
			free(game->map->array);
			return (-1);
		}
		i++;
	}
	game->map->array[game->map->height] = NULL;
	return (0);
}
// load mlx
// create a window
// i = game->map->height - 1;
//     while (i >= 0)
//     {
//         printf("%s\n", game->map->array[i]);
//         i--;
//     }