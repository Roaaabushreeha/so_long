/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:26:00 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 17:03:39 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_game *game)
{
	t_flood	data;
	char	**map_copy;
	int		collectibles;

	map_copy = fmap(game->map->array, game->map->height);
	if (!map_copy)
		return (1);
	collectibles = number_collectibtotal(game->map);
	data.map = map_copy;
	data.map_foold = game->map;
	data.collectibles = &collectibles;
	flood_fill(game->player->player_x, game->player->player_y, &data);
	free_2d_array(map_copy, game->map->height);
	if (collectibles > 0)
	{
		perror("Error: Not all collectibles are reachable.");
		return (1);
	}
	if (!data.map_foold->path)
	{
		perror("Error: Exit is not reachable.");
		return (1);
	}
	return (0);
}

int	is_right(t_game *game)
{
	int	i;
	int	h;

	h = game->map->height;
	i = 0;
	while (i < game->map->width)
	{
		if (game->map->array[0][i] == '0' || game->map->array[h - 1][i] == '0')
		{
			return (1);
		}
		i++;
	}
	i = 1;
	while (i < h - 1)
	{
		if (game->map->array[i][0] == '0'
			|| game->map->array[i][game->map->width - 1] == '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
