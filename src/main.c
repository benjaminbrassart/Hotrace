/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:07:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 01:31:49 by cloew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			brack
		}
		had = hash(*line);//header
                gnl = get_next_line(0, &line);
                //new_node(had, *line)
	}

	return (0);
}
