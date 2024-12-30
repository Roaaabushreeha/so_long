/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:30:32 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/30 12:14:49 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	if (game)
	{
		if (game->image)
		{
			free_images(game);
			free(game->image);
		}
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->player)
			free(game->player);
		 if (game->map)
			free_map(game);
		free(game);
	}
	exit(1);
}
void	free_images(t_game *game)
{
	if (game->image)
	{
		if (game->image->wall)
			mlx_destroy_image(game->mlx, game->image->wall);
		if (game->image->floor)
			mlx_destroy_image(game->mlx, game->image->floor);
		if (game->image->exit)
			mlx_destroy_image(game->mlx, game->image->exit);
		if (game->image->player)
			mlx_destroy_image(game->mlx, game->image->player);
		if (game->image->collectible)
			mlx_destroy_image(game->mlx, game->image->collectible);
	}
}
void	free_map(t_game *game)
{
	int	i;

	if (game->map->array)
	{
		i = 0;
		while (game->map->array[i])
		{
			free(game->map->array[i]);
			i++;
		}
		free(game->map->array);
		free(game->map);
	}
}