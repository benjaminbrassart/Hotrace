/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:07:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 12:48:42 by cloew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			brack
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
