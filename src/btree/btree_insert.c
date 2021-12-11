/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 00:06:24 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 08:47:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void	btree_insert(t_btree **root, t_btree *node)
{
	t_btree	*sub;
	t_btree	*slow;

	if (!*root)
	{
		*root = node;
		return ;
	}
	slow = NULL;
	sub = *root;
	while (sub)
	{
		slow = sub;
		if (node->key < sub->key)
			sub = sub->left;
		else if (node->key > sub->key)
			sub = sub->right;
	}
	if (node->key < slow->key)
		slow->left = node;
	if (node->key > slow->key)
		slow->right = node;
	*root = btree_balance(*root);
}
