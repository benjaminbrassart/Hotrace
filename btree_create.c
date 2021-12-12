/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:25:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 09:27:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

t_btree	*btree_create(t_hash key, char *value)
{
	t_btree	*tree;

	tree = malloc(sizeof (*tree));
	if (tree)
	{
		tree->key = key;
		tree->value = value;
		tree->left = NULL;
		tree->right = NULL;
	}
	return (tree);
}
