/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:49:51 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/29 11:48:21 by marvin           ###   ########.fr       */
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

t_player *init_player()
{
	t_player	*player;
	player = malloc(sizeof(t_player));
	player->player_x=0;
	player->player_y=0;
	return(player);
	// t_player - part of game struct 
}
//t_player *playerrmove(int i,int j,t_game *game)
//{
		
//	game->player->player_x=i;
//	game->player->player_y=j;
	
//	return(game->player);
//}
t_game *move_player(t_game *game,int x,int y)
{
	int newx;
	int newy;
	
	newx=game->player->player_x+x;
	newy=game->player->player_x+y;
	if (game->map->array[newx][newy]!='1')
	{
		game->player->player_x=newx;
		game->player->player_y=newy;
			
	if (game->map->array[newx][newy]=='C')
	{
			game->count_collectible--;
			game->map->array[newx][newx]='0';
	}
	if (game->map->array[newx][newy]=='E')
	{
			if(game->count_collectible==0)
			{
				exit_game(game);
			}
	}
	}
	redraw_player(game, game->mlx, game->win);
return(game);
}
int get_player_postion(t_game *game)
{
	
	int i = 0;
    int j;

    while (i < game->map->height)
    {
        j = 0;
        while (j < game->map->width)
        {
			if (game->map->array[i][j]=='P')
			{
					game->player->player_x=i;
					game->player->player_y=j;
			}
			
            j++;
        }
        i++;
    }
    return 0;
	
}