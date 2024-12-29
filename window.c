/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:44 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/28 18:58:00 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int openwindow(t_game *game)
{
	
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->map->width * 64, game->map->height * 64, "SO_LONG");
 
	return 0;
}

int close_window(void *param)
{
    (void)param; 
    exit(0);
}

int close_window_event(int keycode, t_game *game)
{
    (void)keycode; 
    mlx_destroy_window(game->mlx, game->win); 
    exit(0);
}