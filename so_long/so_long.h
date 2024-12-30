/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:50:37 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/30 16:34:42 by rabu-shr         ###   ########.fr       */
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
	int			height;
	int			width;
	char		**array;
	int 	exit_count;
	int 	player_count;
	int			count_collectible;
}				t_map;

typedef struct s_image
{
	void		*wall;
	int			img_width;
	int			img_height;
	void		*player;
	void		*floor;
	void		*collectible;
	void		*exit;
}				t_image;
typedef struct s_player
{
	int			player_y;
	int			player_x;
	int			count;
}				t_player;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	t_image		*image;

}				t_game;
t_map			*storemap(t_game *game, char **av);
t_map			*initmap(t_game *game);
int				init(t_game *game, char **arr);
int				length(int fd);
char			**init_map(char *file);
int				openwindow(t_game *game);
int				close_window(void *param);
int				close_window_event(int keycode, t_game *game);
int				whichimage(int i, int j, t_game *game);
t_image			*delcarimages(t_game *game);
int				load(t_game *game);
t_game			*inti_game(char **argv);
int				handle_keypress(int keycode, t_game *game);
t_player		*init_player(void);
int				get_player_postion(t_game *game);
int				check_collectible(t_game *game);
void			exit_game(t_game *game);
void			move_player(t_game *game, int x, int y);
int				number_collectib(t_game *game);
void			redraw_player(t_game *game, void *mlx, void *win);
size_t			count_columns(char *row);
void	free_images(t_game *game);
void	free_map(t_game *game);
int is_valid(t_map *map);
int check_count(t_map *map);
int	number_collectibtotal(t_map *map);
int is_square(t_game *game);
size_t removeln(char *line);
#endif