/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:52:41 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/01 15:09:45 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char *buf, char *save)
{
	free(buf);
	free(save);
	return (NULL);
}

static char	*ft_readbuf(char *buf, char *save, int fd)
{
	ssize_t	n;
	char	*temp;

	while (!f_strchr(save, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (check(buf, save));
		else if (n == 0)
			break ;
		buf[n] = '\0';
		temp = f_strjoin(save, buf);
		if (!temp)
		{
			free(save);
			free(temp);
			return (check(buf, temp));
		}
		free(save);
		save = temp;
	}
	free(buf);
	return (save);
}

static char	*ft_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || !save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_save(char *save)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	i++;
	new = (char *)malloc(sizeof(char) * (f_strlen(save) - i + 1));
	if (!new)
		return (NULL);
	while (save[i])
		new[j++] = save[i++];
	new[j] = '\0';
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = f_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(save);
		return (NULL);
	}
	save = ft_readbuf(buf, save, fd);
	if (!save)
	{
		free(save);
		return (NULL);
	}
	line = ft_line(save);
	save = ft_save(save);
	return (line);
}
