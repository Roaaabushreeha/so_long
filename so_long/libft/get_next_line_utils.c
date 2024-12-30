/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:52:58 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/12/29 17:46:30 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char *save, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*p;

// 	i = 0;
// 	if (len > ft_strlen(save) - start)
// 		len = ft_strlen(save) - start;
// 	if (start >= ft_strlen(save))
// 	{
// 		p = malloc(1);
// 		if (!p)
// 			return (NULL);
// 		p[0] = '\0';
// 		return (p);
// 	}
// 	p = malloc((len + 1) * sizeof(char));
// 	if (!p || !save)
// 		return (NULL);
// 	while (i < len && start < ft_strlen((const char *)save))
// 	{
// 		p[i] = save[start];
// 		i++;
// 		start++;
// 	}
// 	p[i] = '\0';
// 	return (p);
// }

char	*f_strdup(const char *s)
{
	char	*p;
	int		i;
	size_t	len;

	i = 0;
	len = f_strlen((char *)s);
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*f_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*ss;

	ss = (char *)s;
	uc = (unsigned char)c;
	while (*ss != '\0')
	{
		if (*ss == uc)
			return (ss);
		ss++;
	}
	if (*ss == '\0' && uc != '\0')
		return (NULL);
	return (ss);
}

char	*f_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	l1;
	size_t	l2;
	int		i;
	int		point;

	l1 = f_strlen(s1);
	l2 = f_strlen(s2);
	i = 0;
	point = 0;
	p = malloc(sizeof(char) * (l1 + l2 + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	while (s1[i] != '\0')
		p[point++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		p[point++] = s2[i++];
	p[point] = '\0';
	return (p);
}

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
