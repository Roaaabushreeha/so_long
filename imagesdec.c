/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagesdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:23:49 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/28 18:50:58 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int whichimage(int i, int j, t_game *game)
// {
// 	void *image;
	
// 	if (game->map->array[i][j] == '1')
// 		image = game->image->wall;
// 	else if (game->map->array[i][j] == '0')
// 		image = game->image->floor;
// 	else if (game->map->array[i][j] == 'E')
// 		image = game->image->exit;
// 	else if (game->map->array[i][j] == 'P')
// 		image = game->image->floor;
// 	else if (game->map->array[i][j] == 'C')
// 		image = game->image->collectible;
// 	else
// 		return 0;
// 	   if (image)
//         mlx_put_image_to_window(game->mlx, game->win, image, j * 64, i * 64);
		
// 	return 0;
// }
// void *delcarimages(t_game *game)
// {
// 	t_image *image = malloc(sizeof(t_image));
//     if (!image)
//     {
//         perror("Error allocating memory for images");
//         return NULL;
//     }
// 	image->img_height=64;
// 	image->img_width=64;
	
// 	 image->floor = mlx_xpm_file_to_image(game->mlx, "floor.xpm", &image->img_width, &image->img_height);
// 	 image->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &image->img_width, &image->img_height);
// 	image->player=mlx_xpm_file_to_image(game->mlx, "re.xmp", &image->img_height,&image->img_width);
// 	  image->exit = mlx_xpm_file_to_image(game->mlx, "tower.xpm", &image->img_width, &image->img_height);
// 	image->collectible=mlx_xpm_file_to_image(game->mlx, "crown.xmp", &image->img_height,&image->img_width);
// 	return (image);
// }
// int load(t_game *game)
// {
// 	int i;
// 	int j;
// 	i=0;
// 	j=0;
// while (i < game->map->height)
// {
// 	j=0;
// 	while (j<game->map->width)
// 	{
// 		whichimage(i,j,game);
// 		j++;
// 	}
// 	i++;
// }
// return 0;
	
// }
#include "so_long.h"

int whichimage(int i, int j, t_game *game)
{
	void *image;
    if (!game || !game->map || !game->map->array || !game->image)
    {
        fprintf(stderr, "Error: Invalid game state\n");
        return -1;
    }

    if (game->map->array[i][j] == '1')
        image = game->image->wall;
    else if (game->map->array[i][j] == '0')
        image = game->image->floor;
    else if (game->map->array[i][j] == 'E')
        image = game->image->exit;
    else if (game->map->array[i][j] == 'P')
        image = game->image->player;
    else if (game->map->array[i][j] == 'C')
        image = game->image->collectible;
    else
        return 0;

mlx_put_image_to_window(game->mlx, game->win, image, j * 64, i * 64);
    return 0;
}

t_image *delcarimages(t_game *game)
{
	t_image *image;
    image = malloc(sizeof(t_image));
    if (!image)
    {
        perror("Error allocating memory for images");

    }
    image->img_height = 64;
    image->img_width = 64;

    image->floor = mlx_xpm_file_to_image(game->mlx, "floor.xpm", &image->img_width, &image->img_height);
    if (!image->floor)
		perror("faile to load floor image");
    image->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &image->img_width, &image->img_height);
    if (!image->wall)
        fprintf(stderr, "Error: Failed to load 'wall.xpm'\n");

    image->player = mlx_xpm_file_to_image(game->mlx, "re.xpm", &image->img_height, &image->img_width);
    if (!image->player)
		perror("failed to laod player");
    image->exit = mlx_xpm_file_to_image(game->mlx, "tower.xpm", &image->img_width, &image->img_height);
    if (!image->exit)
        fprintf(stderr, "Error: Failed to load 'tower.xpm'\n");

    image->collectible = mlx_xpm_file_to_image(game->mlx, "crown.xpm", &image->img_height, &image->img_width);
    if (!image->collectible)
        fprintf(stderr, "Error: Failed to load 'crown.xmp'\n");
return (image);
}

int load(t_game *game)
{
    int i = 0;
    int j;

    if (!game)
    {
        fprintf(stderr, "Error: Invalid game state\n");
        return -1;
    }

    while (i < game->map->height)
    {
        j = 0;
        while (j < game->map->width)
        {
				whichimage(i,j,game);
            j++;
        }
        i++;
    }
    return 0;
}

void	redraw_player(t_game *game, void *mlx, void *win)
{
	load(game);
	mlx_put_image_to_window(mlx, win, game->image->player,
		game->player->player_x * 64, game->player->player_y * 64);
}