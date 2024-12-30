/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:10:13 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/30 17:36:51 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectible(t_game *game)
{
	game->map->count_collectible = number_collectib(game);
	return (game->map->count_collectible);
}

int	number_collectib(t_game *game)
{
	int count;
	int i;
	int j;
	i = 0;
	count = 0;

	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->array[i][j] == 'C')
			{
				count++;
			}

			j++;
		}
		i++;
	}
	return (count);
}