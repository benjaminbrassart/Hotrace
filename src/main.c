/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:07:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 20:42:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
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

static int	parse_init(t_btree **root)
{
	char	*line;
	t_hash	key;
	t_btree	*new;

	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		if (!*line)
			break ;
		key = hash(line);
		free(line);
		if (get_next_line(0, &line) <= 0)
			break ;
		new = btree_create(key, line);
		if (!new)
			break ;
		btree_insert(root, new);
	}
	free(line);
	return (1);
}

static void	exec_get_keys(t_btree **root)
{
	t_hash	key;
	char	*line;
	t_btree	*search;

	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		key = hash(line);
		search = btree_search(*root, key);
		if (search)
			ft_putstr(search->value);
		else
			print_error(line);
		ft_putstr("\n");
		free(line);
	}
}

int	main(void)
{
	t_btree		*root;

	root = NULL;
	if (parse_init(&root))
		exec_get_keys(&root);
	btree_destroy(root);
	return (0);
}
