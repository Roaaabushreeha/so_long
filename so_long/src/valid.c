/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:52:33 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 17:19:56 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(t_map *map, t_game *game)
{
	check_count(map);
	if (is_right(game))
		return (1);
	if (map->exit_count != 1)
		return (1);
	if (map->player_count != 1)
		return (1);
	if (number_collectibtotal(map) == 0)
		return (1);
	if (check_count(map))
		return (1);
	return (0);
}

int	check_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->exit_count = 0;
	map->player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == 'E')
				map->exit_count++;
			else if (map->array[i][j] == 'P')
				map->player_count++;
			else if (map->array[i][j] != 'C' && map->array[i][j] != '0'
					&& map->array[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	number_collectibtotal(t_map *map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	is_square(t_game *game)
{
	size_t	row_length;
	int		i;

	row_length = removeln(game->map->array[0]);
	i = 0;
	while (game->map->array[i])
	{
		if (removeln(game->map->array[i]) != row_length)
		{
			perror("Error: The map is not square.");
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	removeln(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}
