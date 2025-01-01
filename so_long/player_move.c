/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:49:51 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 15:56:28 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 119 || keycode == 65362)
	{
		move_player(game, 0, -1);
	}
	if (keycode == 97 || keycode == 65361)
	{
		move_player(game, -1, 0);
	}
	if (keycode == 115 || keycode == 65364)
	{
		move_player(game, 0, 1);
	}
	if (keycode == 100 || keycode == 65363)
	{
		move_player(game, 1, 0);
	}
	return (0);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player_x = 0;
	player->player_y = 0;
	return (player);
}

void	move_player(t_game *game, int x, int y)
{
	int	newx;
	int	newy;

	newx = game->player->player_x + x;
	newy = game->player->player_y + y;
	if (game->map->array[newy][newx] != '1')
	{
		game->player->player_x = newx;
		game->player->player_y = newy;
		if (game->map->array[newy][newx] == 'C')
		{
			game->map->count_collectible--;
			game->map->array[newy][newx] = '0';
		}
		if (game->map->array[newy][newx] == 'E'
			&& game->map->count_collectible == 0)
		{
			exit_game(game);
		}
		game->player->count++;
		redraw_player(game, game->mlx, game->win);
		ft_putnbr_fd(game->player->count, 1);
		write(1, "\n", 1);
	}
}

int	get_player_postion(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->array[i][j] == 'P')
			{
				game->player->player_x = j;
				game->player->player_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
