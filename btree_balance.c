/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_balance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 06:35:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/12 15:16:18 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_btree	*btree_balance(t_btree *node)
{
	int const	balance = btree_balance_factor(node);

	if (balance >= 2)
	{
		if (btree_balance_factor(node->left) <= -1)
			return (btree_lrrotate(node));
		return (btree_llrotate(node));
	}
	else if (balance <= -2)
	{
		if (btree_balance_factor(node->right) >= 1)
			return (btree_rlrotate(node));
		return (btree_rrrotate(node));
	}
	return (node);
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
