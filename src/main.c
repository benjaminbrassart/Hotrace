/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:07:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 12:53:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>

static void	print_error(char const *keyword)
{
	unsigned int	i;

	i = 0;
	while (keyword[i])
		++i;
	write(1, keyword, i);
	write(1, NOT_FOUND_SUFFIX, sizeof (NOT_FOUND_SUFFIX) - 1);
}

int	main(void)
{
	int		gnl;
	char	*line;
	int		had;

	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(0, &line);
		if (!*line)
		{
			gnl = get_next_line(0, &line);
			while (gnl)
			{
				hash(line);
				//find me
				gnl = get_next_line(0, &line);
			}
			break ;
		}
		had = hash(line); //header
		gnl = get_next_line(0, &line);
		//new_node(had, *line)
	}
	return (0);
}
