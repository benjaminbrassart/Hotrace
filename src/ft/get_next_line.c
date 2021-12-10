/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:53:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/10 22:40:56 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <unistd.h>

static void	gnl_join(char **line, char *buffer, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	while (*line && (*line)[i])
		++i;
	s = malloc(i + n + 1);
	if (s)
	{
		ft_memmove(s, *line, i);
		ft_memmove(s + i, buffer, n);
		s[i + n] = 0;
		free(*line);
		*line = s;
	}
}

static int	gnl_copy(char **line, char *buffer, char **rest, int release)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	gnl_join(line, buffer, i);
	free(*rest);
	if (buffer[i])
		*rest = ft_strdup(buffer + i + 1);
	else
		*rest = NULL;
	i = !!buffer[i];
	if (release)
		free(buffer);
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (!line)
		return (-1);
	bytes = 1;
	*line = NULL;
	if (rest)
		if (gnl_copy(line, ft_strdup(rest), &rest, 1))
			return (1);
	while (bytes > 0)
	{
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes >= 0 && gnl_copy(line, buffer, &rest, 0))
			return (1);
	}
	return (bytes);
}
