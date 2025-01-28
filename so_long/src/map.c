/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:36:19 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 15:13:00 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines_count(int map_fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		line_count++;
		free(line);
	}
	return (line_count);
}

int	open_map(char **av, t_game *game)
{
	int	map_fd;

	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 0)
	{
		perror("error opening map file");
		free(game->map);
		free(game);
		exit(1);
	}
	return (map_fd);
}

t_map	*storemap(t_game *game, char **av)
{
	int	line_count;
	int	i;
	int	map_fd;

	i = 0;
	map_fd = open_map(av, game);
	line_count = map_lines_count(map_fd);
	game->map->array = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map->array)
		exit_game(game);
	close(map_fd);
	map_fd = open_map(av, game);
	while (i < line_count)
	{
		game->map->array[i] = get_next_line(map_fd);
		if (i == 0)
			game->map->width = ft_strlen(game->map->array[i]) - 1;
		i++;
	}
	game->map->height = line_count;
	game->map->array[i] = NULL;
	close(map_fd);
	return (game->map);
}
