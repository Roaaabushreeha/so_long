/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:29:37 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/28 18:22:20 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	length(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

char	**init_map(char *file)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	len = length(fd);
	close(fd);
	map = malloc((len + 1) * sizeof(char *));
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (map);
}
