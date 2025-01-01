/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagesdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:23:49 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 17:35:24 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	whichimage(int i, int j, t_game *game)
{
	void	*image;

	if (game->map->array[i][j] == '1')
		image = game->image->wall;
	else if (game->map->array[i][j] == '0')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'E')
		image = game->image->exit;
	else if (game->map->array[i][j] == 'P')
		image = game->image->floor;
	else if (game->map->array[i][j] == 'C')
		image = game->image->collectible;
	else
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, image, j * 64, i * 64);
	return (0);
}

t_image	*delcarimages(t_game *game)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		exit(1);
	image->img_height = 64;
	image->img_width = 64;
	image->floor = mlx_xpm_file_to_image(game->mlx, "floor.xpm",
			&image->img_width, &image->img_height);
	image->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm",
			&image->img_width, &image->img_height);
	image->player = mlx_xpm_file_to_image(game->mlx, "re.xpm",
			&image->img_height, &image->img_width);
	image->exit = mlx_xpm_file_to_image(game->mlx, "tower.xpm",
			&image->img_width, &image->img_height);
	image->collectible = mlx_xpm_file_to_image(game->mlx, "crown.xpm",
			&image->img_height, &image->img_width);
	return (image);
}

int	load(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			whichimage(i, j, game);
			j++;
		}
		i++;
	}
	return (0);
}

void	redraw_player(t_game *game, void *mlx, void *win)
{
	load(game);
	mlx_put_image_to_window(mlx, win, game->image->player,
		game->player->player_x * 64, game->player->player_y * 64);
}
