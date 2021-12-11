/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:07:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 01:59:28 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	int	gnl;
	char	*line;
	int	had;

	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(0, &line);
		if (!*line)
		{
			gnl = get_next_line(0, &line);
			while (gnl)
			{
				hash(*line);
				//find me
				gnl = get_next_line(0, &line);
			}
			break ;
		}
		had = hash(*line);//header
                gnl = get_next_line(0, &line);
                //new_node(had, *line)
	}
	return (0);
}
