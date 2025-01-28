/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:50:37 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/28 16:44:06 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
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
	int			exit_count;
	int			player_count;
	int			count_collectible;
	int			path;
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
typedef struct s_flood
{
	t_map		*map_foold;
	char		**map;
	int			*collectibles;
}				t_flood;
int				flood_fill(int x, int y, t_flood *data);
char			**fmap(char **map_flood, int height);
int				valid_path(t_game *game);
void			free_2d_array(char **array, int height);
t_map			*storemap(t_game *game, char **av);
t_map			*initmap(t_game *game);
int				length(int fd);
char			**init_map(char *file);
int				close_window(void *param, t_game *game);
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
void			free_images(t_game *game);
void			free_map(t_game *game);
int				is_valid(t_map *map, t_game *game);
int				check_count(t_map *map);
int				number_collectibtotal(t_map *map);
int				is_square(t_game *game);
size_t			removeln(char *line);
int				free_game(t_game *game);
void			nullfunction(t_game *game);
int				is_right(t_game *game);
t_flood			*init_floodfill(char **map, t_map *map_flood,
					int *collectibles);

#endif