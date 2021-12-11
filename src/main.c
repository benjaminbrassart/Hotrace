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
	char		*line;
	t_hash		key;
	t_btree		*new;
	t_btree		*root;

	gnl = 1;
	root = NULL;
	while (gnl)
	{
		gnl = get_next_line(0, &line);
		if (!*line)
		{
			gnl = get_next_line(0, &line);
			while (gnl)
			{
				key = hash(line);
				new = btree_search(root, key);
				if (!new)
				{
					ft_putstr(line);
				}
				else
					ft_putstr(new->value);
				ft_putchar('\n');
				gnl = get_next_line(0, &line);
			}
			break ;
		}
	}
		key = hash(line);
		gnl = get_next_line(0, &line);
		new = btree_create(key, *line);
		if (!new)
			break ;
		btree_insert(&root, new);
	}
	btree_destroy(root);
	return (0);
}
