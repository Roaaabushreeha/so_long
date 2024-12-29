/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:50:37 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/28 18:49:21 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		height;
	int		width;
	char	*line;
	char	**array;
}			t_map;
typedef struct s_image
{
	void		*wall;
	int		img_width;
	int		img_height;
	void		*player;
	void		*floor;
	void		*collectible;
	void		*exit;
}t_image;
typedef struct s_player
{
	int player_y;
	int player_x;
}t_player;
typedef struct s_game
{
	void *mlx;
	void *win;
	int count_collectible;
	t_player *player;
	t_map	*map;
	t_image *image;
	
}t_game;
int			store_map(t_game *game, char **arr);
int			init(t_game *game, char **arr);
int			length(int fd);
char		**init_map(char *file);
int openwindow(t_game *game);
int close_window(void *param);
// int handle_keypress(int keycode, void *param);
int close_window_event(int keycode, t_game *game);
int whichimage(int i, int j, t_game *game);
t_image *delcarimages(t_game *game);
int load(t_game *game);
 t_game *inti_game(char **argv);
 int	handle_keypress(int keycode, t_game *game);
t_player *init_player();
 t_player *playerrmove(int i,int j,t_game *game);
 int get_player_postion(t_game *game);
 int check_collectible(t_game *game);
 void	exit_game(t_game *game);
 t_game *move_player(t_game *game,int x,int y);
 int number_collectib(t_game *game);
 void	redraw_player(t_game *game, void *mlx, void *win);
#endif