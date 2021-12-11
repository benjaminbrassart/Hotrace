/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:53:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 11:50:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <unistd.h>

static void	*ft_memmove(void *dst, void const *src, unsigned int n)
{
	unsigned char		*d;
	unsigned char const	*s;

	d = dst;
	s = src;
	if (src > dst)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			d[n] = s[n];
	return (dst);
}

static char	*gnl_realloc(char *line, char *buf, int line_len, int i)
{
	char	*new_line;

	new_line = malloc(sizeof (*new_line) * (line_len + i + 1));
	if (new_line)
	{
		ft_memmove(new_line, line, line_len);
		ft_memmove(new_line + line_len, buf, i);
		new_line[line_len + i] = 0;
		free(line);
	}
	return (new_line);
}

static int	gnl_join(char **line, char buf[BUFFER_SIZE], int *buf_len)
{
	int		i;
	int		line_len;
	char	*new_line;
	int		on_newline;

	on_newline = 0;
	line_len = 0;
	if (*line)
		while ((*line)[line_len])
			++line_len;
	i = 0;
	while (i < *buf_len && buf[i] != '\n')
		++i;
	new_line = gnl_realloc(*line, buf, line_len, i);
	if (!new_line)
		return (-1);
	*line = new_line;
	if (buf[i] == '\n')
	{
		on_newline = 1;
		++i;
	}
	ft_memmove(buf, buf + i, *buf_len - i);
	*buf_len -= i;
	return (on_newline);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE];
	static int	buf_len = 0;
	int			status;

	*line = NULL;
	while (1)
	{
		if (buf_len > 0)
		{
			status = gnl_join(line, buf, &buf_len);
			if (status)
				return (status);
		}
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len <= 0)
			break ;
	}
	return (buf_len);
}
