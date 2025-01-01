/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:44 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 15:13:55 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param, t_game *game)
{
	(void)param;
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(1);
}

int	free_game(t_game *game)
{
	exit_game(game);
	exit(0);
}
