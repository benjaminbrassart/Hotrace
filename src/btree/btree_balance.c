/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_balance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 06:35:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 08:55:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_btree	*btree_balance(t_btree *node)
{
	t_btree	*new_root;
	int		factor;

	if (node->left)
		node->left = btree_balance(node->left);
	if (node->right)
		node->right = btree_balance(node->right);
	factor = btree_balance_factor(node);
	new_root = node;
	if (factor >= 2)
	{
		if (btree_balance_factor(node->left) <= -1)
			new_root = btree_lrrotate(node);
		else
			new_root = btree_llrotate(node);
	}
	else if (factor <= -2)
	{
		if (btree_balance_factor(node->right) >= 1)
			new_root = btree_rlrotate(node);
		else
			new_root = btree_rrrotate(node);
	}
	return (new_root);
}

t_btree	*btree_llrotate(t_btree *node)
{
	t_btree	*a;
	t_btree	*b;

	a = node;
	b = a->left;
	a->left = b->right;
	b->right = a;
	return (b);
}

t_btree	*btree_lrrotate(t_btree *node)
{
	t_btree	*a;
	t_btree	*b;
	t_btree	*c;

	a = node;
	b = a->left;
	c = b->right;
	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;
	return (c);
}

t_btree	*btree_rlrotate(t_btree *node)
{
	t_btree	*a;
	t_btree	*b;
	t_btree	*c;

	a = node;
	b = a->right;
	c = b->left;
	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;
	return (c);
}

t_btree	*btree_rrrotate(t_btree *node)
{
	t_btree	*a;
	t_btree	*b;

	a = node;
	b = a->right;
	a->right = b->left;
	b->left = a;
	return (b);
}
